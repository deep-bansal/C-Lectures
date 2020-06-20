#include <bits/stdc++.h>

using namespace std;
int minProduct(int* arr,int n)
{
     if(n==1)
     {
         return arr[0];
     }

    int countofZero=0,countofNeg=0;
    int maxNegno=INT_MIN,minPosno=INT_MAX;
    int totalProduct=1;
    for(int i=0;i<6;i++)
    {
        if(arr[i]==0)
        {
            countofZero++;
        }
        else{
        totalProduct*=arr[i];
           if(arr[i]<0)
          {
            countofNeg++;
            maxNegno=max(maxNegno,arr[i]);
          }
          else
          {
              minPosno=min(minPosno,arr[i]);
          }
        }

    }
    if(countofNeg==0)///all positive no.
    {
        if(countofZero>0)
        {
            return 0;
        }
        else
        {
            return minPosno;
        }
    }
    else{
    if(countofNeg&1)///count of negno. is odd
    {
        return totalProduct;
    }
    else
    {
        return totalProduct=(totalProduct)/(maxNegno);
    }
    }

}

int main()
{
    int arr[6]={0,1,1,-2,3,2};
    int n=6;
    cout<<minProduct(arr,n)<<endl;
    return 0;
}
