#include<bits/stdc++.h>
using namespace std;
class node
{
public:
	int data;
	node*left;
	node*right;

	node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};

node* insert(node* root,int d)
{
	if(root==NULL)
	{
		root=new node(d);
		return root;
	}
	if(d<=root->data)
	{
		root->left=insert(root->left,d);
	}
	else
	{
		root->right=insert(root->right,d);
	}
	return root;
}

node* buildbst()
{
	node* root=NULL;
	int d;
	cin>>d;
	while(d!=-1)
	{
		root=insert(root,d);
		cin>>d;
	}
	return root;
}

void print(node* root)
{
	if(root==NULL)
	{
		return;
	}	
	print(root->left);
	cout<<root->data<<" ";
	print(root->right);
}
node* search(node* root,int d)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->data==d)
	{
		return root;
	}
	else if(root->data > d)
	{
		return search(root->left,d);
	}
	else
	{
		return search(root->right,d);
	}
	
	return NULL;
}
node* buildtree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node* root=new node(d);
    root->left=buildtree();
    root->right=buildtree();

    return root;
}

node* deleteinBST(node*root,int key)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(key<(root->data))
	{
		deleteinBST(root->left,key);
	}
	else if(key>(root->data))
	{
		deleteinBST(root->right,key);
	}
	else
	{
		//key found
		if(root->left==NULL && root->right==NULL)
		{
			delete(root);
			return NULL;
		}
		else if(root->left!=NULL && root->right==NULL)
		{
			node*temp=root->left;			
			delete root;
			return temp;

		}
		else if(root->left==NULL && root->right!=NULL)
		{
			node*temp=root->right;			
			delete root;
			return temp;
		}
		else
		{
			///replace with left subtree max
			node*temp=root->left;
			while(temp->right!=NULL)
			{
				temp=temp->right;
			}
			root->data=temp->data;
			root->left=deleteinBST(root->left,root->data);
			return root;
		}
	}
	return root;
}

bool isBST(node* root,int maximum,int minimum)
{
	if(root==NULL)
	{
		return true;
	}
	
	if(root->data>=minimum and root->data < maximum and
		isBST(root->left,root->data,minimum) and isBST(root->right,maximum,root->data))
	{
		return true;
	}
	return false;
}

class nodeHelper
{
public:
	bool isBST;
	int maximum;
	int minimum;
	int size;
	nodeHelper(){
		isBST = true;
		maximum = INT_MIN;
		minimum = INT_MAX;
		size = 0;
	}
	

	};

nodeHelper largestBST(node* root)
{
	if(root==NULL)
	{
		return nodeHelper();
	}

	nodeHelper lefttree=largestBST(root->left);
	nodeHelper righttree=largestBST(root->right);

	nodeHelper curr;
	if(lefttree.maximum<=root->data && righttree.minimum>root->data &&
		lefttree.isBST==true && righttree.isBST==true)
	{
		curr.isBST=true;
		curr.maximum=max(root->data,righttree.maximum);
		curr.minimum=min(root->data,lefttree.minimum);
		curr.size= lefttree.size+righttree.size+1;
	}
	else
	{
		curr.isBST=false;
		curr.size=max(lefttree.size,righttree.size);
	}
	return curr;
}

node* min(node* root) {
	if (root == NULL) {
		return NULL;
	}

	if (root->left == NULL) { //leftmost node found
		return root;
	}

	return min(root->left);

}

node* max(node* root) {
	if (root == NULL) {
		return NULL;
	}

	if (root->right == NULL) { //rightmost node found
		return root;
	}

	return max(root->right);
}


int main(int argc, char const *argv[])
{
	/*node* root=buildbst();
	print(root);
	cout<<endl<<endl;

	node*searchans=search(root,5);
	if(searchans!=NULL)
	{
	   cout<<searchans->data<<endl;	
	}	

	node* delans= deleteinBST(root,15);
	print(delans);
	cout<<endl;

	node* isbst =buildtree();
	if(isBST(isbst,INT_MAX,INT_MIN)==true)
	{
		cout<<"yes it is BST"<<endl;
	}
	else
	{
		cout<<"no it is not bst"<<endl;
	}*/

	node* largeBST=buildtree();
	nodeHelper anss=largestBST(largeBST);
	cout<<anss.size<<endl;



	
	return 0;
}