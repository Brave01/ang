#include <stdio.h>

int foo()
{
  int res = 0;
  res = 2 + 3;
  return res;
}

int main()
{
    printf("%d\n",foo()*2);
  
   return 0;
}
