#include <iostream>

using namespace std;
class queues {
    int* arr;
    int front;
    int rear;
    int totalsize;
    int currentsize;

    public:
    queues (int defaultsize=5)
    {
        totalsize=defaultsize;
        arr=new int [totalsize];
        currentsize=0;
        front=0;
        rear=totalsize-1;

    }
    bool isEmpty()
    {
        return currentsize==0;
    }
    bool isFull()
    {
        return currentsize==totalsize;
    }
    void push(int element)
    {
        ///check if array is full or not
        if(isFull())
        {
            cout<<"queue is full"<<endl;
            return;
        }
        rear=(rear+1)%totalsize;
        arr[rear]=element;
        currentsize++;
    }
    void pop()
    {
        ///check if queue is empty
        if(isEmpty())
        {
            cout<<"queue is empty"<<endl;
            return;
        }
        front=(front+1)%totalsize;
        currentsize--;
    }

    int getFront()
    {
        if(isEmpty())
        {
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }
};
int main()
{
    queues qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.push(50);
    qu.push(60);

    cout<<qu.getFront()<<endl;
    qu.pop();
    cout<<qu.getFront()<<endl;
    qu.pop();
    cout<<qu.getFront()<<endl;
    qu.pop();
    cout<<qu.getFront()<<endl;
    qu.pop();
    cout<<qu.getFront()<<endl;
    qu.pop();
    cout<<qu.getFront()<<endl;
    qu.pop();




    return 0;
}
