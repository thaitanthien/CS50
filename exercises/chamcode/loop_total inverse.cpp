#include <iostream>
#include <iomanip>
using namespace std;
// This program calculates total of inverse numbers:
// S = 1 + 1/2 + 1/3 + … + 1/N
int main() {
  int N;
  do {
    cin >> N;
  }
  while (N <= 0);


  float S = 0;
  for (int i = 1; i <= N; i++) {
    S += 1 / (float) i;
  }

  cout << fixed << setprecision(6) << S;
  return 0;
}