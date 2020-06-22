#include <bits/stdc++.h>
#include <vector>
using namespace std;

class queues
{
	stack<int> st1,st2;

public:
	bool isEmpty(){
		return st1.empty();
	}
	void push(int num){
		st1.push(num);
	}
	void pop(){
	    if(isEmpty())
        {
            cout<<"queue is empty"<<endl;
            return;
        }
	    while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        st2.pop();
         while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
	}
	int getfront(){
		if(isEmpty()){
			cout<<"queue is empty"<<endl;
			return -1;
		}
		while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int result=st2.top();
       while(!st2.empty())
       {
           st1.push(st2.top());
           st2.pop();
       }

       return result;
	}
};

int main(int argc, char const *argv[])

{

	queues qu;

	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.push(4);
	cout<<qu.getfront()<<endl;
	qu.pop();
	cout<<qu.getfront()<<endl;
	qu.pop();
	cout<<qu.getfront()<<endl;
	qu.pop();
	cout<<qu.getfront()<<endl;
	qu.pop();
	cout<<qu.getfront()<<endl;
	qu.pop();
	cout<<qu.getfront()<<endl;
	qu.pop();


	return 0;

}
