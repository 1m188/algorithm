/*

形如：1/a 的分数称为单位分数。

可以把1分解为若干个互不相同的单位分数之和。
例如：
1 = 1/2 + 1/3 + 1/9 + 1/18
1 = 1/2 + 1/3 + 1/10 + 1/15
1 = 1/3 + 1/5 + 1/7 + 1/9 + 1/11 + 1/15 + 1/35 + 1/45 + 1/231
等等，类似这样的分解无穷无尽。

我们增加一个约束条件：最大的分母必须不超过30

请你求出分解为n项时的所有不同分解法。

数据格式要求：

输入一个整数n，表示要分解为n项（n<12）
输出分解后的单位分数项，中间用一个空格分开。
每种分解法占用一行，行间的顺序按照分母从小到大排序。

例如，
输入：
4
程序应该输出：
1/2 1/3 1/8 1/24
1/2 1/3 1/9 1/18
1/2 1/3 1/10 1/15
1/2 1/4 1/5 1/20
1/2 1/4 1/6 1/12

再例如，
输入：
5
程序应该输出：
1/2 1/3 1/12 1/21 1/28
1/2 1/4 1/6 1/21 1/28
1/2 1/4 1/7 1/14 1/28
1/2 1/4 1/8 1/12 1/24
1/2 1/4 1/9 1/12 1/18
1/2 1/4 1/10 1/12 1/15
1/2 1/5 1/6 1/12 1/20
1/3 1/4 1/5 1/6 1/20


资源约定：
峰值内存消耗 < 256M
CPU消耗  < 2000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。


*/

#include <iostream>
#include <vector>
using namespace std;

const int MAX_DENOM = 30;
int n;
vector<int> path;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool canReach(int start, int remain, int targetNum, int targetDen) {
    double sum = 0.0;
    for (int i = 0; i < remain; i++) {
        sum += 1.0 / (start + i);
    }
    return sum >= (double)targetNum / targetDen;
}

void dfs(int start, int remain, int num, int den) {
    if (remain == 0) {
        if (num == 0) {
            for (int i = 0; i < n; i++) {
                if (i > 0) cout << " ";
                cout << "1/" << path[i];
            }
            cout << endl;
        }
        return;
    }

    if (num <= 0 && remain > 0) return;

    if (remain == 1) {
        if (num == 1 && den >= start && den <= MAX_DENOM) {
            path.push_back(den);
            for (int i = 0; i < n; i++) {
                if (i > 0) cout << " ";
                cout << "1/" << path[i];
            }
            cout << endl;
            path.pop_back();
        }
        return;
    }

    int dMin = max(start, (den + num - 1) / num);
    if (dMin > MAX_DENOM) return;

    for (int d = dMin; d <= MAX_DENOM; d++) {
        if (!canReach(d, remain, num, den)) break;

        int newNum = num * d - den;
        int newDen = den * d;
        int g = gcd(newNum, newDen);
        newNum /= g;
        newDen /= g;

        path.push_back(d);
        dfs(d + 1, remain - 1, newNum, newDen);
        path.pop_back();
    }
}

int main() {
    cin >> n;
    dfs(2, n, 1, 1);
    return 0;
}
