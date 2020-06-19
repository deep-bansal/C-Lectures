#include <iostream>

using namespace std;
int findunique(int* arr,int start,int end)
{
    	cout << start << " "<< end << endl;
    if(start==end)
    {
        return start;
    }
    int mid=start+((end-start)/2);
    if(mid&1)///mid is odd
    {
        if(arr[mid+1]==arr[mid])
        {
            ///unique is in left
            return findunique(arr, start, mid - 1);
        }
        else
        {
            ///unique is in right
            return findunique(arr,mid+1,end);
        }
    }
    else
    {
        if(arr[mid+1]==arr[mid])
        {
            ///unique is in right
            return findunique(arr,mid+2,end);

        }
        else
        {
             ///unique is in left
             return findunique(arr,start,mid);
        }

    }



}
int main()
{
    int arr[11]={0,0,1,1,2,2,3,4,4,9,9};
    int n=11;
    int uniqueidx=findunique(arr,0,n-1);
    cout << "unique element : " << arr[uniqueidx] << endl;
    return 0;
}
