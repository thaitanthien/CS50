#include <iostream>
using namespace std;


// This program calculates phone cost
int main() {

  int n;
  cin >> n;

   // cost for the first 50 minutes
  if (n < 50) {
    cout << "So tien = " << 25000 + 600 * n;
  }
  // cost for the first 50 minutes and 150 minutes next
  else if (n >= 50 && n < 150) {
    cout << "So tien = " << 25000 + 600 * 50 + 400 * (n - 50);
  }
  // cost for the first 50 minutes and 150 minutes next and any minutes after that
  else {
    cout << "So tien = " << 25000 + 600 * 50 + 400 * 150 + 200 * (n - 150);
  }

  return 0;
}