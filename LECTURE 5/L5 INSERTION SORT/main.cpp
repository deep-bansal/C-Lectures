#include <iostream>

using namespace std;
void isort (int arr[10],int n)
{
    int key,j;
    for(int i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && key<arr[j])
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;  //placing of key
        for(int i=0;i<5;i++){
        cout<<arr[i]<<", ";
    }
      cout<<endl;
    }


}

int main()
{
    int arr[10]={5,2,9,3,4};
    isort(arr,5);

    return 0;
}
