#include <iostream>

using namespace std;
class dynamicarr
{
    int* data;
    int nextidx;
    int capacity;
public:
    dynamicarr()
    {
        data=new int[5];
        nextidx=0;
        capacity=5;

    }

    dynamicarr(dynamicarr &d)
    {
        this->data =new int [d.capacity];

        for(int i=0;i<d.nextidx;i++)
        {
            this->data[i]=d.data[i];
        }
        this->nextidx=d.nextidx;
        this->capacity=d.capacity;
    }

    void add(int element)
    {
        if(nextidx==capacity)
        {
            int* newD =new int[2* capacity];
            for(int i=0;i<capacity;i++)///new array mei elements copy kr diye h
            {
                newD [i]=data[i];
            }
            delete []data;
            data= newD;
            capacity=capacity*2;
        }
        data[nextidx]=element;
        nextidx++;
    }
    int get (int i)
    {
        if(i<nextidx)
        {
            return data[i];
        }
        else
        {
            return -1;
        }
    }
    void addatidx(int i,int element)
    {
        if(i<nextidx)
        {
            data[i]=nextidx;
        }
        else if(i==nextidx)
        {
            add(element);
        }
        else
        {
            return;
        }
    }

    void print ()
    {
        for(int i=0;i<nextidx;i++)
        {
            cout<<data[i]<<" ";
        }
    }

};
int main()
{
    dynamicarr arr;
    arr.add(1);
    arr.add(2);
    arr.add(3);
    arr.add(4);
    arr.add(5);
    arr.add(6);
    arr.add(1);
    arr.add(2);
    arr.add(3);
    arr.add(4);
    arr.add(5);
    arr.add(6);

    cout<<arr.get(4)<<endl;
    arr.print();

    return 0;
}
