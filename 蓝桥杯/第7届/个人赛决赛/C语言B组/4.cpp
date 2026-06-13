/*

机器人塔

X星球的机器人表演拉拉队有两种服装，A和B。
他们这次表演的是搭机器人塔。

类似：

     A
    B B
   A B A
  A A B B
 B B B A B
A B A B B A

队内的组塔规则是：

  A 只能站在 AA 或 BB 的肩上。
  B 只能站在 AB 或 BA 的肩上。

你的任务是帮助拉拉队计算一下，在给定A与B的人数时，可以组成多少种花样的塔。

输入一行两个整数 M 和 N，空格分开（0<M,N<500）,分别表示A、B的人数，保证人数合理性。

要求输出一个整数，表示可以产生的花样种数。

例如：
用户输入：
1 2

程序应该输出：
3


再例如：
用户输入：
3 3

程序应该输出：
4

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms

请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。


*/

#include <cmath>
#include <iostream>
using namespace std;

int M, N, H;
long long ans = 0;

/*
 * 将 A 编码为 0，B 编码为 1，则规则变为：上层 = 下层左 XOR 下层右。
 * 从塔顶向下逐行构建：每行第一个元素可任取 0/1，该行其余元素由上行唯一确定。
 * 塔高 H 满足 H(H+1)/2 = M+N，整个塔由 H 个首元素决定。
 * DFS 枚举每行首元素，逐行计算各位置值并累加 A 的个数，
 * 当 A 数超过 M 时剪枝，到达塔底时若 A 数等于 M 则计数。
 */
void dfs(int r, long long row, int aCnt) {
    if (aCnt > M) return;
    if (r == H) {
        if (aCnt == M) ans++;
        return;
    }
    int len = r + 1;
    long long prevMask = row & ((1LL << (len - 1)) - 1);
    for (int first = 0; first <= 1; first++) {
        long long cur = first;
        int addA = (first == 0);
        for (int j = 1; j < len; j++) {
            int bit = ((cur >> (j - 1)) & 1) ^ ((prevMask >> (j - 1)) & 1);
            cur |= ((long long)bit << j);
            if (bit == 0) addA++;
        }
        dfs(r + 1, cur, aCnt + addA);
    }
}

int main() {
    cin >> M >> N;
    int total = M + N;
    H = (int)((sqrt(1.0 + 8.0 * total) - 1) / 2);
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}
