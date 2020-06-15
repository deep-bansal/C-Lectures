#include <iostream>

using namespace std;

int main()
{   int n;
     cin>>n;
     int val=1;
     for(int row=1; row<=n; row=row+1){
        //if check idhar islei lagayengeg kyunki row ki baat hum yha pr kr rhe h
        if(row%2==0){
            val=0;}
            else {
                val=1;
            }
            for(int col=1; col<=row; col=col+1){
                cout<<val<<" ";
                val= !val;
            }
            cout<<endl;
        }
     }


