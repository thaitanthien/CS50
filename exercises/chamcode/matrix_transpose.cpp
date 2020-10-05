#include <iostream>
using namespace std;

// This program transposes a matrix
int main() {

    // Matrix of size N*M  
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

    // Transopition matrix
    int new_array[M][N];
    // Transpose the matrix
    for(int i = 0; i < M; i++) {
      for(int j = 0; j < N; j++) {
        new_array[i][j] = array[j][i];
      }
    }

    // Print the transposition matrix
    for(int i = 0; i < M; i++) {
      for(int j = 0; j < N; j++) {
        cout << new_array[i][j] << ' ';
      }
      cout << '\n';
    }

    return 0;
}