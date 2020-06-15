#include <iostream>

using namespace std;

int main()
{       //using while loop
    /*int n;
    cin>>n;
    int i=2;
    while(i<=(n-1)){
        if(n%i==0){
            cout<<n<<" is composite"<<endl;
            break;
        }
        i=i+1;

    }
    if (i==n){
        cout<<n<<" is prime";
    }*/
          // using for loop
    int num;
    cin>>num;
    int i=2;
    for (;i<=(num-1);i=i+1){
        if(num%i==0){
            cout<<num<<" is composite";
            break;
        }
        }
        if (i==num){
                cout<<num<<"is prime";

        }


    return 0;
}
