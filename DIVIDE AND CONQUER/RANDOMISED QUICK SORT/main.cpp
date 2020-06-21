#include <iostream>
#include <ctime>
#include<cstdlib>

using namespace std;
void shuffle(int* a,int s,int e)
{
    srand(time(NULL));
    int j;
    for(int i=e;i>0;i--)
    {
        ///create one random index
        j=rand()%(i+1);
        swap(a[i],a[j]);
    }

}

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
    if(s>=e)
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
    int a[7]={1,2,3,4,5,6,7};
    shuffle(a,0,6);
     for(int i=0;i<=6;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl<<endl;
    quicksort(a,0,6);
    for(int i=0;i<=6;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
