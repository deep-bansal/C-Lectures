#include <iostream>

using namespace std;
bool linearsearch(int*arr,int n,int key)
{
    if(n==0)
    {
        return false;
    }
    if(arr[0]==key || linearsearch(arr+1,n-1,key))
    {
        return true;
    }
    return false;
}

int main()
{
    int arr[10]={11,1,2,5,10};
    int n=5;
    int key;
    cin>>key;
    int result=linearsearch(arr,n,key);
    if(result)
    {
        cout<<"found"<<endl;
    }
    else
    {
        cout<<"not found";
    }
    return 0;
}
