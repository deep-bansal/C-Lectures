#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node
{
public:
	string key;
	T value;
	node<T>* next;

	node(string k,T val)
	{
		key=k;
		value=val;
		next=NULL;
	}

	///destructor
	~node()
	{
		if(next!=NULL)
		{
			delete next;
		}
	}
};

template <typename T>
class hashMap
{
	node<T>** arr;
	int currSize;
	int totalSize;

	int hashFunction(string k)
	{
		int idx=0;
		int length=k.length();
		int multiplicationfactor=1;
		for(int i=0;i<length;i++)
		{
			int res=((k[length-i-1] % totalSize)*(multiplicationfactor % totalSize)) % totalSize;
			idx=((idx % totalSize)+(res % totalSize)) % totalSize;
			multiplicationfactor=((multiplicationfactor % totalSize)*(47 % totalSize))%totalSize;
		}
		return idx;
	}

	void rehash()
	{
		node<T>** oldArray=arr;

		int oldSize=totalSize;

		totalSize= 2 * totalSize;

		arr=new node<T>* [totalSize];

		currSize=0;

		for(int i=0;i<totalSize;i++)
		{
			arr[i]=NULL;
		}

		for(int i=0; i<oldSize; i++)
		{
			if(oldArray[i]!=NULL)
			{
				node<T>* temp=oldArray[i];
				while(temp!=NULL)
				{
					insert(temp->key,temp->value);
					temp=temp->next;
				}
			}
		}

		for(int i=0;i<oldSize;i++)
		{
			delete oldArray[i];
		}
		delete oldArray;

	}

public:

	hashMap(int defaultSize=7)
	{
		currSize=0;
		totalSize=defaultSize;
		arr=new node<T>* [totalSize];

		for(int i=0;i<totalSize;i++)
		{
			arr[i]=NULL;
		} 

	}
	void insert(string k,T value)
	{
		int idx=hashFunction(k);

		///insertion at head of linked list
		node<T>* newNode=new node<T>(k,value);
		newNode->next=arr[idx];
		arr[idx]=newNode;
		currSize++;

		float loadfactor= (float)currSize/totalSize;
		if(loadfactor>0.7)
		{
			rehash();
		}

	}

	T& operator [](string k)// value will be returned by reference
	{
		T* valueAdd=NULL;
		if(search(k)!=NULL) //keyfound 
		{
			valueAdd=search(k);
		}
		else
		{
			T garbageValue;

			insert(k,garbageValue);
			valueAdd=search(k);
		}
		//valueAdd= address of value
		return *valueAdd; // here we are dereferencing address and returning the key;

	}

	void print(){
		for (int i = 0; i < totalSize; ++i)
		{
		if(arr[i]!=NULL)	
			{
			cout<<i<<"------";			
			node<T>* temp = arr[i];
			while(temp != NULL){
				cout<<temp->key<<", "<<temp->value<<"     ";
				temp = temp->next;
			}
			
			cout<<endl;
			}
		}
	}

	T* search (string k) /// here we are returning address
	{
		int idx=hashFunction(k);
		node<T>* temp=arr[idx];
		while(temp!=NULL)
		{
			if(temp->key == k)
			{
				return &(temp->value); // by reference address return ho rha h
			}
			temp=temp->next;
		}
		return NULL;
	}

};

int main(int argc, char const *argv[])
{
	hashMap<int> hm(11);
	hm.insert("ABC", 10);
	hm.insert("DEF", 20);
	hm.insert("ghi",90);
	hm.insert("OPQ", 30);
	hm.insert("uio", 89);
	hm.print();
	cout<<endl;
	/*hm.insert("AbC", 10);
	hm.insert("DeF", 20);
	hm.insert("gHi",90);
	hm.insert("OpQ", 30);
	hm.insert("uIo", 89);
	hm.print();*/

	if(hm.search("ABC") != NULL){
		cout<<"key found"<<endl;
	}else{
		cout<<"key not found"<<endl;
	}
	if(hm.search("AFC") != NULL){
		cout<<"key found"<<endl;
	}else{
		cout<<"key not found"<<endl;
	}
	cout<<endl;

	//hm["ABC"]; //should return value for this key "ABC"
	hm["ABC"] = 90; // it should replace 10 by 90
	hm["AFKC"] = 1000; // it should add a new key "AFKC" in the hashmap 
	                   //and assign value 1000 to it
	hm.print();
	
	return 0;
}