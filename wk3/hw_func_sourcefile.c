#include <stdio.h>

int bar(int a){

  return (a * a);

}

int foo(int a, int b, int c, int d){
  
  return ( d * b ) + ( a * bar(d) ) + c ;

}

int main() {

  int x = foo(1,2,3,4);
  printf("result : %d\n", x);
  return 0;
}

