#include <iostream>
#include <stdbool.h>
#include <iomanip>
using namespace std;
// This program finds average of prime numbers in an array

// Check if a number is prime
bool isPrime(int n) {
  if(n < 2) {
    return false;     // Number is not a prime
  }
  for(int i = 2; i < n; i++) {
    if((n % i) == 0) {
      return false;  // Number is not a prime
    }
  }
  return true;       // Number is a prime
}

// Find average of primes in an array
int main() {
  
  int N;
  cin >> N;

  int *array = new int[N];
  // Input the array
  for(int i = 0; i < N; i++) {
    cin >> array[i];
  }
  
  // Find primes
  int sum = 0;
  int count = 0;
  for(int i = 0; i < N; i++) {
    if(isPrime(array[i])) {
      sum += array[i];
      count++;
    }
  }

  // There is no prime
  if(count == 0) {
    cout << "NOT FOUND\n";
    return 0;
  }
  // Calculate and print the average
  float average = (float)sum / (float)count;
  cout << fixed << setprecision(2) << average;

  return 0;

}