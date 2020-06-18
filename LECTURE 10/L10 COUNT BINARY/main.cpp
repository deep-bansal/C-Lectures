#include <bits/stdc++.h>

using namespace std;
int countstrings(int n,string output)
{
   if(n==0)
   {
       return 1;

   }
    int len=output.length();
    int count=0;
    if(output[len-1]=='0')
    {
        count=countstrings(n-1,output+"0")+countstrings(n-1,output+"1");
    }
    else
    {
        count=countstrings(n-1,output+"0");
    }
    return count;

}

int main()
{
   int t;
   cin>>t;
   for(int i=0;i<t;i++)
   {
    int n;
    cin>>n;
    int result=countstrings(n-1,"0")+countstrings(n-1,"1");
    cout<<result;
    return 0;
   }
}
