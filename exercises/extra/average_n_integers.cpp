#include <iostream>
using namespace std;

// This program finds average of n numbers of integer
int main() {

  cout << "Nhap n: ";
  int n;
  cin >> n;

  int sum = 0;
  int * mang = new int[n];
  
  for(int i = 0; i < n; i++) {
    cout << "Nhap so thu " << i + 1 << " : ";
    cin >> mang[i];
    sum += mang[i];
  }

  cout << "Trung binh cong la: " << sum / n << "\n";

  return 0;
  }