/*
给定大量手机用户通话记录，找出其中通话次数最多的聊天狂人。

输入格式:
输入首先给出正整数N（≤10^5），为通话记录条数。
随后N行，每行给出一条通话记录。
简单起见，这里只列出拨出方和接收方的11位数字构成的手机号码，其中以空格分隔。

输出格式:
在一行中给出聊天狂人的手机号码及其通话次数，其间以空格分隔。
如果这样的人不唯一，则输出狂人中最小的号码及其通话次数，并且附加给出并列狂人的人数。

输入样例:
4
13005711862 13588625832
13505711862 13088625832
13588625832 18087925832
15005713862 13588625832

输出样例:
13588625832 3

代码长度限制
16 KB

时间限制
600 ms

内存限制
64 MB
*/

#include <iostream>
#include <map>

using namespace std;

int N = 0;
map<long long, int> mp; // 存储（电话号码：通话次数）键值对，并且按照电话号码大小排序

// 处理初始化输入
void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long t1 = 0, t2 = 0;
        cin >> t1 >> t2;
        mp[t1]++, mp[t2]++; // 两个电话号码都通话次数+1
    }
}

/* 这里很巧妙，参考了网上的做法，我最开始想的是map按照电话号码排序，但是要求的是通话次数最多的号码，
后来还用了vector，其实完全没必要，这里只需要遍历一遍，如果有号码的通话次数更高的话，则更新电话号码、
通话次数和电话号码的个数，如果有相等的话则记录电话号码的个数，到最后必然是通话次数最高的电话号码，
如果有通话次数相同的电话号码的话肯定是最小的电话号码。 */
void print() {
    long long pn = mp.begin()->first;
    int num = mp.begin()->second;
    int count = 0;
    for (const auto &e : mp) {
        if (e.second == num)
            count++;
        else if (e.second > num) {
            pn = e.first;
            num = e.second;
            count = 1;
        }
    }
    cout << pn << ' ' << num;
    if (count > 1)
        cout << ' ' << count;
}

int main() {
    input();
    print();
    return 0;
}