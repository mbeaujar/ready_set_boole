#include <bitset>
#include <iostream>

// https://en.wikipedia.org/wiki/Gray_code#Constructing_an_n-bit_Gray_code

int gray_code(int num) { return num ^ (num >> 1); }

int main() {
  for (int i = 0; i < 9; i++) {
    std::cout << gray_code(i) << std::endl;
  }
  return 0;
}