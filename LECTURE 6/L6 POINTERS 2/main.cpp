#include <iostream>

using namespace std;
//int sum(int a, int b)
int sum(int&a, int b)
{
    a=a+b;
    cout<<"result inside sum function ";
    cout<<a<<endl;
    return a;
}

int main()
{
    int a=2;
    int b=3;
    int result=sum(a,b);
    cout<<"result under main function ";
    cout<<result<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
   // important
    int* aptr = &a;
	int** aaptr = &aptr;
	cout<<aptr<<endl;
	cout<<aaptr<<endl;
	cout<<*aptr<<endl;
	cout<<**aaptr<<endl;
    return 0;
}
