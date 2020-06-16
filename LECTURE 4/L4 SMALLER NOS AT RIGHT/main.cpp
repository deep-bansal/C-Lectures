#include <iostream>

using namespace std;

int main()
{
    int array[8]={10,9,5,7,4,6,2,1};
    int max=array[7];
    int count =1;
    for(int i=7; i>=0; i-- ){
        if(array[i]>max){
            count++;
            max=array[i];
            cout<<array[i]<<" "<<endl;
        }

    }
    cout<<count;

    return 0;
}
