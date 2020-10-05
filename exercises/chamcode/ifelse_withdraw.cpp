#include <iostream>
using namespace std;

int main() {
  int sotien;
  cin >> sotien;

  if (sotien <= 200 * 1e6 && sotien % 50000 == 0) {
    // tinh so to tien o moi menh gia
    int soto500 = sotien / 500000;
    int soto200 = (sotien - soto500 * 500000) / 200000; 
    int soto100 = (sotien - soto500 * 500000 - soto200 * 200000) / 100000;
    int soto50 = (sotien - soto500 * 500000 - soto200 * 200000 - soto100 * 100000) / 50000;

    if (soto500 > 0) {
      cout << "500K " << soto500 << '\n';
    }
    if (soto200 > 0) {
      cout << "200K " << soto200 << '\n';
    }
    if (soto100 > 0) {
      cout << "100K " << soto100 << '\n';
    }
    if (soto50 > 0) {
      cout << "50K " << soto50 << '\n';
    }
  }
  else {
    cout << "INVALID";
  }
  
  return 0;  
}