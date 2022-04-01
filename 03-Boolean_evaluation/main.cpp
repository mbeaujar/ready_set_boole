#include <iomanip>
#include <iostream>
#include <stack>
#include <vector>

#include "ASTree.hpp"

bool isBinOp(char c) {
  return c == '&' || c == '|' || c == '>' || c == '=' || c == '^' || c == '!';
}

bool eval_formula(std::string& str) {
  ASTree tree;
  bool first = true;
  std::vector<bool> values;

  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] == ' ') continue;
    if (str[i] == '0' || str[i] == '1') {
      values.push_back(str[i] - 48);
    } else if (isBinOp(str[i])) {
      if (values.size() < 1 || values.size() == 1 && first == true) {
        std::cerr << "invalid number of values before operator" << std::endl;
        exit(1);
      }
      if (values.size() == 1) {
        tree.insertNode(str[i], values[0]);
        values.erase(values.begin());
      } else {
        if (first == true) {
          tree.insertNode(str[i], values[0], values[1]);
          values.erase(values.begin());
          values.erase(values.begin());
          first = false;
        } else {
          tree.insertNode(str[i], values[0]);
          values.erase(values.begin());
        }
      }
    } else {
      std::cerr << "Invalid character: " << str[i] << std::endl;
      exit(1);
    }
  }
  // tree.printAST();
  return tree.value();
}

int main(int ac, char** av) {
  if (ac != 2) {
    std::cerr << "Wrong number of arguments" << std::endl;
    return 1;
  }
  std::string expression = av[1];
  std::cout << eval_formula(expression) << std::endl;
  return 0;
}