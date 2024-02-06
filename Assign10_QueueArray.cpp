#include<iostream>
#include<stdio.h>
using namespace std;
class Queue
{
    private:
        int capacity;
        int front;
        int rear;
        int *ptr;
    public:
        Queue(int);
        void insert(int);
        int getFront();
        int getRear();
        bool isFull();
        bool isEmpty();
        void deleteFront();
        ~Queue();
        int count();
};
Queue::Queue(int cap)
{
    if(cap<0)
        cap=-cap;
    if(cap==0)
        cap=10;
    capacity=cap;
    front=-1;
    rear=-1;
    ptr=new int[cap];
}
void Queue::insert(int data)
{
    if(front==0 && capacity-1==rear||front==rear+1)
        cout<<"Overflow";
    else if(rear==-1)
    {
        front=rear=0;
        ptr[rear]=data;
    }
    else if(capacity-1==rear)
    {
        rear=0;
        ptr[rear]=data;
    }
    else
    {
        rear++;
        ptr[rear]=data;
    }
}
int Queue::getFront()
{
    if(isEmpty())
        throw 1;
    return ptr[front];
}
int Queue::getRear()
{
    if(isEmpty())
        throw 1;
    return ptr[rear];
}
bool Queue::isFull()
{
    if(front==0&&rear+1==capacity || rear+1==front)
        return true;
    return false;
}
bool Queue::isEmpty()
{
    if(front==-1)
        return true;
    return false;
}
void Queue::deleteFront()
{
    if(isEmpty())
        cout<<"\nUnderflow";
    else if(front==rear)
        front=rear=-1;
    else if(front==capacity-1)
        front=0;
    else
        front++;
    
}
Queue::~Queue()
{
    if(ptr)
        delete []ptr;
}
int Queue::count()
{
    if(isEmpty())
        return 0;
    if(rear>=front)
        return rear-front+1;
    else
        return capacity+rear-front+1;
}