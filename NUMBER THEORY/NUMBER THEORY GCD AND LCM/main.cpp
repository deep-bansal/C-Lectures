#include <iostream>

using namespace std;
int gcd(int a,int b)
{
    return b==0? a : gcd(b,a%b);
}
int main()
{
    int a,b;
    cin>>a>>b;
    int result=gcd(a,b);
    cout<<result<<endl;
    int lcm;
    lcm=(a*b)/result;
    cout<<lcm<<endl;

    return 0;
}
