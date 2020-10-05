#include <iostream>
#include <math.h>
using namespace std;

// This program finds the largest digit of a number
int main() {

  int n;
  do {
    cin >> n;
  }
  while (n <= 0);  // input n

  int x;
  int max = n % 10;
  while(n) {
    x = n % 10;     // get last number
    if (x > max) {
      max = x;
    }

    n = n/10;       // remove last number
  }  

  cout << max;
  return 0;
}