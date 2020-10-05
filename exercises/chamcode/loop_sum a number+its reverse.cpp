#include <iostream>
#include <math.h>
using namespace std;

// This program calculates sum of a number with its reverse
int main() {

  long n;
  do {
    cin >> n;
  }
  while (n <= 0);  // input n

  int x;
  long n1 = 0;
  long sum = n;
  while(n) {
    x = n % 10;     // get last number
    n1 = n1 * 10 + x;   // add x into n1
 
    n = n/10;       // remove last number
  }  

  cout << n1;
  sum += n1;        // calculate the total
  cout << sum;

  return 0;
}