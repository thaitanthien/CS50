#include <iostream>
using namespace std;

// This program prints prime numbers less than a number
int main() {
  
  int n;
  cin >> n;

  if(n <= 2) {
    cout << "NOT FOUND";
  }

  for(int i = 2; i < n; i++) {
    int count = 0;

    for(int j = 2; j < i; j++) {
      if((i % j) == 0) {
        count++;
        break;
      }        
    }

    if (count == 0) {
      cout << i << ' ';
    } 

  }
  return 0;
}