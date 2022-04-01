#include "ConstNode.hpp"

ConstNode::ConstNode(bool val) : ExpNode(CONST), _value(val) {}

ConstNode::ConstNode(const ConstNode& cpy)
    : ExpNode(CONST), _value(cpy._value) {}

ConstNode::~ConstNode() {}

ConstNode& ConstNode::operator=(const ConstNode& cpy) {
  if (this == &cpy) return *this;
  _value = cpy._value;
  return *this;
}

bool ConstNode::value() { return _value; }

Type ConstNode::type() { return _type; }