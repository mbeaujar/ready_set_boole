#include <bitset>
#include <iostream>

// https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/

int adder(int num1, int num2) {
  int b1, b2, sum = 0, ret = 0, bit;

  if (num1 == 0 && num2 == 0) return 0;
  for (int i = 0; i < 32; i++) {
    b1 = (num1 >> i) & 1;
    b2 = (num2 >> i) & 1;
    if (b1 && b2) {
      if (ret == 1)
        bit = 1;
      else
        bit = 0;
      ret = 1;
    } else {
      if (ret == 1) {
        if (b1 | b2) {
          bit = 0;
          ret = 1;
        } else {
          bit = 1;
          ret = 0;
        }
      } else {
        bit = b1 | b2;
        ret = 0;
      }
    }
    sum = bit ? sum ^ (1 << i) : sum;
    // o(1) ??
    // if (num1 >> i == 0 && num2 >> i == 0 && ret == 0) break;
  }
  return sum;
}

int main() {
  int num1 = 2345;
  int num2 = 8124;
  std::cout << "total sum: " << adder(num1, num2) << std::endl;
  return 0;
}
