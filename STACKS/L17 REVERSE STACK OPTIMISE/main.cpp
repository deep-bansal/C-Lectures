#include <bits/stdc++.h>
#include <vector>
using namespace std;
/// STACK REVERSING USING ONE EXTRA STACK
void transfer( stack<int>&stA, stack<int>&stB, int n)
{
   for(int i=0;i<n;i++)
    {

        stB.push(stA.top());
        stA.pop();
    }
}

void reverseStack(stack<int> &stA)
{
    stack<int>stB;
    int n=stA.size();
    for(int i=0;i<n;++i)
    {
      int temp=stA.top();
      stA.pop();
     transfer(stA,stB,n-i-1);
     stA.push(temp);
     transfer(stB,stA,n-i-1);
    }
}
int main(int argc, char const *argv[])
{
    stack<int> st;
	st.push(5);
	st.push(10);
	st.push(15);
	st.push(20);

    reverseStack(st);

	while(st.empty()==false)
    {
        cout<<st.top()<<endl;
        st.pop();
    }

}
