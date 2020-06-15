#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for (int row=1; row<=n; row=row+1){
        for (int space=1; space<=(n-row); space=space+1){
            cout<<"#";
        }
        cout<<endl;
    }
    return 0;
}
