#include <bits/stdc++.h>

using namespace std;
/*High school student Vasya got a string of length n as a birthday present.
This string consists of letters 'a' and 'b' only.
Vasya denotes beauty of the string as the maximum length of a substring (consecutive subsequence) consisting of equal letters.
Vasya can change no more than k characters of the original string. What is the maximum beauty of the string he can achieve?
Input
The first line of the input contains two integers n and k the length of the string and the maximum number of characters to change.
The second line contains the string, consisting of letters 'a' and 'b' only.
Output
Print the only integer — the maximum beauty of the string Vasya can achieve by changing no more than k characters.*/

int main()
{
    string str;
    int key;
    cin>>str>>key;
    int l=str.length();
    int count[2]={0};
    int ans=0,i=0,left=0;
    while(i<l)
    {
        count[str[i]-'a']++;
        if(min(count[0],count[1])>key)
        {
            count[str[left]-'a']--;
            left++;
        }
        else
        {
            ans++;
        }
        i++;  ///helping in iterating
    }
    cout<<ans<<endl;



    return 0;
}
