#include <iostream>
using namespace std;

struct Teacher{
   char name[128];
   int age;
   double salary;
   // 成员函数
   void who(void)
   {
     cout << "我叫" << name << ",今年" << age << "岁，工资是" << salary << endl;
   }
};

int main(void)
{
   /*struct*/Teacher t = {"杨健",45,1200};
   // 访问成员函数的方法和成员变量一致
   t.who();

   return 0;
}
