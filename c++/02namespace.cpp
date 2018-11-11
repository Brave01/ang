#include <iostream>

using namespace std; 
namespace ns1{
   void func(void)
   {
      cout << "ns1::func" << endl;
   }
}
namespace ns2{
    void func(void)
    {
       cout << "ns2::func" << endl;
    }
}
int main(void)
{
   ns1::func(); // 自定义的名字空间用这种方法安全
   ns2::func();
   using namespace ns1;  // 用不好会报歧义错误
   /*ns1::*/func();
   return 0;
}
