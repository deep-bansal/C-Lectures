#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[10];
    int currentsum=0;
    int maxsum=0;
    for(int i=00; i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        currentsum=currentsum+arr[i];
        if(currentsum<0)
        {
            currentsum=0;
        }

            maxsum=max(maxsum,currentsum);
    }
        cout<<maxsum<<endl;
    }


