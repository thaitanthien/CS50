#include <iostream>
#include <string>
using namespace std;

// This program prints an incantation n times
int main() {
    
  int n;
  cin >> n;
  string than_chu;
  cin.ignore();
  getline (cin, than_chu);
  
  for(int i = 0; i < n ; i++) {
  	cout << than_chu  << '\n';
  }
  
  return 0;
}