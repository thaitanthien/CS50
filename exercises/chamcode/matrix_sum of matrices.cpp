#include <iostream>
using namespace std;

// This program adds 2 matrices together
int main() {
  
  int N, M;
  cin >> N;
  cin >> M;

  int arrayA[N][M];
  int arrayB[N][M];
  int arraySum[N][M];
  // Enter matrix A
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> arrayA[i][j];
    }
  }
  // Enter matrix B
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> arrayB[i][j];
    }
  }
  // Add 2 matrices together
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      arraySum[i][j] = arrayA[i][j] + arrayB[i][j];
    }
  }
  // Print the sum matrix
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cout << arraySum[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}