/**
 * @file HJ101 输入整型数组和排序标识，对其元素按照升序或降序进行排序.cpp
 * @date 2024-11-20
 */

/*
描述
输入整型数组和排序标识，对其元素按照升序或降序进行排序

数据范围：
1
≤
n
≤
1000

1≤n≤1000  ，元素大小满足
0
≤
v
a
l
≤
100000

0≤val≤100000
输入描述：
第一行输入数组元素个数
第二行输入待排序的数组，每个数用空格隔开
第三行输入一个整数0或1。0代表升序排序，1代表降序排序

输出描述：
输出排好序的数字

示例1
输入：
8
1 2 4 9 3 55 64 25
0
复制
输出：
1 2 3 4 9 25 55 64
复制
示例2
输入：
5
1 2 3 4 5
1
复制
输出：
5 4 3 2 1
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int flag = 0;
    cin >> flag;
    if (flag) {
        sort(arr.begin(), arr.end(), [](const int &e1, const int &e2) {
            return e1 > e2;
        });
    } else {
        sort(arr.begin(), arr.end());
    }

    cout << arr[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << arr[i];

    return 0;
}
