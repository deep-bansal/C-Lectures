#include <bits/stdc++.h>

using namespace std;

int main()
{
    deque<string> dq;
	dq.push_back("1");
	dq.push_back("2");
	dq.push_back("3");
	dq.push_front("4");
	dq.push_front("5");
	dq.push_front("6");
	///6,5,4,1,2,3

	for(int i=0;i<dq.size();i++)
    {
        cout<<dq.front()<<endl;
        dq.pop_front();

    }
    return 0;
}
