#include <iostream>
using namespace std;

// This program checks if a number is a prime number
int main() {

  int n;
  cin >> n;

  if (n < 2) {
    cout << "FALSE";
  }
  else {
    for (int i = 2; i < n; i++) {
      if (n % i == 0) {
        cout << "FALSE";
        return 0;
      }
    }
    cout << "TRUE";
  }

  return 0;
}