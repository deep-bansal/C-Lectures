#include <iostream>

using namespace std;
int mazepaths(int startrow,int startcol,int endrow,int endcol,string output)
{
    if(startrow==endrow && startcol==endcol)
    {
       cout<<output<<endl;
        return 1;
    }
    if(startrow>endrow || startcol>endcol)
    {
        return 0;
    }
    int count=0;
             ///horizontal                                                ///vertical
     count+=mazepaths(startrow,startcol+1,endrow,endcol,output+"H")+ mazepaths(startrow+1,startcol,endrow,endcol,output+"V");
     return count;
}

int main()
{
    int startrow,endrow,startcol,endcol;
    cin>>startrow>>startcol>>endrow>>endcol;
   cout<< mazepaths(startrow,startcol,endrow,endcol,"")<<endl;
    return 0;
}
