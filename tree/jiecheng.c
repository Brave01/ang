#include <stdio.h>

int factorial(int val)
{
   int c;
   if(val>=1)
   {
     c = val * factorial(val-1);
   }
   else
   {
     c = 1;
   }
   
   return c;
}

int main()
{
   printf("%d\n",factorial(5));

   return 0;
}
