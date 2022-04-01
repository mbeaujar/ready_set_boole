#include "BinOpNode.hpp"

BinOpNode::BinOpNode(char op, ExpNode* left, ExpNode* right)
    : ExpNode(BINOP), _op(op), _left(left), _right(right) {}

BinOpNode::BinOpNode(const BinOpNode& cpy)
    : ExpNode(BINOP), _op(cpy._op), _left(cpy._left), _right(cpy._right) {}

BinOpNode::~BinOpNode() {}

BinOpNode& BinOpNode::operator=(const BinOpNode& cpy) {
  if (this == &cpy) return *this;
  _op = cpy._op;
  _left = cpy._left;
  _right = cpy._right;
  return *this;
}

bool BinOpNode::value() {
  int leftVal = _left->value();
  int rightVal = _right->value();
  switch (_op) {
    case '|':
      return leftVal | rightVal;
    case '&':
      return leftVal & rightVal;
    case '>':
      return !(leftVal && !rightVal);
    case '=':
      return leftVal == rightVal;
    case '^':
      return leftVal ^ rightVal;
    case '!':
      return leftVal == !rightVal;
    case '+':
      return leftVal + rightVal;
  }
  return 0;
}

Type BinOpNode::type() { return _type; }

char BinOpNode::ope() { return _op; }

ExpNode* BinOpNode::getLeft() { return _left; }

ExpNode* BinOpNode::getRight() { return _right; }