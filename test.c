#include <stdio.h>

int main()
{
  char * str1[] = "hello world";

  printf("%s\n", str1);
  
  int a = 5;
  int * ptr = &a;

  printf("%d\n", ptr);
  
}
