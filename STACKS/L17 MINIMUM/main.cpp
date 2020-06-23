#include <bits/stdc++.h>

using namespace std;
void minimum (stack<int> stA)
{
    stack<int>stB;
    stack<int>stD;
    while(!stA.empty() )
    {
        int a=stA.top();
        stB.push(a);
        stA.pop();
    }
    int minimum=100;
    while(!stB.empty())
    {
       int b=stB.top();
        minimum=min(minimum,b);
        stD.push(minimum);
        int c=stB.top();
        stA.push(c);
        stB.pop();
    }

    cout<<stD.top()<<endl;
    stD.pop();
	cout<<stD.top()<<endl;
	stD.pop();
	cout<<stD.top()<<endl;
	stD.pop();
	cout<<stD.top()<<endl;
	stD.pop();
	cout<<stD.top()<<endl;
	stD.pop();
	cout<<endl<<endl;

}

int main()
{
    stack<int> st;
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(1);
	st.push(5);
    minimum (st);
	cout<<st.top()<<endl;
    st.pop();
	cout<<st.top()<<endl;
	st.pop();
	cout<<st.top()<<endl;
	st.pop();
	cout<<st.top()<<endl;
	st.pop();
	cout<<st.top()<<endl;
	st.pop();
	cout<<endl;

    return 0;
}
