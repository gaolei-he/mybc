#ifndef MYINT_H
#define MYINT_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Bigint
{
public:
    //constructor
    Bigint(long long = 0);
    
    Bigint(string _t);
    
    
    operator bool();
    void half();

    //relational operator
    bool operator >(Bigint &obj);
    bool operator <(Bigint &obj);
    //arithmetic operator
    Bigint operator^(Bigint &obj);
    Bigint operator%(Bigint &obj);
    Bigint operator/(Bigint &obj);
    Bigint operator*(Bigint &obj);
    Bigint operator+(Bigint &obj);
    Bigint operator-(Bigint &obj);
    //compound assignment operators
    Bigint &operator+=(Bigint &obj) { return *this = *this + obj; }
    Bigint &operator-=(Bigint &obj) { return *this = *this - obj; }
    Bigint &operator*=(Bigint &obj) { return *this = *this * obj; }
    Bigint &operator/=(Bigint &obj) { return *this = *this / obj; }
    Bigint &operator%=(Bigint &obj) { return *this = *this % obj; }
    //input and output
    friend istream & operator>>(istream &in, Bigint &obj);
    friend ostream & operator<<(ostream &out, const Bigint &obj);

    vector<int> val_;
    int sign_;

};
#endif