#include <bits/stdc++.h>

using namespace std;

int main()
{   int n;
    cin>>n;
    bool isprime= true;
    int i=2;
    int rootn= pow(n,0.5);
    while (i<=rootn) {
        if(n%i==0){
            isprime=false;

            cout<<"Not prime"<<endl;
               break;
        }
        i=i+1;
    }
    if(isprime) {
        cout<<"Prime"<<endl;
    }

    return 0;
}
