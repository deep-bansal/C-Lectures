#include <iostream>

using namespace std;
void subseqas(string input,string output)
{
    if(input.length()==0)
    {
        int n=output.length();
        for(int i=0;i<n;i++)
        {
           int x=output[i];
            cout<<output[i]<<x;
        }
        cout<<endl;
        return;
    }
    char ch=input[0];
    string ros=input.substr(1);
    subseqas(ros,output);
    subseqas(ros,output+ch);
}


int main()
{
    string str;
    cin>>str;
    subseqas(str,"");
    return 0;
}
