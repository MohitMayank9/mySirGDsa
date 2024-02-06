#include<iostream>
#include<stdio.h>
using namespace std;
class Array
{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        Array(int);
        bool isEmpty();
        bool isFull();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void del(int);
        int getItem(int);
        int count();
        ~Array();
        int find(int);
};
Array::Array(int size)
{
    if(size>0){
        capacity=size;
        lastIndex=-1;
        ptr=new int[capacity];
    }
    else
        ptr=NULL;
}
bool Array::isEmpty()
{
    return lastIndex==-1;
}
bool Array::isFull()
{
    return lastIndex==capacity-1;
}
void Array::append(int data)
{
    if(isFull())
        cout<<"\nOverflow";
    else
    {
        lastIndex++;
        ptr[lastIndex]=data;
    }
}
void Array::insert(int index,int data)
{
    if(index<0 || index>lastIndex+1)
        cout<<"\nInvalid Index";
    else if(isFull())
        cout<<"\nOverflow";
    else
    {
        for(int i=lastIndex;i>=index ;i--)
        {
            ptr[i+1]=ptr[i];
        }
        ptr[index]=data;
        lastIndex++;
    }
}
void Array::edit(int index,int data){
    if(index<0 || index>lastIndex)
        cout<<"\nInvalid Index or empty array";
    else
        ptr[index]=data;
}
void Array::del(int index)
{
    int i;
    if(index<0 || index>lastIndex)
        cout<<"\nInvalid Index or empty array";
    else
    {
        for(i=index;i<lastIndex;i++)
            ptr[i]=ptr[i+1];
        lastIndex--;
    }
}
int Array::getItem(int index)
{
    if(index<0 || index>lastIndex)
    {
        cout<<"\nInvalid Index or empty array";
        throw new exception();
    }
    return ptr[index];
}
int Array::count()
{
    return lastIndex+1;
}
Array::~Array()
{
    delete []ptr;
}
int Array::find(int data)
{
    int i;
    for(i=0;i<=lastIndex;i++)
        if(ptr[i]==data)
            return i;
    return -1;
}
