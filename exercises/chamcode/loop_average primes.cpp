#include <iostream>
#include <iomanip>

using namespace std;
// This program calculates average of prime numbers less or equal than a number

// Check if n is a prime
bool isPrimer(int n) {
  if(n < 2) {
    return false;    // n is not a prime
  }

  for(int i = 2; i < n; i++) {
    if((n % i) == 0) {
      return false; // n is not a prime
    }
  }
  return true;     // n is a prime
}

int main() {
  
  int k;
  cin >> k;
  
  int sum = 0;
  int count = 0;
  // Find prime numbers less or equal than k
  for(int i = 2; i <= k; i++) {
    if(isPrimer(i)) {
      count++;
      sum += i;
    }
  }
  
  // Calculate the average
  float average = (float) sum / (float) count;
  cout << fixed << setprecision(3) << average;
  
  return 0;
}