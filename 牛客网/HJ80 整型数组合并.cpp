/**
 * @file HJ80 整型数组合并.cpp
 * @date 2024-11-28
 */

/*
描述
题目标题：

将两个整型数组按照升序合并，并且过滤掉重复数组元素。
输出时相邻两数之间没有空格。



输入描述：
输入说明，按下列顺序输入：
1 输入第一个数组的个数
2 输入第一个数组的数值
3 输入第二个数组的个数
4 输入第二个数组的数值

输出描述：
输出合并之后的数组

示例1
输入：
3
1 2 5
4
-1 0 3 2
复制
输出：
-101235

*/

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1 = 0;
    cin >> n1;
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];
    sort(arr1.begin(), arr1.end());

    int n2 = 0;
    cin >> n2;
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];
    sort(arr2.begin(), arr2.end());

    unordered_set<int> uset;
    vector<int> res;
    int idx1 = 0, idx2 = 0;
    while (idx1 < arr1.size() && idx2 < arr2.size()) {
        if (arr1[idx1] < arr2[idx2]) {
            if (uset.find(arr1[idx1]) != uset.end()) {
                idx1++;
            } else {
                uset.insert(arr1[idx1]);
                res.push_back(arr1[idx1++]);
            }
        } else {
            if (uset.find(arr2[idx2]) != uset.end()) {
                idx2++;
            } else {
                uset.insert(arr2[idx2]);
                res.push_back(arr2[idx2++]);
            }
        }
    }
    while (idx1 < arr1.size()) {
        if (uset.find(arr1[idx1]) != uset.end()) {
            idx1++;
        } else {
            uset.insert(arr1[idx1]);
            res.push_back(arr1[idx1++]);
        }
    }
    while (idx2 < arr2.size()) {
        if (uset.find(arr2[idx2]) != uset.end()) {
            idx2++;
        } else {
            uset.insert(arr2[idx2]);
            res.push_back(arr2[idx2++]);
        }
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
    }

    return 0;
}
