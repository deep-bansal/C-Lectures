#include <iostream>

using namespace std;
int binarysearch(int* arr,int key,int start,int end)
{
    while(start<=end)
    {
        ///int mid = (start+end)/2 don't use this
		///int mid = start+ ((end - start+1)/2);// considering upper mid as mid

		int mid = start+ ((end - start)/2);/// considering lower mid as mid
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(key>arr[mid])///right half
        {
            start=mid+1;
        }
        else
        {///left half
            end=mid-1;
        }
    }
    return -1;
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int key;
    cin>>key;
    cout<<binarysearch(arr,key,0,9)<<endl;
    return 0;
}
