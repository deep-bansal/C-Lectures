#include <iostream>
using namespace std;
int sumAllsubmatrix(int arr[10][10],int r,int c)
{
    int sum=0;
    for (int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            int topleft= (i+1)*(j+1);
            int bottomright=(r-i)*(c-j);
            sum+=arr[i][j]*topleft*bottomright;
        }
    }
    return sum;
}

int main()
{
    int arr[10][10] = {{1,1},
					 {1,1}};
	int r =2, c =2;
	int sum = sumAllsubmatrix(arr, r, c);
	cout<<sum<<endl;
    return 0;
}
