#include <bits/stdc++.h>

using namespace std;

void InsertAtBottom(stack <int> &st,int val)
{
    if(st.empty())
    {
        st.push(val);
        return;
    }
    int x=st.top();
    st.pop();
    InsertAtBottom(st,val);
    st.push(x);
}

void ReverseSt(stack <int> &st)
{
    if(st.empty())
    {
        return;
    }
    int val=st.top();
    st.pop();
    ReverseSt(st);
    InsertAtBottom(st,val);


}
int main()
{
    stack<int>st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    ReverseSt(st);
    for(int i=0;i<4;i++)
    {
        cout<<st.top()<<endl;
        st.pop();
    }

    return 0;
}
