#include <iostream>

using namespace std;
///here we are finding smallest element
int pivotInRotated(int* arr,int start,int end)
{
    if(start>end)
    {
        return start;
    }
    int mid = start + ((end - start) / 2);
    if(mid>start && arr[mid]<arr[mid-1])
    {
        return mid;
    }
    if(mid<end && arr[mid]>arr[mid+1])
    {
        return mid+1;
    }
    ///searching
    ///right unsorted
    if(arr[mid]>arr[end])
    {
        pivotInRotated(arr,mid+1,end);
    }
    else { // left unsorted
		return pivotInRotated(arr, start, mid - 1);
	}
}

int main()
{
    int arr[20] = {6,7,1,2,3,4,5};
	int idx = pivotInRotated(arr, 0, 6);
	cout << "pivot found at " << idx << endl;
    return 0;
}
