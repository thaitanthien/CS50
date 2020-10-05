#include <iostream>
#include <math.h>
using namespace std;

// This program reverses a number
int main() {

  long n;
  do {
    cin >> n;
  }
  while (n <= 0 || n > 1e10);  // input n (0 < n <= 10 milion). 

  int x;
  long n1 = 0;
  while(n) {
    x = n % 10;     // get last number
    n1 = n1 * 10 + x;   // add x into n1

    n = n/10;       // remove last number
  }  

  cout << n1;
  return 0;
}