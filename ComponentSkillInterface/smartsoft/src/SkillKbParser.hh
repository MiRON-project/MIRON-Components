#ifndef _SKILLKBPARSER_HH
#define _SKILLKBPARSER_HH

#include <string>
#include <cctype>
#include <vector>
#include <utility> 
#include <iostream>
#include <QtCore>
#include <algorithm>

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

#endif