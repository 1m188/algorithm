/**
 * @file L2-018 多项式A除以B.cpp
 * @date 2022-06-07
 */

/*
这仍然是一道关于A/B的题，只不过A和B都换成了多项式。你需要计算两个多项式相除的商Q和余R，其中R的阶数必须小于B的阶数。

输入格式：
输入分两行，每行给出一个非零多项式，先给出A，再给出B。每行的格式如下：

N e[1] c[1] ... e[N] c[N]
其中N是该多项式非零项的个数，e[i]是第i个非零项的指数，c[i]是第i个非零项的系数。各项按照指数递减的顺序给出，保证所有指数是各不相同的非负整数，所有系数是非零整数，所有整数在整型范围内。

输出格式：
分两行先后输出商和余，输出格式与输入格式相同，输出的系数保留小数点后1位。同行数字间以1个空格分隔，行首尾不得有多余空格。注意：零多项式是一个特殊多项式，对应输出为0 0 0.0。但非零多项式不能输出零系数（包括舍入后为0.0）的项。在样例中，余多项式其实有常数项-1/27，但因其舍入后为0.0，故不输出。

输入样例：
4 4 1 2 -3 1 -1 0 -1
3 2 3 1 -2 0 1
输出样例：
3 2 0.3 1 0.2 0 -1.0
1 1 -3.1
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

/* 费了挺大功夫，题目的思路不难想，就是模拟手工多项式相除，但如何具体实现很容易忽视细节，
以及对于多项式除法的过程要熟悉会更舒服一些 */

#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

/**
 * @brief 多项式中的每一项
 */
struct Number {
    int pow = 0;    // 指数
    double coe = 0; // 系数
};

/**
 * @brief 多项式
 */
struct Poly {
    vector<Number> vec; // 整个多项式

    /**
     * @brief 输入
     */
    void input() {
        int n = 0;
        scanf("%d", &n);
        vec.resize(n);
        for (int i = 0; i < n; i++)
            scanf("%d %lf", &vec[i].pow, &vec[i].coe);
    }

    /**
     * @brief 输出
     */
    void print() const {
        vector<Number> tmp = vec;
        for (auto it = tmp.begin(); it != tmp.end();) {
            if (int(it->coe * 10) == 0)
                it = tmp.erase(it);
            else
                it++;
        }
        if (tmp.empty()) {
            printf("0 0 0.0");
        } else {
            printf("%zu %d %.1lf", tmp.size(), tmp[0].pow, tmp[0].coe);
            for (int i = 1; i < tmp.size(); i++)
                printf(" %d %.1lf", tmp[i].pow, tmp[i].coe);
        }
    }

    Poly operator+(const Poly &e) const {
        Poly p;
        auto it = vec.cbegin(), jt = e.vec.cbegin();
        // 类似归并，大的在前，小的在后
        // 注意如果两者相加为零了就不要写进去了
        while (it != vec.cend() && jt != e.vec.cend()) {
            Number n;
            if (it->pow == jt->pow) {
                n.pow = it->pow;
                n.coe = it->coe + jt->coe;
                it++, jt++;
            } else if (it->pow > jt->pow) {
                n = *it;
                it++;
            } else {
                n = *jt;
                jt++;
            }
            if (abs(n.coe) > 1e-5)
                p.vec.push_back(n);
        }
        while (it != vec.cend()) {
            p.vec.push_back(*it);
            it++;
        }
        while (jt != e.vec.cend()) {
            p.vec.push_back(*jt);
            jt++;
        }
        return p;
    }

    Poly operator-(const Poly &e) const {
        Poly p = e;
        for (auto &el : p.vec)
            el.coe *= -1;
        return *this + p;
    }

    void operator+=(const Poly &e) {
        vec = (*this + e).vec;
    }

    void operator-=(const Poly &e) {
        vec = (*this - e).vec;
    }

    /**
     * @brief 模拟手工多项式除法
     * @param e 
     * @return vector<Poly> 有两个Poly元素的数组，第一个是商，第二个是余数
     */
    vector<Poly> operator/(const Poly &e) const {
        vector<Poly> ans(2);

        Poly a{vec}, b{e.vec};

        while (!a.vec.empty() && a.vec[0].pow >= b.vec[0].pow) {
            Number n;
            n.pow = a.vec[0].pow - b.vec[0].pow;
            n.coe = a.vec[0].coe / b.vec[0].coe;
            ans[0].vec.push_back(n);

            Poly t;
            for (const Number &num : b.vec) {
                t.vec.push_back({n.pow + num.pow, n.coe * num.coe});
            }

            a -= t;
        }

        ans[1] = a;

        return ans;
    }
};

int main() {
    Poly a, b;
    a.input(), b.input();
    auto ans = a / b;
    ans[0].print();
    printf("\n");
    ans[1].print();
    return 0;
}