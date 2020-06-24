#include <iostream>

using namespace std;
bool isSafe(char board[1001][1001],int i,int j,int row,int col)
{
    if(board[i][j]=='O' && i<row && j<col)
    {
        return true;
    }
    return false;
}
bool ratinmaze(char board[1001][1001],int soln[1001][1001],int i,int j,int row,int col)
{
    if(i==row-1 && j==col-1)
    {
        soln[i][j]=1;
        return true;
    }
   if(isSafe(board,i,j,row,col))
   {
        soln[i][j]=1;
    if(ratinmaze(board,soln,i,j+1,row,col))
    {
        return true;
    }
    if(ratinmaze(board,soln,i+1,j,row,col))
    {
        return true;
    }
	 if(ratinmaze(board,soln,i-1,j,row,col))
    {
        return true;
    }
	if(ratinmaze(board,soln,i,j-1,row,col))
    {
        return true;
    }
   }
    soln[i][j]=0;
    return false;

}
int main()
{
    int n,m;
    cin>>n>>m;
    char board[1001][1001];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>board[i][j];
        }
    }
  int soln[1001][1001]={0};

  if(ratinmaze(board,soln,0,0,n,m)==true)
  {
      for(int k=0;k<n;k++)
        {
            for(int l=0;l<m;l++)
            {
                cout<<soln[k][l]<<" ";
            }
            cout<<endl;
        }
  }
  else
  {
      cout<<"NO PATH FOUND";
  }


    return 0;
}