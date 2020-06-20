#include <bits/stdc++.h>
using namespace std;
class Car {
  private:
  int price;

  public:
  char name[20]="def";
  int wheels;

  Car(){
   cout<<"This is my constructor"<<endl;
  }
  void setprice(int p)
  {
      if(p>1000)
      {
          price=p;
      }
      else
      {
         price=1000;
      }
  }
   ///PARAMETERISED CONSTRUCTOR
  Car(int p,char* ne,int w):wheels(4)
  {
      price=p;
      ///wheels=w; ///assignment of constant value is not possible
      strcpy(name,ne);
  }

  ///COPY CONSTRUCTOR
  Car(Car &X):wheels(X.wheels)
  {
      price=X.price;
      wheels=X.wheels;
      strcpy(name,X.name);
  }
  int getprice(){
     return price;
  }
  void operator = (Car &X)
  {
      cout<<"my assignment operator"<<endl;
       price=X.price;
      wheels=X.wheels;
      strcpy(name,X.name);
  }
   void print() const{ ///this function is now constant
  cout<<name<<endl;
  cout<<price<<endl;
  cout<<wheels<<endl;
  cout<<"--------------------"<<endl;

  }
};


int main()
{
    Car c;
    ///c.name="ABC"; assignment not possible
    c.name[0]='a';
    c.name[1]='b';
    c.name[2]='c';
    c.setprice(500);
    c.wheels=4;
    cout<<"this is c"<<endl;
    c.print();
    cout<<c.getprice()<<endl;

    Car F(c);
    cout<<"this is f"<<endl;
    ///F.wheels(5); not accepting this
    F.print();

    Car G(200,"DHI",3);
    G.setprice(2000);
    cout<<"this is g"<<endl;
    G.print();
    cout<<G.getprice()<<endl;

    Car H;
    H=G; ///all things are copied from starting
    cout<<"this is H"<<endl;
    H.print();

    H.name[0]='Z';

    G.print();
    H.print();



    return 0;
}
