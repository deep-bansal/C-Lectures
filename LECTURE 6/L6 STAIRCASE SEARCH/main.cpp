#include <iostream>

using namespace std;
bool staircasesearch (int arr[5][4],int r,int c,int key)
{
    int i=0, j=c-1;
    while(i<r && j>=0)
    {
        if(key==arr[i][j])
        {
            return true;
        }
        else if(key>arr[i][j])
        {
            i++;
        }
        else{
            j--;
        }
    }
     return false;

}

int main()
{
    int key;
    cin>>key;
    int arr[5][4]=     { {1,11,111,1111},

					     {2,22,222,2222},

                         {3,33,333,3333},

                         {4,44,444,4444},

				         {5,55,555,5555} };
       bool result= staircasesearch (arr,5,4,key);
        if(result)
        {
            cout<<"is found"<<endl;
        }
        else
        {
            cout<<"is not found"<<endl;
        }

    return 0;
}
