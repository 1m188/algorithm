/*
BISHI5 【模板】多重集合操作

描述
维护一个初始为空的多重集合
M
M，支持如下六种操作：
∙
 
∙操作 1：向集合
M
M 插入一个整数
x
x。
∙
 
∙操作 2：从集合
M
M 删除一个整数
x
x，若
x
x 不存在，则忽略；若存在多个，则只删除一个。
∙
 
∙操作 3：查询整数
x
x 在集合
M
M 中的个数。
∙
 
∙操作 4：查询集合
M
M 中元素的总个数（含重复计数）。
∙
 
∙操作 5：查询整数
x
x 在集合
M
M 中的前驱（定义为小于
x
x 的最大元素），若不存在则返回
−
1
−1。
∙
 
∙操作 6：查询整数
x
x 在集合
M
M 中的后继（定义为大于
x
x 的最小元素），若不存在则返回
−
1
−1。
输入描述：
第一行输入一个整数
n
n（
1
≦
n
≦
1
0
5
1≦n≦10
5
 ），表示操作总数。
接下来
n
n 行，每行输入两个整数
opt
opt 和
x
x（
0
≦
∣
x
∣
≦
1
0
6
0≦∣x∣≦10
6
 ），
opt
opt 表示操作类型，
1
≦
opt
≦
6
1≦opt≦6。
输出描述：
对于每个操作 3、4、5、6，在一行中输出一个整数，表示对应操作的查询结果。
示例1
输入：
2
1 1
3 1
复制
输出：
1
复制
说明：
首先插入
1
1，然后查询
1
1 在集合中的个数为
1
1。
示例2
输入：
6
1 2
1 2
3 2
2 2
3 2
4 0
复制
输出：
2
1
1
复制
说明：
在两次插入
2
2 后，查询个数为
2
2；删除一次后，查询个数为
1
1；最后查询集合大小，当前集合中仅有一个
2
2，故输出
1
1。
*/

#include <iostream>
#include <map>
using namespace std;

std::map<int, int> mp;
int totalSize = 0;

void insertValue(int x) {
    // TODO 实现插入逻辑
    if (auto it = mp.find(x); it == mp.end()) {
        mp.insert({x, 1});
    } else {
        it->second++;
    }
    totalSize++;
}
void eraseValue(int x) {
    // TODO 实现删除逻辑
    if (auto it = mp.find(x); it != mp.end()) {
        if (--it->second == 0) {
            mp.erase(it);
        }
        totalSize--;
    }
}
int xCount(int x) {
    // TODO 求x在集合中的个数
    auto it = mp.find(x);
    return it == mp.end() ? 0 : it->second;
}
int sizeOfSet() {
    // TODO 返回集合大小
    return totalSize;
}
int getPre(int x) {
    // TODO 实现找前驱
    auto it = mp.lower_bound(x);
    return it == mp.begin() ? -1 : (--it)->first;
}
int getBack(int x) {
    // TODO 实现找后继
    auto it = mp.upper_bound(x);
    return it == mp.end() ? -1 : it->first;
}

int main() {
    int q, op, x;
    cin >> q;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> x;
            insertValue(x);
        }
        if (op == 2) {
            cin >> x;
            eraseValue(x);
        }
        if (op == 3) {
            cin >> x;
            cout << xCount(x) << endl;
        }
        if (op == 4) {
            cout << sizeOfSet() << endl;
        }
        if (op == 5) {
            cin >> x;
            cout << getPre(x) << endl;
        }
        if (op == 6) {
            cin >> x;
            cout << getBack(x) << endl;
        }
    }
    return 0;
}