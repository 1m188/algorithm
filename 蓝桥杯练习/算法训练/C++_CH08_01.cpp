/*
问题描述
　　已知一个有理数类Zrf_Ratio，实现如下的操作符重载形式：
　　friend std::ostream& operator<<(std::ostream&, const zrf_Ratio&);//输出最简分数
　　friend std::istream& operator>>(std::istream&, zrf_Ratio&);
　　friend bool operator==(const zrf_Ratio&, const zrf_Ratio&);
　　friend bool operator<(const zrf_Ratio&, const zrf_Ratio&);
测试
　　测试时主程序会输入四个整数a, b, c, d，表示两个分数a/b和c/d。要求输出最简分数以及两个分数相等和大小的比较结果。
样例输入
1 7 26 25
样例输出
zrf is:1/7; ssh is:26/25
(zrf==ssh) is:0; (zrf<ssh) is:1
*/

#include <iostream>
#include <cassert>
using namespace std;
class zrf_Ratio
{
    friend std::ostream &operator<<(std::ostream &, const zrf_Ratio &);
    friend std::istream &operator>>(std::istream &, zrf_Ratio &);
    friend bool operator==(const zrf_Ratio &, const zrf_Ratio &);
    friend bool operator<(const zrf_Ratio &, const zrf_Ratio &);

  public:
    zrf_Ratio(int = 0, int = 1);
    zrf_Ratio(const zrf_Ratio &);

  private:
    int num;
    int den;
    void reduce(); //化为最简分数
};
//补充完整构造函数

//公有成员函数:
zrf_Ratio::zrf_Ratio(int num, int den) : num(num), den(den)
{
    reduce();
}

zrf_Ratio::zrf_Ratio(const zrf_Ratio &r) : num(r.num), den(r.den)
{
    reduce();
}

//私有成员函数:
void swap(int &m, int &n)
{
    int t;
    t = m;
    m = n;
    n = t;
}

int zrf_Gcd(int m, int n)
{
    if (m < n)
        swap(m, n);
    assert(n >= 0);
    while (n > 0)
    {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}

void zrf_Ratio::reduce()
{
    if (num == 0 || den == 0)
    {
        num = 0;
        den = 1;
        return;
    }
    if (den < 0)
    {
        den *= -1;
        num *= -1;
    }
    if (num == 1)
        return;
    int sgn = (num < 0 ? -1 : 1);
    int g = zrf_Gcd(sgn * num, den);
    num /= g;
    den /= g;
}

std::ostream &operator<<(std::ostream &o, const zrf_Ratio &z)
{
    o << z.num << '/' << z.den;
    return o;
}

std::istream &operator>>(std::istream &i, zrf_Ratio &z)
{
    i >> z.num >> z.den;
    return i;
}

bool operator==(const zrf_Ratio &z1, const zrf_Ratio &z2)
{
    return z1.den == z2.den && z1.num == z2.num;
}

bool operator<(const zrf_Ratio &z1, const zrf_Ratio &z2)
{
    return z1.num * z2.den < z2.num * z1.den;
}

int main()
{
    int a = 0, b = 0, c = 0, d = 0;
    cin >> a >> b >> c >> d;
    zrf_Ratio zrf(a, b), ssh(c, d);
    std::cout << "zrf is:" << zrf << "; ssh is:" << ssh << '\n';
    std::cout << "(zrf==ssh) is:" << (zrf == ssh) << "; (zrf<ssh) is:" << (zrf < ssh) << endl;
    return 0;
}