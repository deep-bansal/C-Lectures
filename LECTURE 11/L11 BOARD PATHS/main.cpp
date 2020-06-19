#include <iostream>

using namespace std;
int boardpaths(int start,int stop,string output)
{
    if(start==stop)
    {
        cout<<output<<endl;
        return 1;
    }
    if(start>stop)
    {
        return 0;
    }
    int count=0;
    for(int i=1;i<=6;i++)
    {
        char ch='0'+i;
        count+=boardpaths(start+i,stop,output+ch+" ");
    }
    return count;
}



int main()
{
   int start;
   int stop;
   cin>>start>>stop;
  cout<<boardpaths(start,stop,"")<<endl;

      return 0;
}
