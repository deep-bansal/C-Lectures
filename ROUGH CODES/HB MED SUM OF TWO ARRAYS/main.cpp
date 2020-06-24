#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr1[1000];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    int m;
    cin>>m;
    int arr2[1000];
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
    int arr3[10000]={0};
    int maxim=max(n,m);

    int i=n-1,j=m-1,k=maxim-1;
    int sum=0,carry=0;
    while(i>=0 && j>=0 && k>=0)
    {
         sum=arr1[i]+arr2[j]+carry;
        if(sum>=10)
        {
            arr3[k]=sum%10;
            carry=sum/10;
        }
        else
        {
            arr3[k]=sum;
            carry=0;
        }
        i--;
        j--;
        k--;
    }
     while(k>=0 && j >=0 && k==j){
        arr3[k] = arr2[j] ;
        k--;
        j-- ;
    }
    while(k>=0 && i >=0 && k==i){
        arr3[k] = arr1[i] ;
        k--;
        i-- ;
    }
    if(carry!=0)
    {
        cout<<carry<<", ";
    }

    for(int i=0;i<=maxim-1;i++)
    {
        cout<<arr3[i]<<", ";
    }
    cout<<"END";

   /** int sum1=0;
    for(int i=0;i<=n-1;i++)
    {
        sum1+=arr1[i]*pow(10,n-1-i);
    }

    int sum2=0;
    for(int j=0;j<=m-1;j++)
    {
        sum2+=arr2[j]*pow(10,m-1-j);
    }

    int result=sum1+sum2;

*/








    return 0;
}
