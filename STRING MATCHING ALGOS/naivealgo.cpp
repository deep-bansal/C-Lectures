#include<bits/stdc++.h>
using namespace std;

void naiveAlgo(string str,string pat)
{
	for (int i = 0; i < str.length()-pat.length(); ++i)
	{
		int j;
		for (j=0; j < pat.size(); ++j)
		{
			if(str[i+j] != pat[j])
			{
				break;
			}
		}
		if(j == pat.size())
		{
			cout<<"pattern found at "<<i<<endl;
		}
	}

}
int main(int argc, char const *argv[])
{
	string str,pat;
	cin>>str>>pat;

	naiveAlgo(str,pat);
	return 0;
}