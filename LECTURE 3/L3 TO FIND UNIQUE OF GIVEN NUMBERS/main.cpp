#include <iostream>

using namespace std;

int main()
{
    int n;   //n is numbers that will be provided by  user
    cin>>n;
    int firstnum;
    cin>>firstnum;
    int totalxor;
       totalxor= firstnum;
    for(int i=1; i<n; i++){
            int num;
            cin>>num;
        totalxor =totalxor^num;

    }
      cout<<totalxor;
    return 0;
}
