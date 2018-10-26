// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 3 - Problem 0
// Program: CS213-2018-A1-T3-P0
// Purpose: Apply basic arithmetic operations on bigINT class
// Author1: Mostafa Omar Mahmoud - 20170292
// Author2: Ahmed Mohamed Hanafy - 20170357
// Date:    26 October 2018
// Version: 1.0
/// main file in project
/// having problems with the + operator
/// finished the setters and getters and paramterized constructors
/// commit in 26/10/18 9:00AM  by HANAFY


#include <iostream>
#include "bigINT.h"
using namespace  std;


int main(){

    string pSTRING_1 , pSTRING_2;
    cin>>pSTRING_1;
    bigINT num0(pSTRING_1);
    cout<<num0.getBig_INT()<<endl;
    long long pLL1;
    cin>>pLL1;
    bigINT num1(pLL1);
    cout<<num1.getBig_INT()<<endl;
//    num0+num1;
//    num0 = num0+num1;
    cout<<num0+num1<<endl;          /// i have a problem here with  the + operator
    cout<<num0.getBig_INT()<<endl;
//    cout<<num0+num1<<endl;

}
