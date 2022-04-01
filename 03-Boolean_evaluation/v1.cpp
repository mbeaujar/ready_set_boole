#include <iomanip>
#include <iostream>
#include <stack>

bool isBinOp(char c) {
  return c == '&' || c == '|' || c == '>' || c == '=' || c == '^' || c == '!';
}

bool calcul(char ope, bool num1, bool num2) {
  switch (ope) {
    case '|':
      return num1 | num2;
    case '&':
      return num1 & num2;
    case '>':
      return !(num1 && !num2);
    case '=':
      return num1 == num2;
    case '^':
      return num1 ^ num2;
    case '!':
      return num1 == !num2;
    default:
      std::cerr << "Error: wrong char: " << ope << std::endl;
      break;
  }
  return 0;
}

bool eval_formula(std::string& str) {
  std::stack<bool> values;
  std::stack<char> op;

  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] == ' ') continue;
    if (str[i] == '0' || str[i] == '1') {
      values.push(str[i] - 48);
    } else if (isBinOp(str[i])) {
      op.push(str[i]);
    } else {
      std::cerr << "Invalid character: " << str[i] << std::endl;
      exit(1);
    }
  }

  while (!op.empty()) {
    if (values.size() < 2) {
      std::cerr << "Wrong number of operators and operands" << std::endl;
      exit(1);
    }
    char ope = op.top();
    op.pop();

    bool num1 = values.top();
    values.pop();

    bool num2 = values.top();
    values.pop();

    values.push(calcul(ope, num1, num2));
  }
  if (values.size() == 0) return 0;
  return values.top();
}

int main(int ac, char** av) {
  if (ac != 2) {
    std::cerr << "Wrong number of arguments" << std::endl;
    return 1;
  }
  std::string expression = av[1];
  std::cout << std::boolalpha << eval_formula(expression) << std::endl;
  return 0;
}