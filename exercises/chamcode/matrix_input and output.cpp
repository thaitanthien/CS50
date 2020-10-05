#include <iostream>
using namespace std;

// This program enters and prints a matrix
int main() {
  
  // Matrix of size N * M
  int N, M;
  cin >> N;
  cin >> M;

  int array[N][M];
  // Enter the matrix
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> array[i][j];
    }
  }

  // Print the matrix
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cout << array[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}