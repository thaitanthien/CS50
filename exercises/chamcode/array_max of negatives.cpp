#include <iostream>
using namespace std;

// This program finds the maximum of n negative numbers
int main() {

  int n;
  cin >> n;

  int * array = new int[n];
  for (int i = 0; i < n; i++) { // Input n numbers
    cin >> array[i];
  }

  int max = 0;
  for (int i = 0; i < n; i++) {
    if (max == 0 && array[i] < 0) {
     max = array[i];
    }
    else if (array[i] < 0 && max < array[i]) {
      max = array[i];
    }
  }

  if (max == 0) {
    cout << "NOT FOUND"; // There is no negative
  }
  else {
    cout << max;
  }

  return 0;  
}