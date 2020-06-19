#include <iostream>

using namespace std;
bool isSafe (int board[10][10],int i,int j,int n)
{
   ///left diagonal;
    int r=i,c=j;
    while(r>=0 && c>=0)
    {
        if( board[r][c]==1)
        {
            return false;
        }
        r--;
        c--;
    }
    ///right diagonal
    r=i,c=j;
    while(r>=0 && c<n){
            if(board[r][c]==1)
                {
                return false;
                }
        r--;
        c++;
    }
    r=i,c=j;
    while(r>=0)
    {
        if(board[r][c]==1)
        {
            return false;
        }
        r--;
    }
    ///cell is safe
    return true;
}
bool nQueens (int board[10][10],int row,int n)
{
    if(row==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }
    for(int col=0;col<n;col++)
    {
        if(isSafe(board,row,col,n))
        {
            board[row][col]=1;
            bool queenplaced=nQueens(board,row+1,n);
            if(queenplaced==true)
            {
                return true;
            }
            ///back track
            board[row][col]=0;

        }
    }
    ///this shows we are unable to place the queen in the whole row;
    return false;
}
int main()
{
    int board[10][10]={0};
    int n;

    nQueens(board,0,4);
    return 0;
}
