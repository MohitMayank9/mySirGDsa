#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class CDLL
{
    private:
        node *start;
    public:
        CDLL();
        void insertAtStart(int);
        void insertAtLast(int);
        node* search(int);
        void insertAfter(node*,int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(int);
        ~CDLL();
};
CDLL::CDLL()
{
    start=NULL;
}
void CDLL::insertAtStart(int data)
{
    node *n=new node;
    n->item=data;
    if(start==NULL)
    {
        n->prev=n;
        n->next=n;
        start=n;
    }
    else
    {
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;
        start=n;
    }
}
void CDLL::insertAtLast(int data)
{
    node *n=new node;
    n->item=data;
    if(start==NULL)
    {
        n->prev=n;
        n->next=n;
        start=n;
    }
    else
    {
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;
    }
}
node* CDLL::search(int data)
{
    node *t;
    if(start)
    {
        t=start;
        do 
        {
            if(t->item==data)
                return t;
            t=t->next;
        }while(t!=start);
    }
    return NULL;
}
void CDLL::insertAfter(node *temp,int data)
{
    if(temp)
    {
        node *n=new node;
        n->item=data;
        n->prev=temp;
        n->next=temp->next;
        temp->next->prev=n;
        temp->next=n;
    }
    
}
void CDLL::deleteFirst()
{
    if(start)
    {
        if(start->next==start)
        {
            delete start;
            start=NULL;
        }
        else
        {
            node *r;
            r=start;
            start->prev->next=start->next;
            start->next->prev=start->prev;
            start=start->next;
            delete r;
        }
    }
}
void CDLL::deleteLast()
{
    if(start)
    {
        if(start->next==start)
        {
            delete start;
            start=NULL;
        }
        else
        {
            node *r;
            r=start->prev;
            r->prev->next=start;
            start->prev=r->prev;
            
            delete r;
        }
    }
}
void CDLL::deleteNode(int data)
{
    if(start)
    {
        if(start->item==data)
        {
            deleteFirst();
        }
        else
        {
            node *t;
            t=start->next;
            while(t!=start)
            {
                if(t->item==data)
                {
                    t->next->prev=t->prev;
                    t->prev->next=t->next;
                    delete t;
                    break;
                }
                t=t->next;
            }

        }
    }
}
CDLL::~CDLL()
{
    while(start)
        deleteFirst();
}