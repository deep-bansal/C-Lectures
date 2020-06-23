#include <bits/stdc++.h>

using namespace std;
void rotatestring(char* ch,int k)
{
    int i=strlen(ch);
    while(i>=0)
    {
        ch[i+k]=ch[i];
        i--;
    }
    i=strlen(ch);
    int j=i-k,s=0;
    while(j<i)
    {
        ch[s]=ch[j];
        j++;
        s++;
    }

    ch[i-k]='\0';


    cout<<ch;

}

int main()
{
    char ch[100];
    cin.getline(ch,100);
    int k;
    cin>>k;
    rotatestring(ch,k);
    return 0;
}
