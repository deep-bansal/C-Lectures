#include <bits/stdc++.h>

using namespace std;
char* mystrtok(char str[],char delim)
{
    ///static variable
    static char* input=NULL;
    if(str!=NULL)
    {
        input=str;
    }
    if(input==NULL)
    {
        return NULL;
    }
    char* output=new char[strlen(input)+1];
    ///+1 for null character at end
    ///return a word as dynamically allocated word array from my function
    ///read the word from input and store it in output and return word till delimiter
    int i;
    for(i=0;input[i]!='\0';i++)
    {
        if(input[i]!=delim)
        {
            output[i]=input[i];
        }
        else
        {
            output[i]='\0';
            input=input+i+1;
            return output;
        }
    }
    output[i]='\0';
    input=NULL;
    return output;
}

int main()
{
    char str[]="hi, I am teaching about strtok in ,c++";
    char *ptr;
    ptr = mystrtok(str,' ');

    while(ptr != NULL)
    {
        cout<<ptr<<endl;
        ptr=mystrtok(NULL,' ');
    }
    return 0;
}
