#include <bits/stdc++.h>

using namespace std;
class node
{
public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

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

int Countnodes(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int nodes=1+Countnodes(root->left)+Countnodes(root->right);
    return nodes;
}
void printkthlevel(node* root,int k)
{
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    if(root->left)
    {
        printkthlevel(root->left,k-1);
    }
    if(root->right)
    {
        printkthlevel(root->right,k-1);
    }
}
int height(node*root)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return 0;
    }
    int h=1+max(height(root->left),height(root->right));

    return h;
}

///level printing in one traversal with queue
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

void leftView(node* root,int level,int &maxlevel)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return;
    }

    if(level>maxlevel)
    {
        maxlevel=level;
        cout<<"left node->";
        cout<<root->data<<", ";
    }
   if(root->left) leftView(root->left,level+1,maxlevel);
   else leftView(root->right,level+1,maxlevel);
}
void rightView(node* root,int level,int &maxlevel)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return;
    }
    if(level>maxlevel)
    {
        maxlevel=level;
        cout<<"right node->";
        cout<<root->data<<", ";
    }
   if(root->right) rightView(root->right,level+1,maxlevel);
   else rightView(root->left,level+1,maxlevel);

}

void leafnodes (node* root)
{
    if(root==NULL)
    {
        return;
    }

    if(root->left==NULL && root->right==NULL)
    {
       cout<<"leaf node->";
        cout<<root->data<<" ";
        return;
    }

    leafnodes(root->left);
    leafnodes(root->right);

}

void boundarynodes(node* root)
{
    cout<<root->data<<" ";
    int maxlevel=0;
    leftView(root,0,maxlevel);
    cout<<endl;
    maxlevel=0;
    rightView(root,0,maxlevel);
    cout<<endl;
    leafnodes(root);
    cout<<endl;
}


int main()
{
    node*root=buildtree();
    levelOrderWithNextLine(root);
    cout<<endl;
    cout<<endl;
    boundarynodes(root);






    return 0;
}
