#include <iostream>

using namespace std;


         int factorial (int a){
           int factA=1;
           for(int i=1; i<=a; i++){
            factA=factA*i;
           }
           return factA;
           }
          int ncr (int n, int r){
              int a= factorial(n);
              int b=factorial(r);
              int c=factorial(n-r);
              int result= a/(b*c);
            return result;

}

int main()
{   int n,r;
    cin>>n>>r;
    /*int n=5;
     int ans= factorial(n);
     cout<<ans; */
     int ans=ncr (n,r);
     cout<<ans;


    return 0;
}
