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
void mirror(node* root)
{
    if(root==NULL)
    {
        return;
    }

    swap(root->left,root->right);

    mirror(root->left);
    mirror(root->right);
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

void leftViewPrint(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	cout<<root->data<<", ";
	while (q.size() > 1) {
		node* front = q.front();
		if (front == NULL) {
			cout << endl;
			q.pop();
			cout<<q.front()->data<<", ";
			q.push(NULL);
		}
		else {
			if (front->left) {
				q.push(front->left);
			}
			if (front->right) {
				q.push(front->right);
			}
			q.pop();
		}
	}
}

void leftView(node* root,int level,int &maxlevel)
{
    if(root==NULL)
    {
        return;
    }
    if(level>maxlevel)
    {
        maxlevel=level;
        cout<<root->data<<", ";
    }
    leftView(root->left,level+1,maxlevel);
    leftView(root->right,level+1,maxlevel);
}
void rightView(node* root,int level,int &maxlevel)
{
    if(root==NULL)
    {
        return;
    }
    if(level>maxlevel)
    {
        maxlevel=level;
        cout<<root->data<<", ";
    }
    rightView(root->right,level+1,maxlevel);
    rightView(root->left,level+1,maxlevel);

}
class Pair
{
public:
    int height;
    bool isBalanced;
};

Pair isTreeBalanced(node* root)
{
    Pair P;
    if(root==NULL)
    {
        P.height=-1;
        P.isBalanced=true;
        return P;
    }
    
    Pair left= isTreeBalanced(root->left);
    Pair right=isTreeBalanced(root->right);

    P.height=max(left.height,right.height)+1;
    if(abs(left.height-right.height)<=1 && left.isBalanced && right.isBalanced)
    {
        P.isBalanced=true;
    }
    else
    {
        P.isBalanced=false;
    }
    return P;

}

node* buildheightbalancedtree(int* arr,int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid=start+((end-start)/2);
    node* root=new node(arr[mid]);
    root->left=buildheightbalancedtree(arr,start,mid-1);
    root->right=buildheightbalancedtree(arr,mid+1,end);
    return root;
}
int i=0;
node* buildtreebypreandin(int* pre,int* inorder,int start,int end)
{
    if(start>end)
    {
        return NULL;
    }

    node*root=new node (pre[i]);
    int idx=-1;
    for(int k=start;k<=end;k++)
    {
        if(inorder[k]==pre[i])
        {
            idx=k;
            break;
        }
    }
    i++;
    root->left=buildtreebypreandin(pre,inorder,start,idx-1);
    root->right=buildtreebypreandin(pre,inorder,idx+1,end);
    return root;
}

int j=8;
node* buildtreebypostandin(int* post,int* inorder,int start,int end)
{
    if(start>end)
    {
        return NULL;
    }

    node*root=new node (post[j]);
    int idx=-1;
    for(int k=start;k<=end;k++)
    {
        if(inorder[k]==post[j])
        {
            idx=k;
            break;
        }
    }
    j--;
    root->right=buildtreebypostandin(post,inorder,idx+1,end);
    root->left=buildtreebypostandin(post,inorder,start,idx-1);

    return root;
}

int main()
{
    node*root=buildtree();
    levelOrderWithNextLine(root);
    cout<<endl;
    cout<<endl;

  /**  mirror(root);
    levelOrderWithNextLine(root);
    cout<<endl;
    cout<<endl;

    leftViewPrint(root);
    cout<<endl;
    cout<<endl;

    int maxlevel=-1;
    leftView(root,0,maxlevel);
    cout<<endl;
    cout<<endl;

    maxlevel=-1;
    rightView(root,0,maxlevel);
    cout<<endl;
    cout<<endl;*/

    Pair ans=isTreeBalanced(root);
    if(ans.isBalanced)
    {
        cout<<"tree is balanced"<<endl;
    }
    else
    {
        cout<<"tree not balanced"<<endl;
    }

   int arr[9]={1,2,3,4,5,6,7,8,9};
    node*root1=buildheightbalancedtree(arr,0,8);
    levelOrderWithNextLine(root1);
    cout<<endl;
    cout<<endl;


    int pre[9]={1,2,3,4,5,6,7,8,9};
    int inorder[9]={3,2,5,4,6,1,7,8,9};
    node*root2=buildtreebypreandin(pre,inorder,0,8);
    levelOrderWithNextLine(root2);
    cout<<endl;
    cout<<endl;


    int post[9]={3,5,6,4,2,9,8,7,1};
    node*root3=buildtreebypostandin(post,inorder,0,8);
    levelOrderWithNextLine(root3);
    cout<<endl;
    cout<<endl;

  






    return 0;
}
