#include <iostream>

using namespace std;
int partition(int* a,int s,int e)
{
    int pivot=a[e];
    int i=s-1;
    for(int j=s;j<e;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
  return i+1;
}
void quicksort(int* a, int s,int e)
{
    if(s==e)
    {
        return;
    }
   int p=partition(a,s,e);
   quicksort(a,s,p-1);
   quicksort(a,p+1,e);
return;
}


int main()
{
    int a[7]={2,1,5,6,7,5,8};
    quicksort(a,0,6);
    for(int i=0;i<=6;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
