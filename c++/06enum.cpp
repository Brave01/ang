#include <iostream>
using namespace std;

int main(void)
{
   enum Color{RED,YELLOW,BULE};
   cout << RED << ',' << YELLOW << ',' << BULE << endl; //0 1 2
   /*enum*/ Color c;
   //c = 2;// C:ok C++:error
   c = BULE;
   cout << c << endl;
  
   return 0;
}
