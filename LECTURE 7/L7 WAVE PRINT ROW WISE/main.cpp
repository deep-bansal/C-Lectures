#include <iostream>
using namespace std;
void waveprint (int arr[10][10],int r,int c)
{
    for(int row=0;row<r;row++)
    {
        if(row%2==0)
        {          ///even
            for(int col=0;col<c;col++)
            {
                cout<<arr[row][col]<<",";
            }
            cout<<endl;
        }
            else
            {       ///odd
                for(int col=c-1;col>=0;col--)
                {
                    cout<<arr[row][col]<<",";
                }
                cout<<endl;
            }
    }
}

int main()
{
    int arr[10][10];
    int r=5,c=4;
    for(int row=0;row<r;row++)
    {
        for(int col=0;col<c;col++)
        {
            arr[row][col]=(10*row)+col+1;
        }
    }
    for(int row=0;row<r;row++)
    {
        for(int col=0;col<c;col++)
        {
            cout<<arr[row][col]<<",";
        }
        cout<<endl;
    }
    cout<<endl;
    waveprint(arr,r,c);
    return 0;
}
