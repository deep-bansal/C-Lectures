#include <iostream>

using namespace std;

int main()
{
    int arr1[10]={1,2,6};
    int arr2[10]={5,6};
    int arr3[10]={7,10,11};
    int size1=3,size2=2,size3=3;
    int triplet1,triplet2,triplet3;
    int i=0,j=0,k=0;
    int mindiff=INT_MAX;
    while(i<size1 && j<size2 && k<size3)
    {
        int maximum=max(arr1[i],max(arr2[j],arr3[k]));
        int minimum=min(arr1[i],min(arr2[j],arr3[k]));

        int currentdiff=maximum-minimum;
        if(currentdiff<mindiff)
        {
            mindiff=currentdiff;
            triplet1=arr1[i];
            triplet2=arr2[j];
            triplet3=arr3[k];
        }
        if(mindiff==0)
        {
            break;
        }
        if(arr1[i] == minimum){
			i++;
		}
		else if(arr2[j] == minimum){
			j++;
		}
		else{
			k++;
		}
    }
    cout<<"min diff is : "<<mindiff<<endl;
	cout<<triplet1<<","<< triplet2<<","<<triplet3<<endl;


    return 0;
}
