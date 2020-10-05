#include <iostream>

// This program prints the perimeter and the area of a rectangle
int main() {

  long a;
  int b;
  
  // input condition: a > 0, b <= 100000
  do {
    std::cin >> a >> b;
  }
  while (a <= 0 || b > 100000);


  std::cout << 2 * (a + b) << ' ' << a * b << '\n';
  
  return 0;
}