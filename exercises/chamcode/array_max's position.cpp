#include <iostream>
using namespace std;

// This program prints positions of maximum values from n integer numbers
int main() {

  int n;
  cin >> n;

  // input n numbers
  int * mang = new int[n];
  for(int i = 0; i < n; i++) {
    cin >> mang[i];
  }

  // find maximum numbers among n numbers
  int max = mang[0];
  for(int i = 1; i < n; i++) {
    if (mang[i] > max) {
      max = mang[i];
    } 
  }
  
  // print positions
  for(int j = 0; j < n; j++) {
    if(max == mang[j]) {
      cout << j + 1 << ' ';
    }
  }

  return 0;
}