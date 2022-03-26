#include <bitset>
#include <cstdlib>
#include <iostream>

// https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/

int adderV1(int num1, int num2) {
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
  }
  return sum;
}

// https://en.wikipedia.org/wiki/Adder_%28electronics%29#Half_adder

// Inputs |	Outputs
//  A	 B	|  C	S
//  0	 0	|  0	0
//  0	 1	|  0	1
//  1	 0	|  0	1
//  1	 1	|  1	0

int adder(int num1, int num2) {
  int sum = 0;
  bool a, b, carry = 0;

  for (int i = 0; i < 32; i++) {
    a = (1 << i) & num1;
    b = (1 << i) & num2;

    sum = (a ^ b ^ carry) ? sum ^ (1 << i) : sum;

    // case where we have 1 ^ 1 = 0
    carry = ((a & b) | (a & carry) | (b & carry));

    // not O(1) anymore
    // if (num1 >> i == 0 && num2 >> i == 0 && carry == 0) break;
  }
  return sum;
}

int main(int ac, char **av) {
  if (ac != 3) {
    std::cerr << "Wrong number of arguments" << std::endl;
    std::cerr << "expected: ./adder [number] [number]" << std::endl;
    return 1;
  }
  int num1 = atoi(av[1]), num2 = atoi(av[2]);

  std::cout << adder(num1, num2) << std::endl;

  return 0;
}
