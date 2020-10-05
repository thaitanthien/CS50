#include <iostream>
#include <stdbool.h>
#include <math.h>
using namespace std;
// This program finds square numbers in an array

// Check if a number is square number
bool isSquare(int n) {
  if(n < 1) {
    return false;
  }
  int sqr = sqrt(n);
  if(sqr*sqr == n) {
    return true;
  }  
  return false;
}

// Find square numbers in the array
int main() {
  
  int N;
  cin >> N;

  int count = 0;
  int *array = new int[N];
  for(int i = 0; i < N; i++) {    
    // Input each element of the array
    cin >> array[i];
  }
  
  // Print the square number
  for(int i = 0; i < N; i++) {
    if(isSquare(array[i])) {
      cout << array[i] << ' ';
      count++;
    }
  }
  
  // There is no square number in the array
  if(count == 0) {
    cout << "NOT FOUND\n";
  }

  return 0;  
}