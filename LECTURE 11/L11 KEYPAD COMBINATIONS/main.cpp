#include <iostream>

using namespace std;

string keypad[10]={"+","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};
void keypadcombinations(string input,string output,int &count)
{
    if(input.length()==0)
    {
        cout<<output<<" ";
        count++;
        return;
    }

    int y=input[0]-'0';
    string str2=keypad[y];
    string ros=input.substr(1);
    for(int i=0;i<str2.length();i++)
    {
        char include=str2[i];
        keypadcombinations(ros,output+include,count);
    }

}

int main()
{
    string str;
    cin>>str;
    int count=0;
    keypadcombinations(str,"",count);
    cout<<endl<<count;

    return 0;
}
