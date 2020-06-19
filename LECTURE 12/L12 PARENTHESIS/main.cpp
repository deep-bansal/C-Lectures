#include <iostream>

using namespace std;
void parenthesis (int N,string output,int open, int close)
{

    if(close==N)
    {
        cout<<output<<endl;
        return;
    }
    if(open>close)
    {

        parenthesis (N,output+")",open,close+1);
    }

    if(open<N)
    {
        parenthesis (N,output+"(",open+1,close);
    }


}
int main()
{
    int n;
    cin>>n;
    parenthesis(n,"",0,0);
    return 0;
}
