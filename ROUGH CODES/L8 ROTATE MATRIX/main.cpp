#include <iostream>
using namespace std;
void rotation(int arr[100][100],int r,int c)
{
    ///reversing
    for(int i=0;i<r;i++)
    {
        int left=0,right=c-1;
        while(left<right)
        {
            swap(arr[i][left],arr[i][right]);
            left++;
            right--;
        }
    }
   /* for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<arr[i][j]<<",";
        }
        cout<<endl;
    }*/
    ///swapping
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            cout<<arr[i][j]<<", ";
        }
        cout<<endl;
    }
}

int main()
{
    int arr[100][100]={0};

    int r=5,c=5;
    for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			arr[i][j] = 0;
		}
	}

    for(int row=0;row<r;row++)
    {
        for(int col=0;col<c;col++)
        {
            arr[row][col]=(10*row)+col+1;
        }
    }
    rotation (arr,r,c);
    return 0;
}
