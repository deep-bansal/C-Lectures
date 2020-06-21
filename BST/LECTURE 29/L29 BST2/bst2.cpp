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

void levelOrderWithNextLine(node* root) {
	queue<node*> q;

	q.push(root);
	q.push(NULL);
	while (q.size() > 1) {
		node* front = q.front();
		if (front == NULL) {
			cout << endl;
			q.push(NULL);
		}
		else {
			cout << front->data << ", ";

			if (front->left) {
				q.push(front->left);
			}
			if (front->right) {
				q.push(front->right);
			}
		}
		q.pop();
	}

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

class LinkedList{
public:
	node* head;
	node*tail;
};

LinkedList bstToLL(node* root)
{
	LinkedList ans;
	if(root==NULL)
	{
		ans.head=NULL;
		ans.tail=NULL;
		return ans;
	}
	else if(root->right==NULL and root->left==NULL)
	{
		ans.head=ans.tail=root;
		return ans;
	}
    else if(root->left!=NULL and root->right==NULL)
    {
    	LinkedList leftLL=bstToLL(root->left);
    	leftLL.tail->right=root;
    	ans.head=leftLL.head;
    	ans.tail=root;
    	return ans;
    }
    else if(root->left==NULL and root->right!=NULL)
    {
    	LinkedList rightLL=bstToLL(root->right);
    	root->right=rightLL.head;
    	ans.head=root;
    	ans.tail=rightLL.tail;
    	return ans;
    }
    else
    {
    	LinkedList leftLL=bstToLL(root->left);
    	LinkedList rightLL=bstToLL(root->right);
    	leftLL.tail->right=root;
    	root->right=rightLL.head;
    	ans.head=leftLL.head;
    	ans.tail=rightLL.tail;
    	return ans;
    }



}
node* pred=NULL;
node* A=NULL;
node* B=NULL;

void swappedTree(node* root)
{
	if(root==NULL)
	{
		return;
	}
	///inorder traversal
	swappedTree(root->left);
	node* curr=root;
		if(pred!=NULL and curr->data<pred->data)
		{
			B=curr;
			if(A==NULL)
			{
				A=pred;
			}
			else
			{
				return;
			}
		}
	pred=curr;
	swappedTree(root->right);	

}

void swap(node*  a,node* b)
{
	node* temp= new node(a->data);
	a->data=b->data;
	b->data=temp->data;
	delete(temp);

}

void recoverActualBST(node* root)
{
	if(root==NULL)
	{
		return;
	}
	swappedTree(root);
	swap(A,B);
}

node* inordersuccesor(node* root,int key)
{
	node* target=search(root,key);
	if(target==NULL)
	{
		return NULL;
	}
	else
	{
		//target found
		if(target->right!=NULL)
		{
			node* temp=target->right;
			while(temp->left!=NULL)
			{
				temp=temp->left;
			}
			return temp;
		}
		else
		{
			///target lies in ancestor
			node* ancestor=NULL;
			node* successor=root;
			while(successor!=target)
			{
				if(successor->data>target->data)
				{
					ancestor=successor;
					successor=successor->left;
				}
				else
				{
					successor=successor->right;
				}
			}
			return ancestor;
		}

	}
}

int countBSTs (int n)
{
	if(n==0)
	{
		return 1;
	}

	int totalBSTs=0;
	for(int i=1;i<=n;i++)
	{
		totalBSTs+= countBSTs(i-1)*countBSTs(n-i);
	}
	return totalBSTs;
}


int main(int argc, char const *argv[])
{
	node* root=buildbst();
	levelOrderWithNextLine(root);
	cout<<endl<<endl;

	/**LinkedList ll = bstToLL(root);
	 node* l = ll.head;
	 while (l) {
	 	cout << l->data << ", ";
	 	l = l->right;
	 }
	 cout << endl;

	node* root2=buildtree();
	levelOrderWithNextLine(root2);
	cout<<endl<<endl;

	recoverActualBST(root2);
	levelOrderWithNextLine(root2);
	cout<<endl<<endl;**/

	node* successornode=inordersuccesor(root,9);
	cout<<successornode->data<<endl;

	///cout<<countBSTs(3)<<endl;





	
	return 0;
}