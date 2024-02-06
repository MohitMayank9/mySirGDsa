#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class Deque
{
    private:
        node *front,*rear;
    public:
        Deque();
        void insertFront(int);
        void insertRear(int);
        void deleteFront();
        void deleteRear();
        int getFront();
        int getRear();
        ~Deque();
        bool isEmpty();

};
Deque::Deque()
{
    front=NULL;
    rear=NULL;
}
void Deque::insertFront(int data)
{
    node *n=new node;
    n->prev=NULL;
    n->item=data;
    n->next=front;
    
    if(front!=NULL)
        front->prev=n;
    front=n;
    if(rear==NULL)
        rear=n;
}
void Deque::insertRear(int data)
{
    node *n=new node;
    n->prev=rear;
    n->item=data;
    n->next=NULL;
    if(rear!=NULL)
        rear->next=n;
    rear=n;
    if(front==NULL)
        rear=n;
}
void Deque::deleteFront()
{
    if(front)
    {
        if(front->next==NULL)
        {
            delete front;
            front=rear=NULL;
        }
        else
        {
            node *t;
            t=front;
            front=front->next;
            delete t;
        }
    }
}
void Deque::deleteRear()
{
    if(rear)
    {
        if(rear->prev==NULL)
        {
            delete rear;
            front=rear=NULL;
        }
        else
        {
            node *t;
            t=rear;
            rear=rear->prev;
            delete t;
        }
    }
}
int Deque::getFront()
{
    if(front==NULL)
        throw 1;
    return front->item;
}
int Deque::getRear()
{
    if(rear==NULL)
        throw 1;
    return rear->item;
}
Deque::~Deque()
{
    while(front)
        deleteFront();
}
bool Deque::isEmpty()
{
    return front==NULL;
}