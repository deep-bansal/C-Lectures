#include <iostream>
using namespace std;
///veryimp it works on indexes
void ssort(int arr[10],int n)
{

    for(int i=0;i<n;i++)
    {
        int minidx=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minidx])
            {
                minidx=j;
            }
        }
        ///swap(arr[i],arr[minidx])
        int key=arr[minidx];
        for(int l=(minidx-1);l>=i;l--)
        {
            arr[l+1]=arr[l];
        }
        arr[i]=key;
    }
}

int main()
{
    int arr[10] = {5,9,1,3,2,6};
	ssort(arr,6);
	for (int i = 0; i < 6; ++i)
	{
		cout<<arr[i]<<", ";
	}
	cout<<endl;
    return 0;
}
