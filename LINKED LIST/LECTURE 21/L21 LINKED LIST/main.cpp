#include <bits/stdc++.h>

using namespace std;
class node
{
public:
    int data;
    node*next;
    ///constructor
    node(int d)
    {
        data=d;
        next=NULL;
    }
};
void insertAtHead(node* &head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
        return;
    }
    node*temp=new node(data);
    temp->next=head;
    head=temp; /// new head is temp node now
    return;
}
int length(node*head)
{
    int len=0;
    while(head->next!=NULL)
    {
        len++;
        head=head->next;
    }
    return len;
}
void insertAtTail(node* &head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
        return;
    }
    node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    temp->next=new node(data);
    return;
}
void insertAtMiddle(node* &head,int data,int p)
{
    if(head==NULL || p==1)
    {
        insertAtHead(head,data);
    }
    else if(p>length(head))
    {
        insertAtTail(head,data);
    }
    else
    {
        int jump=1;
        node*temp=head;
        while(jump<p-1)
        {
            temp=temp->next;
            jump++;
        }
        node*n=new node(data);
        n->next=temp->next;
        temp->next=n;
    }
}
void printlist(node*head)
{
    while(head !=NULL)
    {
        cout<<head->data<<endl;
        head=head->next;
    }
}

int main()
{
    node*head=NULL;


	insertAtHead(head,5);

	insertAtTail(head,10);

	insertAtTail(head,15);

	insertAtHead(head,2);
	insertAtMiddle(head,6,2);



	cout<<length(head)<<endl;

	printlist(head);


    return 0;
}
