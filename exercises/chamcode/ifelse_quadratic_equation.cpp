#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

// this progam solves the quadratic equation ax^2 + bx + c = 0
int main() {

  float a;
  float b;
  float c;
  cin >> a >> b >> c;

  if (a == 0 && b == 0 & c == 0) {
    cout << "VSN";
  }
  else if (a == 0 && b == 0 && c != 0) {
    cout << "VN";
  }
  else if (a == 0 && b != 0 && c != 0) {
    cout << "x = " << fixed << setprecision(2) << -c / b;
  }
  else if ( a != 0 && b != 0 && c != 0) {
      float delta = (b * b) - (4 * a * c);
      if (delta < 0) {
        cout << "VN";
      }
      else if (delta == 0) {
        cout << "x = " << fixed << setprecision(2) << - b / 2 / a;
      }
      else if (delta > 0) {
        cout << fixed << setprecision(2) << (-b - sqrt(delta)) / 2 / a << ' '
            << fixed << setprecision(2) << (-b + sqrt(delta)) / 2 / a << '\n';
      }
  }
  
  return 0;
}