#include <iostream>

using namespace std;
int odd_even(int num){
    if (num%2==0){
        cout<<num<<" is even";}
        else{cout<<num<<"is odd";}

    }

int main()
{


    int n;
    cin>>n;
    odd_even(n);

}
