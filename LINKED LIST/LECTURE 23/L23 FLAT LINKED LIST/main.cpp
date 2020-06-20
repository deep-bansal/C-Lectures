#include <iostream>

using namespace std;
class node
{
public:
    int data;
    node* down;
    node* right;
    node(int d)
    {
        data=d;
        right=NULL;
        down=NULL;
    }
};
void insertAtDown(node* &head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
        return;
    }
    node*temp=head;
    while(temp->down!=NULL)
    {
        temp=temp->down;

    }
    temp->down=new node(data);
    return;
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
    if(a->data<=b->data)
    {
        c=a;
        c->down=merge(a->down,b);
    }
    else
    {
        c=b;
        c->down=merge(a,b->down);
    }
    return c;

}
node* flatlinkedlist(node*head)
{
    if(head==NULL || head->right==NULL)
    {
        return head;
    }
    node*c;
    c=merge(head,flatlinkedlist(head->right));\
    return c;
}

void printlist(node*head)
{
    while(head !=NULL)
    {
        cout<<head->data<<" ";
        head=head->down;
    }
    cout<<endl;
}

int main()
{
    node* head = NULL;
	insertAtDown(head, 3);
	insertAtDown(head, 9);
	insertAtDown(head, 10);
	insertAtDown(head, 15);
	insertAtDown(head->right, 4);
	insertAtDown(head->right, 14);
	insertAtDown(head->right, 20);
	insertAtDown(head->right, 25);
	insertAtDown(head->right, 35);
	insertAtDown(head->right->right, 1);
	insertAtDown(head->right->right, 10);
	insertAtDown(head->right->right, 12);
	head = flatlinkedlist(head);
	printlist(head);

    return 0;
}
