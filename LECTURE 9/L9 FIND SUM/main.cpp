#include <iostream>

using namespace std;
int sum(int n)
{
    if(n==1)
    {
        return 1;
    }
    int sums=n+sum(n-1);
    return sums;
}

int main()
{
   int n;
   cin>>n;
   int result=sum(n);
   cout<<result;
    return 0;
}
