#include <iostream>
#include <ctime>
#include<cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    cout<<"the no is "<<rand()%100<<endl;
    return 0;
}
