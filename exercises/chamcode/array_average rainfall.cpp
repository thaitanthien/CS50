#include <iostream>
#include <iomanip>
using namespace std;

// This program calculates average of rainfall in a month
int main() {

  // input so thang
  int n;
  cin >> n;

  int sum = 0;
  int * array = new int[n];
  for (int i = 0; i < n; i++) {
    // Input rainfall each month
    cin >> array[i];
    sum += array[i];
  }
  // Calculate average
  float average = (float) sum / (float) n;

  int count = 0;
  for(int i = 0; i < n; i++) {
    if(array[i] > average) {
      // Print months have rainfall more than average
      cout << i + 1 << ' ';
      count++;
    }
  }
   if (count == 0) {
     // Print months have rainfall less than average
    cout << "NOT FOUND";
  }
  return 0;  
}