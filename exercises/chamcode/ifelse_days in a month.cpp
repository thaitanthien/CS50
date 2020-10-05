#include <iostream>

using namespace std;
// This program prints number of days in a month
int main() {

  int thang;
  cin >> thang;

  switch(thang) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    cout << "31";
    break;

    case 4: case 6: case 9: case 11:
    cout << "30";
    break;

    case 2:
    cout << "28";
    break;

    default:
    cout << "NOT FOUND";
  }
  
  return 0;
}