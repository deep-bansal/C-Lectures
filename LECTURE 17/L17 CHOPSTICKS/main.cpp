#include <bits/stdc++.h>
/***Actually, the two sticks in a pair of chopsticks need not be of the same length.
A pair of sticks can be used to eat as long as the difference in their length is at most D.
The Chef has N sticks in which the ith stick is L[i] units long.
 A stick can't be part of more than one pair of chopsticks.
 Help the Chef in pairing up the sticks to form the maximum number of usable pairs of chopsticks.**/
#define ll long long
using namespace std;

int main()
{
    ll int n,d;
    cin>>n>>d;
    ll int arr[10000];
    for(ll int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    ll int pairs=0;
    ll int j=0;
    while(j<n-1)
    {
        if((arr[j+1]-arr[j])<=d)
        {
            pairs++;
        }
       j++;


    }
    cout<<pairs<<endl;

    return 0;
}
