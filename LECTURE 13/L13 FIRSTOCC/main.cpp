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
        end=mid-1;
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

int main()
{
   int arr[10] = {1,2,3,3,3,3,4,4,5};
	int key;
	cin>>key;
	int idx = lastOcc(arr,0, 9, key);
	if(idx < 0){
		cout<<key<<" not found"<<endl;
        }
	else{
		cout<<key<<" found at "<<idx<<endl;
	}


    return 0;
}
