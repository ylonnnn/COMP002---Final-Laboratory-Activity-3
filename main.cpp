#include <iostream>

int greatestCommonFactor(int x, int y) {
  // Gets the highest and lowest of the two numbers
  int max = std::max(x, y), min = std::min(x, y);

  // If the higher is divisible by the lower, return
  // the lower as it is the greatest common divisor
  if (!(max % min))
    return min;

  // Brute force checking
  int gcf = 1;

  // Iterate through the numbers from 1 to the lower number
  for (int i = gcf; i <= min; i++) {

    // If the higher and lower numbers are divisible by the current number (i),
    // set the new greatest common factor to the current number (i)
    if (!(max % i) && !(min % i))
      gcf = i;
  }

  return gcf;
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