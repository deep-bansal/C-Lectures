#include <bits/stdc++.h>
using namespace std;
class Car {
  private:
  int price;

  public:
  char* name;
  int wheels;


  Car(){
      name=NULL;
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
      int l=strlen(ne);
      name=new char[l+1];
      strcpy(name,ne);

  }
  ///copy constructor
	///shallow copy
	/// Car(Car &X){
	/// 	cout<<"my copy constructor"<<endl;
	/// 	wheels = X.wheels;
	///	price = X.price;
	/// 	fuleTank = X.fuleTank;
	/// 	name = X.name;
	/// }

  ///DEEP COPY CONSTRUCTOR
  Car(Car &X):wheels(X.wheels)
  {
      price=X.price;
      wheels=X.wheels;
      int l=strlen(X.name);
      name=new char[l+1];
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
  void setname(char* n){
  if(name==NULL)
  {
      name=new char[strlen(n)+1];
      strcpy(name,n);
  }
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
    c.setname("BMW");
    c.setprice(500);
    c.wheels=4;
    cout<<"this is c"<<endl;
    c.print();
    ///cout<<c.getprice()<<endl;

    Car G(200,"DHI",3);
    G.print();

    Car F(c);
    F.name[0]='G'; /// shallow copy took place using default copy constructor
    c.print();
    F.print();






    return 0;
}
