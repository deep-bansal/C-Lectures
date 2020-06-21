#include<bits/stdc++.h>
using namespace std;

int catalanConcept(int n)
{
	if(n == 0 || n == 1)
	{
		return 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans += catalanConcept(i-1) * catalanConcept(n-i);
	}
	return ans;

}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<catalanConcept(n)<<endl;
	return 0;
}