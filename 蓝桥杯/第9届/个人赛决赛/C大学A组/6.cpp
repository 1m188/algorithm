/*

标题：采油

LQ公司是世界著名的石油公司，为世界供应优质石油。
最近，LQ公司又在森林里发现了一大片区域的油田，可以在这个油田中开采n个油井。
LQ公司在这n个油井之间修建了n-1条道路，每条道路连接两个油井，路径中间不会路过任何油井，而且这些道路将所有油井连通。
建立油井的时候需要使用一台大型设备，运输起来非常麻烦，LQ公司准备在其中的一个油井位置建立一个空运站，先将设备空运到空运站，之后每次经过他们建立的道路来运输这个大型设备以建立不同的油井，当油井建立完毕后再从空运站将大型设备运走。
为了减少运输的麻烦，公司要求大型设备在道路上运输的总路程是最短的。

在建立油井和采油的过程中需要花费一些人力，第i个油井需要花费Bi个人，而一旦油井建成，就需要Si个人一直坚守在油井上进行维护。
当然，如果一个人参与了油井的建设，他可以直接留下来维护油井，或者参与下一个油井的建设，但是在维护油井的人不能再参加后续油井的建设了。

现在LQ公司想知道，大型设备运输的总路径长度最短是多少？在保证总路径长度最短的情况下，LQ公司至少需要花费多少人力才能完成所有油井的建立与维护。

【输入格式】
　　输入的第一行包含一个整数n，表示油井的数量。油井由1到n依次标号。
　　第二行包含n个整数，依次表示B1, B2, …, Bn，相邻的整数之间用一个空格分隔。
　　第三行包含n个整数，依次表示S1, S2, …, Sn，相邻的整数之间用一个空格分隔。
　　接下来n-1行描述油井之间的道路，其中的第i行包含两个整数a，b，用一个空格分隔，表示一条道路的起点为i+1、终点为a，长度为b，道路是双向的，设备可以从任意一端运送到另一端，每条道路都可以经过任意多次。数据保证任意两个油井之间都可以通过道路连接。

【输出格式】
　　输出包含两个整数，用一个空格分隔，表示最优情况下大型设备需要运输的总路程，以及在总路程最短的情况下最少需要花费的人力数量。

【样例输入】
2
10 20
15 15
1 8

【样例输出】
16 30

【样例说明】
　　有两种方案达到最优。
　　方案一：在油井2建立空运站，先建立油井2，再将大型设备运输到油井1建立油井1，最后将大型设备运回油井2。
　　方案二：在油井1建立空运站，先将大型设备运输到油井2建立油井2，再将大型设备运送到油井1建立油井1。

【样例输入】
6
3 10 20 7 15 9
2 6 10 4 8 7
1 9
1 2
2 5
3 4
3 7

【样例输出】
54 38

【数据规模和约定】
　　对于20%的数据：n不超过10；
　　另外20%的数据：每个油井最多和两个油井之间有道路直接连接；
　　另外10%的数据：有n-1个油井只有一条道路与其他油井连接；
　　对于100%的数据：n不超过100000，B、S、c均为不超过10000的正整数。

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
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 100005;

int n;
ll B[MAXN], S[MAXN];
vector<pair<int, ll>> adj[MAXN];
ll total_weight = 0;
ll sum_S = 0;

ll c[MAXN], d[MAXN];

ll down_C[MAXN], down_D[MAXN];
ll up_C[MAXN], up_D[MAXN];

// 按 C 降序排序，计算聚合值 (C, D)
// f(P) = max(C, P - D)
pll aggregate(vector<pll> &items) {
    if (items.empty()) return {0, 0};
    sort(items.begin(), items.end(),
         [](const pll &a, const pll &b) { return a.first > b.first; });
    ll total_D = 0;
    for (auto &it : items)
        total_D += it.second;
    ll suffix = total_D;
    ll best_C = -1e18;
    for (auto &it : items) {
        suffix -= it.second;
        if (it.first - suffix > best_C) best_C = it.first - suffix;
    }
    return {best_C, total_D};
}

// 合并两个聚合值（先 a 后 b）
pll merge_two(const pll &a, const pll &b) {
    if (a.second == 0 && b.second == 0) return {0, 0};
    ll new_c = max(a.first - b.second, b.first);
    return {new_c, a.second + b.second};
}

void dfs1(int u, int p) {
    vector<pll> items;
    items.push_back({c[u], d[u]});
    for (size_t i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;
        if (v == p) continue;
        dfs1(v, u);
        items.push_back({down_C[v], down_D[v]});
    }
    pll res = aggregate(items);
    down_C[u] = res.first;
    down_D[u] = res.second;
}

ll ans;

void dfs2(int u, int p) {
    // 计算以 u 为根的答案
    {
        vector<pll> items;
        items.push_back({c[u], d[u]});
        if (p != 0) items.push_back({up_C[u], up_D[u]});
        for (size_t i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            if (v == p) continue;
            items.push_back({down_C[v], down_D[v]});
        }
        pll res = aggregate(items);
        ll cur_ans = sum_S + res.first;
        if (cur_ans < ans) ans = cur_ans;
    }

    // 收集孩子列表并按 down_C 降序排列
    vector<pair<pll, int>> children;
    for (size_t i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;
        if (v == p) continue;
        children.push_back({{down_C[v], down_D[v]}, v});
    }
    sort(children.begin(), children.end(),
         [](const pair<pll, int> &a, const pair<pll, int> &b) {
             return a.first.first > b.first.first;
         });

    int k = (int)children.size();
    vector<pll> pref(k + 1, {0, 0});
    for (int i = 0; i < k; i++) {
        pref[i + 1] = merge_two(pref[i], children[i].first);
    }

    vector<pll> suff(k + 1, {0, 0});
    for (int i = k - 1; i >= 0; i--) {
        suff[i] = merge_two(children[i].first, suff[i + 1]);
    }

    for (int i = 0; i < k; i++) {
        int v = children[i].second;
        vector<pll> items_up;
        items_up.push_back({c[u], d[u]});
        if (p != 0) items_up.push_back({up_C[u], up_D[u]});
        if (pref[i].second != 0) items_up.push_back(pref[i]);
        if (suff[i + 1].second != 0) items_up.push_back(suff[i + 1]);
        pll res = aggregate(items_up);
        up_C[v] = res.first;
        up_D[v] = res.second;
        dfs2(v, u);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &B[i]);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &S[i]);

    for (int i = 1; i < n; i++) {
        int a;
        ll b;
        scanf("%d%lld", &a, &b);
        adj[i + 1].push_back({a, b});
        adj[a].push_back({i + 1, b});
        total_weight += b;
    }

    for (int i = 1; i <= n; i++) {
        d[i] = min(B[i], S[i]);
        c[i] = max(0LL, B[i] - S[i]);
        sum_S += S[i];
    }

    dfs1(1, 0);
    ans = sum_S + down_C[1];
    dfs2(1, 0);

    printf("%lld %lld\n", 2 * total_weight, ans);

    return 0;
}
