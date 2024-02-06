#include<iostream>
#include<stdio.h>
using namespace std;
class DynArray
{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    protected:
        void doubleArray();
        void halfArray();
    public:
        DynArray(int);
        DynArray(DynArray &);
        DynArray& operator=(DynArray &);
        bool isEmpty();
        bool isFull();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void del(int);
        int getItem(int);
        int count();
        ~DynArray();
        int find(int);
        int getCapacity();

};
DynArray::DynArray(int size)
{
    if(size>0){
        capacity=size;
        lastIndex=-1;
        ptr=new int[capacity];
    }
    else
        ptr=NULL;
}
DynArray::DynArray(DynArray &a)
{
    capacity=a.capacity;
    lastIndex=a.lastIndex;
    ptr=new int[capacity];
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=a.ptr[i];
}
DynArray& DynArray::operator=(DynArray &a)
{
    if(this != &a){
        if(ptr!=NULL)
        delete []ptr;
        capacity=a.capacity;
        lastIndex=a.lastIndex;
        ptr=new int[capacity];
        for(int i=0;i<=lastIndex;i++)
            ptr[i]=a.ptr[i];
    }
    return *this;
}
void DynArray::doubleArray()
{
    int *temp;
    temp=new int[capacity*2];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity*=2;
}
void DynArray::halfArray()
{
     int *temp;
    temp=new int[capacity/2];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity/=2;
}
bool DynArray::isEmpty()
{
    return lastIndex==-1;
}
bool DynArray::isFull()
{
    return lastIndex==capacity-1;
}
void DynArray::append(int data)
{
    if(isFull())
        doubleArray();
    lastIndex++;
    ptr[lastIndex]=data;
}
void DynArray::insert(int index,int data)
{
    if(index<0 || index>lastIndex+1)
        cout<<"\nInvalid Index";
    else 
    {
        if(isFull())
            doubleArray();
        for(int i=lastIndex;i>=index ;i--)
        {
            ptr[i+1]=ptr[i];
        }
        ptr[index]=data;
        lastIndex++;
    }
}
void DynArray::edit(int index,int data){
    if(index<0 || index>lastIndex)
        cout<<"\nInvalid Index or empty array";
    else
        ptr[index]=data;
}
void DynArray::del(int index)
{
    int i;
    if(index<0 || index>lastIndex)
        cout<<"\nInvalid Index or empty array";
    else
    {
        for(i=index;i<lastIndex;i++)
            ptr[i]=ptr[i+1];
        lastIndex--;
        if(capacity>1 && lastIndex+1 <=capacity/2)
            halfArray();
    }
}
int DynArray::getItem(int index)
{
    if(index<0 || index>lastIndex)
    {
        cout<<"\nInvalid Index or empty array";
        throw new exception();
    }
    return ptr[index];
}
int DynArray::count()
{
    return lastIndex+1;
}
DynArray::~DynArray()
{
    delete []ptr;
}
int DynArray::find(int data)
{
    int i;
    for(i=0;i<=lastIndex;i++)
        if(ptr[i]==data)
            return i;
    return -1;
}
int DynArray::getCapacity()
{
    return capacity;
}