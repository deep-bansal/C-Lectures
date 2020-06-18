#include <iostream>
using namespace std;
void spiralprint (int arr[11][11],int m,int n)
{
    int startrow=0,endrow=m-1,startcol=0,endcol=n-1;
    while(startrow<=endrow && startcol<=endcol)
    {
        ///traversing startrow
        int i=startcol;
        while(i<=endcol)
        {
            cout<<arr[startrow][i]<<",";
            i++;
        }
        startrow++;
            ///print endcol
            i=startrow;
            while (i<=endrow)
            {
                cout<<arr[i][endcol]<<",";
                i++;
            }
            endcol--;
            ///print endrow
            if(endrow>=startrow)
        {
            i=endcol;
            while(i>=startcol)
            {
               cout<<arr[endrow][i]<<",";
               i--;
            }
            endrow--;
        }
        ///print startcol
        if(endcol>=startcol)
        {
            i=endrow;
            while(i>=startrow)
            {
                cout<<arr[i][startcol]<<",";
                i--;
            }
            startcol++;
        }
    }

}

int main()
{
    int arr[11][11];
    int m,n;
    cin>>m>>n;
    for(int row=0;row<m;row++)
    {
        for(int col=0;col<n;col++)
        {
            arr[row][col]=(10*row)+col+1;
        }
    }
    for(int row=0;row<m;row++)
    {
        for(int col=0;col<n;col++)
        {
           cout<<arr[row][col]<<",";
        }
        cout<<endl;
    }
    cout<<endl;
    spiralprint(arr,m,n);
    return 0;
}
