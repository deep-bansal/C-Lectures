#include <iostream>
using namespace std;
void dnfAlgo(int* arr,int n)
{
    int left=0,mid=0,right=n-1;
    while(mid<=right)
    {
        if(arr[mid]==0)
        {
            swap(arr[mid],arr[left]);
            mid++;
            left++;
        }
        else if(arr[mid]==2)
        {
            swap(arr[mid],arr[right]);
            right--;
        }
        else{
                mid++;}
    }
}

int main()
{
    int n = 11;
	int arr[11] = {1,2,0,1,1,0,2,0,1,2,1};
	dnfAlgo(arr,n);
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<", ";
	}
	cout<<endl;
    return 0;
}
