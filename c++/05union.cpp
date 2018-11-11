#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
   union{//匿名联合 一共占4个字节
     unsigned int ui; //4     
     unsigned char uc[4]; //4
   }; 
   ui = 0x12345678;
   for(int i=0;i<4;i++)
   {
     printf("%#x ",uc[i]);  //显示禁止标示 
     printf("%p ",&uc[i]);
   }
   printf("\n");
   return 0;
}
