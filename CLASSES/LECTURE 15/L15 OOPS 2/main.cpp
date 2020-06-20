#include <bits/stdc++.h>
using namespace std;
class Car {

  public:
  char name[20]="def";
  int price;
  int wheels;

  Car(){
   cout<<"This is my constructor"<<endl;
  }
  ///PARAMETERISED CONSTRUCTOR
  Car(int p,char* ne,int w)
  {
      price=p;
      wheels=w;
      strcpy(name,ne);
  }

  ///COPY CONSTRUCTOR
  Car(Car &X)
  {
      price=X.price;
      wheels=X.wheels;
      strcpy(name,X.name);
  }

  void print(){
  cout<<name<<endl;
  cout<<price<<endl;
  cout<<wheels<<endl;
  cout<<"--------------------"<<endl;

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
    cout<<"size taken by object "<<sizeof(c)<<endl;
    cout<<"size taken "<<sizeof(Car)<<endl; ///this is the size that object will take if this class is used

   c.print();
   Car f(26,"GHI",4);
   f.print();

   Car G(f);
   G.print();

    return 0;
}
