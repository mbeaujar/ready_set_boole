#ifndef _BINOPNODE_HPP_
#define _BINOPNODE_HPP_

#include "ExpNode.hpp"

class BinOpNode : public ExpNode {
  char _op;
  ExpNode *_left;
  ExpNode *_right;

 public:
  BinOpNode(char, ExpNode *, ExpNode *);
  BinOpNode(const BinOpNode &);
  ~BinOpNode();
  BinOpNode &operator=(const BinOpNode &);

  bool value();

  Type type();
  char ope();

  ExpNode *getLeft();
  ExpNode *getRight();
};

#endif  // _BINOPNODE_HPP_