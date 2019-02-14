#include "cstdio"
#include "vector"
#include "string"
#include "iostream"
#include "cstring"

struct BigInteger
{
    static const int BASE = 100000000; //主要是每八位储存一次，储存结果在数组里，且最后八位储存在数组最开头，以此类推
    static const int WIDTH = 8;
    std::vector<int> s;

    BigInteger(long long num = 0) { *this = num; } //构造函数
    BigInteger &operator=(long long num);          //赋值运算符，下面重载
    BigInteger &operator=(const std::string &str);
    BigInteger operator+(const BigInteger &b) const; //加法
    //BigInteger operator-(const BigInteger &b) const;
    //BigInteger operator*(const BigInteger &b) const;
    //BigInteger operator/(const BigInteger &b) const;
    BigInteger operator+=(const BigInteger &b);
    bool operator<(const BigInteger &b) const; //各种比较运算符
    bool operator>(const BigInteger &b) const { return b < *this; }
    bool operator<=(const BigInteger &b) const { return !(b < *this); }
    bool operator>=(const BigInteger &b) const { return !(*this < b); }
    bool operator!=(const BigInteger &b) const { return b < *this || *this < b; }
    bool operator==(const BigInteger &b) const { return !(b < *this) && !(*this < b); }
};

BigInteger &BigInteger::operator=(long long num)
{
    s.clear();
    do
    {
        s.push_back(num % BASE);
        num /= BASE;
    } while (num > 0);
    return *this;
}

BigInteger &BigInteger::operator=(const std::string &str)
{
    s.clear();
    int x = 0, len = (str.length() - 1) / WIDTH + 1;
    for (int i = 0; i < len; i++)
    {
        int end = str.length() - i * WIDTH;
        int start = std::max(0, end - WIDTH);
        sscanf(str.substr(start, end - start).c_str(), "%d", &x);
        s.push_back(x);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const BigInteger &x) //重载输入输出运算符
{
    out << x.s.back();
    for (int i = x.s.size() - 2; i >= 0; i--)
    {
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for (int j = 0; j < strlen(buf); j++)
        {
            out << buf[j];
        }
    }
    return out;
}

std::istream &operator>>(std::istream &in, BigInteger &x)
{
    std::string s = "";
    if (in >> s)
    {
        x = s;
    }
    return in;
}

BigInteger BigInteger::operator+(const BigInteger &b) const //重载+运算符
{
    BigInteger c = BigInteger();
    c.s.clear();
    for (int i = 0, g = 0;; i++)
    {
        if (g == 0 && i >= s.size() && i >= b.s.size())
        {
            break;
        }
        int x = g;
        if (i < s.size())
        {
            x += s[i];
        }
        if (i < b.s.size())
        {
            x += b.s[i];
        }
        c.s.push_back(x % BASE);
        g = x / BASE;
    }
    return c;
}

BigInteger BigInteger::operator+=(const BigInteger &b) //重载+=运算符
{
    *this = *this + b;
    return *this;
}

bool BigInteger::operator<(const BigInteger &b) const
{
    if (s.size() != b.s.size())
    {
        return s.size() < b.s.size();
    }
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] != b.s[i])
        {
            return s[i] < b.s[i];
        }
    }
    return false;
}