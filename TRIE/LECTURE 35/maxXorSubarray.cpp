#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
class node
{

public:
	int data;
	node* zero;
	node* one;
	int preXor;
	node (int d)

	{
		data = d;
		zero = NULL;
		one = NULL;
		preXor = 0;
	}


};

class trie
{
public:
	node* root;

	trie()
	{
		root = new node('\0');
	}

	void insert (int num)
	{
		node* temp = root;
		for (int i = 31 ; i >= 0 ; i-- )
		{
			int currBit = (num >> i ) & 1;
			//num = 0101'0'10101 >> i => (0101'0')&1 =>value of ith bit (i.e. 0 or 1)
			if (currBit) // currBit == 1
			{
				if (temp->one == NULL)
				{
					node* bit = new node(1);
					temp->one = bit;
				}
				temp = temp->one;
			}
			else
			{
				// currbit == 0
				if (temp->zero == NULL)
				{
					node* bit = new node(0);
					temp->zero = bit;
				}
				temp = temp->zero;
			}
		}
		temp -> preXor = num;
	}

	int xorQuery(int num)
	{
		node* temp = root;

		for (int k = 31 ; k >= 0 ; k--)
		{

			int currbit = (num >> k) & 1;
			if (currbit)
			{
				if (temp->zero)
				{
					temp = temp->zero;
				}
				else
				{
					temp = temp->one;
				}
			}
			else {
				if (temp->one) {
					temp = temp->one;
				}
				else {
					temp = temp->zero;
				}
			}
		}

		return num xor temp->preXor;

	}




};

int main(int argc, char const *argv[])
{
	trie t;
	int n = 6;
	int arr[10] = {8, 1, 2, 12, 7, 6};
	int PrefixXor = 0;
	int maxSubarrayXor = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		PrefixXor = PrefixXor xor arr[i];
		t.insert(PrefixXor);
		maxSubarrayXor = max(maxSubarrayXor, t.xorQuery(PrefixXor));
	}
	cout << maxSubarrayXor << endl;

}