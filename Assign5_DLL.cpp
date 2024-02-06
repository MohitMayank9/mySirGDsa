#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class DLL
{
    private:
        node *start;
    public:
        DLL();
        void insertAtStart(int);
        void insertAtLast(int);
        node* search(int);
        void insertAfter(node *,int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(int);
        ~DLL();
};
DLL::DLL()
{
    start=NULL;
}
void DLL::insertAtStart(int data)
{
    node *n;
    n=new node;
    n->prev=NULL;
    n->item=data;
    n->next=start;
    if(start)
        start->prev=n;
    start=n;
}
void DLL::insertAtLast(int data)
{
    node *n,*t;
    n=new node;
    n->item=data;
    n->next=NULL;
    if(start==NULL)
    {
        n->prev=NULL;
        start=n;
    }
    else
    {
        t=start;
        while(t->next!=NULL)
            t=t->next;
        n->prev=t;
        t->next=n;
    }
}
node* DLL::search(int data)
{
    node *t;
    t=start;
    while(t)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    return NULL;
}
void DLL::insertAfter(node *temp,int data)
{
    node *n;
    if(temp)
    {
        n=new node;
        n->item=data;
        n->next=temp->next;
        n->prev=temp;
        if(temp->next!=NULL)
            temp->next->prev=n;
        temp->next=n;
    }
}
void DLL::deleteFirst()
{
    node *t;
    if(start)
    {
        if(start->next==NULL)
        {
            delete start;
            start=NULL;
        }
        else
        {
            t=start;
            start->next->prev=NULL;
            start=start->next;
            delete t;
        }
    }
}
void DLL::deleteLast()
{
    node *t;
    if(start)
    {
        if(start->next==NULL)
        {
            delete start;
            start=NULL;
        }
        else
        {
            t=start;
            while(t->next!=NULL)
                t=t->next;
            t->prev->next=NULL;
            delete t;
        }
    }
}
void DLL:: deleteNode(int data)
{
    node *t;
    t=start;
    while(t)
    {
        if(t->item==data)
        {
            if(t->next!=NULL)
                t->next->prev=t->prev;
            if(t->prev!=NULL)
                t->prev->next=t->next;
            if(t->prev==NULL)
                start=t->next;
            delete t;
            break;
        }
        t=t->next;
    }

}
DLL::~DLL()
{
    while(start)
        deleteFirst();
}