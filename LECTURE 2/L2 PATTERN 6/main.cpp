#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    //1st half
    for (int row=1; row<=n; row=row+1){
            // 3 loop method
        //for A spaces

        for (int space=1; space<=(n-row); space=space+1){
            cout<<" ";
        }
         for (int star=1; star<=(2*row-1); star=star+1){
            cout<<"*";
        }
        cout<<endl; }

        //2nd half
        for (int row=(n-1); row>=1; row=row-1){
            // 3 loop method
        //for A spaces

        for (int space=1; space<=(n-row); space=space+1){
            cout<<" ";
        }
         for (int star=1; star<=(2*row-1); star=star+1){
            cout<<"*";
        }
        cout<<endl; }
    return 0;
}
