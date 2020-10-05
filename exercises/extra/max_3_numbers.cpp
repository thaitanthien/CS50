#include <iostream>
using namespace std;

// This program finds maximum value from 3 numbers of integer
int main() {
  
  int max = 0;
  int N = 3;
  int array[N];

  for (int i = 0; i < N; i++) {
    cout << "Nhap so thu " << i + 1 << ": ";
    cin >> array[i];

    if (max < array[i]) {
       max = array[i];   
    }
   
   }
  cout << "So lon nhat trong ba so la: " << max << "\n";

  return 0;
}