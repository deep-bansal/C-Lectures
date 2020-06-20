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
void delAtHead(node* &head)
{
    if(head==NULL)
    {
        return;
    }
    node* temp=head;
    head=head->next;
    delete temp;
    return;

}
void delAtTail(node* &head)
{
    if(head==NULL || head->next==NULL)
    {
        delAtHead(head);
        return;
    }
    node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return;
}
void delAtMiddle(node* &head,int p)
{
    if(p==1 || head==NULL || head->next==NULL)
    {
        delAtHead(head);
        return;
    }
    else if(p>=length(head))
    {
        delAtTail(head);
        return;
    }
    int jump=1;
    node* temp=head;
    while(jump<p-1)
    {
        jump++;
        temp=temp->next;
    }
    node* todel=temp->next;
    temp->next=temp->next->next;
    delete todel;
    return;
}
bool searchiterative(node* head,int key)
{
    while(head!=NULL)
    {
        if(head->data==key)
        {
            return true;
        }
        head=head->next;
    }
    return false;
}
bool searchrecursive(node *head,int key)
{
    if(head==NULL)
    {
        return false;
    }
    if(head->data==key)
    {
        return true;
    }
    return searchrecursive(head->next,key);
}
void buildLinkedlist (node* &head)
{
    int d;
    cin>>d;
    while(d !=-1)
    {
        insertAtTail(head,d);
        cin>>d;
    }
    return;

}
node* mid(node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node*slow=head;
    node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
void kthfromlast(node*head,int k)
{
    node*slow=head;
    node*fast=head;
    int count=0;
    if (head!=NULL)
    {
        while(count<k)
        {
            if(fast==NULL)
            {
                cout<<k<<"greater than no of nodes present"<<endl;
                return;
            }
            fast=fast->next;
            count++;
        }
        while(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
         cout<<k<<"th node from last is"<<slow->data<<endl;
    }


}
void reverseLL(node* &head)
{
    node* prev=NULL;
    node* curr=head;
    node* nextnode;

        while(curr!=NULL)
        {
            nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        head=prev;

}
node* reverseLLrec( node * head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node* smallhead=reverseLLrec(head->next);
    node* current=head;
    current->next->next=current;
    current->next=NULL;
    return smallhead;

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
        c->next=merge(a->next,b);
    }
    else
    {
        c=b;
        c->next=merge(a,b->next);
    }
    return c;

}
node* mergesort(node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node* midnode=mid(head);
    node*a=head; ///left linked list
    node*b=midnode->next; ///right linked list

    midnode->next=NULL;
    a=mergesort(a);
    b=mergesort(b);
    node*c=merge(a,b);
    return c;

}

void printlist(node*head)
{
    while(head !=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

istream& operator >> (istream &is,node* &head)
{
    buildLinkedlist(head);
    return is;
}
ostream& operator << (ostream& os,node* &head)
{
    printlist(head);
    return os;
}

int main()
{
    node*head=NULL;

	insertAtHead(head,5);
	cout<<length(head)<<endl;
	insertAtTail(head,10);
	insertAtTail(head,15);
	insertAtHead(head,2);
	insertAtMiddle(head,6,2);
	insertAtTail(head,17);
	/**cout<<searchiterative(head,100)<<endl;
	cout<<searchrecursive(head,100)<<endl;
	cout<<length(head)<<endl;**/


	printlist(head);
	/**reverseLL(head);
	printlist(head)*/

	head=reverseLLrec(head);
	printlist(head);
	kthfromlast(head,3);
	cout<<endl;
	cout<<length(head);
	node*head1=NULL;
	node*head2=NULL;
	///cin>>head1>>head2;
	///cout<<head1<<endl<<head2<<endl;
	head=merge(head1,head2);
	cout<<head<<endl;
	node* head3=NULL;
	cin>>head3;
	cout<<head3<<endl;
	head3=mergesort(head3);
	cout<<head3<<endl;



    return 0;
}
