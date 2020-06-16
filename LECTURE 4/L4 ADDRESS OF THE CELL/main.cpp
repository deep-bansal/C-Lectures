#include <iostream>

using namespace std;

int main()
{
    int x=9;
    cout<<&x<<endl;

    float y=10.57;
    cout<<&y<<endl;

    char ch='A';
    cout<<&ch<<endl;
    cout<<(void*)&ch;
    return 0;
}
