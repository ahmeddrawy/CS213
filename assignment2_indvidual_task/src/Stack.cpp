#include "Stack.h"
int SIZE = 10000;
Stack::Stack(int x )
{
    msize = 0;
    marr.resize(x,0);
}
void Stack:: push(int x)
{
    if(msize == marr.size())
    {
        cout<<"the stack is full "<<endl;
        return ;
    }
    marr[msize]= x;
    msize++;
}
void  Stack ::pop()
{
    if(msize == 0)
    {
        cout<<"stack is empty "<<endl;
        return;
    }
    msize--;
}
int Stack:: top()
{
    if(msize == 0)
    {
        cout<<"the stack is empty \n";
        return -1;
    }
    return marr[msize-1];
}
void Stack:: clearstack()
{
    marr.resize(10000,0);
    msize = 0;
}
void Stack ::resizestack(int x){    /// note that the data will be gone
    marr.resize(x);
    msize = 0;
}
bool Stack:: isempty(){
        return  msize == 0;
}
int Stack:: getsize(){
        return msize ;
}


