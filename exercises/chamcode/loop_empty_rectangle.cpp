#include <iostream>
using namespace std;

/* This program prints a empty rectangle(n,m) (ex. n = 3, m = 3)
***
* *
***
*/
int main() {

  // input the height n, the width m of the rectangle (n, m > 2)
  int n, m;
  do {
    cin >> n >> m;
  }
  while (n <= 2 || m <= 2);

  // print the first line of *
  for(int i = 1; i <= m; i++) {
    cout << "*";
  }
  cout << '\n';

  // print the body of the rectangle
  for(int i = 0; i < n - 2; i++) {
    cout << "*";
    for(int j = 0; j < m - 2; j++) {
      cout << ' ';  
      }
    cout << "*\n";
  }
  // print the last line of *
  for(int i = 1; i <= m; i++) {
    cout << "*";
  }
  cout << '\n';

  return 0;
}