#include <iomanip>
#include <iostream>
#include <stack>
#include <vector>

#include "ASTree.hpp"

bool display;

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
      if (values.size() < 1 || (values.size() == 1 && first == true)) {
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
  if (display) tree.printAST();
  return tree.value();
}

int main(int ac, char** av) {
  display = false;

  if (ac < 2 || ac > 3) {
    std::cerr << "Wrong number of arguments" << std::endl;
    return 1;
  }
  if (ac == 3) {
    if (std::string(av[2]) != "-d") {
      std::cerr << "Wrong argument" << std::endl;
      std::cerr << "-d display AST" << std::endl;
      return 1;
    }
    display = true;
  }
  std::string expression = av[1];
  std::cout << eval_formula(expression) << std::endl;
  return 0;
}