#include <bits/stdc++.h>

using namespace std;
char firstUnique(string str)
{
   queue<char>qu;
   int freq[26]={0};
    for(int i=0;i<str.size();i++)
    {
        char ch=str[i];
        freq[ch-'a']++;
        if(freq[ch-'a']>1)
        {
            while(!qu.empty() && freq[qu.front()-'a']>1)///queue front is not unique
        {
            qu.pop();
        }
        }
        else
        {
            qu.push(ch);
        }
      ///to print at every index  cout<<qu.front()<<endl;

    }
    return qu.front();
}

int main()
{
    string str="abcbadcfgf";
   cout<<firstUnique(str);
    return 0;
}
