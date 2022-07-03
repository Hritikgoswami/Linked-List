#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node*next;
}*head,*tail;

node* create_new_node(int info)
{
    node* ptr=new node;
    ptr->data=info;
    ptr->next=NULL;
    return ptr;
}

void insert(node* newptr)
{
    if(!head)
    {
        head=tail=newptr;
        return;
    }
    tail->next=newptr;
    tail=tail->next;
}

void display_linked_list(node*head)
{
    if(!head)
    {
        cout<<"Empty list\n";
        return;
    }
    cout<<"List is\n";
    while(head)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
}

node* reverse_list(node* head)
{
    node* prev=NULL;
    node* curr=head;
    node* save;
    while(curr)
    {
        save=curr->next;
        curr->next=prev;
        prev=curr;
        curr=save;
    }
    head=prev;
    return head;
}

int main()
{
    int choice=1;
    int info;
    head=tail=NULL;
    while(choice==1)
    {
        cout<<"Enter node value:\n";
        cin>>info;
        node* newptr=create_new_node(info);
        insert(newptr);
        cout<<"Wanna enter more nodes? 1->YES 2->NO\n";
        cin>>choice;
    }
    display_linked_list(head);

    node* newptr=reverse_list(head);
    cout<<"\nReversed Linked List:\n";

    display_linked_list(newptr);
    return 0;

}