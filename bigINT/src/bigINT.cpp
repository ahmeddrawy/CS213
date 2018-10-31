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




bigINT ::bigINT(string mstring){       /// parametrized constructor initializing the string to passed string
                                            /// if positive take all the string else take substring from 1 to n
    if(mstring[0]>='0'&&mstring[0]<='9')
        this->mstring = mstring;
    else {
        sign = mstring[0]!='-';
        this->mstring = mstring.substr(1);

    }

}
bigINT::bigINT(long long x){        /// constructor to take long long and assign it to the string in BigINT
    mstring = convert_decimal(abs(x));      /// send abs x to the negative values
    if(x<0)
        sign = 0;
    else
        sign =1;

}
//bigINT& operator=(const bigINT& other){

//}
//bigINT(const bigINT& other);                ///copy const.
//bigINT& bigINT :: operator=(const bigINT& other){     ///assignment cons.
//    this->mstring = other.mstring;
//    return *this;
//
//}











//string bigINT::getBig_INT(){
//            return mstring;
//}
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
bigINT bigINT ::Subtraction(bigINT first,bigINT second) /// returns string result of a - b including sign if negative
{
                                /// edited by hanafy because returning string was causing initializing the
                                /// sign of the new bigINT with zero which is negative
    bool neg = 0;
    string ans;
    string a = first.mstring;
    string b = second.mstring ;
    if ((a.size() < b.size()) || (a.size() == b.size() && a < b))
    {
        neg = 1;
        swap(a, b);         /// making sure that A is the larger than B
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> num1(a.size()), num2(b.size());
    for (int i = 0; i <(int)( a.size()); ++i)
        num1[i] = a[i] - '0';
    for (int i = 0; i <(int)( b.size()); ++i)
        num2[i] = b[i] - '0';

    for (int i = 0; i < (int)( b.size()); ++i)
    {
        if (num1[i] >= num2[i])
            ans += (num1[i] - num2[i] + '0');
        else
        {
            for (int j = i + 1; j <(int)( b.size()); ++j)
            {
                num1[j-1] += 10;
                if (num1[j] > 0)
                {
                    num1[j]--;
                    break;
                }
            }
            ans += (num1[i] - num2[i] + '0');
        }
    }
//    if (neg)
//        ans += '-';
    reverse(ans.begin(), ans.end());
    bool allZeros = true;
    for (int i = 0; i < (int)(ans.size()); ++i) /// edited by hanafy looping from zero because the sign is assigned out of the string

    {
        if (ans[i] != '0')
        {
            allZeros = false;
            break;
        }
        else
            ans.erase(i,1);           /// we have problem with the erase it gives bad alloc
                                        /// fixed by giving it len of the erasing
    }
    bigINT ret(ans );
    ret.sign = !neg;
    return ret;
}

bigINT bigINT :: operator+(bigINT obj){ ///positive adding
    if(this->sign == obj.sign){
        bigINT res (add_function(*this , obj) );
        cout<<this->mstring<<" "<<obj.mstring<<" "<<add_function(*this , obj)<<endl;
        res.sign = this->sign;                  /// returning new bigINT with the same sign and sum of two BIGINTS
        return res;

    }
    else {
            cout<<"subtracting here\n";
//        bigINT res;
        if (this->sign == 1)
            return Subtraction(*this, obj); /// return the subtraction final answer with the sign
        else
            return Subtraction(obj, *this);


//        return res;
    }
}

bigINT bigINT :: operator-(bigINT obj)
{
                            /// we have problem now with the negative values
//    if(this->sign ==0 )

    obj.sign = !obj.sign;
//    this->sign = !this->sign;
    return (*this + obj);
}


string add_function(bigINT first , bigINT second) {     /// friend function adding two bigINT without handling the sign
//    bigINT retINT (this->mstring);
    string temp1 =first.mstring;
    string temp2 = second.mstring;



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
    return ans;

}
/**
Old code
bigINT bigINT :: operator -(bigINT obj){
    string _1st   = this->mstring;
    string _2nd = obj.mstring;

}
*/
ostream& operator <<(ostream &out ,const  bigINT &obj){
    if(!obj.sign)
        out<<'-';
    out<<obj.mstring;

    return out;

}
