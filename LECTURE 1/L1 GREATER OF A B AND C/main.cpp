#include <iostream>

using namespace std;

int main()
{
    // can also be written as int a,b,c;
int a;
int b;
int c;
cin>>a>>b>>c;
//&& this denotes and
// use of () for if
if ((a>b)&& (a>c)){
    cout<<a;
}
else if ((b>a) && (b>c)) {
    cout<<b;
}
else cout<<c;
}
