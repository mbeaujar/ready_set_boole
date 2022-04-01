#ifndef _ASTREE_HPP_
#define _ASTREE_HPP_

#include <iostream>

class ASTree {
  ExpNode* _root;

  void deleteAST(ExpNode*);

  void printNode(std::string, ExpNode*, bool);

 public:
  ASTree();
  ASTree(const ASTree&);
  ~ASTree();
  ASTree& operator=(const ASTree&);

  void insertNode(char, int, int);

  void insertNode(char, int);
  bool value();

  void printAST();
};

#endif  // _ASTREE_HPP_