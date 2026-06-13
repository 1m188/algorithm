/*

生成树计数

给定一个 n*m 的格点图，包含 n 行 m 列共 n*m 个顶点，相邻的顶点之间有一条边。
【图1.png】给出了一个3*4的格点图的例子。


如果在图中删除部分顶点和其相邻的边，如上图删除第2行第3列和第3行第1列的顶点后，如【图2.png】所示。

图的生成树指包含图中的所有顶点和其中的一部分边，使得任意两个顶点之间都有由边构成的唯一路径。如果两个生成树包含有不同的边即被认为不同，则上图中共有31种不同的生成树，其中a边不选有10种，a边选有21种。
给出格点图中保留的顶点的信息，请计算该图一共有多少种不同的生成树。

【输入格式】
输入的第一行包含两个整数n, m，用空格分隔，表示格点图的行数和列数。
接下来n行，每行m个字母（中间没有分隔字符），每个字母必然是大写E或大写N，E表示对应的顶点存在，N表示对应的顶点不存在。保证存在至少一个顶点。

【输出格式】
输出一行，包含一个整数，表示生成树的个数。答案可能很大，你只需要计算答案除以1000000007的余数即可。

【样例输入】
3 4
EEEE
EENE
NEEE

【样例输出】
31

【数据规模与约定】
对于10%的数据，1<=n<=2。
对于30%的数据，1<=n<=3。
对于40%的数据，1<=n<=4。
对于50%的数据，1<=n<=5。
另有20%的数据，1<=n*m<=12。
另有10%的数据，1<=m<=15。
对于100%的数据，1<=n<=6，1<=m<=100000。

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 4500ms

请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。

*/

#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

int n, m;
int exist[100005][6]; // exist[col][row]

int normalize(int comp[6], int out[6]) {
    int fresh = 0, map_id[10];
    memset(map_id, -1, sizeof(map_id));
    for (int i = 0; i < n; i++) {
        if (comp[i] < 0) {
            out[i] = -1;
            continue;
        }
        if (map_id[comp[i]] == -1) map_id[comp[i]] = fresh++;
        out[i] = map_id[comp[i]];
    }
    return fresh;
}

int encode(int comp[6]) {
    int code = 0;
    for (int i = 0; i < n; i++)
        code = code * 7 + (comp[i] + 1);
    return code;
}
void decode(int code, int comp[6]) {
    for (int i = n - 1; i >= 0; i--) {
        comp[i] = (code % 7) - 1;
        code /= 7;
    }
}

int find(int *uf, int x) {
    while (uf[x] != x) {
        uf[x] = uf[uf[x]];
        x = uf[x];
    }
    return x;
}

int main() {
    if (scanf("%d%d", &n, &m) < 2) return 0;
    for (int i = 0; i < n; i++) {
        char buf[100005];
        if (scanf("%s", buf) < 1) return 0;
        for (int j = 0; j < m; j++)
            exist[j][i] = (buf[j] == 'E');
    }

    // DP: map stateCode => ways
    map<ll, ll> dp;
    int horz0Max = 1 << (n - 1);
    int validHorz0Mask = 0;
    for (int r = 0; r < n - 1; r++)
        if (exist[0][r] && exist[0][r + 1])
            validHorz0Mask |= (1 << r);

    for (int horz0 = 0; horz0 < horz0Max; horz0++) {
        if (horz0 & ~validHorz0Mask) continue;
        int uf[6];
        for (int i = 0; i < n; i++)
            uf[i] = i;
        bool cycle = false;
        for (int r = 0; r < n - 1 && !cycle; r++) {
            if (!exist[0][r] || !exist[0][r + 1]) continue;
            if (!(horz0 & (1 << r))) continue;
            int a = find(uf, r), b = find(uf, r + 1);
            if (a == b)
                cycle = true;
            else
                uf[a] = b;
        }
        if (cycle) continue;
        int initComp[6];
        int fresh = 0, map_id[10];
        memset(map_id, -1, sizeof(map_id));
        for (int r = 0; r < n; r++) {
            if (!exist[0][r]) {
                initComp[r] = -1;
                continue;
            }
            int root = find(uf, r);
            if (map_id[root] == -1) map_id[root] = fresh++;
            initComp[r] = map_id[root];
        }
        dp[(ll)encode(initComp) << 1] = (dp[(ll)encode(initComp) << 1] + 1) % MOD;
    }

    for (int col = 1; col < m; col++) {
        map<ll, ll> ndp;
        for (auto &entry : dp) {
            ll key = entry.first, ways = entry.second;
            if (!ways) continue;
            int hasFinished = key & 1;
            int oldCode = key >> 1;
            int oldComp[6];
            decode(oldCode, oldComp);

            int oldCnt = 0;
            for (int r = 0; r < n; r++)
                if (oldComp[r] >= oldCnt) oldCnt = oldComp[r] + 1;

            // UF: FIN(0), old components(1..oldCnt), new vertices(oldCnt+1..oldCnt+n)
            int total = 1 + oldCnt + n;

            // 仅枚举实际上可能存在的边
            int validHorzMask = 0, validVertMask = 0;
            for (int r = 0; r < n - 1; r++)
                if (exist[col][r] && exist[col][r + 1])
                    validHorzMask |= (1 << r);
            for (int r = 0; r < n; r++)
                if (exist[col - 1][r] && exist[col][r])
                    validVertMask |= (1 << r);

            int horzMax = 1 << (n - 1), vertMax = 1 << n;
            for (int horz = 0; horz < horzMax; horz++) {
                if (horz & ~validHorzMask) continue; // 跳过无效水平边
                for (int vert = 0; vert < vertMax; vert++) {
                    if (vert & ~validVertMask) continue; // 跳过无效竖直边
                    int uf[30];
                    for (int i = 0; i < total; i++)
                        uf[i] = i;
                    bool cycle = false;

                    // 新列内部水平边
                    for (int r = 0; r < n - 1 && !cycle; r++) {
                        if (!exist[col][r] || !exist[col][r + 1]) continue;
                        if (!(horz & (1 << r))) continue;
                        int a = find(uf, 1 + oldCnt + r), b = find(uf, 1 + oldCnt + r + 1);
                        if (a == b)
                            cycle = true;
                        else
                            uf[a] = b;
                    }
                    if (cycle) continue;

                    // 竖直边：旧列 → 新列
                    for (int r = 0; r < n && !cycle; r++) {
                        if (!exist[col - 1][r] || !exist[col][r]) continue;
                        if (!(vert & (1 << r))) continue;
                        int a = find(uf, 1 + oldComp[r]); // 旧分量
                        int b = find(uf, 1 + oldCnt + r); // 新顶点
                        if (a == b)
                            cycle = true;
                        else
                            uf[a] = b;
                    }
                    if (cycle) continue;

                    // 旧分量未连到新列的，接入 FIN
                    int newHasFinished = hasFinished;
                    for (int i = 0; i < oldCnt && !cycle; i++) {
                        bool connNew = false;
                        for (int r = 0; r < n && !connNew; r++) {
                            if (!exist[col][r]) continue;
                            if (find(uf, 1 + i) == find(uf, 1 + oldCnt + r))
                                connNew = true;
                        }
                        if (!connNew) {
                            int a = find(uf, 1 + i), b = find(uf, 0);
                            if (a == b)
                                cycle = true; // shouldn't happen
                            else {
                                uf[a] = b;
                                newHasFinished = 1;
                            }
                        }
                    }
                    if (cycle) continue;

                    // 新列各顶点的分量
                    int newComp[6];
                    for (int r = 0; r < n; r++) {
                        if (!exist[col][r]) {
                            newComp[r] = -1;
                            continue;
                        }
                        newComp[r] = find(uf, 1 + oldCnt + r);
                    }
                    int norm[6];
                    normalize(newComp, norm);
                    ll newKey = ((ll)encode(norm) << 1) | newHasFinished;
                    ndp[newKey] = (ndp[newKey] + ways) % MOD;
                }
            }
        }
        dp = std::move(ndp);
        if (dp.empty()) break;
    }

    // 统计答案：终态要求所有顶点连通
    ll ans = 0;
    for (auto &entry : dp) {
        ll key = entry.first;
        int hasFinished = key & 1;
        int code = key >> 1;
        int comp[6];
        decode(code, comp);

        // 新列顶点须全部在同一分量内
        int uni = -1;
        for (int r = 0; r < n; r++) {
            if (!exist[m - 1][r]) continue;
            if (uni == -1) uni = comp[r];
            if (comp[r] != uni) {
                uni = -2;
                break;
            }
        }
        if (uni == -2) continue; // 多分量，不合法

        // 所有顶点必须已全部汇入一个分量：
        // hasFinished=1 表示已有闭合部分，则新列分量数须为0
        // hasFinished=0 则新列必须恰好有一个完整分量
        if (hasFinished) {
            if (uni == -1) // 新列无顶点，全已闭合
                ans = (ans + entry.second) % MOD;
        } else {
            if (uni >= 0) // 仅剩一个分量
                ans = (ans + entry.second) % MOD;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
