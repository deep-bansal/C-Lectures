#include <iostream>
using namespace std;
void subarrays(int arr[10], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            for(int k=i; k<=j;k++)
            {
                cout<<arr[k]<<", ";
            }
            cout<<endl;
        }
    }
}
int main()
{
    int arr[4]={1,2,3,4};
    subarrays(arr,4);
    return 0;
}
