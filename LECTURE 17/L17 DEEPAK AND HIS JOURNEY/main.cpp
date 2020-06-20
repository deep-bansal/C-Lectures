#include <iostream>
#define ll long long
using namespace std;

ll int minCost(ll int n,ll int* c,ll int* l)
{
   ll int minprice=c[0];
   ll int totalprice=minprice*l[0];
    for(int i=1;i<n;i++)
    {
        if(c[i]<minprice)
        {
            minprice=c[i];
        }
         totalprice+=minprice*l[i];
    }
    return totalprice;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
     ll int n;
     cin>>n;
     ll int c[10000],l[10000];
     for(ll int i=0;i<n;i++)
     {
         cin>>c[i];
     }
     for(ll int i=0;i<n;i++)
     {
         cin>>l[i];
     }
    cout<<minCost(n,c,l)<<endl;
    }
    return 0;
}
