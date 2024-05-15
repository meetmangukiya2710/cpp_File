
#include <iostream>
using namespace std;
class Math
{
public:
   int a, b;


   void setData()
   {
       cout << "Enter The Value Of A :-";
       cin >> a;


       cout << "Enter The Value Of B :-";
       cin >> b;


       cout << endl;
   }
   void Addition()
   {
       cout << "First Value Addition Is = " << a + b << endl;
       cout << endl;
   }
   void Addition(int a,int b)
   {
       cout << "Second Value Addition Is = " << a + b << endl;
       cout << endl;
   }
   void Addition(double a,double b)
   {
       cout << "Third Value Addition Is = " << a + b << endl;
   }
   void Addition(char a)
   {
       cout << "Fourth Value Charecter Is = " << a;
   }
};


int main()
{
   Math m1;
   m1.setData();
   m1.Addition();
   m1.Addition(50,50);
   m1.Addition(10.20,20.30);
   m1.Addition('A');
}
