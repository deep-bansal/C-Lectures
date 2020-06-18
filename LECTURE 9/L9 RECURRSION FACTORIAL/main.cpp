#include <iostream>

using namespace std;
int factorial(int n)
{
    if(n==0)
    {
        return 1;
    }
    int factn=n*factorial(n-1);
    return factn;
}

int main()
{
    int n;
    cin>>n;
    int result= factorial(n);
    cout<<result;
    return 0;
}
