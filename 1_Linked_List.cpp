#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* next;
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
    }
    tail->next=newptr;
    tail=tail->next;
}
void display_linked_list(node* head)
{
    if(!head)
    {
        cout<<"Empty Linked List";
        return;
    }
    cout<<"Created New Linked List is \n";
    while(head)
    {
        cout<<head->data<<"->";
        head=head->next;
    }

}
node* find_mid(node* head)
{
    if(!head) return NULL;
    node* small,*large;
    small=large=head;
    while(large and large->next)
    {
        small=small->next;
        large=large->next;
        if(large)
            large=large->next;
    }
    return small;
}

int main()
{
    int choice=1;
    int info;
    head=tail=NULL;

    while(choice==1)
    {
        cout<<"Enter node value\n";
        cin>>info;
        node *newptr=create_new_node(info);
        insert(newptr);
        cout<<"Wanna enter more node? 1->Yes 2->No\n";
        cin>>choice;

    }
    display_linked_list(head);
    node*mid =find_mid(head);
    if(!mid)
    {
        cout<<"List Is Empty";
    }
    else{
        cout<<"Mid Element Is "<<mid->data;
    }
    return 0;

}