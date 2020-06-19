#include <iostream>

using namespace std;
bool isSafe (int board[10][10],int  i,int j,int row,int col)
{

    if(board[i][j]==0 && i<row && j<col)
    {
        return true;
    }
    return false;
}
bool ratinmaze(int board[10][10],int i,int j,int row,int col,int soln[10][10])
{
    if(i==row-1 && j==col-1)
    {
        soln[i][j]={2};
        ///print soln board
        for(int k=0;k<row;k++)
        {
            for(int l=0;l<col;l++)
            {
                cout<<soln[k][l]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;

        return true;
    }
    bool horizontal=false,vertical=false;
    soln[i][j]={2};
    ///horizontal
    if(isSafe(board,i,j+1,row,col))
    {
        horizontal=ratinmaze(board,i,j+1,row,col,soln);
    }
    ///vertical
    if(isSafe(board,i+1,j,row,col))
    {
        vertical=ratinmaze(board,i+1,j,row,col,soln);
    }
    ///backtrack
    soln[i][j]=0;
    return horizontal or vertical;
}

int main()
{
   int r = 5, c = 4;

	int board[10][10] = {
	    {0, 0, 0, 1},
		{0, 1, 0, 1},
		{0, 0, 0, 1},
		{0, 0, 0, 1},
		{0, 1, 0, 0} };
		int soln[10][10]={0};

	if(ratinmaze(board,0,0,r,c,soln)){
		cout<<"path possible"<<endl;
	}
	else{
		cout<<"path not possible"<<endl;
	}
    return 0;
}
