#include "ExpNode.hpp"

ExpNode::ExpNode(Type type) : _type(type) {}

ExpNode::ExpNode(const ExpNode& cpy) : _type(cpy._type) {}

ExpNode::~ExpNode() {}

ExpNode& ExpNode::operator=(const ExpNode& cpy) {
  if (this == &cpy) return *this;
  _type = cpy._type;
  return *this;
}
