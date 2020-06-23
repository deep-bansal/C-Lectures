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

void print (node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<", ";
    print(root->left);
    print(root->right);
}
void printAllLevels(node* root)
{
    int levels=height(root);
    for(int i=0;i<=levels;i++)
    {
        printkthlevel(root,i);
        cout<<endl;
    }
}
int diameter(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int owndiameter=height(root->left)+height(root->right)+2;
    int leftdiameter=diameter(root->left);
    int rightdiameter=diameter(root->right);
    return max(owndiameter,max(leftdiameter,rightdiameter));
}
///level printing in one traversal with queue

 void levelOrder(node* root)
 {
	queue<node*> q;
	q.push(root);

	while (!q.empty()) {
		node* front = q.front();
		cout << front->data << ", ";
		q.pop();
		if (front->left) {
			q.push(front->left);
		}
		if (front->right) {
			q.push(front->right);
		}
		
	}
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
class Pair{
public:
    int height;
    int diameter;


};
Pair diameterOpt(node* root)
{
    Pair P;
    if(root==NULL)
    {
       P.height=-1;
       P.diameter=0;
       return P;
    }
    if(root->right==NULL && root->left==NULL)
    {
        P.height=0;
        P.diameter=0;
        return P;
    }
    Pair left=diameterOpt(root->left);
    Pair right=diameterOpt(root->right);

    P.height=max(left.height,right.height)+1;
    int owndiameter=left.height+right.height+2;
    P.diameter=max(left.diameter,max(right.diameter,owndiameter));

    return P;
}
int replacewithDecSum(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return root->data;
    }

    int leftSum=replacewithDecSum(root->left);
    int rightSum=replacewithDecSum(root->right);

    int temp=root->data;
    root->data=leftSum+rightSum;

    return temp+root->data;
}

int main()
{
    node*root=buildtree();
    print(root);
    cout<<endl;
    cout<<height(root)<<endl;
    printkthlevel(root,2);
    cout<<endl;
    printAllLevels(root);
    cout<<endl;
    levelOrder(root);
    cout<<endl;
    levelOrderWithNextLine(root);
    cout<<endl;
    cout<<diameter(root)<<endl;
    Pair ans=diameterOpt(root);
    cout<<ans.diameter<<endl;
    replacewithDecSum(root);
    levelOrderWithNextLine(root);



    return 0;
}
