#include <bits/stdc++.h>
#include <cstring>
using namespace std;

 ///to sort based upon length
 bool compare (string a,string b)
    {
        if(a.length()==b.length())
        {
            return a>b;
        }
        else{
        return a.length()>b.length(); ///length wise sort
        }
    }

int main()
{
    string s ("HELLO WORLD");
    cout<<s<<endl;

    string s2="another way!";
    cout<<s2<<endl;

    ///to input a sting
    string s3;
    getline(cin,s3);
    cout<<s3<<endl;

    ///another way to get input
   /* string str1;
    cin>>str1;
    cout<<str1<<endl; */

    ///to access particular character
    char c1=s[2];
    cout<<c1<<endl;

    ///to reverse a string
    reverse(s2.begin(),s2.end());
    cout<<s2<<endl;

    ///to add the strings
    string st1="abc";
    string st2="def";
    string st3= st1+st2;
    cout<<st3<<endl;

    ///to add character in string
    char ch='x';
    st1+=ch;
    cout<<st1<<endl;

    ///to find substring
    string str4="abcdefghijk";
    string str5=str4.substr(2,4);
    cout<<str5<<endl;

    ///to sort the string
    string arr[]={"apple","banannananaan","pineapple","mango","guava"};
    sort(arr,arr+4);
    for(int i=0;i<4;i++)
    {
        cout<<arr[i]<<endl;
    }

    ///to sort based upon length

    sort (arr,arr+5,compare);
    for(int i=0;i<=4;i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}
