// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 3 - Problem 0
// Program: CS213-2018-A1-T3-P0
// Purpose: Apply basic arithmetic operations on bigINT class
// Author1: Mostafa Omar Mahmoud - 20170292
// Author2: Ahmed Mohamed Hanafy - 20170357
// Date:    26 October 2018
// Version: 1.0
/// the implementation of class functions file
/// having problems with the + operator
/// finished the setters and getters and paramterized constructors
/// commit in 26/10/18 9:00AM  by HANAFY


#include "bigINT.h"

template <typename T>
//string convert_decimal(T  x);/// generic function to make it able use this function with whatever the data type
                            /// we need here only the long long and int

string convert_decimal(T  x){ /// generic function to make it able use this function with whatever the data type
                            /// we need here only the long long and int
    string ret;
    while(x){
        char temp = x%10 +'0';
        ret += temp;
        x/=10;
    }

    reverse(ret.begin(), ret.end());
    return ret;
}




bigINT ::bigINT(string mstring){       /// paramterized constructor intializing the string to passed string
    this->mstring = mstring;
}
bigINT::bigINT(long long x){        /// constructor to take long long and assign it to the string in BigINT
    mstring = convert_decimal(x);

}
//bigINT(const bigINT& other);                ///copy const.
//bigINT& bigINT :: operator=(const bigINT& other){     ///assignment cons.
//    this->mstring = other.mstring;
//    return *this;
//
//}











string bigINT::getBig_INT(){
            return mstring;
}
void bigINT::setBig_INT(string mstring){
    this->mstring = mstring;
}
void bigINT::setBig_INT(long long mstring){
    this->mstring = mstring;
}
void bigINT::setBig_INT(int mstring){
    this->mstring = mstring;
}
void bigINT::setBig_INT(double mstring){
    this->mstring = mstring;
}
bigINT bigINT :: operator+(bigINT obj){ /// straighforward + operator without keep tracking of the carry but it doesn't work

    bigINT retINT (this->mstring);
    string temp1 = retINT.mstring;
    string temp2 = obj.mstring;
//    string ret ;
    temp1.resize(max(temp1.size() , temp2.size()) +1);
    reverse(temp1.begin() ,temp1.end() );
    reverse(temp2.begin() ,temp2.end() );
    for(int i = 0 ; i<(int)(temp1.size()); ++i){
        temp1[i] +=temp2[i];
    }
    reverse(temp1.begin() , temp1.end());
    cout<<temp1<<endl;
    return (retINT);
}
ostream& operator <<(ostream &out ,const  bigINT &obj){
    out<<obj.mstring;

    return out;

}
