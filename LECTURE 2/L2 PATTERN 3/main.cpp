#include <iostream>

using namespace std;

int main()
{
     int n;
    cin>>n;
     int val=0;


    for (int row=1; row<=n; row=row+1){

        for (int col=1; col<=row; col=col+1){
           //value phle badd rhi h fir print ho rhi h islei val 0 se strt h
                val=val+1;
        cout<<val<<" ";


        }
           cout<<endl;

    }
    return 0;
}
