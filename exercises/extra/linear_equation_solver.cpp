#include <iostream>

using namespace std;

int main() {

  // This program solves the linear equation ax + b = 0
  cout << "Nhap a: ";
  int a;
  cin >> a;
  cout << "Nhap b: ";
  int b;
  cin >> b;


  if(a != 0 && b == 0) {
    cout << "Nghiem cua phuong trinh la: x = 0\n";
  } else if(a == 0 && b != 0) {
    cout << "Phuong trinh vo nghiem.\n";
  } else {
    cout << "Nghiem cua phuong trinh la: x = " << -(b / a) << " \n";
  }

  return 0;
}