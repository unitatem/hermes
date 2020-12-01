#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <iostream>
#include <vector>

class CityNode;
class TownNode;

class Visitor
{
public:
    std::string report;

    virtual ~Visitor() = default;

    virtual void visit(const CityNode&) {}
    virtual void visit(const TownNode&) {}
};

class Node
{
public:
    virtual ~Node() = default;

    virtual void accept(Visitor& v) = 0;
};

class CityNode : public Node
{
public:
    const static std::string name;

    void accept(Visitor& v) override
    {
        v.visit(*this);
    }
};
const std::string CityNode::name = "CityNode";

class TownNode : public Node
{
public:
    const static std::string name;

    void accept(Visitor& v) override
    {
        v.visit(*this);
    }
};
const std::string TownNode::name = "TownNode";

class XmlReportVisitor : public Visitor
{
public:
    void visit(const CityNode& node) override
    {
        report += "XmlReportVisitor > " + node.name + "\n";
    }

    void visit(const TownNode& node) override
    {
        report += "XmlReportVisitor > " + node.name + "\n";
    }
};

class JsonReportVisitor : public Visitor
{
public:
    void visit(const CityNode& node) override
    {
        report += "JsonReportVisitor > " + node.name + "\n";
    }

    void visit(const TownNode& node) override
    {
        report += "JsonReportVisitor > " + node.name + "\n";
    }
};

TEST(visitor, good_weather)
{
    // Given
    CityNode city_node;
    TownNode town_node;
    std::vector<std::reference_wrapper<Node>> nodes = { city_node, town_node };

    XmlReportVisitor xml_report_visitor;
    JsonReportVisitor json_report_visitor;
    std::vector<std::reference_wrapper<Visitor>> visitors = { xml_report_visitor, json_report_visitor };

    // When
    for (const auto& visitor : visitors)
    {
        for (const auto& node : nodes)
        {
            node.get().accept(visitor.get());
        }
    }

    // Then
    EXPECT_EQ(visitors[0].get().report, "XmlReportVisitor > CityNode\nXmlReportVisitor > TownNode\n");
    EXPECT_EQ(visitors[1].get().report, "JsonReportVisitor > CityNode\nJsonReportVisitor > TownNode\n");
}
