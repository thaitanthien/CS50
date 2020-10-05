#include <iostream>
#include <iomanip>

using namespace std;

// This program prints total, difference, product & quotient of 2 numbers
int main() {
  
  int a;
  int b;
  
  do {
    cin >> a >> b;
  }
  while (b == 0);

  float divide = (float) a / (float) b;
  // std::cout.precision(4);
    
  cout << (a + b) << ' ' << (a - b) << '\n'
       << (a * b) << ' ' << fixed << setprecision(2) << divide << '\n';

  return 0;
  
}

