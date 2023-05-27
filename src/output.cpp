#include "global.h"
#include <iostream>
#include <string>
#include "myint.h"
#include <vector>
#include <iomanip>
using namespace std;
void output(string s)
{
    //cout << "#" << s << endl;
    if(obase == 10) cout << s << endl;
    else
    {
        Bigint ans = s, R = obase;
        if(ans.sign_ == -1) cout << '-';
        Bigint tmp = R;
        while (!(tmp > ans)) tmp *= R;
        tmp /= R;
        vector<int> v1;
        ans.sign_ = 1;
        //cout << "#" << tmp << endl;
        while (ans || tmp)
        {
            Bigint tmp1 = ans/tmp;
            int tmp2 = 0;
            //cout << "#!" << tmp1 << endl;
            while(tmp1.val_.size())
            {
                tmp2 *= 10;
                tmp2 += tmp1.val_.back();
                tmp1.val_.pop_back();
            }
            //cout << "#!" << tmp2 << endl;
            v1.push_back(tmp2);
            ans %= tmp;
            tmp /= R;
        }
        if(obase > 16)
        {
            int wid = 2;
            if(obase > 99) wid = 3;
            for(auto i:v1) cout << ' ' << setw(wid) << setfill('0') << i;
        }
        else
        {
            for(auto i:v1) if(i>9) cout << char('A' + i - 10);else cout << i;
        }
        puts("");
    }
    
    
}
void output(int num)
{
    cout << num << endl;
}