#include <iostream>
#include <iomanip>
using namespace std;

// This program convert time in second to hh:mm:ss
int main() {

  long n;
  cin >> n;

  int h = n / 3600;
  int m = (n % 3600) / 60;
  int s = (n % 3600) % 60;

  cout << setw(2) << setfill('0') << h << ":"
       << setw(2) << setfill('0') << m << ":"
       << setw(2) << setfill('0') << s;

  return 0;

}