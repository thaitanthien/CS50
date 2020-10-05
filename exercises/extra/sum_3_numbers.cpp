#include <iostream>
using namespace std;

// This program finds sum of 3 integer numbers
int main() {

    int sum = 0;

    int array[3];

    for (int i = 0; i < 3; i++) {
    cout << "Nhap so thu " << i + 1 << ": ";
    cin >> array[i];

    sum += array[i];
    }

    cout << "Tong ba so la: " << sum << "\n";

    return 0;
}