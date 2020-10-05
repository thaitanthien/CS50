#include <iostream>
using namespace std;
// This program seperates positive and negative numbers
int main() {

  int n;
  cin >> n;

  int * array = new int[n];
  for (int i = 0; i < n; i++) { // Input n numbers
    cin >> array[i];
  }

  int count_positive = 0;
  for(int i = 0; i < n; i++) {
    if(array[i] > 0) {
      cout << array[i] << ' ';  // Print positive numbers
      count_positive++;
    }
  }
  if(count_positive == 0) {
    cout << "NOT FOUND"; 
  }
  
  cout << "\n";

  int count_negative = 0;   
  for(int i = 0; i < n; i ++) {
    if(array[i] < 0) {
      cout << array[i] << ' ';   // Print negative numbers
      count_negative++;
    }
  }
  if(count_negative == 0) {
    cout << "NOT FOUND";
  }   
  
  return 0;  
}