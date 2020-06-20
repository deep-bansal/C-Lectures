#include <iostream>

using namespace std;
void prime_seive(int* p,int n)
{
    ///first mark all odd numbers as prime
    for(int i=3;i<=n;i+=2)
    {
        p[i]=1;
    }
    ///seive
    for(int i=3;i<=n;i+=2)
    {
        ///if current no is prime
        if(p[i]==1)
        {
            ///mark its multiples as not prime
            for(int j=i*i;j<=n;j=j+ 2 *i)
            {
                p[j]=0;
            }
        }
    }
    p[2]=1;
    p[0]=p[1]=0;
}

int main()
{
    int n;
    cin>>n;
    int p[100005]={0};
    prime_seive(p,n);
    for(int i=0;i<=n;i++)
    {
        if(p[i]==1)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}
