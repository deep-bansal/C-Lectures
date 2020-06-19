#include <iostream>

using namespace std;
void permutations2(char* arr,int i)
{
    if(arr[i]=='\0')
    {
        cout<<arr<<endl;
        return;
    }
    for(int j=i;arr[j]!='\0';j++)
    {
        swap(arr[i],arr[j]);
        permutations2(arr,i+1);
          swap(arr[i],arr[j]);
    }

}
int main()
{
    char arr[100];
    cin>>arr;
    permutations2(arr,0);
    return 0;
}
