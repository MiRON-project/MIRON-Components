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
	std::size_t found_name = answer.find("(NAME", 0, 5);
    if(found_name == std::string::npos)
        return "NIL";
	std::size_t found_end_parenthesis = answer.find(")", found_name);
	std::string name = answer.substr(found_name + 6, 
		found_end_parenthesis - found_name - 6);
	return name;	
}

std::string parseKBSkillResult(const std::string& answer)
{
	std::size_t found_name = answer.find("(RESULT", 0, 7);
    if(found_name == std::string::npos)
        return "SUCCESS";
	std::size_t found_end_parenthesis = answer.find(")", found_name);
	std::string name = answer.substr(found_name + 8, 
		found_end_parenthesis - found_name - 8);
	return name;	
}

int parseKBSkillId(const std::string& answer)
{
	std::size_t found_name = answer.find("(ID", 0, 3);
    if(found_name == std::string::npos)
        return -1;
	std::size_t found_end_parenthesis = answer.find(")", found_name);
	std::string id = answer.substr(found_name + 4, 
		found_end_parenthesis - found_name - 4);
	return std::stoi(id);	
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

std::map<std::string, std::string> parseJsonInput(const QJsonObject& skill)
{
    std::map<std::string, std::string> input;
    QJsonObject skill_in_attribute = skill["in-attribute"].toObject();
	QJsonObject::iterator att = skill_in_attribute.begin();
    for (; att != skill_in_attribute.end(); ++att)
    {
        const auto key = att.key();
        QJsonValue value = att.value();
        if (value.isString())
            input.insert(std::make_pair(key.toStdString(), 
                value.toString().toStdString()));
        else if (value.isDouble())
            input.insert(std::make_pair(key.toStdString(), 
                std::to_string(value.toDouble())));
        else if (value.isBool())
            input.insert(std::make_pair(key.toStdString(), 
                std::to_string(value.toBool())));
        else
            std::cerr << "Input variable is not parsable" << std::endl;
    }
    return input;
}

std::pair<std::vector<std::string>, std::vector<std::string>> parseJsonOutput(const QJsonObject& skill)
{
    std::vector<std::string> output;
    std::vector<std::string> output_keys;
    QJsonObject skill_in_attribute = skill["out-attribute"].toObject();
	QJsonObject::iterator att = skill_in_attribute.begin();
    for (; att != skill_in_attribute.end(); ++att)
    {
        output_keys.push_back(att.key().toStdString());
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
    return std::make_pair(output, output_keys);
}

std::string generateSkillKBMsg(const std::string& skill_name, int id,
    const std::map<std::string, std::string>& in, 
    const std::vector<std::string>& out)
{
    auto t_skill_name = stringToupper(skill_name);
    std::string message = "";
    message += "(KB-UPDATE :KEY '(IS-A) :VALUE '((IS-A SKILL)(NAME ";
    message += t_skill_name + ")";
    message += "(ID " + std::to_string(id) + ")";
    
    for (auto it = in.begin(); it != in.end(); ++it)
    {
        message += "(" + it->first + " ";
        message += it->second + ")";
    }

    for (size_t i = 0; i < out.size(); ++i)
    {
        message += "(OUT_" + std::to_string(i + 1) + " ";
        message += out[i] + ")";
    }
    message += "))";
    return message;
}

std::string stringToupper(const std::string& str)
{
    std::string t_str = str;
    std::for_each(t_str.begin(), t_str.end(), [](char & c){
        c = ::toupper(c);});
    return t_str;
}