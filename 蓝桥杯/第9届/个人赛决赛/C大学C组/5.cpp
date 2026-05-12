/*

标题：交换次数

IT产业人才需求节节攀升。业内巨头百度、阿里巴巴、腾讯（简称BAT）在某海滩进行招聘活动。
招聘部门一字排开。由于是自由抢占席位，三大公司的席位随机交错在一起，形如：
ABABTATT，这使得应聘者十分别扭。
于是，管理部门要求招聘方进行必要的交换位置，使得每个集团的席位都挨在一起。即最后形如：
BBAAATTT 这样的形状，当然，也可能是：
AAABBTTT 等。

现在，假设每次只能交换2个席位，并且知道现在的席位分布，
你的任务是计算：要使每个集团的招聘席位都挨在一起需要至少进行多少次交换动作。

输入是一行n个字符（只含有字母B、A或T），表示现在的席位分布。
输出是一个整数，表示至少交换次数。

比如，输入：
TABTABBTTTT

程序应该输出：
3

再比如，输入：
TTAAABB

程序应该输出：
0

我们约定，输入字符串的长度n 不大于10万

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms

请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。



*/

#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    // 统计每种字符的总数
    int cnt[3] = {0}; // 0=A, 1=B, 2=T
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A')
            cnt[0]++;
        else if (s[i] == 'B')
            cnt[1]++;
        else
            cnt[2]++; // 'T'
    }

    // 6 种目标排列
    int perm[6][3] = {
        {0, 1, 2}, // A B T
        {0, 2, 1}, // A T B
        {1, 0, 2}, // B A T
        {1, 2, 0}, // B T A
        {2, 0, 1}, // T A B
        {2, 1, 0}  // T B A
    };
    char ch[3] = {'A', 'B', 'T'};

    int ans = INT_MAX;

    for (int p = 0; p < 6; p++) {
        int c0 = cnt[perm[p][0]]; // 第一个字符的个数
        int c1 = cnt[perm[p][1]]; // 第二个字符的个数
        // c2 = cnt[perm[p][2]] 实际上不需要

        char x = ch[perm[p][0]];
        char y = ch[perm[p][1]];
        char z = ch[perm[p][2]];

        int xy = 0, xz = 0; // X 区中 Y 和 Z 的个数
        int yx = 0, yz = 0; // Y 区中 X 和 Z 的个数
        int zx = 0, zy = 0; // Z 区中 X 和 Y 的个数

        // 扫描 X 区 [0, c0)
        for (int i = 0; i < c0; i++) {
            if (s[i] == y)
                xy++;
            else if (s[i] == z)
                xz++;
        }
        // 扫描 Y 区 [c0, c0+c1)
        for (int i = c0; i < c0 + c1; i++) {
            if (s[i] == x)
                yx++;
            else if (s[i] == z)
                yz++;
        }
        // 扫描 Z 区 [c0+c1, n)
        for (int i = c0 + c1; i < n; i++) {
            if (s[i] == x)
                zx++;
            else if (s[i] == y)
                zy++;
        }

        // 直接两两交换
        int sxy = min(xy, yx);
        int sxz = min(xz, zx);
        int syz = min(yz, zy);

        // 剩余错位元素形成三元环
        int R = (xy - sxy) + (xz - sxz);

        int total = sxy + sxz + syz + 2 * R;
        if (total < ans) ans = total;
    }

    cout << ans << endl;
    return 0;
}
