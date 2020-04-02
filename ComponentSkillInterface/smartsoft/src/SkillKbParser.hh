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

std::pair<std::vector<std::string>, std::string> parseKBMsg(
    const std::string& answer);

std::vector<std::string> parseKBOutputs(const std::string& answer);

std::string parseKBSkillName(const std::string& answer);

bool stringCompareInsensitive(std::string & str1, std::string &str2);

std::vector<std::string> parseJsonInput(const QJsonObject& skill);

std::vector<std::string> parseJsonOutput(const QJsonObject& skill);

std::string generateSkillKBMsg(std::string skill_name,
    const std::vector<std::string>& in, 
    const std::vector<std::string>& out);

struct ParsedSkillDefinition
{
    int id;
    std::string skill_name;
    std::string skill_definition;
    std::string msg_type;
    std::vector<std::string> in;
    std::vector<std::string> out;
    std::string result;
    std::string result_value;

    ParsedSkillDefinition(const QJsonDocument& doc)
    {
        QJsonObject root = doc.object();
        QJsonObject json_skill = root["skill"].toObject();

        msg_type = root["msg-type"].toString().toStdString();
        id = root["id"].toInt();
		skill_name = json_skill["name"].toString().toStdString();
		skill_definition = json_skill["skill-definition-fqn"].toString().
            toStdString();
		in = parseJsonInput(json_skill);
		out = parseJsonOutput(json_skill);
        result = "SUCCESS";
        result_value = "OK";
    }

    std::string parseResult()
    {
        QJsonObject root;
        QJsonObject result_json;
        
        root["msg-type"] = "skill-result";
		root["id"] = id;
		result_json["result"] = QString::fromUtf8(result.c_str());
		result_json["result-value"] = QString::fromUtf8(result_value.c_str());
		root["result"] = result_json;
		QJsonDocument answer(root);
        QString json_answer = answer.toJson(QJsonDocument::Compact);
        return json_answer.toStdString();
    }
};

struct ParsedJasonStr
{
    int id;
    std::string msg_type;
    QJsonParseError error;
    QJsonDocument _doc;

    ParsedJasonStr(const QJsonDocument& doc) : 
        _doc(doc)
    {
        QJsonObject root = doc.object();
        msg_type = root["msg-type"].toString().toStdString();
    }

    ParsedJasonStr(const std::string& file)
    {
        auto cfile = file.c_str();
        QString line = QString::fromUtf8(cfile);
		QJsonDocument _doc = QJsonDocument::fromJson(line.toUtf8(), &error);
        
        if(QJsonParseError::NoError != error.error)
		{
			std::cout << "error: parsing json error:" << 
				error.errorString().toStdString() << std::endl;
		}
        else
        {
            QJsonObject root = _doc.object();
            msg_type = root["msg-type"].toString().toStdString();
        }
    }
};

struct ParsedJasonQuery : ParsedJasonStr
{

    std::string query_type;

    ParsedJasonQuery(const QJsonDocument& doc) : 
        ParsedJasonStr(doc)
    {
        init();
    }

    ParsedJasonQuery(const ParsedJasonStr& doc) :
        ParsedJasonStr(doc._doc)
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
    std::unordered_map<std::string, double> values;

    ParsedQueryParameterChanged(const ParsedJasonQuery& doc) : 
        ParsedJasonQuery(doc)
    {
        QJsonObject root = _doc.object();
        QJsonObject query = root["query"].toObject();
        param_repository = query["ParameterSetRepository"].toString().
            toStdString();
        param_set = query["ParameterSet"].toString().toStdString();
        component = query["Component"].toString().toStdString();
        parameter = query["Parameter"].toString().toStdString();

        QJsonObject _values = query["values"].toObject();
        
        for (auto it = _values.begin(); it != _values.end(); ++it)
            values.insert({it.key().toStdString(), it.value().toDouble()});
    }

    std::string parseResult()
    {
        return "";
    }

};

#endif