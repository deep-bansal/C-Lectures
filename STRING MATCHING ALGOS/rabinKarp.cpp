#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define prime 119

ll createHashVal(string str,int n)
{
	ll result = 0;
	for (int i = 0; i < n; ++i)
	{
		result += (ll)(str[i]* (ll)pow(prime,i));
	}
	return result;
}

ll recalcHashVal(string str,int oldIndex,int newIndex,ll oldHash,int patLength)
{
	ll newHash = oldHash - str[oldIndex];
	newHash/= prime;
	newHash+= (ll) (str[newIndex]*(ll)(pow(prime,patLength-1)));

	return newHash;
}

bool checkEqual(string str1,string str2,int start1,int end1,int start2,int end2)
{
	if(end1- start1 != end2-start2)
	{
		return false;
	}
	while(start1<= end1 and start2<=end2)
	{
		if(str1[start1]!= str2[start2])
		{
			return false;
		}
		start1++;start2++;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	string str,pat;
	cin>>str>>pat;
	ll patHash = createHashVal(pat,pat.length());
	ll strHash = createHashVal(str,pat.length());

	for (int i = 0; i <= str.length() - pat.length(); ++i)
	{
    
		if(patHash == strHash and checkEqual(str,pat,i,i+pat.length()-1,0,pat.length()-1))
		{
			cout<<i<<endl;
		}
		if(i < str.length() - pat.length())
		{
			strHash = recalcHashVal(str,i,i+pat.length(),strHash,pat.length());
		}
        	
	}
    return 0;
	

}