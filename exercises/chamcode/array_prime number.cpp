#include <iostream>
#include <stdbool.h>
using namespace std;
// This program finds prime numbers in an array

// Check if a number is a prime
bool isPrime(int n) {
  if(n < 2) {
    return false;   // Is not a prime
  }
  for(int i = 2; i < n; i++) {
    if((n % i) == 0) {
      return false; // Is not a prime
      break;
    }
  }
  return true;      // Is a prime
}

// Find primes in an array
int main() {

  int N;
  cin >> N; // Input N

  int *array = new int[N];
  // Input the array
  for(int i = 0; i < N; i++) {
    cin >> array[i];
  }

  // Check if number in array is prime
  int count = 0;
  for(int i = 0; i < N; i++) {
    if(isPrime(array[i])) {
      cout << array[i] << ' ';
      count++;
    }
  }

  // There is no prime in the array
  if(count == 0) {
    cout << "NOT FOUND";
  }
  
  return 0;
}