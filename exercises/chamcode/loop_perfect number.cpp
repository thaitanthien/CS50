#include <iostream>
using namespace std;

// This program checks if a number is perfect number
int main() {

  int n;
  do {
    cin >> n;
  }
  while (n <= 0);
  
  int sum = 0;
  for(int i = 1; i <= n; i++) {
    if (n % i == 0) {
      sum += i;
    }
  }

  if(sum == 2 * n) {
    cout << "TRUE";
  }
  else {
    cout << "FALSE";
  }
}