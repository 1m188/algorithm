/*

标题：数组操作

给出一个长度为 n 的数组 {A}，由 1 到 n 标号 ， 你需要维护 m 个操作。
操作分为三种，输入格式为：

1 L R d，将数组中下标 L 到 R 的位置都加上 d，即对于 L<=i<=R，执行A[i]=A[i]+d。

2 L1 R1 L2 R2，将数组中下标为 L1 到 R1 的位置，赋值成 L2 到 R2 的值，保证 R1-L1=R2-L2。
换句话说先对 0<=i<=R2-L2 执行 B[i]=A[L2+i]，再对 0<=i<=R1-L1 执行 A[L1+i]=B[i]，其中 {B} 为一个临时数组。

3 L R，求数组中下标 L 到 R 的位置的和，即求出 ∑_(i=L到R) A_i 。

输入格式:
从标准输入读入数据。
第一行一个整数 Case，表示测试点编号，其中 Case=0 表示该点为样例。
第二行包含两个整数 n,m。保证 1<=n,m<=10^5。
第三行包含 n 个整数 A_i，表示这个数组的初值。保证 0<=A_i<=10^5。
接下来 m 每行描述一个操作，格式如问题描述所示。
对于操作中提到每个数，满足 0<=d<=10^5，1<=L<=R<=n，1<=L1<=R1<=n，1<=L2<=R2<=n，R1-L1=R2-L2。

输出格式:
输出到标准输出。
对于每次 3 操作输出一行一个数，表示求和的结果。


样例输入:
0
5 6
1 2 3 4 5
2 1 3 3 5
3 3 5
1 2 4 2
3 3 5
2 1 3 3 5
3 1 5

样例输出:
14
18
29

----------------------------
测试点	  n,m	       其他约束
----------------------------
1,2      <=10^3	       无
3,4      <=10^5	       没有2操作
5,6,7     <=10^5       n 为偶数，且所有2操作满足 L1=1,R1=n/2  ,L2=n/2+1,R2=n
8,9,10	  <=10^5       无


资源约定：
峰值内存消耗 < 2048M
CPU消耗  < 2000ms

请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。



*/

#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const int MAXN = 100005;
const int B = 320; // sqrt(MAXN) ≈ 316，取整到 320

int n, m;
ll a[MAXN];
int block_id[MAXN];
int block_start[320], block_end[320];
int block_cnt;
ll lazy[320];
ll block_sum[320];

void build() {
    block_cnt = (n + B - 1) / B;
    for (int i = 0; i < block_cnt; i++) {
        block_start[i] = i * B + 1; // 1-indexed
        block_end[i] = min((i + 1) * B, n);
        lazy[i] = 0;
        block_sum[i] = 0;
        for (int j = block_start[i]; j <= block_end[i]; j++) {
            block_id[j] = i;
            block_sum[i] += a[j];
        }
    }
}

// 将块 bid 的懒标记下推到元素
void push_down(int bid) {
    if (lazy[bid] == 0) return;
    for (int i = block_start[bid]; i <= block_end[bid]; i++) {
        a[i] += lazy[bid];
    }
    lazy[bid] = 0;
}

// 重新计算块 bid 的和
void rebuild(int bid) {
    block_sum[bid] = 0;
    for (int i = block_start[bid]; i <= block_end[bid]; i++) {
        block_sum[bid] += a[i];
    }
}

// 操作 1：区间加法
void range_add(int L, int R, ll d) {
    int bl = block_id[L], br = block_id[R];
    if (bl == br) {
        push_down(bl);
        for (int i = L; i <= R; i++)
            a[i] += d;
        rebuild(bl);
        return;
    }
    // 左端部分块
    push_down(bl);
    for (int i = L; i <= block_end[bl]; i++)
        a[i] += d;
    rebuild(bl);
    // 中间完整块
    for (int b = bl + 1; b < br; b++) {
        lazy[b] += d;
        block_sum[b] += d * (block_end[b] - block_start[b] + 1);
    }
    // 右端部分块
    push_down(br);
    for (int i = block_start[br]; i <= R; i++)
        a[i] += d;
    rebuild(br);
}

// 操作 2：区间复制
void range_copy(int L1, int R1, int L2, int R2) {
    if (L1 == L2) return; // 复制到自身，无需操作
    int len = R1 - L1 + 1;

    // 用静态数组替代 vector，避免动态内存分配和排序开销
    static bool touched[320];
    static int touched_list[320];
    int touched_cnt = 0;

    auto mark = [&](int bid) {
        if (!touched[bid]) {
            touched[bid] = true;
            touched_list[touched_cnt++] = bid;
        }
    };

    bool forward = (L1 <= L2 || L1 > R2);

    if (forward) {
        int cur_src = L2, cur_dst = L1, remaining = len;
        while (remaining > 0) {
            int src_bid = block_id[cur_src], dst_bid = block_id[cur_dst];
            int batch = min({remaining,
                             block_end[src_bid] - cur_src + 1,
                             block_end[dst_bid] - cur_dst + 1});

            if (lazy[dst_bid]) push_down(dst_bid);

            if (lazy[src_bid] == 0) {
                memcpy(&a[cur_dst], &a[cur_src], sizeof(ll) * batch);
            } else {
                ll add = lazy[src_bid];
                for (int j = 0; j < batch; j++)
                    a[cur_dst + j] = a[cur_src + j] + add;
            }

            mark(dst_bid);
            cur_src += batch;
            cur_dst += batch;
            remaining -= batch;
        }
    } else {
        int cur_src = R2, cur_dst = R1, remaining = len;
        while (remaining > 0) {
            int src_bid = block_id[cur_src], dst_bid = block_id[cur_dst];
            int batch = min({remaining,
                             cur_src - block_start[src_bid] + 1,
                             cur_dst - block_start[dst_bid] + 1});

            if (lazy[dst_bid]) push_down(dst_bid);

            if (lazy[src_bid] == 0) {
                memcpy(&a[cur_dst - batch + 1], &a[cur_src - batch + 1],
                       sizeof(ll) * batch);
            } else {
                ll add = lazy[src_bid];
                for (int j = 0; j < batch; j++)
                    a[cur_dst - j] = a[cur_src - j] + add;
            }

            mark(dst_bid);
            cur_src -= batch;
            cur_dst -= batch;
            remaining -= batch;
        }
    }

    for (int i = 0; i < touched_cnt; i++) {
        int bid = touched_list[i];
        rebuild(bid);
        touched[bid] = false;
    }
}

// 操作 3：区间求和
ll range_sum(int L, int R) {
    int bl = block_id[L], br = block_id[R];
    ll ans = 0;
    if (bl == br) {
        push_down(bl);
        for (int i = L; i <= R; i++)
            ans += a[i];
        return ans;
    }
    push_down(bl);
    for (int i = L; i <= block_end[bl]; i++)
        ans += a[i];
    for (int b = bl + 1; b < br; b++)
        ans += block_sum[b];
    push_down(br);
    for (int i = block_start[br]; i <= R; i++)
        ans += a[i];
    return ans;
}

int main() {
    int Case;
    scanf("%d", &Case);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    build();
    while (m--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int L, R;
            ll d;
            scanf("%d%d%lld", &L, &R, &d);
            range_add(L, R, d);
        } else if (op == 2) {
            int L1, R1, L2, R2;
            scanf("%d%d%d%d", &L1, &R1, &L2, &R2);
            range_copy(L1, R1, L2, R2);
        } else {
            int L, R;
            scanf("%d%d", &L, &R);
            printf("%lld\n", range_sum(L, R));
        }
    }
    return 0;
}
