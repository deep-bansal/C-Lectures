#include <iostream>

using namespace std;
int placepivot(int*arr,int start,int end)
{
    int pivot=arr[end];
    int i=start-1;
    for(int j=start;j<end;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[j],arr[i]);
        }
    }
    i++;
	swap(arr[i],arr[end]);/// placing pivot at it's right position
	return i;
}
void quicksort(int* arr,int start,int end)
{
    if(start>=end)
    {
        return;
    }
    int pivotidx=placepivot(arr,start,end);
    ///left half
    quicksort(arr,start,pivotidx-1);
     ///right half
     quicksort(arr,pivotidx+1,end);



}
int main()
{
    int arr[6]={5,3,2,1,9,4};
    int n=6;
    quicksort(arr,0,5);
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
