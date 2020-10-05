#include <iostream>
using namespace std;

// This program finds sum of columns, sum of rows of a matrix
int main() {
  
  // Matrix size N * M
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

  // Find sum of rows
  for(int i = 0; i < N; i++) {    
    int sum_row = 0;
    for(int j = 0; j < M; j++) {
      sum_row += array[i][j];
    }
    cout << sum_row << ' ';
  }
  cout << '\n';

  // Find sum of columns
  for(int j = 0; j < M; j++) {
    int sum_column = 0;
    for(int i = 0; i < N; i++) {
      sum_column += array[i][j];
    }
    cout << sum_column << ' ';
  }
  cout << '\n';

  return 0;

}