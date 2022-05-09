/**
 * @file 7-27 家谱处理.cpp
 * @date 2022-05-09
 */

/*
人类学研究对于家族很感兴趣，于是研究人员搜集了一些家族的家谱进行研究。
实验中，使用计算机处理家谱。
为了实现这个目的，研究人员将家谱转换为文本文件。下面为家谱文本文件的实例：

John
  Robert
    Frank
    Andrew
  Nancy
    David
家谱文本文件中，每一行包含一个人的名字。
第一行中的名字是这个家族最早的祖先。
家谱仅包含最早祖先的后代，而他们的丈夫或妻子不出现在家谱中。
每个人的子女比父母多缩进2个空格。
以上述家谱文本文件为例，John这个家族最早的祖先，他有两个子女Robert和Nancy，
Robert有两个子女Frank和Andrew，Nancy只有一个子女David。

在实验中，研究人员还收集了家庭文件，并提取了家谱中有关两个人关系的陈述语句。
下面为家谱中关系的陈述语句实例：

John is the parent of Robert
Robert is a sibling of Nancy
David is a descendant of Robert
研究人员需要判断每个陈述语句是真还是假，请编写程序帮助研究人员判断。

输入格式:
输入首先给出2个正整数N（2≤N≤100）和M（≤100），其中N为家谱中名字的数量，
M为家谱中陈述语句的数量，输入的每行不超过70个字符。

名字的字符串由不超过10个英文字母组成。在家谱中的第一行给出的名字前没有缩进空格。
家谱中的其他名字至少缩进2个空格，即他们是家谱中最早祖先（第一行给出的名字）的后代，
且如果家谱中一个名字前缩进k个空格，则下一行中名字至多缩进k+2个空格。

在一个家谱中同样的名字不会出现两次，且家谱中没有出现的名字不会出现在陈述语句中。
每句陈述语句格式如下，其中X和Y为家谱中的不同名字：

X is a child of Y
X is the parent of Y
X is a sibling of Y
X is a descendant of Y
X is an ancestor of Y
输出格式:
对于测试用例中的每句陈述语句，在一行中输出True，如果陈述为真，或False，如果陈述为假。

输入样例:
6 5
John
  Robert
    Frank
    Andrew
  Nancy
    David
Robert is a child of John
Robert is an ancestor of Andrew
Robert is a sibling of Nancy
Nancy is the parent of Frank
John is a descendant of Andrew

输出样例:
True
True
True
False
False

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 模拟题，考的是树的相关内容，但并不一定真的要构建树，只需要根据空格确定树节点
的层级即可。

对于这个题目，其中需要有5个判断，但其实只要3个就行了，其中有两个其实就是其对应
的函数的另外一种传参顺序形式而已。

注意细节，注意细节，注意细节。尤其是传入的两个节点不一定有严格的先后顺序，
要注意判断相关条件。

因为对于两个名字需要快速找到其所在的位置和其空格数，所以用了unordered_map
来存储名字到索引，然后另一个数组则是索引到空格数。之所以用unordered_map是
因为不会排序，比map排序的要快一点。

题目不算太难，但很考验对细节的把握和对于模型的构建。 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * @brief 关系
 * @param X X is ... of Y
 * @param Y X is ... of Y
 * @param relation 关系，{child, parent, sibling, descendant, ancestor}
 */
struct Relation {
    string X, Y, relation;
};

vector<int> spaces;             // 每行的空格数
unordered_map<string, int> ndx; // 名字到该名字所在行的映射
vector<Relation> statements;    // 每个陈述的关键内容

/**
 * @brief 输入初始化
 */
void input() {
    int N = 0, M = 0;
    cin >> N >> M;

    // 这里要注意，输入之后会有一个回车，而下面又是getline，
    // 如果不吃掉这个回车下面的getline会把这个回车拿下去，
    // 从而造成少输入一行或者输入一行为空的情况
    cin.get();

    while (N--) {
        string s;
        getline(cin, s);
        int sps = 0;
        while (s[0] == ' ') { // 将名字和名字前的空格分开存储
            sps++;
            s.erase(s.begin());
        }
        spaces.push_back(sps);
        ndx[s] = spaces.size() - 1;
    }

    vector<string> vt(6);
    while (M--) { // 输入陈述，将其中的关键词保存下来
        for (int i = 0; i < 6; i++)
            cin >> vt[i];
        statements.push_back({vt[0], vt[5], vt[3]});
    }
}

/**
 * @brief 判断是否是孩子
 * @param parent 待判断的父节点
 * @param child 待判断的子节点
 * @return true 是
 * @return false 否
 */
bool judge_child(const string &parent, const string &child) {
    int pi = ndx[parent], ci = ndx[child];

    // 首先判断父亲应该在孩子的上面，并且孩子比父亲的空格数多2
    if (!(pi < ci && spaces[ci] - spaces[pi] == 2))
        return false;
    // 其次在两个索引中间不能够有其他的兄弟乃至先祖
    for (int i = pi + 1; i < ci; i++)
        if (!(spaces[i] > spaces[pi]))
            return false;

    return true;
}

/**
 * @brief 判断两个节点是否为兄弟
 * @param x 兄弟1
 * @param y 兄弟2
 * @return true 是
 * @return false 否
 */
bool judge_sibling(const string &x, const string &y) {
    int xi = ndx[x], yi = ndx[y];

    // 首先两个兄弟不管谁在上谁在下，反正都是兄弟，空格缩进必须相同
    if (!(spaces[xi] == spaces[yi]))
        return false;
    int mi = min(xi, yi), bi = max(xi, yi);
    // 其次，两个兄弟之间不能够有其他的父辈，最多只能有其他兄弟
    for (int i = mi + 1; i < bi; i++)
        if (!(spaces[i] >= spaces[mi]))
            return false;

    return true;
}

/**
 * @brief 判断是否是祖先
 * @param anc 待判断的祖先节点
 * @param des 待判断的后代节点
 * @return true 是
 * @return false 否
 */
bool judge_descendant(const string &anc, const string &des) {
    int ai = ndx[anc], di = ndx[des];

    // 祖先应该在后代上面并且后代的空格缩进一定要严格大于祖先
    if (!(ai < di && spaces[di] > spaces[ai]))
        return false;
    // 从祖先到后代之间不能够有其他的祖先的兄弟，否则就不是祖先的后代了
    for (int i = ai + 1; i < di; i++)
        if (!(spaces[i] > spaces[ai]))
            return false;

    return true;
}

/**
 * @brief 计算并输出结果
 */
void calc() {
    auto print = [](bool f) { cout << (f ? "True" : "False") << '\n'; };

    for (const auto &state : statements) {
        if (state.relation == "child")
            print(judge_child(state.Y, state.X));
        else if (state.relation == "parent")
            print(judge_child(state.X, state.Y));
        else if (state.relation == "sibling")
            print(judge_sibling(state.X, state.Y));
        else if (state.relation == "descendant")
            print(judge_descendant(state.Y, state.X));
        else
            print(judge_descendant(state.X, state.Y));
    }
}

int main() {
    input();
    calc();
    return 0;
}