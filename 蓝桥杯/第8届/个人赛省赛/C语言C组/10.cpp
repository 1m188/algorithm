/*
标题：图形排版

    小明需要在一篇文档中加入 N 张图片，其中第 i 张图片的宽度是 Wi，高度是 Hi。
假设纸张的宽度是 M，小明使用的文档编辑工具会用以下方式对图片进行自动排版：

    1. 该工具会按照图片顺序，在宽度 M 以内，将尽可能多的图片排在一行。该行的高度是行内最高的图片的高度。例如在 M=10 的纸张上依次打印 3x4, 2x2, 3x3 三张图片，则效果如下图所示，这一行高度为4。(分割线以上为列标尺，分割线以下为排版区域；数字组成的矩形为第x张图片占用的版面)

0123456789
----------
111
111  333
11122333
11122333

    2. 如果当前行剩余宽度大于0，并且小于下一张图片，则下一张图片会按比例缩放到宽度为当前行剩余宽度(高度向上取整)，然后放入当前行。例如再放入一张4x9的图片，由于剩余宽度是2，这张图片会被压缩到2x5，再被放入第一行的末尾。此时该行高度为5：

0123456789
----------
        44
111     44
111  33344
1112233344
1112233344

    3. 如果当前行剩余宽度为0，该工具会从下一行开始继续对剩余的图片进行排版，直到所有图片都处理完毕。此时所有行的总高度和就是这 N 张图片的排版高度。例如再放入11x1, 5x5, 3x4 的图片后，效果如下图所示，总高度为11：

0123456789
----------
        44
111     44
111  33344
1112233344
1112233344
5555555555
66666
66666777
66666777
66666777
66666777

    现在由于排版高度过高，图片的先后顺序也不能改变，小明只好从 N 张图片中选择一张删除掉以降低总高度。他希望剩余N-1张图片按原顺序的排版高度最低，你能求出最低高度是多少么？

输入：
第一行包含两个整数 M 和 N，分别表示纸张宽度和图片的数量。
接下来 N 行，每行2个整数Wi, Hi，表示第 i 个图大小为 Wi*Hi。

对于30%的数据，满足1<=N<=1000
对于100%的数据，满足1<=N<=100000，1<=M, Wi, Hi<=100

输出：
一个整数，表示在删除掉某一张图片之后，排版高度最少能是多少。

样例输入：
4 3
2 2
2 3
2 2

样例输出：
2

另一个示例，
样例输入：
2 10
4 4
4 3
1 3
4 5
2 1
2 3
5 4
5 3
1 5
2 4

样例输出：
17

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 2000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。


解题思路：
M, Wi, Hi ≤ 100，可用 O(N*M) DP 避免 O(N²)。

核心观察：后缀函数 f(i, rw, rh) = max(rh, A) + B（关于 rh 的线性-max 形式）。
从右到左对每个 i 和 rw 计算 (A_i[rw], B_i[rw])。

转移：
1) rw >= Wi：可完整放入
   new_rw = rw - Wi
   new_rw==0 → 当前行恰好满 → A_i[rw] = Hi, B_i[rw] = S[i+1]
   new_rw>0  → A_i[rw] = max(Hi, A_{i+1}[new_rw]), B_i[rw] = B_{i+1}[new_rw]

2) rw < Wi：需缩放
   缩放后高度 sh = ceil(Hi * rw / Wi)
   当前行填满 → A_i[rw] = sh, B_i[rw] = S[i+1]

其中 S[i] = A_i[M] + B_i[M]（从新行起处理图片 i..N-1 的总高度）。

前缀：模拟布局，记录每个位置的 (total_h, rw, rh)。
删除 d：ans[d] = pre_h[d] + f_{d+1}(pre_rw[d], pre_rh[d])
  若 pre_rw[d]==0 → ans += S[d+1]
  否则 ans += max(pre_rh[d], A_{d+1}[pre_rw[d]]) + B_{d+1}[pre_rw[d]]
取最小 ans。
*/
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

const int MAXN = 100005, MAXM = 105;
int A[MAXN][MAXM], B[MAXN][MAXM], S[MAXN];
int W[MAXN], H[MAXN];
int pre_h[MAXN], pre_rw[MAXN], pre_rh[MAXN];

int main() {
    int M, N;
    cin >> M >> N;
    for (int i = 0; i < N; i++)
        cin >> W[i] >> H[i];

    // ---- 后缀 DP ----
    for (int rw = 1; rw <= M; rw++)
        A[N][rw] = B[N][rw] = 0;
    S[N] = 0;

    for (int i = N - 1; i >= 0; i--) {
        int w = W[i], h = H[i];
        for (int rw = 1; rw <= M; rw++) {
            if (rw >= w) {
                int nrw = rw - w;
                if (nrw == 0) {
                    A[i][rw] = h;
                    B[i][rw] = S[i + 1];
                } else {
                    A[i][rw] = max(h, A[i + 1][nrw]);
                    B[i][rw] = B[i + 1][nrw];
                }
            } else {
                int sh = (h * rw + w - 1) / w;
                A[i][rw] = sh;
                B[i][rw] = S[i + 1];
            }
        }
        S[i] = A[i][M] + B[i][M];
    }

    // ---- 前缀 ----
    pre_h[0] = 0;
    pre_rw[0] = M;
    pre_rh[0] = 0;
    for (int i = 0; i < N; i++) {
        int rw = pre_rw[i], rh = pre_rh[i];
        long long total = pre_h[i];
        int w = W[i], h = H[i];

        if (rw >= w) {
            int nrw = rw - w;
            int nrh = max(rh, h);
            if (nrw == 0) {
                pre_h[i + 1] = total + nrh;
                pre_rw[i + 1] = M;
                pre_rh[i + 1] = 0;
            } else {
                pre_h[i + 1] = total;
                pre_rw[i + 1] = nrw;
                pre_rh[i + 1] = nrh;
            }
        } else {
            int sh = (h * rw + w - 1) / w;
            int nrh = max(rh, sh);
            pre_h[i + 1] = total + nrh;
            pre_rw[i + 1] = M;
            pre_rh[i + 1] = 0;
        }
    }

    // ---- 枚举删除 ----
    long long ans = LLONG_MAX;
    for (int d = 0; d < N; d++) {
        int rw = pre_rw[d];
        int rh = pre_rh[d];
        long long cur = pre_h[d];
        int nxt = d + 1;

        if (rw == 0) {
            cur += S[nxt];
        } else {
            cur += max(rh, A[nxt][rw]) + B[nxt][rw];
        }
        ans = min(ans, cur);
    }

    // 还需考虑不删任何图片的情况（即原始排版高度）
    // 但题目要求必须删一张，所以不用考虑。
    // 实际上 ans 已包含所有删一张的情况。

    cout << ans << endl;
    return 0;
}
