#include <iostream>

using namespace std;
int fibo(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    int result=fibo(n-1)+fibo(n-2);
    return result;
}

int main()
{
    int n;
    cin>>n;
    cout<<fibo(n)<<endl;

    return 0;
}
