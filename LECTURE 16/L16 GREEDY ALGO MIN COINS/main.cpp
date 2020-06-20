#include <iostream>

using namespace std;
int coins[4]={10,5,2,1};
int MinCoins(int n)
{
    int NumofCoins=0;
    int i=0;
    while(n>0)
    {
      if(n>=coins[i])
      {
          NumofCoins+=(n/coins[i]);
          n%=coins[i];
      }
      i++;
    }
    return NumofCoins;
}
int main()
{
    int n;
    cin>>n;
    cout<<MinCoins(n)<<endl;
    return 0;
}
