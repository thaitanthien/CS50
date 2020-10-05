#include <iostream>
#include <iomanip>

// This program prints area and volume of a circle
int main() {

  float R;  
  std::cin >> R;
  float S;
  float V;

  S = 4 * 3.14 * R * R;
  V = (4.0 / 3.0) * 3.14 * R * R * R;

  //std::cout.precision(2);
  std::cout << std::fixed << std::setprecision(2) << S << ' ' 
  			<< std::fixed << std::setprecision(2) << V << '\n';
  return 0;
}