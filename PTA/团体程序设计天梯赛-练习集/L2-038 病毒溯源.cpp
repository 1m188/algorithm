/**
 * @file L2-038 病毒溯源.cpp
 * @date 2022-06-19
 */

/*
V.JPG
病毒容易发生变异。某种病毒可以通过突变产生若干变异的毒株，而这些变异的病毒又可能被诱发突变产生第二代变异，如此继续不断变化。

现给定一些病毒之间的变异关系，要求你找出其中最长的一条变异链。

在此假设给出的变异都是由突变引起的，不考虑复杂的基因重组变异问题 —— 即每一种病毒都是由唯一的一种病毒突变而来，并且不存在循环变异的情况。

输入格式：
输入在第一行中给出一个正整数 N（≤10 
4
 ），即病毒种类的总数。于是我们将所有病毒从 0 到 N−1 进行编号。

随后 N 行，每行按以下格式描述一种病毒的变异情况：

k 变异株1 …… 变异株k
其中 k 是该病毒产生的变异毒株的种类数，后面跟着每种变异株的编号。第 i 行对应编号为 i 的病毒（0≤i<N）。题目保证病毒源头有且仅有一个。

输出格式：
首先输出从源头开始最长变异链的长度。

在第二行中输出从源头开始最长的一条变异链，编号间以 1 个空格分隔，行首尾不得有多余空格。如果最长链不唯一，则输出最小序列。

注：我们称序列 { a 
1
​
 ,⋯,a 
n
​
  } 比序列 { b 
1
​
 ,⋯,b 
n
​
  } “小”，如果存在 1≤k≤n 满足 a 
i
​
 =b 
i
​
  对所有 i<k 成立，且 a 
k
​
 <b 
k
​
 。

输入样例：
10
3 6 4 8
0
0
0
2 5 9
0
1 7
1 2
0
2 3 1
输出样例：
4
0 4 9 1
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

/* dfs求最长路径 */

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector<bool> flags;
int n = 0, start = -1;
vector<int> maxlink, currlink;

void dfs(int curr = start) {
    currlink.push_back(curr);
    flags[curr] = true;

    for (const int &i : g[curr]) {
        if (!flags[i])
            dfs(i);
    }

    if (currlink.size() > maxlink.size()) {
        maxlink = currlink;
    }

    currlink.pop_back();
}

int main() {

    scanf("%d", &n);
    g.resize(n);
    flags.resize(n, true);

    for (int i = 0; i < n; i++) {
        int k = 0;
        scanf("%d", &k);
        while (k--) {
            int a = 0;
            scanf("%d", &a);
            g[i].push_back(a);
            flags[a] = false;
        }
    }
    for (auto &e : g)
        sort(e.begin(), e.end());

    for (int i = 0; i < n; i++) {
        if (flags[i]) {
            start = i;
            break;
        }
    }
    flags = vector<bool>(n);

    dfs();

    printf("%zu\n", maxlink.size());
    printf("%d", maxlink[0]);
    for (int i = 1; i < maxlink.size(); i++)
        printf(" %d", maxlink[i]);

    return 0;
}