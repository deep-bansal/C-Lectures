#include <iostream>

using namespace std;

int main()
{
    int a=10;
    cout<<"address of a-->"<<&a<<endl;
    int* ptrA=&a;
    cout<<"ptrA-->"<<ptrA<<endl;
    cout<<"val at ptrA-->"<<*ptrA<<endl;
    cout<<"address of ptrA-->"<<&ptrA<<endl;
    cout<<"value at address of ptrA-->"<<*(&ptrA)<<endl;
    cout<<endl<<endl;

    char ch = 'X';
	char* ptrCh = &ch;
	cout<< "address of ch -> "<< &ch <<endl;
	cout<<"ptrCh -> "<<(void*)ptrCh<<endl;   //Explicit typecasting
	cout<< "address of ptrCh -> "<< &ptrCh <<endl;
	cout<<endl<<endl;

	bool b = true;
	bool* ptrB = &b;
	cout<<"b-->"<<b<<endl;
	cout<< "address of b -> "<< &b <<endl;
	cout<<"ptrB -> "<<ptrB<<endl;
	cout<< "address of ptrB -> "<< &ptrB <<endl;
	cout<<endl<<endl;

	double f =787983704.92483;
	double* ptrD = &f;
	cout<<"double -> "<< f<<endl;
	cout<<"int ->"<<(int)f<<endl;
	cout<< "address of f -> "<< &f <<endl;
	cout<<"ptrD -> "<<ptrD<<endl;
	cout<< "address of ptrD -> "<< &ptrD <<endl;
	cout<<endl<<endl;

	cout<<"size of a "<<sizeof(a)<<endl;
	cout<<"size of ptrA "<<sizeof(ptrA)<<endl;
	cout<<"size of ch "<<sizeof(ch)<<endl;
	cout<<"size of ptrCh "<<sizeof(ptrCh)<<endl;
	cout<<"size of f "<<sizeof(f)<<endl;
	cout<<"size of ptrD "<<sizeof(ptrD)<<endl;
	cout<<endl<<endl;

	cout<<*(ptrD)<<endl;
	cout<<*((int*)ptrD)<<endl;
	cout<<endl<<endl;

	int i = 55;
	int p = 90;
	int* ptr1 = &p;
	int* ptr2 = &i;
	cout<<ptr1<<endl; //1 address of ptr1
	cout<<ptr2<<endl;//2  address of ptr2
	ptr1 = ptr2;
	cout<<* ptr1<<endl;//3 55
	cout<<* ptr2<<endl;//4 55
    return 0;
}
