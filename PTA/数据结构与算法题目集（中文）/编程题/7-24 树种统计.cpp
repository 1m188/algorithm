/**
 * @file 7-24 树种统计.cpp
 * @date 2022-05-08
 */

/*
随着卫星成像技术的应用，自然资源研究机构可以识别每一棵树的种类。
请编写程序帮助研究人员统计每种树的数量，计算每种树占总数的百分比。

输入格式:
输入首先给出正整数N（≤10^5），随后N行，每行给出卫星观测到的一棵树的种类名称。
种类名称由不超过30个英文字母和空格组成（大小写不区分）。

输出格式:
按字典序递增输出各种树的种类名称及其所占总数的百分比，其间以空格分隔，保留小数点后4位。

输入样例:
29
Red Alder
Ash
Aspen
Basswood
Ash
Beech
Yellow Birch
Ash
Cherry
Cottonwood
Ash
Cypress
Red Elm
Gum
Hackberry
White Oak
Hickory
Pecan
Hard Maple
White Oak
Soft Maple
Red Oak
Red Oak
White Oak
Poplan
Sassafras
Sycamore
Black Walnut
Willow

输出样例:
Ash 13.7931%
Aspen 3.4483%
Basswood 3.4483%
Beech 3.4483%
Black Walnut 3.4483%
Cherry 3.4483%
Cottonwood 3.4483%
Cypress 3.4483%
Gum 3.4483%
Hackberry 3.4483%
Hard Maple 3.4483%
Hickory 3.4483%
Pecan 3.4483%
Poplan 3.4483%
Red Alder 3.4483%
Red Elm 3.4483%
Red Oak 6.8966%
Sassafras 3.4483%
Soft Maple 3.4483%
Sycamore 3.4483%
White Oak 10.3448%
Willow 3.4483%
Yellow Birch 3.4483%

代码长度限制
16 KB

时间限制
1500 ms

内存限制
64 MB
*/

/* 挺简单的，利用C++里的map很容易，注意map天然按照key来排序，所以还可以省略掉后续的
排序过程，直接输出就行了，注意iostream对于小数点精度输出的设置方法 */

#include <iomanip>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> mp; // 存储 树-数目 键值对的map，并且按照key的字典序排序
int N = 0;           // 树的总数目

/**
 * @brief 输入初始化
 */
void input() {
    cin >> N;
    cin.get();
    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        mp[s]++;
    }
}

/**
 * @brief 输出结果
 */
void print() {
    cout << setiosflags(ios::fixed) << setprecision(4);
    for (const auto &e : mp) {
        cout << e.first << ' ' << double(e.second) / N * 100 << "%\n";
    }
}

int main() {
    input();
    print();
    return 0;
}