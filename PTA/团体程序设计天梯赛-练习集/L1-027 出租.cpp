/**
 * @file L1-027 出租.cpp
 * @date 2022-05-18
 */

/*
下面是新浪微博上曾经很火的一张图：



一时间网上一片求救声，急问这个怎么破。其实这段代码很简单，index数组就是arr数组的下标，
index[0]=2 对应 arr[2]=1，index[1]=0 对应 arr[0]=8，index[2]=3 对应 arr[3]=0，以此类推…… 
很容易得到电话号码是18013820100。

本题要求你编写一个程序，为任何一个电话号码生成这段代码 —— 事实上，只要生成最前面两行就可以了，
后面内容是不变的。

输入格式：
输入在一行中给出一个由11位数字组成的手机号码。

输出格式：
为输入的号码生成代码的前两行，其中arr中的数字必须按递减顺序给出。

输入样例：
18013820100

输出样例：
int[] arr = new int[]{8,3,2,1,0};
int[] index = new int[]{3,0,4,3,1,0,2,4,3,4,4};

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 存储每个数字和其索引的映射 */

#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

string pnum;                    // 电话号码
vector<int> arr,                // 电话号码组成元素
    indexvec;                   // 电话号码中每个数字在arr中的索引
map<int, int, greater<int>> mp; // 存储电话号码组成元素与其从大到小排列的索引的映射，使用greater从大到小排列

/**
 * @brief 输入
 */
void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> pnum;
}

/**
 * @brief 计算并给两个数组赋值
 */
void calc() {

    for (const char &c : pnum)
        mp[c - '0'] = 0;

    int idx = 0;
    for (auto &e : mp) {
        e.second = idx++;
        arr.push_back(e.first);
    }

    for (const char &c : pnum)
        indexvec.push_back(mp[c - '0']);
}

/**
 * @brief 按格式要求输出
 */
void print() {
    cout << "int[] arr = new int[]{";
    cout << arr[0];
    for (int i = 1; i < arr.size(); i++)
        cout << ',' << arr[i];
    cout << "};\n";

    cout << "int[] index = new int[]{";
    cout << indexvec[0];
    for (int i = 1; i < indexvec.size(); i++)
        cout << ',' << indexvec[i];
    cout << "};";
}

int main() {
    input();
    calc();
    print();
    return 0;
}