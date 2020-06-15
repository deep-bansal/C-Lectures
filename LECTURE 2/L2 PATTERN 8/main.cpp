#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for (int row=1; row<=n; row=row+1){
        //for pattern A
        for(int space=1; space<=(n-row); space=space+1){
            cout<<"  ";}
            //for pattern B
            for(int val=1; val<=row; val=val+1){
                cout<<val<<" ";
            }
            //for pattern C
            for (int val2=1;val2<=(row-1); val2=val2+1){
                cout<<val2<<" ";
            }
            cout<<endl;
        }

    return 0;
}
