// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 3 - Problem 0
// Program: CS213-2018-A1-T3-P0
// Purpose: Apply basic arithmetic operations on bigINT class
// Author1: Mostafa Omar Mahmoud - 20170292
// Author2: Ahmed Mohamed Hanafy - 20170357
// Date:    26 October 2018
// Version: 1.0
/// the implementation of class functions file
/// having problems with the fixed the + operator for the postive numbers adding
/// finished the setters and getters and paramterized constructors
/// commit in 26/10/18 12PM  by HANAFY
/// v1.1


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
bigINT bigINT :: operator+(bigINT obj){ ///positive adding

//    bigINT retINT (this->mstring);
    string temp1 = this->mstring;
    string temp2 = obj.mstring;



    reverse(temp1.begin() ,temp1.end() );
    reverse(temp2.begin() ,temp2.end() );
    if(temp1.size()<temp2.size())               /// make temp1 is the larger one to make it possible after reversing adding the remaining numbers
                                                ///e.q : 10000 , 23
                                                ///     0001 , 32 so we can add the 1
        swap(temp1,temp2);
    int mnsz = min(temp1.size() ,temp2.size());
    int mxsz = max(temp1.size() , temp2.size());


    int carry = 0;                          /// keep track of the remainder and add it to the sum each iteration
    int i ;
    string ans ;
    for( i = 0 ; i<(int)(mnsz); ++i){                           /// iterating to the min size of the 2 string to  add the common digits
                                                                /// like 23 and 1000 adding 2 3 to 0 0
            int sum  = temp1[i]-'0' + temp2[i]-'0'+ carry;      /// adding remainder to sum so if we have 8 + 5
                                                                /// and the remainder is 1 then the sum is 13 +1
                                                                /// we add the sum%10 to the digit place and carry =  sum/10
            carry = sum/10;

        ans+= sum%10 +'0';
    }

    for(int j = i ; j<int(mxsz) ; ++j){                 ///iterating on the remaining part of the larger string to add the rest
                                                        /// also we still keep tracking of remainder

        int sum = temp1[j]+carry -'0';
        carry = sum/10;
        ans+=sum%10+'0';

    }

    if(carry)                               /// we can't have more than one extra space for the carry because the maximum carry is 9
        ans += carry +'0';


    reverse(ans.begin() , ans.end());

     bigINT retINT (ans);
    return (retINT);
}
ostream& operator <<(ostream &out ,const  bigINT &obj){
    out<<obj.mstring;

    return out;

}
