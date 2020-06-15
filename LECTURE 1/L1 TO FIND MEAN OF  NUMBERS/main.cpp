#include <iostream>

using namespace std;

int main()
{
  int i,j,sum,N;
  N=4;
  j=0;
  sum=0;
  i=1;
  while (i<=N){
    cin>>j;
    sum=(sum+j);
    i=i+1;

  }
  // (/)only provides integral values
  cout<<(sum)/N;
    return 0;
}
