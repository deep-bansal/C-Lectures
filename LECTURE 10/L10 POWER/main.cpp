#include <iostream>

using namespace std;
int power (int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    int result=a*power(a,b-1);
    return result;
}
int powerbetter(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    int small =powerbetter(a,b/2);
    int result=small*small;
    if(b&1)
    {
        result=a*result;
    }
}

int main()
{
    int a,b;
    cin>>a>>b;
   // cout<<power(a,b)<<endl;
    cout<<powerbetter(a,b)<<endl;

    return 0;
}
