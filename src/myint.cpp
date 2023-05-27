#include <iostream>
#include <vector>
#include <algorithm>
#include "myint.h"
#include "global.h"
using namespace std;

    //constructor
    Bigint::Bigint(long long _t)
    {
        if(_t < 0) sign_ = -1;
        else sign_ = 1;
        _t = abs(_t);
        if(!_t) val_.push_back(0);
        while (_t)
        {
            val_.push_back(_t%10);
            _t /= 10;
        }
    }
    Bigint::Bigint(string _t)
    {
        if(_t.front() == '-')
        {
            sign_ = -1;
            _t = _t.substr(1, _t.size());
        }
        else sign_ = 1;
        while (_t.size())
        {
            int x = _t.back()-'0'; //A 65 0 48 65-48-7=10
            if(x > 9) x -= 7;
            val_.push_back(x);
            _t.pop_back();
        }
        
    }
    //cast operator while()
    Bigint::operator bool()
    {
        if(val_.size() == 1 && val_.back() == 0 || val_.size() == 0) return false;
        else return true;
    }

    //relational operator
    bool Bigint::operator >(Bigint &obj)
    {
        if(sign_ * obj.sign_ == -1) return sign_ > obj.sign_;
        else if(sign_ == -1)
        {
            Bigint tmp1 = *this, tmp2 = obj;
            tmp1.sign_ = 1, tmp2.sign_ = 1;
            return !(tmp1 > tmp2);
        }
        if(val_.size() != obj.val_.size()) return val_.size() > obj.val_.size();
        for(int i=val_.size()-1;i>=0;i--) if(val_[i] != obj.val_[i]) return val_[i] > obj.val_[i];
        return false;
    }
    bool Bigint::operator <(Bigint &obj)
    {
        return obj > *this;
    }

    //arithmetic operator
    Bigint Bigint::operator^(Bigint &obj)//only for positive int
    {
        Bigint tmp, tmp3 = 1;
        Bigint tmp1 = *this, tmp2 = obj;
        if(obj.val_.size() == 1 && obj.val_[0] == 0) return Bigint(1);
        else if(obj.val_.size() == 1 && obj.val_[0] == 1) return *this;
        tmp2 = tmp2 - tmp3;
        while (tmp2)
        {
            tmp2 = tmp2 - tmp3;
            tmp1 = tmp1 * (*this);
        }
        return tmp1;
        
    }
    Bigint Bigint::operator%(Bigint &obj) // 7%3 = 7 - 7/3*3
    {
        if(obj.val_.size() == 1 && obj.val_[0] == 0) return Bigint();
        Bigint tmp1 = (*this) / obj, tmp3 = obj;
        tmp3.sign_ = 1;
        tmp1.sign_ = 1;
        Bigint tmp2 = tmp1 * tmp3;
        Bigint tmp4 = *this;
        tmp4.sign_ = 1;
        return tmp4 - tmp2;
    }
    void Bigint::half()
    {
        Bigint tmp = *this;
        this->val_.clear();
        for(int i=tmp.val_.size()-1, t=0;i>=0;i--)
        {
            t *= 10;
            t += tmp.val_[i];
            val_.push_back(t/2);
            t %= 2;
        }
        reverse(val_.begin(), val_.end());
        while(val_.back() == 0 && val_.size() > 1) val_.pop_back();
    }
    Bigint Bigint::operator/(Bigint &obj)
    {
        if(obj.val_.size() == 1 && obj.val_[0] == 0) return Bigint();
        Bigint tmp, tmp1 = *this, tmp2 = obj;
        tmp1.sign_ = 1, tmp2.sign_ = 1;
        if(tmp1 < tmp2 || obj.val_.size() == 1 && obj.val_[0] == 0) return tmp;
        
        Bigint r = tmp1, l = 0, mi = 2, mi1 = 1;
        while (l < r)
        {
            Bigint mid = l + r + mi1;
            mid.half();
            if((mid * tmp2) > tmp1) r = mid - mi1;
            else l = mid;
            //cout << mid << endl;
        }
        if(sign_ * obj.sign_ == -1) l.sign_ = -1;
        //cout << "#1" << l << "#2" << endl;
        return l;
    }
    Bigint Bigint::operator*(Bigint &obj)// 123   456
    {
        Bigint tmp;
        for (int i = 0; i < val_.size(); i++)
        {
            for (int j = 0, t = 0; j < obj.val_.size() || t; j++)
            {
                if(j<obj.val_.size()) t += val_[i] * obj.val_[j];
                if(tmp.val_.size() < i + j + 1) tmp.val_.push_back(t%10);
                else
                {
                    t += tmp.val_[i+j];
                    tmp.val_[i+j] = t % 10;
                }
                t /= 10;
            }
            
        }
        while(tmp.val_.back() == 0 && tmp.val_.size() > 1) tmp.val_.pop_back();
        if(sign_ * obj.sign_ == -1)
            if(!(val_.size() == 1 && val_[0] == 0 || obj.val_.size() == 1 && obj.val_[0] == 0)) tmp.sign_ = -1;

        return tmp;
    }
    Bigint Bigint::operator+(Bigint &obj)
    {
        if(this->sign_ * obj.sign_ == -1)
        {
            Bigint tmp1 = *this, tmp2 = obj, tmp;
            tmp1.sign_ = 1, tmp2.sign_ = 1;
            if(sign_ == -1) tmp = tmp2 - tmp1;
            else tmp = tmp1 - tmp2;
            return tmp;
        }
        Bigint tmp;
        tmp.val_.clear();
        for (int i = 0, t = 0; i < obj.val_.size() || i < (*this).val_.size() || t; i++)
        {
            if(i < obj.val_.size())  t += obj.val_[i];
            if(i < (*this).val_.size()) t += (*this).val_[i];
            tmp.val_.push_back(t % 10);
            t /= 10;
        }
        if(obj.sign_ == -1) tmp.sign_ = -1;
        return tmp;
    }
    Bigint Bigint::operator-(Bigint &obj)
    {
        if(obj.sign_ * (*this).sign_ == -1)
        {
            Bigint tmp1 = obj, tmp2 = (*this);
            tmp1.sign_ = 1, tmp2.sign_ = 1;
            Bigint tmp = tmp1 + tmp2;
            if(this->sign_ == -1) tmp.sign_ = -1;
            return tmp;
        }
        else if(obj > (*this))
        {
            Bigint tmp = obj - *this;
            tmp.sign_ = -1;
            return tmp;
        }
        
        Bigint tmp;
        tmp.val_.clear();
        for (int i = 0, t = 0; i < val_.size(); i++)
        {
            if(i < val_.size()) t += val_[i];
            if(i < obj.val_.size()) t -= obj.val_[i];
            tmp.val_.push_back((t+10)%10);
            if(t < 0) t = -1;
            else t = 0;
        }
        while (tmp.val_.size() > 1 && tmp.val_.back() == 0) tmp.val_.pop_back();
        return tmp;
    }
    //input and output
    istream &operator>>(istream &in, Bigint &obj)
    {
        string str;
        
        if(in >> str)
        {
            if(str.front() == '-')
            {
                obj = str.substr(1, str.size());
                obj.sign_ = -1;
            }
            else
            {
                obj = str;
                obj.sign_ = 1;
            }
        }
        return in;
    }
    ostream &operator<<(ostream &out, const Bigint &obj)
    {
        if(obj.sign_ == -1) cout << '-';
        for(int i=obj.val_.size()-1;i>=0;i--)
            out << obj.val_[i];
        return out;
    }
    vector<int> val_;
    int sign_;
