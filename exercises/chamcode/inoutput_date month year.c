#include <stdio.h>

// This program prints date month year
int main() {
  
  int d,m,y;
  scanf("%d%d%d", &d, &m, &y);
  printf("%02d/%02d/%04d\n", d, m, y);
  
  return 0;
}