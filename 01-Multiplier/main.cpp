#include <bitset>
#include <iostream>

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

// https://en.wikipedia.org/wiki/Binary_multiplier

//      1011   (this is binary for decimal 11)
//    x 1110   (this is binary for decimal 14)
//    ======
//      0000   (this is 1011 x 0)
//     1011    (this is 1011 x 1, shifted one position to the left)
//    1011     (this is 1011 x 1, shifted two positions to the left)
// + 1011      (this is 1011 x 1, shifted three positions to the left)
// =========
//  10011010   (this is binary for decimal 154)

int multiplier(int num1, int num2) {
  int sum = 0;
  bool b;

  for (int i = 0; i < 32; i++) {
    b = (1 << i) & num2;
    sum = adder(sum, b ? num1 << i : 0);

    // not O(1)
    // if (num2 >> i == 0) break;
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

  std::cout << multiplier(num1, num2) << std::endl;

  return 0;
}