#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;
}*head;
node* create_new_node(int info)
{
    node*ptr=new node;
    ptr->data=info;
    ptr->next=NULL;
    return ptr;
}

node* find_junction(node* head)
{
    node *fast,*slow;
    fast=slow=head;
    while(fast and fast->next)
    {
        slow=slow->next;
        fast=fast->next;
        if(fast)
        {
            fast=fast->next;
        }
        if(slow==fast)
        {
            slow=head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;

        }
    }
    return NULL;

}
void print_cycle(node* start)
{
    node* ptr=start;
    do
    {
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }while(ptr!=start);
    return;

}

int main()
{
    head=NULL;
    head=create_new_node(1);
    head->next=create_new_node(2);
    head->next->next=create_new_node(3);
    head->next->next->next=create_new_node(4);
    head->next->next->next->next=create_new_node(5);
    head->next->next->next->next->next=create_new_node(6);
    head->next->next->next->next->next->next=head->next->next;

    node* start=find_junction(head);

    if(!start)
    cout<<"NO cycle";
    else
    {
        cout<<"cycle starts at "<<start->data<<"\n";
        cout<<"cycle is ";
        print_cycle(start);

    }
    return 0;

    

}