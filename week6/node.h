#pragma once

#include "date.h"
#include <functional>

enum class LogicalOperation {
  And,
  Or,
};

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual,
};

class Node {
public:
    virtual bool Evaluate(Date date_, string event_) const = 0;
};

class EmptyNode : public Node {
public:
    bool Evaluate(Date date_, string event_) const override {
        return 1;
    }
};

class DateComparisonNode : public Node {
    const Comparison cmp;
    const Date date;
public:
    DateComparisonNode(Comparison cmp_, Date date_) : cmp(cmp_), date(date_) {

    }
    bool Evaluate(Date date_, string event_) const override {
        if (cmp == Comparison::Less) {
            return date_ < date;
        }
        else if (cmp == Comparison::LessOrEqual) {
            return date_ <= date;
        }
        else if (cmp == Comparison::Greater) {
            return date_ > date;
        }
        else if (cmp == Comparison::GreaterOrEqual) {
            return date_ >= date;
        }
        else if (cmp == Comparison::Equal) {
            return date_ == date;
        }
        else {
            return date_ != date;
        }
    }
};

class EventComparisonNode : public Node {
    const Comparison cmp;
    const string event;
public:
    EventComparisonNode(Comparison cmp_, string event_) : cmp(cmp_), event(event_) {

    }
    bool Evaluate(Date date_, string event_) const override {
        if (cmp == Comparison::Less) {
            return event_ < event;
        }
        else if (cmp == Comparison::LessOrEqual) {
            return event_ <= event;
        }
        else if (cmp == Comparison::Greater) {
            return event_ > event;
        }
        else if (cmp == Comparison::GreaterOrEqual) {
            return event_ >= event;
        }
        else if (cmp == Comparison::Equal) {
            return event_ == event;
        }
        else {
            return event_ != event;
        }
    }
};

class LogicalOperationNode : public Node {
    shared_ptr<Node> left, right;
    const LogicalOperation operation;
public:
    LogicalOperationNode(LogicalOperation operation_, 
                         shared_ptr<Node> left_, shared_ptr<Node> right_) 
                         : operation(operation_), left(left_), right(right_) {

    }
    bool Evaluate(Date date_, string event_) const override {
        if (operation == LogicalOperation::And) {
            return left->Evaluate(date_, event_) && right->Evaluate(date_, event_);
        }
        else  {
            return left->Evaluate(date_, event_) || right->Evaluate(date_, event_);
        }
    }
};