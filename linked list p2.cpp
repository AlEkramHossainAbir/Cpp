#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef struct myList{
    int data;
    struct myList *next;
}node;
void display(node *s)
{
    while(s->next!=NULL)
    {
        cout<<s->next->data<<endl;
        s=s->next;
    }
}
void search(node *s,int search_data)
{
    int count =0;
    while(s->next!=NULL)
    {
        if(s->next->data==search_data)
        {
            count++;
        }
        s=s->next;

    }
    cout<<search_data<<" count is "<<count<<endl;
}
void delete_node(node *s,int data)
{
    while(s->next!=NULL)
    {
        if(s->next->data==data)
        {
            s->next = s->next->next;
            break;
        }
        s=s->next;
    }
}
void insert(node *s,int data)
{
    while(s->next!=NULL)
    {
        s=s->next;
    }
    s->next=(node*) malloc(sizeof(node));
    s->next->data = data;
    s->next->next=NULL;
}

int main()
{
    node *first = (node*) malloc(sizeof(node));
    first->next=NULL;
    insert(first,1);
    insert(first,2);
    insert(first,3);
    insert(first,4);
    display(first);
    delete_node(first,3);
    display(first);
    search(first,2);



}
