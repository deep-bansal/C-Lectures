#include <iostream>

using namespace std;
class polynomial
{

public:
    int capacity;
    int* degCoeff;

    polynomial()
    {
       capacity=6;
       degCoeff=new int[capacity]();

    }

   void  setcoefficient(int degree,int coeff)
    {
           if(degree>=capacity)
           {
               int* newdegCoeff=new int[2*capacity];

               for(int i=0;i<capacity;i++)
               {
                   newdegCoeff[i]=degCoeff[i];
               }
               delete []degCoeff;
               degCoeff=newdegCoeff;
               capacity=(2*capacity);
           }
           degCoeff[degree]=coeff;
    }

    polynomial operator +(const polynomial &p1)
    {
        polynomial result;
        if(this->capacity > p1.capacity)
        {
            for(int i=0;i<this->capacity;i++)
            {
                result.degCoeff[i]=this->degCoeff[i];
            }
            for(int i=0;i<p1.capacity;i++)
            {
                result.degCoeff[i]+=p1.degCoeff[i];
            }
            return result;
        }
        else
        {
            for(int i=0;i<p1.capacity;i++)
            {
                result.degCoeff[i]=p1.degCoeff[i];
            }
            for(int i=0;i<this->capacity;i++)
            {
                result.degCoeff[i]+=this->degCoeff[i];
            }
            return result;
        }

    }
     polynomial operator -(const polynomial &p1)
    {
        polynomial result;

            for(int i=0;i<this->capacity;i++)
            {
                result.degCoeff[i]=this->degCoeff[i];
            }
            for(int i=0;i<p1.capacity;i++)
            {
                result.degCoeff[i]-=p1.degCoeff[i];
            }
            return result;
    }
    polynomial operator* (const polynomial &p2)
    {
        polynomial result;
        for(int i=0;i<this->capacity;i++)
        {
            for(int j=0;j<p2.capacity;j++)
            {
                int coeffinal= (this->degCoeff[i])*(p2.degCoeff[j]);
                int degfinal= i+j;

                if(degfinal<result.capacity)
                {
                    result.degCoeff[degfinal]+=coeffinal;
                }
                else
                {
                    result.setcoefficient(degfinal,coeffinal);
                }
            }

        }
        return result;

    }
    ///copy constructor
    polynomial(polynomial &p1)
    {
        int capacity1=p1.capacity;
        degCoeff=new int[capacity1];
        for(int i=0;i<p1.capacity;i++)
        {
            degCoeff[i]=p1.degCoeff[i];
        }
    }

    void print ()
    {
        for(int i=0;i<capacity;i++)
        {
            if(degCoeff[i]!=0)
            {
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
    }

};

int main()
{
    int count1,count2,choice;
    cin>>count1;
    int* degree1=new int[count1];
    int* coeff1=new int [count1];
    for(int i=0;i<count1;i++)
    {
        cin>>degree1[i];
    }
    for(int i=0;i<count1;i++)
    {
        cin>>coeff1[i];
    }

    polynomial first;
    for(int i=0;i<count1;i++)
    {
        first.setcoefficient(degree1[i],coeff1[i]);
    }

    cin>>count2;
    int* degree2=new int[count2];
    int* coeff2=new int [count2];
    for(int i=0;i<count2;i++)
    {
        cin>>degree2[i];
    }
    for(int i=0;i<count2;i++)
    {
        cin>>coeff2[i];
    }
    polynomial second;
    for(int i=0;i<count2;i++)
    {
        second.setcoefficient(degree2[i],coeff2[i]);
    }
    cout<<"polynomial 1st=";
    first.print();
    cout<<endl;
    cout<<"polynomial 2st=";
    second.print();
    cout<<endl;

    cin>>choice;
    polynomial result;

   switch(choice)
    {
        ///Add
    case 1:
        result=first+second;
        result.print();
        break;

        ///Subtract
    case 2:
        result=first-second;
        result.print();
        break;

           ///Multiply
    case 3:
        result=first*second;
        result.print();
        break;

        ///copy constructor
    case 4:
        {
           polynomial third(first);
           cout<<"Polynomial 3rd";
           third.print();
           cout<<endl;
        /**   if(third.degCoeff==first.degCoeff)
          {
            cout<<"false"<<endl;
          }
           else
          {
            cout<<"true"<<endl;
          }**/
           break;
        }

        ///copy assignment operator
    case 5:
       {
            polynomial fourth;
            fourth=first;
            if(fourth.degCoeff==first.degCoeff)
           {
            cout<<"false"<<endl;
           }
            else
           {
            cout<<"true"<<endl;
           }
            break;
       }

    }

return 0;
}
