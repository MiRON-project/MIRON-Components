#ifndef _SKILLKBPARSER_HH
#define _SKILLKBPARSER_HH

#include <string>
#include <cctype>
#include <vector>
#include <utility>
#include <iostream>
#include <QtCore>
#include <algorithm>
#include <unordered_map>
#include "AceSmartSoftKernel/smartCommParameterRequest.hh"

std::pair<std::vector<std::string>, std::string> parseKBMsg(
    const std::string &answer);

std::vector<std::string> parseKBOutputs(const std::string &answer);

std::string parseKBSkillName(const std::string &answer);

std::string parseKBSkillResult(const std::string &answer);

bool stringCompareInsensitive(std::string &str1, std::string &str2);

std::map<std::string, std::string> parseJsonInput(const QJsonObject &skill);

std::pair<std::vector<std::string>, std::vector<std::string>> parseJsonOutput(const QJsonObject &skill);

std::string generateSkillKBMsg(const std::string &skill_name,
                               int id, const std::map<std::string, std::string> &in,
                               const std::vector<std::string> &out);

std::string stringToupper(const std::string &str);

int parseKBSkillId(const std::string &answer);

struct ParsedSkillDefinition
{
  int id;
  std::string skill_name;
  std::string skill_definition;
  std::string msg_type;
  std::map<std::string, std::string> in;
  std::vector<std::string> out;
  std::vector<std::string> out_keys;
  std::string result;
  std::string result_value;
  QJsonObject root_;

  ParsedSkillDefinition(const QJsonDocument &doc)
  {
    QJsonObject root = doc.object();
    QJsonObject json_skill = root["skill"].toObject();

    msg_type = root["msg-type"].toString().toStdString();
    id = root["id"].toInt();
    skill_name = json_skill["name"].toString().toStdString();
    skill_definition = json_skill["skill-definition-fqn"].toString().toStdString();
    in = parseJsonInput(json_skill);
    auto outs = parseJsonOutput(json_skill);
    out = outs.first;
    out_keys = outs.second;
    result = "SUCCESS";
    result_value = "OK";
  }

  std::string parseResult()
  {
    QJsonObject result_json;

    root_["msg-type"] = "skill-result";
    root_["id"] = id;
    result_json["result"] = QString::fromUtf8(result.c_str());
    result_json["result-value"] = QString::fromUtf8(result_value.c_str());
    root_["result"] = result_json;
    QJsonDocument answer(root_);
    QString json_answer = answer.toJson(QJsonDocument::Compact);
    return json_answer.toStdString();
  }

  void parseOutputs(const std::vector<std::string> ordered_outputs)
  {
    if (ordered_outputs.size() != out_keys.size())
      return;
    
    QJsonObject outputs;
    for (size_t i = 0; i < out_keys.size(); ++i)
    {
      double value = 0;
      try
      {
        value = std::stod(ordered_outputs[i]);
        outputs[QString::fromUtf8(out_keys[i].c_str())] = value;
      }
      catch (...)
      {
        outputs[QString::fromUtf8(out_keys[i].c_str())] =
            QString::fromUtf8(ordered_outputs[i].c_str());
      }
    }
    root_["outputs"] = outputs;
  }
};

struct ParsedJasonStr
{
  int id;
  std::string msg_type;
  QJsonParseError error;
  QJsonDocument _doc;

  ParsedJasonStr(const QJsonDocument &doc) : _doc(doc)
  {
    QJsonObject root = doc.object();
    msg_type = root["msg-type"].toString().toStdString();
    id = root["id"].toInt();
  }

  ParsedJasonStr(const std::string &file)
  {
    auto cfile = file.c_str();
    QString line = QString::fromUtf8(cfile);
    _doc = QJsonDocument::fromJson(line.toUtf8(), &error);

    if (QJsonParseError::NoError != error.error)
    {
      std::cout << "error: parsing json error:" << error.errorString().toStdString() << std::endl;
    }
    else
    {
      QJsonObject root = _doc.object();
      msg_type = root["msg-type"].toString().toStdString();
      id = root["id"].toInt();
    }
  }
};

struct ParsedJasonQuery : ParsedJasonStr
{
  std::string query_type;

  ParsedJasonQuery(const QJsonDocument &doc) : ParsedJasonStr(doc)
  {
    init();
  }

  ParsedJasonQuery(const ParsedJasonStr &doc) : ParsedJasonStr(doc)
  {
    init();
  }

  void init()
  {
    QJsonObject root = _doc.object();
    QJsonObject query = root["query"].toObject();
    query_type = query["type"].toString().toStdString();
  }
};

struct ParsedQueryParameterChanged : ParsedJasonQuery
{
  std::string param_repository;
  std::string param_set;
  std::string component;
  std::string parameter;
  std::map<std::string, double> values;

  ParsedQueryParameterChanged(const ParsedJasonQuery &doc) : ParsedJasonQuery(doc)
  {
    QJsonObject root = _doc.object();
    QJsonObject query = root["query"].toObject();
    param_repository = query["ParameterSetRepository"].toString().toStdString();
    param_set = query["ParameterSet"].toString().toStdString();
    component = query["Component"].toString().toStdString();
    parameter = query["Parameter"].toString().toStdString();

    QJsonObject _values = query["values"].toObject();

    for (auto it = _values.begin(); it != _values.end(); ++it)
      values.insert({it.key().toStdString(), it.value().toDouble()});
  }

  SmartACE::CommParameterRequest buildRequest()
  {
    SmartACE::CommParameterRequest parameterRequest;
    parameterRequest.setTag(buildTag());

    size_t i = 1;
    for (auto it = values.begin(); it != values.end(); ++it,
              ++i)
      parameterRequest.setString(std::to_string(i),
                                 std::to_string(it->second));
    return parameterRequest;
  }

  SmartACE::CommParameterRequest commitRequest()
  {
    SmartACE::CommParameterRequest parameterRequest;
    parameterRequest.setTag("COMMIT");
    return parameterRequest;
  }

  std::string buildTag()
  {
    return stringToupper(param_repository) + "." +
           stringToupper(param_set) + "." + stringToupper(parameter);
  }
};

#endif