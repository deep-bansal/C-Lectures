#include <iostream>

using namespace std;
void decorder(int n)
{
    if(n==0)
    {
        return ;
    }
    cout<<n<<endl;
    decorder(n-1);

}

void incorder(int n)
{
    if(n==0)
    {
        return;
    }
    incorder(n-1);
    cout<<n<<endl;
}
void dec_incorder(int n)
{
    if(n==0)
    {
        return;
    }
    cout<<n<<endl; ///prints decorder
    dec_incorder(n-1);
    cout<<n<<endl;///prints incorder
}

void inc_decorder(int n,int i)
{
    if(i>n)
    {
        return;
    }
    cout<<i<<endl;  ///incorder
    inc_decorder(n,i+1);
    cout<<i<<endl; ///decorder
}
int main()
{
    int n;
    cin>>n;
    ///decorder(n);
    ///incorder(n);
    ///dec_incorder(n);
    inc_decorder(n,1);

    return 0;
}
