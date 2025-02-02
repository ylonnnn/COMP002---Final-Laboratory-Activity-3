#include <iostream>

int greatestCommonFactor(int x, int y) {
  // Using Euclidean Algorithm
  while (y) {
    int temp = x;

    x = y;
    y = temp % y;
  }

  return x;
}

int leastCommonMultiple(int x, int y) {
  // Using the formula: (x * y) / GCF(x, y)
  return (x * y) / greatestCommonFactor(x, y);
}

int main() {

  // Information output
  std::cout << "WELCOME!\nThis program will compute for the following:\n1. "
               "Greatest Common Divisor (GCD)\n2. Least Common Multiple "
               "(LCM)\n3. Common Divisors\n\n";

  // Input queries
  int x, y;

  // For the first number (x)
  std::cout << "Enter the first number: ";
  std::cin >> x;
  if (x < 1 || std::cin.fail()) {
    std::cout << "Please input a valid positive integer!\n";
    return 1;
  }

  // For the first number (y)
  std::cout << "Enter the second number: ";
  std::cin >> y;
  if (y < 1 || std::cin.fail()) {
    std::cout << "Please input a valid positive number!\n";
    return 1;
  }

  // Greatest Common Factor (GCF)
  std::cout << "The Greatest Common Factor (GCF) of " << x << " and " << y
            << " is: " << greatestCommonFactor(x, y) << "\n";

  // Least Common Multiple (LCM)
  std::cout << "The Least Commmon Multiple (LCM) of " << x << " and " << y
            << " is: " << leastCommonMultiple(x, y) << "\n";

  // Common Divisors (Brute Force)
  std::cout << "The Common Divisors of " << x << " and " << y << " are : ";

  for (int i = 1; i <= greatestCommonFactor(x, y); i++) {
    if (!(x % i) && !(y % i))
      std::cout << i << ", ";
  }

  std::cout << "\n";

  return 0;
}