#include <bits/stdc++.h>

using namespace std;
class stacks {
   queue<int> q1,q2;

   int currentsize;
   public:
   stacks()
   {
       currentsize=0;
   }
   bool isEmpty()
   {
       return currentsize==0;
   }
   void push(int x)
   {
       q2.push(x);
       while(!q1.empty())
       {
           q2.push(q1.front());
           q1.pop();
       }
       queue<int> q=q1;
       q1=q2;
       q2=q;
       currentsize++;
   }
   void pop()
   {
       if(isEmpty())
       {
           cout<<"stack is empty"<<endl;
           return;
       }

      q1.pop();
      currentsize--;

   }
   int top()
   {
       if(isEmpty())
       {
           cout<<"stack is empty"<<endl;
           return -1;
       }
       return q1.front();
   }

};
int main()
{
    stacks st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

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
    cout<<st.top()<<endl;
    st.pop();





    return 0;
}
