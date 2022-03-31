#ifndef _NODE_HPP_
#define _NODE_HPP_

#include <iostream>

enum Type {
  NONE,
  CONST,
  BINOP,
};

class ExpNode {
 protected:
  Type _type;

 public:
  ExpNode(Type type) : _type(type) {}
  virtual ~ExpNode() {}
  virtual int value() = 0;
  virtual Type type() = 0;
};

class ConstNode : public ExpNode {
  int _number;

 public:
  ConstNode(int val) : ExpNode(CONST), _number(val) {}

  int value() { return _number; }

  Type type() { return _type; }
};

class BinOpNode : public ExpNode {
  char _op;
  ExpNode *_left;
  ExpNode *_right;

 public:
  BinOpNode(char op, ExpNode *left, ExpNode *right)
      : ExpNode(BINOP), _op(op), _left(left), _right(right) {}

  int value() {
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

  Type type() { return _type; }

  ExpNode *getLeft() { return _left; }
  ExpNode *getRight() { return _right; }
};

#endif  // _NODE_HPP_