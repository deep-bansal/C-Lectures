#include <bits/stdc++.h>

using namespace std;
bool ispermutation(char*s1,char*s2)
{
    int l1=strlen(s1);
    int l2=strlen(s2);
    int arr[26]={0};
    if(l1!=l2)
    {
        return false;
    }
    ///check for freq of s1
    for(int i=0;i<l1;i++)
    {
        arr[s1[i]-'a']++;
    }
     for(int i=0;i<26;i++)
    {
        cout<<arr[i]<<",";
    }
    for(int i=0;i<l2;i++)
    {
        arr[s2[i]-'a']--;
    }
    for(int i=0;i<26;i++)
    {
        cout<<arr[i]<<",";
        if(arr[i]!=0)
        {
            return false;
        }

    }
    return true;

}

int main()
{
    ///to check if two substrings are permutation to each other or not
    /// if length and frequency of two strings are equal then they are permutation to each other
    char s1[100];
    cin.getline(s1,100);
    char s2[100];
    cin.getline(s2,100);


    if(ispermutation(s1,s2))
    {
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }

       return 0;
}
