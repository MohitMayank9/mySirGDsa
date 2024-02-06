#include<iostream>
#include<stdio.h>
using namespace std;
class Stack
{
    private:
        int capacity;
        int top;
        int *ptr;
    public:
        Stack(int);
        void push(int);
        bool isFull();
        bool isEmpty();
        int peek();
        int pop();
        ~Stack();
        void reverse();
        int getSize();
        Stack& operator=(Stack&);
        Stack(Stack&);
};
Stack::Stack(int cap)
{
    if(cap<0)
        cap=-cap;
    if(cap==0)
        cap=4;

    capacity=cap;
    top=-1;
    ptr=new int[cap];
    
}
void Stack::push(int data)
{
    if(isFull())
        cout<<"\nStack Overflow";
    else
    {
        top++;
        ptr[top]=data;
    }
}
bool Stack::isFull()
{
    return top==capacity-1;
}
bool Stack::isEmpty()
{
    return top==-1;
}
int Stack::peek()
{
    try{
        if(top==-1)
            throw 1;
        return ptr[top];
    }
    catch(int e){
        cout<<"Empty Stack";
        return 0;
    }

}
int Stack::pop()
{
    try{
        if(top==-1)
            throw 1;
        int x=ptr[top];
        top--;
        return x;
    }
    catch(int e){
        cout<<"Empty Stack";
        return 0;
    }
}
Stack::~Stack()
{
    delete []ptr;
}
void Stack::reverse()
{
    int t;
    for(int i=0;i<(top+1)/2;i++)
    {
        t=ptr[i];
        ptr[i]=ptr[top-i];
        ptr[top-i]=t;
    }
}
int Stack::getSize()
{
    return top+1;
}
Stack& Stack::operator=(Stack &s)
{
    if(this!=&s){
        capacity=s.capacity;
        top=s.top;
        if(ptr!=NULL)
            delete []ptr;
        ptr=new int[capacity];
        for(int i=0;i<=top;i++)
            ptr[i]=s.ptr[i];
    }
    return *this;
}
Stack::Stack(Stack &s)
{
    capacity=s.capacity;
    top=s.top;
    
    ptr=new int[capacity];
    for(int i=0;i<=top;i++)
        ptr[i]=s.ptr[i];
}
void reverseStack(Stack &s)
{
    Stack *tempStack=new Stack(s.getSize());
    while(!s.isEmpty())
    {
        tempStack->push(s.pop());
    }
    s=*tempStack;
}
void minValueTracking()
{
    Stack s1(5);
    Stack min(5);
    int x;
    for(int i=0;i<5;i++){
        cout<<"Enter a number: ";
        cin>>x;
        s1.push(x);
        if(min.isEmpty())
            min.push(x);
        else
        {
            if(x<min.peek())
                min.push(x);
            else
                min.push(min.peek());
        }
    }

    for(int i=0;i<5;i++)
    {
        cout<<"\nMinimum value in the stack is "<<min.peek();
        s1.pop();
        min.pop();
    }

}
int main()
{
    minValueTracking();
    cout<<endl;
    return 0;
}