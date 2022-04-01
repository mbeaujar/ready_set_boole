#ifndef _ASTREE_HPP_
#define _ASTREE_HPP_

#include <iostream>

#include "Node.hpp"

class ASTree {
  ExpNode* _root;

  void deleteAST(ExpNode* pointer) {
    if (pointer == nullptr) return;
    if (pointer->type() == CONST) {
      delete pointer;
    } else {
      BinOpNode* p = dynamic_cast<BinOpNode*>(pointer);
      deleteAST(p->getLeft());
      deleteAST(p->getRight());
      delete p;
    }
  }

  void printNode(std::string prefix, ExpNode* node, bool isLeft) {
    if (node != nullptr) {
      std::cout << prefix;
      std::cout << (isLeft ? "├──" : "└──");
      ConstNode* tmp = dynamic_cast<ConstNode*>(node);
      if (tmp) {
        std::cout << tmp->value() << std::endl;
      } else {
        BinOpNode* op = dynamic_cast<BinOpNode*>(node);
        std::cout << "[" << op->ope() << "]" << std::endl;
        printNode(prefix + (isLeft ? "|  " : "   "), op->getLeft(), true);
        printNode(prefix + (isLeft ? "|  " : "   "), op->getRight(), false);
      }
    }
  }

 public:
  ASTree() : _root(nullptr){};
  ~ASTree() { deleteAST(_root); };

  void insertNode(char ope, int num1, int num2) {
    ExpNode* node =
        new BinOpNode(ope, new ConstNode(num1), new ConstNode(num2));
    if (_root == nullptr) {
      _root = node;
    }
  }

  void insertNode(char ope, int num2) {
    ExpNode* node = new BinOpNode(ope, _root, new ConstNode(num2));
    _root = node;
  }

  int value() { return _root->value(); }

  void printAST() { printNode("", _root, false); }
};

#endif  // _ASTREE_HPP_