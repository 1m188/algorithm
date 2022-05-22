/**
 * @file L2-007 家庭房产.cpp
 * @date 2022-05-22
 */

/*
给定每个人的家庭成员和其自己名下的房产，请你统计出每个家庭的人口数、人均房产面积及房产套数。

输入格式：
输入第一行给出一个正整数N（≤1000），随后N行，每行按下列格式给出一个人的房产：

编号 父 母 k 孩子1 ... 孩子k 房产套数 总面积
其中编号是每个人独有的一个4位数的编号；
父和母分别是该编号对应的这个人的父母的编号（如果已经过世，则显示-1）；
k（0≤k≤5）是该人的子女的个数；孩子i是其子女的编号。

输出格式：
首先在第一行输出家庭个数（所有有亲属关系的人都属于同一个家庭）。随后按下列格式输出每个家庭的信息：

家庭成员的最小编号 家庭人口数 人均房产套数 人均房产面积
其中人均值要求保留小数点后3位。家庭信息首先按人均面积降序输出，若有并列，则按成员编号的升序输出。

输入样例：
10
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 -1 0 2 300
3721 -1 -1 1 2333 2 150
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 -1 3721 3 6661 6662 6663 1 100

输出样例：
3
8888 1 1.000 1000.000
0001 15 0.600 100.000
5551 4 0.750 100.000

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 并   查   集

整体的思想是，数组并查集基本结构不多说，每个节点还并有一个总房子和总面积，
对于一个集合而言，用其中编号最小的当作其代表（并查集树根），并且存储该户人家
的总面积和总房产，其他所有节点都指向这个节点，最后计算指向非自己节点的节点
有多少个，其被指向的节点就是最小编号，并且其中所含总房产和总面积除以所有人
就是平均值，最后按照规定输出 */

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

/**
 * @brief 并查集中的节点
 */
struct Node {
    int pre = -1;        // 父节点（家族中最小编号者）
    int total_house = 0; // 家族总房产（如果这个节点是编号最小）
    int total_area = 0;  // ...总面积...
    bool flag = false;   // 表示这个节点是否是输入的节点，在最后统计人数的时候统计输入表示的节点，其他虽然在数组中但是未被提到的节点都当作不存在
};

/**
 * @brief 家族结构体
          
          用来存储最终的结果
 */
struct Home {
    int min_id = -1;      // 家族中编号最小的编号
    int num = 0;          // 家族人数
    double house_per = 0; // 平均房产
    double area_per = 0;  // 平均面积
};

vector<Node> ufset(9999 + 1); // 并查集（索引为编号，内容为其父节点（家族中编号最小者））

/**
 * @brief 并查集找到节点的最终根节点，并且使用路径压缩
 * @param x 要找其根节点的节点
 * @return int 结果
 */
int uffind(int x) {
    return ufset[x].pre == x ? x : (ufset[x].pre = uffind(ufset[x].pre));
}

/**
 * @brief 合并两个节点所在的集合
 * @param x 其中一个节点
 * @param y 另一个节点
 */
void ufunion(int x, int y) {
    x = uffind(x), y = uffind(y);
    if (x < y) { // 这里是按照编号较小者合并
        ufset[y].pre = x;
    } else {
        ufset[x].pre = y;
    }
}

/**
 * @brief 输入
 */
void input() {

    for (int i = 0; i < ufset.size(); i++)
        ufset[i].pre = i;

    int n = 0; // 总人数
    scanf("%d", &n);

    while (n--) {

        vector<int> tmp;

        int x = 0;
        scanf("%d", &x); // 自己编号
        tmp.push_back(x);
        ufset[x].flag = true;

        scanf("%d", &x); // 父亲编号
        if (x != -1)
            tmp.push_back(x);

        scanf("%d", &x); // 母亲编号
        if (x != -1)
            tmp.push_back(x);

        int k = 0;
        scanf("%d", &k); // 总孩子数
        while (k--) {
            scanf("%d", &x);
            tmp.push_back(x);
        }

        int house = 0, area = 0; // 该户人家的房子和面积
        scanf("%d %d", &house, &area);

        // 用该户人家最小编号者存储这户人家的房子和面积
        int root = *min_element(tmp.begin(), tmp.end());
        ufset[root].total_house += house;
        ufset[root].total_area += area;

        // 合并该户最小者和其中的每个节点
        // 如果其中没有人指向别的节点，就会指向这个最小者
        // 如果有人指向别的节点，就会指向两者中更小的
        // 最后两个集合合并，所有节点最终只有一个根
        for (const int &i : tmp) {
            ufset[i].flag = true;
            ufunion(root, ufset[i].pre);
        }
    }
}

/**
 * @brief 计算并输出
 */
void calc() {

    vector<int> population(ufset.size());     // 人口
    vector<double> total_house(ufset.size()), // 总房子
        total_area(ufset.size());             // 总面积

    for (int i = 0; i < ufset.size(); i++) {
        int pre = uffind(i);                      // 先给最终结果每个指向根，并做路径压缩
        population[pre]++;                        // 人口++
        total_house[pre] += ufset[i].total_house; // 根中总房子+=每个指向它的节点的总房子，如果这个节点是这户人家最小编号者就加上去了，如果不是则其会为0，不对最终结果产生影响
        total_area[pre] += ufset[i].total_area;
    }

    // 开始求最终结果
    vector<Home> home;
    for (int i = 0; i < population.size(); i++) {
        // 指向自己（为根）
        // 并且是一个输入涉及的节点
        if (ufset[i].flag && ufset[i].pre == i) {
            Home t;
            t.min_id = i;
            t.num = population[i];
            t.house_per = total_house[i] / t.num;
            t.area_per = total_area[i] / t.num;
            home.push_back(t);
        }
    }

    // 按要求排序
    sort(home.begin(), home.end(), [](const Home &e1, const Home &e2) {
        if (e1.area_per != e2.area_per)
            return e1.area_per > e2.area_per;
        else
            return e1.min_id < e2.min_id;
    });

    // 顺序输出
    printf("%zu\n", home.size());
    for (const auto &e : home) {
        printf("%04d %d %.3lf %.3lf\n", e.min_id, e.num, e.house_per, e.area_per);
    }
}

int main() {
    input();
    calc();
    return 0;
}