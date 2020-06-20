#include <iostream>
using namespace std;
class Car {

  public:
  char name[20]="def";
  int price;
  int wheels;

  void print(){
  cout<<name<<endl;
  cout<<price<<endl;
  cout<<wheels<<endl;

  }
};


int main()
{
    Car c;
    ///c.name="ABC";
    c.name[0]='a';
    c.name[1]='b';
    c.name[2]='c';
    c.price=25;
    c.wheels=4;
    cout<<sizeof(c)<<endl;
    cout<<sizeof(Car)<<endl;

   c.print();

    return 0;
}
