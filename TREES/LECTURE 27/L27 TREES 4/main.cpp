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
    if(root->left==NULL && root->right==NULL)
    {
        P.height=0;
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
void printnodesinsubtree(node* root,int k)
{
    if(root == NULL || k<0)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<", ";
        return;
    }
    printnodesinsubtree(root->left,k-1);
    printnodesinsubtree(root->right,k-1);
}
int nodesatdistk(node* root,int target,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->data==target)
    {
        printnodesinsubtree(root,k);
        return 0;
    }
    int dLeft= nodesatdistk(root->left,target,k);
    if(dLeft!=-1)
    {
        if(dLeft+1==k)
        {
            cout<<root->data<<", ";
        }
        else
        {
            printnodesinsubtree(root->right,k-dLeft-2);
        }
        return dLeft+1;
    }
    int dRight= nodesatdistk(root->right,target,k);
    if(dRight!=-1)
    {
        if(dRight+1==k)
        {
            cout<<root->data<<", ";
        }
        else
        {
            printnodesinsubtree(root->left,k-dRight-2);
        }
        return dRight+1;
    }
    return -1;

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

bool identical(node* A,node*B)
{
    if(A==NULL && B==NULL)
    {
        return true;
    }
    if(A!=NULL && B!=NULL)
    {
        bool leftsubtree=identical(A->left,B->left);
        bool rightsubtree=identical(A->right,B->right);
        if(A->data==B->data && leftsubtree && rightsubtree)
        {
            return true;
        }

    }
    return false;
}
bool structureidentical(node* A,node*B)
{
    if(A==NULL && B==NULL)
    {
        return true;
    }
    if(A!=NULL && B!=NULL)
    {
        bool leftsubtree=structureidentical(A->left,B->left);
        bool rightsubtree=structureidentical(A->right,B->right);
        return leftsubtree and rightsubtree;
    }
    return false;
}

node* lca(node*root,int A,int B)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==A or root->data==B)
    {
        return root;
    }
    node*leftlca=lca(root->left,A,B);
    node*rightlca=lca(root->right,A,B);

    if(leftlca !=NULL && rightlca!=NULL)
    {
        return root;
    }
    else if(leftlca!=NULL)
    {
        return leftlca;
    }
    else
    {
        return rightlca;
    }
}

int minDepthofleaf(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return 0;
    }
    int leftMin=0,rightMin=0;
    if(root->left)
    {
        leftMin=minDepthofleaf(root->left);
    }
    if(root->right)
    {
        rightMin=minDepthofleaf(root->right);
    }
    return min(leftMin,rightMin)+1;
}


int main()
{
    node*root=buildtree();
    levelOrderWithNextLine(root);
    cout<<endl<<endl;

    /**node* root2=buildtree();
    levelOrderWithNextLine(root2);
    cout<<endl<<endl;
    if(identical(root,root2))
    {
        cout<<"Trees are identical"<<endl;
    }
    else
    {
        cout<<"Trees are not identical"<<endl;
    }*/

    nodesatdistk(root,4,1);
    cout<<endl<<endl;

    int ans=minDepthofleaf(root);
    cout<<ans<<endl<<endl;

    node*  ans2=lca(root,4,5);
    cout<<ans2->data<<endl;







    return 0;
}
