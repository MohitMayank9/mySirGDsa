#include<iostream>
#include<stdio.h>
using namespace std;
struct node 
{
    int item;
    int pno;
    node *next;
};
class PriorityQueue
{
    private:
        node *start;
    public:
        PriorityQueue();
        void insert(int,int);
        void deleteNode();
        int getHighestPriorityElement();
        int getHighestPriorityNumber();
        ~PriorityQueue();
        bool isEmpty();
};
PriorityQueue::PriorityQueue()
{
    start=NULL;
}
void PriorityQueue::insert(int data,int pno)
{
    node *n=new node;
    node *t1,*t2;
    n->item=data;
    n->pno=pno;
    if(start==NULL)
    {
        n->next=NULL;
        start=n;
    }
    else
    {
        t2=NULL;
        t1=start;
        while(t1)
        {
            if(pno>t1->pno)
                break;
            t2=t1;
            t1=t1->next;
        }

        if(t2)
        {
            n->next=t1;
            t2->next=n;
        }
        else
        {
            n->next=t1;
            start=n;
        }
    }
}
void PriorityQueue::deleteNode()
{
    if(start)
    {
        node *r=start;
        start=start->next;
        delete r;
    }
}
int PriorityQueue::getHighestPriorityElement()
{
    if(start==NULL)
        throw 1;
    return start->item;
}
int PriorityQueue::getHighestPriorityNumber()
{
    if(start==NULL)
        throw 1;
    return start->pno;
}
PriorityQueue::~PriorityQueue()
{
    while(start)
        deleteNode();
}
bool PriorityQueue::isEmpty()
{
    return start==NULL;
}