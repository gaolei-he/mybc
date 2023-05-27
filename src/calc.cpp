#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include "input.h"
#include "myint.h"
#include "global.h"
using namespace std;
string calc(string a, string b, char op)
{
    Bigint s1, s2;
    //cout << "#" << a << " " << b << endl;
    if(a.front() >= 'a') s1 = lib[a];
    else s1 = a;
    if(b.front() >= 'a') s2 = lib[b];
    else s2 = b;
    // cout << '#' << endl;
    // cout << s1 << endl << s2 << endl << op << endl;
    // if(ibase != 10)
    // {
    //     //cout << '#' << ibase << endl;
        
    // Bigint tmp = 1;
    // Bigint R = ibase;
    // Bigint tmp1, tmp2;
    // int i = 0;
    // while (i < s1.val_.size())
    // {
    //     Bigint t1 = s1.val_[i++];
    //     Bigint t2 = (t1 * tmp);
    //     tmp1 += t2;
    //     tmp *= R;
    // }
    //     s1 = tmp1;
    //     i = 0;
    //     tmp = 1;
    //     while(i < s2.val_.size())
    //     {
    //         Bigint t1 = s2.val_[i++];
    //         Bigint t2 = (t1 * tmp);
    //         tmp2 += t2;
    //         tmp *= R;
    //     }
    //     s2 = tmp2;
    // }
    Bigint ans;
    switch (op)
    {
    case '+':
        ans = s1 + s2;
        break;
    case '-':
        ans = s1 - s2;
        break;
    case '*':
        ans = s1 * s2;
        break;
    case '/':
        ans = s1 / s2;
        break;
    case '^':
        ans = (s1 ^ s2);
        break;
    default:
        ans = s1 + s2;
        break;
    }
    string str;
    if(ans.sign_ < 0) str += '-';
    for(int i=ans.val_.size()-1;i>=0;i--) str.push_back(ans.val_[i] + '0');
    //cout << '#' << str << endl;
    return str;
}