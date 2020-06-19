#include <iostream>

using namespace std;
int friendspairing(int n)
{
    if(n<=2)
    {
        return n;
    }
    int single=friendspairing(n-1);
    int pair= (n-1)*friendspairing(n-2);
    int result=single+pair;
    return result;



}
int main()
{
    int n;
    cin>>n;
    cout<<friendspairing(n)<<endl;
    return 0;
}
