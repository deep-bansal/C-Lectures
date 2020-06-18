#include <bits/stdc++.h>

using namespace std;
void addstar(string input,string output)
{
    if(input.length()==0)
    {
        cout<<output<<endl;
    }
        if(input.length()>=2 && input[0]=='x' && input[1]=='x' )
        {
            string osf=output+"x*";
            string ros=input.substr(1);
        addstar(ros,osf);

        }
        else
        {
            string osf=output+input[0];
            string ros= input.substr(1);
		addstar(ros, osf);
        }

}

int main()
{
    string s;
    cin>>s;
    addstar(s,"");

    return 0;
}
