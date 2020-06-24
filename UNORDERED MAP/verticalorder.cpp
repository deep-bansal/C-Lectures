#include <bits/stdc++.h>
#include <unordered_map>
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

void verticalorderprint(node* root,int d,map<int,vector<int> > & mp)
{
    if(root==NULL)
    {
        return;
    }
    mp[d].push_back(root->data);
    verticalorderprint(root->left,d-1,mp);
    verticalorderprint(root->right,d+1,mp);
}

int main(int argc, char const *argv[])
{
    node * root= buildtree ();

    levelOrderWithNextLine(root);
    cout<<endl;

    map<int,vector<int> >mp;
    int d=0;
    verticalorderprint(root,d,mp);

    for(auto it:mp)
    {
        for(auto x: it.second)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}