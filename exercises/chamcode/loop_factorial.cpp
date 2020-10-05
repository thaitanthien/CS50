#include <iostream>
using namespace std;

// This program calculates factorial n!
int main() {
  int n;
  do {
    cin >> n;
  }
  while (n < 0);

  long giaithua = 1;

  for (int i = 1; i <= n; i++) {
    giaithua = giaithua * i;
  }

  cout << giaithua;

  return 0;
}