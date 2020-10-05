#include <iostream>
using namespace std;

// This program checks if a matrix is a symmetric matrix
int main() {
  
  // Square matrix of N
  int N;
  cin >> N;
  int array[N][N];
  // Enter the matrix
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> array[i][j];
    }
  }

  // Check if matrix is a symmetric matrix
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(array[i][j] != array[j][i]) {
        cout << "FALSE";
        return 0;
      }
    }
  }

  cout << "TRUE";
  return 0;
}