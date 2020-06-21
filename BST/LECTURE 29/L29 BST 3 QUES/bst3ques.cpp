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
node* merge(node*a,node*b)
{
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }
    node*c;
    if(a->data < b->data)
    {
        c=a;
        c->right=merge(a->right,b);
    }
    else if(a->data > b->data)
    {
        c=b;
        c->right=merge(a,b->right);
    }
    else
    {
    	c=a;
    	c->right=merge(a->right,b->right);
    }
    return c;

}

node* inordorpredecessor(node* root,int key)
{
	node* target=search(root,key);
	if(target==NULL)
	{
		return NULL;
	}
	else
	{
		//target found
		if(target->left!=NULL)
		{
			node* temp=target->left;
			while(temp->right!=NULL)
			{
				temp=temp->right;
			}
			return temp;
		}
		else
		{
			///predecessor lies in ancestor
			node* ancestor=NULL;
			node* predecessor=root;
			while(predecessor!=target)
			{
				if(predecessor->data < target->data)
				{
					ancestor=predecessor;
					predecessor=predecessor->right;
				}
				else
				{
					predecessor=predecessor->left;
				}
			}
			return ancestor;
		}

	}
}

int main(int argc, char const *argv[])
{
	/*node* root1=buildbst();
	node* root2=buildbst();

	LinkedList LL1=bstToLL(root1);
	node* LLL1=LL1.head;
	LinkedList LL2=bstToLL(root2);
	node* LLL2=LL2.head;
	node* finalmerge=merge(LLL1,LLL2);
	while(finalmerge!=NULL)
	{
		cout<<finalmerge->data<<" ";
		finalmerge=finalmerge->right;
	}*/

	node* root=buildbst();
	node* predecessornode=inordorpredecessor(root,11);
	cout<<predecessornode->data<<endl;

	





	
	return 0;
}