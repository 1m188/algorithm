/**
 * @file L1-020 帅到没朋友.cpp
 * @date 2022-05-18
 */

/*
当芸芸众生忙着在朋友圈中发照片的时候，总有一些人因为太帅而没有朋友。
本题就要求你找出那些帅到没有朋友的人。

输入格式：
输入第一行给出一个正整数N（≤100），是已知朋友圈的个数；
随后N行，每行首先给出一个正整数K（≤1000），为朋友圈中的人数，然后列出一个朋友圈内的所有人——为方便起见，
每人对应一个ID号，为5位数字（从00000到99999），ID间以空格分隔；之后给出一个正整数M（≤10000），
为待查询的人数；随后一行中列出M个待查询的ID，以空格分隔。

注意：没有朋友的人可以是根本没安装“朋友圈”，也可以是只有自己一个人在朋友圈的人。
虽然有个别自恋狂会自己把自己反复加进朋友圈，但题目保证所有K超过1的朋友圈里都至少有2个不同的人。

输出格式：
按输入的顺序输出那些帅到没朋友的人。ID间用1个空格分隔，行的首尾不得有多余空格。
如果没有人太帅，则输出No one is handsome。

注意：同一个人可以被查询多次，但只输出一次。

输入样例1：
3
3 11111 22222 55555
2 33333 44444
4 55555 66666 99999 77777
8
55555 44444 10000 88888 22222 11111 23333 88888

输出样例1：
10000 88888 23333

输入样例2：
3
3 11111 22222 55555
2 33333 44444
4 55555 66666 99999 77777
4
55555 44444 22222 11111

输出样例2：
No one is handsome

代码长度限制
16 KB

时间限制
200 ms

内存限制
64 MB
*/

/* 不算难，但需要注意细节，尤其是输入输出的部分 */

#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_LEN = 99999 + 1;

vector<bool> circle(MAX_LEN);     // 索引是朋友id，内容是这个id有没有朋友
vector<bool> is_checked(MAX_LEN); // 最后输出的时候判断是否查询过

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    while (n--) {
        int k = 0;
        cin >> k;
        if (k <= 0) {
            continue;
        } else if (k == 1) { // 注意这里k为1的时候本来要跳过朋友圈置位的，但后面会有一个id输入，得要把这个id输入骗过去
            cin >> k;
            continue;
        }

        while (k--) {
            int id = 0;
            cin >> id;
            circle[id] = true; // 题目说k超过1的都至少会有两个不同的人，也就是说在k>1的朋友圈里所有人都是有朋友的
        }
    }

    int m = 0;
    cin >> m;

    vector<int> ans;
    while (m--) {
        int id = 0;
        cin >> id;
        if (!is_checked[id] && !circle[id]) {
            ans.push_back(id);
            is_checked[id] = true;
        }
    }

    if (ans.empty())
        cout << "No one is handsome";
    else {
        // 注意题目要求的是5位id数，每个id输出要足够5位，对于从输入转int自动去掉前置0而言，不足的位数用0补齐
        cout << setw(5) << setfill('0') << ans[0];
        for (int i = 1; i < ans.size(); i++)
            cout << ' ' << setw(5) << setfill('0') << ans[i];
    }
}

int main() {
    input();
    return 0;
}