#include <iostream>
using namespace std;

// This program counts even from n numbers of integer
int main() {
 
  cout << "Nhap n: ";
  int n;
  cin >> n;

  int even = 0;

  int * mang = new int[n];

  for(int i = 0; i < n; i++) {
    cout << "Nhap so thu " << i + 1 << ": ";
    cin >> mang[i];

    if(mang[i] % 2 == 0) {
      even += 1;
    } 

  }

  cout << "So so chan la: " << even << "\n";
  
  return 0;
}