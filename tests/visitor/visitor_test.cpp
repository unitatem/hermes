#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <iostream>

class CityNode;
class TownNode;

class Visitor
{
public:
    virtual ~Visitor() = default;

    virtual void visit(const CityNode& e) = 0;
    virtual void visit(const TownNode& e) = 0;
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

class ReportVisitor : public Visitor
{
public:
    void visit(const CityNode& node) override
    {
        std::cout << "CityNode: " << node.name << std::endl;
    }

    void visit(const TownNode& node) override
    {
        std::cout << "TownNode: " << node.name << std::endl;
    }
};

TEST(test, success)
{
    CityNode city_node;
    TownNode town_node;

    ReportVisitor report_visitor;

    city_node.accept(report_visitor);
    town_node.accept(report_visitor);
}
