#include<iostream>
using namespace std;

// This program prints product of prime factors interspersed with *
int main() {
  
    int n;
    cin >> n;

    for(int i = 2; i <= n; i++) {
      while(n % i == 0) {
        cout << i;
        n /= i;

        if(n >= i) {
          cout << '*';
        }
      }
    }

    return 0;
}