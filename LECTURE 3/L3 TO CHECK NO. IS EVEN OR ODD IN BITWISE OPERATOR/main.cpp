#include <iostream>

using namespace std;

int main()
{
    //bitwise operator
    //to check even or odd
    int a;
    cin>>a;
    int b=1;
    if((a&b)==0){
        cout<<a<<" is even";
    }
    else{
        cout<<a<<" "<<"is odd";
    }
    return 0;
}
