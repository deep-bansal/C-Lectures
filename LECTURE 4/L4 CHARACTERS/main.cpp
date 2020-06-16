#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char ch;
    cin>>ch;
    while(ch !='0'){
        cout<<ch;
        cin.get(ch);
    }
}

