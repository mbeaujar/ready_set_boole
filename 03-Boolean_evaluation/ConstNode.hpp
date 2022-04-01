#ifndef _CONSTNODE_HPP_
#define _CONSTNODE_HPP_

#include "ExpNode.hpp"

class ConstNode : public ExpNode {
  bool _value;

 public:
  ConstNode(bool);
  ConstNode(const ConstNode&);
  ~ConstNode();
  ConstNode& operator=(const ConstNode&);

  bool value();
  Type type();
};

#endif