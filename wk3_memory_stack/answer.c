#include <stdio.h>

int bar (int a){
  return a*a;

}
int foo (int a, int b, int c,int d){
  return  a * bar(d) + b * d + c;
}

int main ( void ) {
  int a = foo(1,2,3,4);
  printf("result : %d\n", a);
  return 0;
}
