#include <iostream>
using namespace std;

// This program finds minimum value from n number of float
int main() {

  cout << "Nhap n: ";
  int n;
  cin >> n;


  int * mang = new int[n];

  for(int i = 0; i < n; i++) {
    cout << "Nhap so thu " << i + 1 << ": ";
    cin >> mang[i];
  }

  int min = mang[0];
  
  for(int i = 1; i < n; i++) {
    if (mang[i] < min) {
      min = mang[i];
    }

  }

  cout << "So nho nhat la: " << min << "\n";

  return 0;

}