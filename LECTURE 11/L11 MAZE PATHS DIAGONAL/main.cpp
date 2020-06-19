#include <iostream>

using namespace std;
void mazepaths(int startrow,int startcol,int endrow,int endcol,string output)
{
    if(startrow==endrow && startcol==endcol)
    {
       cout<<output<<endl;
        return ;
    }
    if(startrow>endrow || startcol>endcol)
    {
        return ;
    }
    ///horizontal
     mazepaths(startrow,startcol+1,endrow,endcol,output+"H");
    ///vertical
     mazepaths(startrow+1,startcol,endrow,endcol,output+"V");
     /// diagonal
    mazepaths(startrow+1,startcol+1,endrow,endcol,output+"D");

}

int main()
{
    int startrow,endrow,startcol,endcol;
    cin>>startrow>>startcol>>endrow>>endcol;
   mazepaths(startrow,startcol,endrow,endcol,"");
    return 0;
}
