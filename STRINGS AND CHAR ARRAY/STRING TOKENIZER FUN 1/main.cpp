#include <bits/stdc++.h>

using namespace std;

int main()
{
    char str [100]="hi, this is tutorial class," ;

    char* ptr;
    ptr=strtok(str," ,");
    while(ptr != NULL)
    {
        cout<<ptr<<endl;
        ptr=strtok(NULL," ,"); ///using two at same time
    }
    return 0;
}
