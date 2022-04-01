#ifndef _EXPNODE_HPP_
#define _EXPNODE_HPP_

#include "enum.hpp"

class ExpNode {
 protected:
  Type _type;

 public:
  ExpNode(Type);
  ExpNode(const ExpNode&);
  virtual ~ExpNode();
  ExpNode& operator=(const ExpNode&);

  virtual bool value() = 0;
  virtual Type type() = 0;
};

#endif  // _EXPNODE_HPP_