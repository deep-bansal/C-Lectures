#include <iostream>
using namespace std;
void subarrays(int arr[10], int n)
{
    int maxsum=0;
    int currentsum=0;
    int left,right;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            currentsum=0;
            for(int k=i; k<=j;k++)
            {
                currentsum= currentsum+ arr[k];

            }
             if(currentsum>maxsum)
             {
                 maxsum=currentsum;
                 left=i;
                 right=j;
             }

        }
    }
     cout<<maxsum<<endl;
     for(int i=left; i<=right; i++) ///to print the subarray
     {
         cout<<arr[i]<<" ,";
     }
}
int main()
{
    int arr[9]={-4,1,3,-2,6,2,-8,-9,4};
    subarrays(arr,9);
    return 0;
}
