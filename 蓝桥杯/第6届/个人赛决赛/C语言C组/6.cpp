/*

 标题：切开字符串

 Pear有一个字符串，不过他希望把它切成两段。
 这是一个长度为N（<=10^5）的字符串。
 Pear希望选择一个位置，把字符串不重复不遗漏地切成两段，长度分别是t和N-t（这两段都必须非空）。

 Pear用如下方式评估切割的方案：
 定义"正回文子串"为：长度为奇数的回文子串。
 设切成的两段字符串中，前一段中有A个不相同的正回文子串，后一段中有B个不相同的非正回文子串，则该方案的得分为A*B。

 注意，后一段中的B表示的是："...非正回文..."，而不是: "...正回文..."。
 那么所有的切割方案中，A*B的最大值是多少呢？

 【输入数据】
 输入第一行一个正整数N（<=10^5）
 接下来一行一个字符串，长度为N。该字符串仅包含小写英文字母。
 【输出数据】
 一行一个正整数，表示所求的A*B的最大值。
 【样例输入】
 10
 bbaaabcaba
 【样例输出】
 38
 【数据范围】
 对于20%的数据，N<=100
 对于40%的数据，N<=1000
 对于100%的数据，N<=10^5

 资源约定：
 峰值内存消耗 < 512M
 CPU消耗  < 1000ms


 请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

 所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

 注意: main函数需要返回0
 注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
 注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

 提交时，注意选择所期望的编译器类型。

 解法：回文树（Palindromic Tree / Eertree）统计不同奇数长度回文子串，
       后缀自动机（Suffix Automaton）统计不同子串总数。
       前一段用正序回文树求 A[i]，后一段用逆序字符串的回文树求 oddSuf，
       用逆序字符串的后缀自动机求 totalSuf，枚举切割点取最大 A*B。

 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int MAXN = 100005;

/* ========== 回文树（Palindromic Tree） ========== */
struct PalindromicTree {
    int ch[MAXN][26]; // 转移边
    int len[MAXN];    // 该节点代表回文串的长度
    int fail[MAXN];   // 后缀链接（最长回文后缀）
    int sz;           // 当前节点数
    int last;         // 上一次插入后所在的节点
    int oddCnt;       // 不同奇数长度回文子串个数

    void init() {
        memset(ch[0], 0, sizeof(ch[0]));
        memset(ch[1], 0, sizeof(ch[1]));
        len[0] = -1; // 奇根：长度为 -1
        fail[0] = 0;
        len[1] = 0; // 偶根：长度为 0
        fail[1] = 0;
        sz = 1;
        last = 1;
        oddCnt = 0;
    }

    void extend(const char *s, int pos) {
        int c = s[pos] - 'a';
        int cur = last;

        // 沿 fail 链寻找可以扩展的节点
        while (pos - len[cur] - 1 < 0 || s[pos - len[cur] - 1] != s[pos])
            cur = fail[cur];

        // 如果该转移已存在，直接跳到该节点
        if (ch[cur][c]) {
            last = ch[cur][c];
            return;
        }

        // 创建新节点
        int now = ++sz;
        memset(ch[now], 0, sizeof(ch[now]));
        ch[cur][c] = now;
        len[now] = len[cur] + 2;

        // 新回文串长度为奇数 → 不同的正回文子串 +1
        if (len[now] & 1)
            oddCnt++;

        // 设置 fail 指针
        if (len[now] == 1) {
            fail[now] = 1; // 单字符回文的后缀回文是空串（偶根）
        } else {
            int tmp = fail[cur];
            while (pos - len[tmp] - 1 < 0 || s[pos - len[tmp] - 1] != s[pos])
                tmp = fail[tmp];
            fail[now] = ch[tmp][c];
        }

        last = now;
    }
};

/* ========== 后缀自动机（Suffix Automaton） ========== */
struct SAM {
    int ch[MAXN * 2][26]; // 转移边
    int len[MAXN * 2];    // 该状态代表的最长子串长度
    int link[MAXN * 2];   // 后缀链接
    int sz;               // 当前状态数
    int last;             // 上一次插入后所在的状态
    long long distCnt;    // 不同子串总数 = Σ(len[i] - len[link[i]])

    void init() {
        memset(ch[0], 0, sizeof(ch[0]));
        len[0] = 0;
        link[0] = -1;
        sz = 0;
        last = 0;
        distCnt = 0;
    }

    void extend(int c) {
        int cur = ++sz;
        memset(ch[cur], 0, sizeof(ch[cur]));
        len[cur] = len[last] + 1;

        int p = last;
        while (p != -1 && !ch[p][c]) {
            ch[p][c] = cur;
            p = link[p];
        }

        if (p == -1) {
            link[cur] = 0;
        } else {
            int q = ch[p][c];
            if (len[p] + 1 == len[q]) {
                link[cur] = q;
            } else {
                int clone = ++sz;
                memcpy(ch[clone], ch[q], sizeof(ch[q]));
                len[clone] = len[p] + 1;
                link[clone] = link[q];
                while (p != -1 && ch[p][c] == q) {
                    ch[p][c] = clone;
                    p = link[p];
                }
                link[q] = clone;
                link[cur] = clone;
            }
        }

        distCnt += len[cur] - len[link[cur]];
        last = cur;
    }
};

/* ========== 全局数据 ========== */
static char s[MAXN];             // 原串
static char r[MAXN];             // 逆序串
static int A[MAXN];              // A[i] = 前缀 s[0..i] 中不同正回文子串个数
static int oddSuf[MAXN];         // oddSuf[i] = 后缀 s[i..n-1] 中不同正回文子串个数
static long long totalSuf[MAXN]; // totalSuf[i] = 后缀 s[i..n-1] 中不同子串总数

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string str;
    cin >> n >> str;
    strncpy(s, str.c_str(), MAXN - 1);
    s[MAXN - 1] = '\0';

    // ---------- 1. 正序回文树 → 前缀 A[i] ----------
    {
        static PalindromicTree pt;
        pt.init();
        for (int i = 0; i < n; i++) {
            pt.extend(s, i);
            A[i] = pt.oddCnt;
        }
    }

    // ---------- 2. 构建逆序串 r ----------
    for (int i = 0; i < n; i++)
        r[i] = s[n - 1 - i];
    r[n] = '\0';

    // ---------- 3. 逆序回文树 → 后缀 oddSuf[i] ----------
    {
        static PalindromicTree pt;
        pt.init();
        for (int i = 0; i < n; i++) {
            pt.extend(r, i);
            oddSuf[n - 1 - i] = pt.oddCnt;
        }
    }

    // ---------- 4. 逆序后缀自动机 → 后缀 totalSuf[i] ----------
    {
        static SAM sam;
        sam.init();
        for (int i = 0; i < n; i++) {
            sam.extend(r[i] - 'a');
            totalSuf[n - 1 - i] = sam.distCnt;
        }
    }

    // ---------- 5. 枚举切割点求最大 A * B ----------
    long long ans = 0;
    for (int t = 1; t < n; t++) {
        long long a = A[t - 1];
        long long b = totalSuf[t] - oddSuf[t];
        ans = max(ans, a * b);
    }
    cout << ans << endl;

    return 0;
}
