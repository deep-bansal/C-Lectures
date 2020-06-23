#include <bits/stdc++.h>

using namespace std;
int ans[10];

void StockSpan(int* stocks,int days)
{
    stack <int> st;
    for(int i=0;i<days;i++)
    {
        int currDayprice=stocks[i];
        while(!st.empty() and stocks[st.top()]<=currDayprice)
        {
            st.pop();
        }
        int greaterDayVal=st.empty()? i:st.top();
        ans[i]=i-greaterDayVal;
        st.push(i);
    }
}
int main()
{
    int stocks[10]={100,90,70,80,85,60,90};
    int days=7;
    StockSpan(stocks,days);
    for(int i=0;i<days;i++)
    {
        cout<<ans[i]<<endl;
    }

    return 0;
}
