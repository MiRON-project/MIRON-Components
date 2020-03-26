#include "SkillKbParser.hh"

std::pair<std::vector<std::string>, std::string> parseKBMsg(
    const std::string& answer)
{
	auto outputs = parseKBOutputs(answer);
	auto name = parseKBSkillName(answer);
	return std::make_pair(outputs, name);
}

std::vector<std::string> parseKBOutputs(const std::string& answer)
{
	std::vector<int> index;
	std::vector<std::string> unordered_outputs;
	std::vector<std::string> outputs;

	std::size_t found_out = 0;
	std::size_t found_space = 0;
	std::size_t found_end_parenthesis = 0;
	while(true)
	{
		found_out = answer.find("OUT_", found_out, 4);
		if(found_out == std::string::npos)
			break;
		found_space = answer.find(" ", found_out);
        auto index_int = std::stoi(answer.substr(found_out + 4, 
            found_space - found_out - 4)) - 1;
		index.push_back(index_int);	
		found_end_parenthesis = answer.find(")", found_out);
        auto out = answer.substr(found_space + 1, 
            found_end_parenthesis - found_space - 1);
		unordered_outputs.push_back(out);
        ++found_out;
	}
	
	outputs.resize(index.size());
	for (size_t i = 0; i < index.size(); ++i)
		outputs[index[i]] = unordered_outputs[i];
    for (auto& out : outputs)
        std::cout << "out = " << out << "\n";
	return outputs;
}

std::string parseKBSkillName(const std::string& answer)
{
	std::size_t found_name = answer.find("NAME", 0, 4);
    if(found_name == std::string::npos)
        return "NIL";
	std::size_t found_end_parenthesis = answer.find(")", found_name);
	std::string name = answer.substr(found_name + 5, 
		found_end_parenthesis - found_name - 5);
	return name;	
}

bool stringCompareInsensitive(std::string & str1, std::string &str2)
{
    return ((str1.size() == str2.size()) && 
        std::equal(str1.begin(), str1.end(), str2.begin(), [](char & c1, 
            char & c2)
            {
                return (c1 == c2 || std::toupper(c1) == std::toupper(c2));
            })
            );
}

std::vector<std::string> parseJsonInput(const QJsonObject& skill)
{
    std::vector<std::string> input;
    QJsonObject skill_in_attribute = skill["in-attribute"].toObject();
	QJsonObject::iterator att = skill_in_attribute.begin();
    for (; att != skill_in_attribute.end(); ++att)
    {
        QJsonValue value = att.value();
        if (value.isString())
            input.push_back(value.toString().toStdString());   
        else if (value.isDouble())
            input.push_back(std::to_string(value.toDouble()));
        else if (value.isBool())
            input.push_back(std::to_string(value.toBool()));
        else
            input.push_back(std::to_string(value.toInt()));
    }
    return input;
}

std::vector<std::string> parseJsonOutput(const QJsonObject& skill)
{
    std::vector<std::string> output;
    QJsonObject skill_in_attribute = skill["out-attribute"].toObject();
	QJsonObject::iterator att = skill_in_attribute.begin();
    for (; att != skill_in_attribute.end(); ++att)
    {
        QJsonValue value = att.value();
        if (value.isString())
            output.push_back(value.toString().toStdString());   
        else if (value.isDouble())
            output.push_back(std::to_string(value.toDouble()));
        else if (value.isBool())
            output.push_back(std::to_string(value.toBool()));
        else
            output.push_back(std::to_string(value.toInt()));
    }
    return output;
}

std::string generateSkillKBMsg(std::string skill_name,
    const std::vector<std::string>& in, 
    const std::vector<std::string>& out)
{
    std::transform(skill_name.begin(), skill_name.end(), skill_name.begin(), 
        ::toupper);
    std::string message = "";
    message += "(KB-UPDATE :KEY '(IS-A) :VALUE '((IS-A SKILL)(NAME ";
    message += skill_name + ")";

    for (size_t i = 0; i < in.size(); ++i)
    {
        message += "(IN_" + std::to_string(i + 1) + " ";
        message += in[i] + ")";
    }

    for (size_t i = 0; i < out.size(); ++i)
    {
        message += "(OUT_" + std::to_string(i + 1) + " ";
        message += out[i] + ")";
    }
    message += "))";
    return message;
}