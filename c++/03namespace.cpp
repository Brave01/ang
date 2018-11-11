#include <iostream>

using namespace std; //以后使用标准名字空间可以省略std:: 
namespace ns1{
   void func(void)
   {
      cout << "ns1::func" << endl;
   }
   int num = 100;
}
namespace ns2{
    void func(void)
    {
       cout << "ns2::func" << endl;
    }
    int num = 200;
}
int num = 300;  // 放到无名名字空间里面 ::num
int main(void)
{
/*
   using ns1::func; // 名字空间声明 --- 用的也比较少 --- 声明局部当前优先高
   func();
   using namespace ns2; // 全局声明 优先级低
   func();
   //using ns2::func;
   //func();  // 歧义错误
   ns2::func();
*/
   cout << num << endl;
   cout << ns1::num << endl;
   //using ns2::num;
   cout << ns2::num << endl;
   cout << ::num << endl;
   

   return 0;
}
