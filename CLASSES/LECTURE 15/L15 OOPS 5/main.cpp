#include <bits/stdc++.h>
using namespace std;
class Car{
	int price = 100;
public:
	char* name;
	int fuleTank;
	int wheels;
	//constructor
	Car(): wheels(4){
		cout<<"inside my constructor"<<endl;
		name = new char[10];
			}
	Car(int w, int p, char* n, int f){
		cout<<"inside my initialization list constructor"<<endl;
		wheels = w;
		setPrice(p);
		fuleTank=f;
		name = new char[strlen(n)];
		strcpy(name, n);
	}
	//setter
	void setPrice(int p){
		if(p>=100){
			price = p;
		}
		else{
			cout<<"price is too low"<<endl;
		}
	}
	//getter
	int getPrice(){
		return price;
	}
	void operator = (Car &X){
		cout<<"my = operator"<<endl;
		wheels = X.wheels;
     	setPrice(X.price);
		fuleTank = X.fuleTank;
		strcpy(name, X.name);
	}
	void print(){
		cout<<name<<endl;
		cout<<price<<endl;
		cout<<wheels<<endl;
		cout<<fuleTank<<endl;
		cout<<"----------------------"<<endl;
	}
};
 ostream& operator <<(ostream& o,Car &X){
	o<<X.name<<endl;
	o<<X.getPrice()<<endl;
	o<<X.wheels<<endl;
	o<<X.fuleTank<<endl;
	o<<"----------------------";
	return o;
}

istream& operator >>(istream& o,Car &X){
	int n;
	o>>n;
	X.fuleTank = n;
	return o;
}

int main(int argc, char const *argv[])
{
	char arr[10] = "abc";
	Car E(4, 1000,arr , 30);/// inside parameterised not constant
	///E.wheels(7); bcoz constant
	//E.print();
	Car F(E);
	E.fuleTank = 100;
	E.name[0] = 'J';
	F.name[1] = 'Z';
	cout<<E<<F;


	return 0;

}

