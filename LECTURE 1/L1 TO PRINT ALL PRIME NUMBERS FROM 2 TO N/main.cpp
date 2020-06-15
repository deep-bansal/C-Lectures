#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int i=2;
    while (i<=n){
        int j=2;
        while (j<=(i-1)){
            if (i%j==0){
                 break;
            }
            j=j+1;
            }
            if (i==j){
                cout<<i<<endl;
            }
            i=i+1;
        }

    return 0;
}
