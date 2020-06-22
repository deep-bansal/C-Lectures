#include <bits/stdc++.h>

using namespace std;
int getPrec(char ch)
{
    if(ch=='^')
    {
        return 3;
    }
    else if(ch=='*' || ch=='/')
    {
        return 2;
    }
    else if(ch=='+'|| ch=='-')
    {
        return 1;
    }
    else if(ch==')'|| ch=='(')
    {
        return 0;
    }
    return -1;
}
string convertInfixToPostfix(string str)
{
     string result;
     stack<char>st;
     for(int i=0;i<str.size();i++)
     {
         char ch=str[i];
         int prec=getPrec(ch);
         if(prec==-1)
         {
             result+=ch;
         }
         else {
            if(ch=='(')
            {
                st.push(ch);
            }
            else if(ch==')')
            {
                while(!st.empty() && st.top()!='(')
                {
                    result+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                ///ch is an operator
                while(!st.empty() && getPrec(st.top())>=prec && st.top()!='(')
                {
                    result+=st.top();
                    st.pop();
                }
                st.push(ch);
            }
         }
     }
     while(!st.empty())
     {
        result+=st.top();
        st.pop();
     }
     return result;


}
int main()
{
   string str = "A+B*C-D*E";
	cout<<str<<endl;
	cout<<convertInfixToPostfix(str)<<endl;
	string str2 = "((A+B)*C-D)*E";
	cout<<str2<<endl;
	cout<<convertInfixToPostfix(str2)<<endl;

    return 0;
}
