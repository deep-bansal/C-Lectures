#include <iostream>

using namespace std;
int lastOcc(int* arr,int start,int end,int key)
{
    int ans={0};
    while(start<=end)
  {
      int mid=start+((end-start)/2);
    if(arr[mid]==key)
    {
        ans=mid;
        start=mid+1;
    }
    else if(arr[mid]>key)
    {
        end=mid-1;
    }
    else
    {
        start=mid+1;
    }
  }
  return ans;
}
int lastOccrec(int* arr,int start,int end,int key,int &ans)
{
    if(start>end)
    {
        return -1;
    }
    int mid= start+((end-start)/2);

    if(arr[mid]==key)
    {
        ans=mid;
        lastOccrec(arr,mid+1,end,key,ans);
    }
    else if(arr[mid]>key)
    {
        lastOccrec(arr,start,mid-1,key,ans);
    }
    else
    {
        lastOccrec(arr,mid+1,end,key,ans);
    }
    return ans;

}

int main()
{
   int arr[13] = {1,2,3,3,3,3,4,4,5,5,6,7,8};
	int key;
	cin>>key;
	int ans=0;
	int idx = lastOccrec(arr,0, 12, key,ans);
	if(idx < 0){
		cout<<key<<" not found"<<endl;
        }
	else{
		cout<<key<<" found at "<<idx<<endl;
	}


    return 0;
}
