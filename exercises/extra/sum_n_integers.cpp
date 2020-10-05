#include <iostream>
using namespace std;

// This program finds sum of n interger numbers
int main() {
  
  cout << "Nhap n: ";
  int n;
  cin >> n;

  int tong = 0;

  int * score = new int[n];

  for(int i = 0; i < n ; i++) {
    cout << "Nhap so thu " << i + 1 << ": ";
      cin >> score[i];

      tong += score[i];
  }

  cout << "Tong la: " << tong << "\n";

  return 0;
}