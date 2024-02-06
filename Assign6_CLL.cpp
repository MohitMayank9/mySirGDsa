#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    int item;
    node *next;
};
class CLL
{
    private:
        node *last;
    public:
        CLL();
        void insertAtStart(int);
        void insertAtLast(int);
        node* search(int);
        void insertAfter(node *,int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(int);
        ~CLL();
};
CLL::CLL()
{
    last=NULL;
}
void CLL::insertAtStart(int data)
{
    node *n=new node;
    n->item=data;
    if(last==NULL)
    {
        n->next=n;
        last=n;
    }
    else
    {
        n->next=last->next;
        last->next=n;
    }
}
void CLL::insertAtLast(int data)
{
    node *n=new node;
    n->item=data;
    if(last==NULL)
    {
        n->next=n;
        last=n;
    }
    else
    {
        n->next=last->next;
        last->next=n;
        last=n;
    }
}
node* CLL::search(int data)
{
    node *t;
    if(last)
    {
        t=last->next;
    
        do 
        {
            if(t->item==data)
                return t;
            t=t->next;
        }while(t!=last->next);
    }
    return NULL;
}
void CLL::insertAfter(node *temp,int data)
{

    if(temp)
    {
        node *n=new node;
        n->item=data;
        n->next=temp->next;
        temp->next=n;
        if(temp==last)
            last=n;
    }
}
void CLL::deleteFirst()
{
    node *t;
    if(last)
    {
        if(last->next==last)
        {
            delete last;
            last=NULL;
        }
        else
        {
            t=last->next;
            last->next=t->next;
            delete t;
        }
    }
}
void CLL::deleteLast()
{
    node *t
    if(last)
    {
        if(last->next==last)
        {
            delete last;
            last=NULL;
        }
        else
        {
            t=last->next;
            while(t->next!=last)
                t=t->next;
            t->next=last->next;

            delete last;
            last=t;
        }
    }
}
void CLL::deleteNode(int data)
{
    node *t,*r;
    if(last)
    {
        
        t=last->next;
        if(t->item==data)
            deleteFirst();
        else
        {
            do
            {
                if(t->next->item==data)
                {
                    r=t->next;
                    t->next=r->next;
                    if(r==last)
                        last=t;
                    delete r;
                    break;
                }    
                t=t->next;
            } while (t!=last->next);
        }
        
    }
}
CLL::~CLL()
{
    while(last)
        deleteFirst();
}