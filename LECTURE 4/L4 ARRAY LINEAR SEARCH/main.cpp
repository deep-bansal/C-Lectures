#include <iostream>
using namespace std;
int main()
{
    int arr[7]={1,2,3,4,5,7,8};
    int n;
    cin>>n;
    bool isarray=false;
    for(int i=0; i<7; i=i+1){
        if(arr[i]==n){
            isarray=true;
            cout<<"true"<<endl;
            cout<<i;
             break;
                }

        }
        if(isarray==false)
        {
            cout<<"false";
        }
    }


