/**
 * @file L2-026 小字辈.cpp
 * @date 2022-06-12
 */

/*
本题给定一个庞大家族的家谱，要请你给出最小一辈的名单。

输入格式：
输入在第一行给出家族人口总数 N（不超过 100 000 的正整数） —— 简单起见，我们把家族成员从 1 到 N 编号。随后第二行给出 N 个编号，其中第 i 个编号对应第 i 位成员的父/母。家谱中辈分最高的老祖宗对应的父/母编号为 -1。一行中的数字间以空格分隔。

输出格式：
首先输出最小的辈分（老祖宗的辈分为 1，以下逐级递增）。然后在第二行按递增顺序输出辈分最小的成员的编号。编号间以一个空格分隔，行首尾不得有多余空格。

输入样例：
9
2 6 5 5 -1 5 6 4 7
输出样例：
4
1 9
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

/* 从节点往上遍历到根，求出节点深度，在这个过程中要记得保留遍历路径上的所有节点的路径
深度，在下次需要的时候就不用再求一遍 */

#include <cstdio>
#include <vector>
using namespace std;

struct Node {
    int parent = -1;
    int depth = -1;
};

vector<Node> vec;  // 存储节点的数组
int n = 0;         // 总节点数
vector<int> ans;   // 最终结果
int max_depth = 0; // 最大深度（最小辈分）

void get_depth() {
    for (int i = 1; i <= n; i++) {
        if (vec[i].depth != -1) continue; // 已经被设置过深度，跳过

        int depth = 0;
        for (int x = i; x != -1; x = vec[x].parent) {
            if (vec[x].depth != -1) { // 如果碰到了已经设置过深度的节点
                depth += vec[x].depth;
                break;
            }
            depth++;
        }

        if (depth > max_depth) {
            max_depth = depth;
            ans = {i};
        } else if (depth == max_depth)
            ans.push_back(i);

        for (int x = i; x != -1; x = vec[x].parent) {
            if (vec[x].depth != -1) break; // 如果碰到了已经设置过深度的节点
            vec[x].depth = depth--;
        }
    }
}

int main() {

    scanf("%d", &n);
    vec.resize(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &vec[i].parent);

    get_depth();

    printf("%d\n%d", max_depth, ans[0]);
    for (int i = 1; i < ans.size(); i++)
        printf(" %d", ans[i]);

    return 0;
}