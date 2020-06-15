#include <iostream>

using namespace std;

int main()
{


    int n;
    cin>>n;
    for (int row=1; row<=n; row=row+1){
            // 3 loop method
        //for A

        for (int space=1; space<=(n-row); space=space+1){
            cout<<" ";
        }
      /*  //for B
        for(int star1=1; star1<=row; star1=star1+1){
            cout<<"*";
        }
        //for C
        for (int star2=1; star2<=(row-1); star2=star2+1 )
            cout<<"*";
        cout<<endl;}  */

         //single mode for stars
        //optimization of star case only
        for (int star=1; star<=(2*row-1); star=star+1){
            cout<<"*";
        }
        cout<<endl; }
    return 0;
}
