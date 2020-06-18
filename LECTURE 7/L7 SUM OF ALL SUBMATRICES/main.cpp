#include <iostream>
using namespace std;
int sumAllsubmatrix(int arr[10][10], int r, int c)
{
    int sum=0;
    for(int tli=0;tli<r;tli++)
    {
        for(int tlj=0;tlj<c;tlj++)
        {
           ///cout<<tli<<"  "<<tlj<<" -->";
           for(int bri=tli;bri<r;bri++)
           {
               for(int brj=tlj;brj<c;brj++)
               {
                 /// cout<<bri<<" "<<brj<<",";
                  for(int i=tli;i<=bri;i++)
                  {
                      for(int j=tlj;j<=brj;j++)
                      {
                          sum=sum+arr[i][j];
                      }
                  }
               }
           }
        }///cout<<endl;
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
