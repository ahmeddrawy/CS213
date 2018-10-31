// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 3 - Problem 0
// Program: CS213-2018-A1-T3-P0
// Purpose: Apply basic arithmetic operations on bigINT class
// Author1: Mostafa Omar Mahmoud - 20170292
// Author2: Ahmed Mohamed Hanafy - 20170357
// Date:    26 October 2018
// Version: 1.0
/// header file in project
/// having problems with the fixed the + operator for the postive numbers adding
/// finished the setters and getters and paramterized constructors
/// commit in 26/10/18 12PM  by HANAFY
/// v1.1




#ifndef BIGINT_H
#define BIGINT_H
#include<bits/stdc++.h>


using namespace std;
class bigINT
{
    public:
        bigINT();
        bigINT(string mstring);
        bigINT(long long x);
        bigINT(double x);


//        bigINT& operator=(const bigINT& other);
        void setBig_INT(string mstring);
        void setBig_INT(long long  mstring);
        void setBig_INT(int mstring);
        void setBig_INT(double mstring);
        bigINT operator+(bigINT obj);           /// operator overloading
        bigINT operator-(bigINT obj);
//        string getBig_INT();
        friend string add_function(bigINT , bigINT);
         bigINT Subtraction(bigINT , bigINT);
        friend ostream&operator <<(ostream &out ,const bigINT &obj);
    protected:

    private:
        string mstring ; bool sign ; /// sign 1 if positive  0 otherwise
};

#endif // BIGINT_H
