/*
BISHI4 【模板】集合操作

描述
您需要动态地维护一个初始为空的集合
M
M，并且支持以下操作：

∙
 
∙操作
1
1：向集合
M
M 中插入一个数
x
x，如果
x
x 在集合
M
M 中已经存在，则忽略本次操作。
∙
 
∙操作
2
2：从集合
M
M 中删除一个数
x
x，如果
x
x 不在集合
M
M 中，则忽略本次操作。
∙
 
∙操作
3
3：查询一个数
x
x 是否在集合
M
M 中。如果存在，输出
YES
YES；否则输出
NO
NO。
∙
 
∙操作
4
4：查询集合
M
M 中元素的个数，即集合
M
M 的大小。
∙
 
∙操作
5
5：查询集合
M
M 中
x
x 的前驱（前驱定义为小于
x
x 且最大的数），如果前驱不存在，则输出
−
1
−1。
∙
 
∙操作
6
6：查询集合
M
M 中
x
x 的后继（后继定义为大于
x
x 且最小的数），如果后继不存在，则输出
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
 ），表示操作的个数。
接下来
n
n 行，每行表示一次操作。对于操作
1
、
2
、
3
、
5
、
6
1、2、3、5、6，输入两个整数
opt
opt 和
x
x（
1
≦
opt
≦
6
1≦opt≦6，
0
≦
x
≦
1
0
6
0≦x≦10
6
 ），分别表示操作类型和操作的参数；对于操作
4
4，输入两个整数
opt
opt ，表示操作类型。
输出描述：
对于操作类型为
3
、
4
、
5
、
6
3、4、5、6 的每次操作，按照题意输出对应的查询结果，每个结果占一行。
示例1
输入：
4
1 4
4
2 4
3 4
复制
输出：
1
NO
复制
说明：
第一步插入操作向集合
M
M 中插入了元素
4
4；
第二步查询操作类型为
4
4，查询集合大小，当前集合中只有元素
4
4，大小为
1
1，因此输出
1
1；
第三步删除了集合
M
M 中的元素
4
4；
第四步查询元素
4
4 是否在集合
M
M 中，不在，故输出
NO
NO。
示例2
输入：
5
1 5
1 10
1 20
5 15
6 15
复制
输出：
10
20
复制
说明：
前三步插入操作使集合
M
=
{
5
,
10
,
20
}
M={5,10,20}；
第四步操作类型为
5
5，查询前驱，数字
15
15 在集合中前驱为
10
10，输出
10
10；
第五步操作类型为
6
6，查询后继，数字
15
15 在集合中后继为
20
20，输出
20
20。
*/

#include <iostream>
#include <set>
using namespace std;

set<int> s;

void insertValue(int x) {
    // TODO 实现插入逻辑
    s.insert(x);
}
void eraseValue(int x) {
    // TODO 实现删除逻辑
    auto it = s.find(x);
    if (it != s.end()) s.erase(it);
}
int xInSet(int x) {
    // TODO 实现存在性检查
    return s.find(x) != s.end();
}
int sizeOfSet() {
    // TODO 返回集合大小
    return s.size();
}
int getPre(int x) {
    // TODO 实现找前驱
    auto it = s.lower_bound(x);
    if (it == s.begin()) return -1;
    return *(--it);
}
int getBack(int x) {
    // TODO 实现找后继
    auto it = s.upper_bound(x);
    if (it == s.end()) return -1;
    return *it;
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
            if (xInSet(x)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
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