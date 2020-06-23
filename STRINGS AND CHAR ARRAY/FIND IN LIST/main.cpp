#include <bits/stdc++.h>
using namespace std;

int main()
{
    char key[100];
    cin>>key;
    char a[10][100]={"apple","mango","orange","banana","pineapple"};
    int i;
    for(i=0;i<10;i++)
    {
        if(strcmp(key,a[i])==0)
        {
            cout<<"found at index "<<i<<endl;
            break;
        }
    }

    if(i==10)
    {
        cout<<"not found";
    }

    return 0;
}
