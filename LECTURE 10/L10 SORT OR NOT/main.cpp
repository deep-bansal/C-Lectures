#include <iostream>

using namespace std;
bool sortcheck(int* arr,int n)
{
    if(n==1)
    {
        return true;
    }
    if(arr[0]<arr[1] &&  sortcheck(arr+1,n-1))
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    int arr[10];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(sortcheck(arr,n))
    {
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}
