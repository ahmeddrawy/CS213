#ifndef STACK_H
#define STACK_H
#include <iostream>

#include <bits/stdc++.h>
using namespace std;


class Stack
{
    public:
        Stack(int );
        void push(int x);
        void  pop();
        int  top();
        void  clearstack();
        bool  isempty();
        int  getsize();
        void resizestack(int x);


    protected:

    private:
        valarray < int > marr;
        int msize ;
};

#endif // STACK_H
