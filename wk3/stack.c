#include <stdio.h>

int sum (int a,  int b) {
  int c = a + b;
  return c;
}

int main( void ){
  int n1 = 1;
  int n2 = 2;

  printf("sum = %d\n", sum(n1, n2));

  return 0;
}
