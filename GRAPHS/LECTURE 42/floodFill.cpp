#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int R,C;

void printMatrix(char mat[][50])
{
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

void floodFill(char mat[][50], int i,int j,char ch,char color)
{
	// matrix boundary
	if(i< 0 || j< 0 || i>=R || j>=C)
	{
		return;
	}
	// figure boundary
	if(mat[i][j] != ch)
	{
		return;
	}
	mat[i][j] =color;
	for (int k = 0; k < 4 ; ++k)
	{
	   floodFill(mat,i+dx[k],j+dy[k],ch,color);
	}
}

int main(int argc, char const *argv[])
{
	cin>>R>>C;

	char input[R][C];
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin>>input[i][j];
		}
	}

	
	return 0;
}