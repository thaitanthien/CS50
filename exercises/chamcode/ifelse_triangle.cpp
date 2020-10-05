#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
// This program prints the circumference and area of a triangle
int main() {
  
  float a, b, c;
  cin >> a >> b >> c;
  if (a > 0 && b > 0 && c > 0 &&
     (a + b) > c && (a + c) > b && (b + c) > a) {
    float p = (a + b + c) / 2;

    float q = p * (p - a) * (p - b) * (p - c);

    float S = sqrt(q);
    
    cout << fixed << setprecision(2) << p * 2 << ' ' << fixed << setprecision(2) << S;  
  }
  else {
    cout << "NO";
  }

  return 0;  
}