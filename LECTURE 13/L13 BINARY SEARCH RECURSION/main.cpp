#include <iostream>

using namespace std;
int binarysearch(int*arr,int key,int start,int end)
{
    if(start>end)
    {
        return -1;
    }
    int mid=start+((end-start)/2);
    if(arr[mid]==key)
    {
        return mid;
    }
    else if(arr[mid]>key)
    {
        binarysearch(arr,key,start,mid-1);
    }
    else
    {
         binarysearch(arr,key,mid+1,end);
    }
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int key;
    cin>>key;
    cout<<binarysearch(arr,key,0,9)<<endl;
    return 0;
}
