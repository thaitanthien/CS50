#include <iostream>
using namespace std;

// This program finds number n of fibonaci chain:
// f(n) = f(n-1) + f(n-2), n > 2 và f(1) = 1, f(2) = 1.
int main() {

  int n;
  do {
    cin >> n;   // Input n (0 < n <= 50)
  }
  while (n <= 0 || n > 50);

  if (n == 1 || n == 2) {
    cout << 1;
  }

  else {
    long fn;
    long f1 = 1;
    long f2 = 1;
    
    for(int i = 3; i <= n; i++) {
      fn = f1 + f2;
      f1 = f2;    // Prepare for the next loop
      f2 = fn;
    }

    cout << fn;
  }

  return 0;
}