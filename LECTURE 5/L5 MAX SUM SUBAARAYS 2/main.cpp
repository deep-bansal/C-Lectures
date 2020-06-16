#include <iostream>
using namespace std;
void subarrays(int arr[10], int n)
{
    int cumsum[10]={0};
    int maxsum=0;
    int currentsum=0;
    int left,right;
    cumsum[0]=arr[0];
    for(int i=1;i<10;i++)
    {
        cumsum[i]=cumsum[i-1]+arr[i];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            currentsum=0;
            currentsum=cumsum[j]-cumsum[i-1];
            if(currentsum>maxsum)
        {
            maxsum=currentsum;
            left=i;
            right=j;
        }
        }

    }
     cout<<maxsum<<endl;
     for(int i=left; i<=right; i++) //to print the subarray
     {
         cout<<arr[i]<<" ,";
     }
}
int main()
{
    int arr[9]={-4,1,3,-2,6,2,-1,-4,-7};
    subarrays(arr,9);
    return 0;
}
