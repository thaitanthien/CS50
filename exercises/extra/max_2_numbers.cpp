#include <iostream>
using namespace std;

// This program finds maximum of 2 numbers
int main() {

  int a;
  int b;
  cout << "Nhap so thu nhat:\n";
  cin >> a;
  cout << "Nhap so thu hai:\n";
  cin >> b;

  if (a > b) {
    cout << "So lon nhat trong hai so la: " << a << "\n";
  }
    else {
      cout << "So lon nhat trong hai so la: " << b << "\n";
  }

  return 0;
}