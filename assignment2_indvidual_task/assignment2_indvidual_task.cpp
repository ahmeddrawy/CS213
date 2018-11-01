#include <iostream>
#include <bits/stdc++.h>
#include "Stack.h"
using  namespace std;



int main(){
    int x ; cin>>x;
    Stack s(x) ;
    s.push(3);
    s.push(3);

    cout<<s.top()<<endl;
    cout<<s.getsize()<<endl;
    s.clearstack();
    cout<<s.top()<<endl;
}
