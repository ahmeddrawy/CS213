// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 3 - Problem 0
// Program: CS213-2018-A1-T3-P0
// Purpose: Apply basic arithmetic operations on bigINT class
// Author1: Mostafa Omar Mahmoud - 20170292
// Author2: Ahmed Mohamed Hanafy - 20170357
// Date:    26 October 2018
// Version: 1.0
/// header file in project
/// having problems with the + operator
/// finished the setters and getters and paramterized constructors
/// commit in 26/10/18 9:00AM by HANAFY



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

        bigINT(const bigINT& other);
        bigINT& operator=(const bigINT& other);
        void setBig_INT(string mstring);
        void setBig_INT(long long  mstring);
        void setBig_INT(int mstring);
        void setBig_INT(double mstring);
        bigINT operator+(bigINT obj);
        bigINT operator-(bigINT obj);
        string getBig_INT();
        friend ostream&operator <<(ostream &out ,const bigINT &obj);
    protected:
    private:

        string mstring ;
};

#endif // BIGINT_H
