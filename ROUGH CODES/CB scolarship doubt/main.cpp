#include <bits/stdc++.h>

using namespace std;
bool isPossible(int x,int m,int n,int mid,int y)
{
    if((mid*x)<= (m+((n-mid)*y)))
    {
        return true;
    }
    return false;
}
int scolarstudents(int n,int start,int end,int x,int y,int m)
{

    int ans=0;
    while(start<=end)
    {
        int mid =start+((end-start)/2);
        if(isPossible(x,m,n,mid,y))
        {
            ans=mid;
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return ans;
}

int main()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    cout<<scolarstudents(n,0,n,x,y,m);

}

