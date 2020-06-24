#include<bits/stdc++.h>
using namespace std;
#define INT_M 1005
int reset[INT_M] ={0};

void kmpPreProcess(string pat)
{

	int i = 0,j = -1;
	reset[0] =-1;
	while(i <pat.length())
	{
		while(j>= 0 and pat[i] != pat[j])
		{
			j = reset[j];
		}
		i++;j++;
		reset[i] = j;
	}
	for (int i = 0; i <= pat.length(); ++i)
	{
		cout<<reset[i]<<" ";
	}
	cout<<endl;
}
void kmpSearch(string str,string pat)
{
	kmpPreProcess(pat);
	int i = 0,j=0;
	while(i < str.size())
	{
		while( j>= 0 and str[i] != pat[j])
		{
			j = reset[j];
		}
		i++;
		j++;

		if(j == pat.size())
		{
			cout<<i-j<<endl;
			j = reset[j];
		}
	}
}
int main(int argc, char const *argv[])
{
	string str,pat;
	cin>>str>>pat;
	kmpSearch(str,pat);
	
	return 0;
}