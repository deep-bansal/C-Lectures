#include <iostream>

using namespace std;

int main()
{
    int a[10];
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
   /* for(int i=0; i<10;i++)
    {
        a[i]=a[i]*a[i];
        cout<<a[i]<<endl;
    }*/
    int key;
    cin>>key;
    for(int i=0;i<n;i++)
    {
        if(key==a[i])
        {
            cout<<i;
        }
    }
    return 0;
}
