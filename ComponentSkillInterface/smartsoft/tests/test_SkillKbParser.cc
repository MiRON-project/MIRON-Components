#include <gtest/gtest.h> 
#include <SkillKbParser.hh>

TEST(ParsedJasonStrTest, QJsonDocumentParser) 
{
    QJsonObject root;
    root["msg-type"] = "unknown";
    root["id"] = 0;
    QJsonDocument doc(root);
    QString json_str = doc.toJson(QJsonDocument::Compact);
    ParsedJasonStr parsed_from_doc(doc);

    ASSERT_EQ(parsed_from_doc.id, 0);
    ASSERT_EQ(parsed_from_doc.msg_type, "unknown");
}

TEST(ParsedJasonStrTest, StringParser) 
{
    QJsonObject root;
    root["msg-type"] = "unknown";
    root["id"] = 0;
    QJsonDocument doc(root);
    QString json_str = doc.toJson(QJsonDocument::Compact);
    ParsedJasonStr parsed_from_str(json_str.toStdString());

    ASSERT_EQ(parsed_from_str.id, 0);
    ASSERT_EQ(parsed_from_str.msg_type, "unknown");
}

TEST(ParsedJasonQuery, QJsonDocumentParser) 
{
    QJsonObject root;
    QJsonObject query;
    root["msg-type"] = "query";
    root["id"] = 0;
    query["type"] = "some-query";
    root["query"] = query;

    QJsonDocument doc(root);
    ParsedJasonQuery parsed_from_doc(doc);

    ASSERT_EQ(parsed_from_doc.id, 0);
    ASSERT_EQ(parsed_from_doc.msg_type, "query");
    ASSERT_EQ(parsed_from_doc.query_type, "some-query");
}

TEST(ParsedJasonQuery, ParsedJasonStrParser_doc) 
{
    QJsonObject root;
    QJsonObject query;
    root["msg-type"] = "query";
    root["id"] = 0;
    query["type"] = "some-query";
    root["query"] = query;

    QJsonDocument doc(root);
    ParsedJasonStr parsed_jstr_from_doc(doc);
    ParsedJasonQuery parsed_from_doc(parsed_jstr_from_doc);

    ASSERT_EQ(parsed_from_doc.id, 0);
    ASSERT_EQ(parsed_from_doc.msg_type, "query");
    ASSERT_EQ(parsed_from_doc.query_type, "some-query");
}

TEST(ParsedJasonQuery, ParsedJasonStrParser_str) 
{
    QJsonObject root;
    QJsonObject query;
    root["msg-type"] = "query";
    root["id"] = 0;
    query["type"] = "some-query";
    root["query"] = query;

    QJsonDocument doc(root);
    QString json_str = doc.toJson(QJsonDocument::Compact);
    ParsedJasonStr parsed_jstr_from_str(json_str.toStdString());
    ParsedJasonQuery parsed_from_doc(parsed_jstr_from_str);

    ASSERT_EQ(parsed_from_doc.id, 0);
    ASSERT_EQ(parsed_from_doc.msg_type, "query");
    ASSERT_EQ(parsed_from_doc.query_type, "some-query");
}

TEST(ParsedQueryParameterChanged, ParsedJasonQuery_doc) 
{
    QJsonObject values;
    values["velocity_x"] = 1.12;
    values["velocity_y"] = 0.45;
    
    QJsonObject query;
    query["type"] = "change-parameter";
    query["ParameterSetRepository"] = "some-parameter-repository";
    query["ParameterSet"] = "some-parameter-set";
    query["Component"] = "some-component";
    query["Parameter"] = "some-parameter";
    query["values"] = values;

    QJsonObject root;
    root["msg-type"] = "query";
    root["id"] = 0;  
    root["query"] = query;

    QJsonDocument doc(root);
    ParsedJasonQuery parsed_query(doc);
    ParsedQueryParameterChanged parsed(parsed_query);

    ASSERT_EQ(parsed.id, 0);
    ASSERT_EQ(parsed.msg_type, "query");
    ASSERT_EQ(parsed.query_type, "change-parameter");
    ASSERT_EQ(parsed.param_repository, "some-parameter-repository");
    ASSERT_EQ(parsed.param_set, "some-parameter-set");
    ASSERT_EQ(parsed.component, "some-component");
    ASSERT_EQ(parsed.parameter, "some-parameter");
    ASSERT_EQ(parsed.values["velocity_x"], 1.12);
    ASSERT_EQ(parsed.values["velocity_y"], 0.45);
}