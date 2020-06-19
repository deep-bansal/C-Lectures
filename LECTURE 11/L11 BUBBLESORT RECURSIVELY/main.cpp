#include <iostream>

using namespace std;
void bubblesort(int* a,int n)
{
    if(n==1)
    {
        return;
    }
    for(int i=0;i<=n-2;i++)
    {
        if(a[i]>a[i+1])
        {
            swap(a[i],a[i+1]);
        }
    }
    bubblesort(a,n-1);
}
void bubblesort2 (int* a,int j,int n)
{
    if(n==1)
    {
        return;
    }
    if(j==n-1)
    {
        bubblesort2(a,0,n-1);
        return; ///always return on base case
    }
    if(a[j]>a[j+1])
    {
        swap(a[j],a[j+1]);
    }
    bubblesort2(a,j+1,n);

}

int main()
{
    int a[5]={5,4,2,1,0};
    int n=5;
    int j=0;
    ///bubblesort(a,n);
    bubblesort2(a,j,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
