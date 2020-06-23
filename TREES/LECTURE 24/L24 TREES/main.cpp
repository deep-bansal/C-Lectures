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
void preorderprint (node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<", ";
    preorderprint(root->left);
    preorderprint(root->right);
}
void Inorderprint (node*root)
{
    if(root==NULL)
    {
        return;
    }

    Inorderprint(root->left);
    cout<<root->data<<", ";
    Inorderprint(root->right);
}
void Postorderprint (node*root)
{
    if(root==NULL)
    {
        return;
    }

    Postorderprint(root->left);
    Postorderprint(root->right);
    cout<<root->data<<", ";
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
int Sumnodes(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int Sum=root->data+Sumnodes(root->left)+Sumnodes(root->right);
    return Sum;
}
int main()
{
    node*root=buildtree();
    print(root);
    cout<<endl;
    preorderprint(root);
    cout<<endl;
    Inorderprint(root);
    cout<<endl;
    Postorderprint(root);
    cout<<endl;
    cout<<Countnodes(root)<<endl;
    cout<<Sumnodes(root)<<endl;


    return 0;
}
