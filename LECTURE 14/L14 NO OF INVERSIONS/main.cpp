#include <iostream>

using namespace std;
int merge(int*arr,int start,int mid,int end)
{
    int i=start,j=mid+1,k=0;
    int temp[100]={0};
    int count=0;
    while(i<=mid && j<=end)
    {
       if(arr[i]<arr[j])
      {
        temp[k]=arr[i];
        i++;
        k++;
      }
      else
      {
          temp[k]=arr[j];
          j++;
          k++;
          count+=(mid-i+1);
      }
    }
    //copy remaining elements
	while (i <= mid) {
		temp[k] = arr[i];
		k++;
		i++;
	}
	while (j <= end) {
		temp[k] = arr[j];
		k++;
		j++;
	}
	//copy to actual array
	i = 0;
	while (start <= end) {
		arr[start] = temp[i];
		start++;
		i++;
	}
	return count;
}
int mergesort (int* arr, int start, int end)
{
    if(start==end)
    {
        return 0;
    }

    int mid=start+((end-start)/2);
    int count=0;
    ///left half
    count+=mergesort(arr,start,mid);
    ///right half
    count+=mergesort(arr,mid+1,end);

    count+=merge(arr,start,mid,end);
    return count;
}
int main()
{
    int arr[10]={15,8,9,10,2,3,1};
    int inversions=mergesort(arr,0,6);
    cout<<inversions<<endl;
    for(int i=0;i<=6;i++)
    {
        cout<<arr[i]<<", ";
    }
    return 0;
}
