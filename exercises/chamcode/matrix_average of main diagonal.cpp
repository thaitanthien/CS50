#include <iostream>
#include <iomanip>
using namespace std;

// This program calculates average of matrix's main diagonal
int main() {
  
  int N;
  cin >> N;
  int array[N][N];
  // Enter the matrix
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> array[i][j];
    }
  }

  // Calculate the average
  int sum = 0;
  int count = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(i == j) {
        sum += array[i][j];
        count++;
      }
    }
  }
  float average = (float) sum / (float) count;
  cout << fixed << setprecision(2) << average;

  return 0;
}