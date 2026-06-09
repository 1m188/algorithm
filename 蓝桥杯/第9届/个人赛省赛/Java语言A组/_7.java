/*

标题：三体攻击

【题目描述】
三体人将对地球发起攻击。为了抵御攻击，地球人派出了 A × B × C 艘战舰，在太空中排成一个 A 层 B 行 C 列的立方体。其中，第 i 层第 j 行第 k 列的战舰（记为战舰 (i, j, k)）的生命值为 d(i, j, k)。

三体人将会对地球发起 m 轮“立方体攻击”，每次攻击会对一个小立方体中的所有战舰都造成相同的伤害。具体地，第 t 轮攻击用 7 个参数 lat, rat, lbt, rbt, lct, rct, ht 描述；
所有满足 i ∈ [lat, rat],j ∈ [lbt, rbt],k ∈ [lct, rct] 的战舰 (i, j, k) 会受到 ht 的伤害。如果一个战舰累计受到的总伤害超过其防御力，那么这个战舰会爆炸。

地球指挥官希望你能告诉他，第一艘爆炸的战舰是在哪一轮攻击后爆炸的。

【输入格式】
从标准输入读入数据。
第一行包括 4 个正整数 A, B, C, m；
第二行包含 A × B × C 个整数，其中第 ((i − 1)×B + (j − 1)) × C + (k − 1)+1 个数为 d(i, j, k)；
第 3 到第 m + 2 行中，第 (t − 2) 行包含 7 个正整数 lat, rat, lbt, rbt, lct, rct, ht。

【输出格式】
输出到标准输出。
输出第一个爆炸的战舰是在哪一轮攻击后爆炸的。保证一定存在这样的战舰。

【样例输入】
2 2 2 3
1 1 1 1 1 1 1 1
1 2 1 2 1 1 1
1 1 1 2 1 2 1
1 1 1 1 1 1 2

【样例输出】
2

【样例解释】
在第 2 轮攻击后，战舰 (1,1,1) 总共受到了 2 点伤害，超出其防御力导致爆炸。


【数据约定】
对于 10% 的数据，B = C = 1；
对于 20% 的数据，C = 1；
对于 40% 的数据，A × B × C, m ≤ 10, 000；
对于 70% 的数据，A, B, C ≤ 200；
对于所有数据，A × B × C ≤ 10^6, m ≤ 10^6, 0 ≤ d(i, j, k), ht ≤ 10^9。


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 3000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
不要使用package语句。不要使用jdk1.7及以上版本的特性。
主类的名字必须是：Main，否则按无效代码处理。

*/

/*
 * 算法思路：二分答案 + 三维差分
 *
 * 1. 二分答案：
 *    - 若前 mid 轮攻击后已有战舰爆炸，则答案 <= mid，向左半区收缩；
 *    - 若前 mid 轮攻击后没有战舰爆炸，则答案 > mid，向右半区收缩。
 *    - 最终 lo == hi + 1，ans 即为满足条件的最小轮次。
 *
 * 2. 三维差分（check 函数核心）：
 *    - 每次攻击对子立方体 [la..ra] x [lb..rb] x [lc..rc] 统一加 h，
 *      等价于在差分数组 diff 的 8 个顶点上做 +h / -h 标记。
 *    - 对差分数组求三维前缀和即可还原每个位置的累计伤害。
 *    - 前缀和递推公式（容斥原理）：
 *        sum(i,j,k) = diff(i,j,k)
 *                   + sum(i-1,j,k) + sum(i,j-1,k) + sum(i,j,k-1)
 *                   - sum(i-1,j-1,k) - sum(i-1,j,k-1) - sum(i,j-1,k-1)
 *                   + sum(i-1,j-1,k-1)
 *
 * 3. 复杂度：
 *    - 每次 check：O(mid + A*B*C)
 *    - 二分 log(m) 次，总复杂度 O(log(m) * (m + A*B*C))
 *    - 数据规模 A*B*C <= 10^6, m <= 10^6，可在 3 秒内通过。
 */
public class _7 {

    // 立方体的三层维度：A 层、B 行、C 列；m 为攻击轮次总数
    static int A, B, C, m;
    // d[i] 为第 i 艘战舰的防御力（一维展开，0-indexed）
    static long[] d;
    // attacks[t][0..6] 分别存储第 t 轮攻击的 la, ra, lb, rb, lc, rc, h
    static int[][] attacks;

    /* ========== 快速读入（手动解析字节流，避免 Scanner 的性能开销） ========== */

    static java.io.InputStream is = System.in;
    // 64KB 读入缓冲区
    static byte[] inbuf = new byte[1 << 16];
    static int inlen = 0, inptr = 0;

    // 从缓冲区读取一个字节，缓冲区耗尽时自动从输入流补充
    static int readByte() throws Exception {
        if (inptr >= inlen) {
            inptr = 0;
            inlen = is.read(inbuf);
            if (inlen <= 0)
                return -1;
        }
        return inbuf[inptr++];
    }

    // 跳过空白字符，解析并返回下一个非负整数（int 范围）
    static int nextInt() throws Exception {
        int c = readByte();
        while (c <= ' ')
            c = readByte();
        int res = 0;
        while (c > ' ') {
            res = res * 10 + (c - '0');
            c = readByte();
        }
        return res;
    }

    // 跳过空白字符，解析并返回下一个非负长整数（long 范围，用于防御力 d 可达 10^9）
    static long nextLong() throws Exception {
        int c = readByte();
        while (c <= ' ')
            c = readByte();
        long res = 0;
        while (c > ' ') {
            res = res * 10 + (c - '0');
            c = readByte();
        }
        return res;
    }

    /* ========== 主函数 ========== */

    public static void main(String[] args) throws Exception {
        // 读入立方体维度和攻击轮次
        A = nextInt();
        B = nextInt();
        C = nextInt();
        m = nextInt();

        // 读入 A*B*C 艘战舰的防御力，按层优先顺序存储
        // 战舰 (i,j,k) 对应下标 ((i-1)*B + (j-1))*C + (k-1)，其中 i,j,k 均为 1-indexed
        int n = A * B * C;
        d = new long[n];
        for (int i = 0; i < n; i++) {
            d[i] = nextLong();
        }

        // 读入 m 轮攻击参数：la, ra, lb, rb, lc, rc, h
        attacks = new int[m][7];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 7; j++) {
                attacks[i][j] = nextInt();
            }
        }

        // 二分答案：寻找最小的轮次 ans，使得前 ans 轮攻击后至少有一艘战舰爆炸
        // 单调性保证：若前 k 轮有战舰爆炸，则前 k+1 轮也一定有（伤害只增不减）
        int lo = 1, hi = m, ans = m;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(mid)) {
                // 前 mid 轮已有战舰爆炸，记录答案并尝试更小的轮次
                ans = mid;
                hi = mid - 1;
            } else {
                // 前 mid 轮尚无战舰爆炸，需要更多轮次
                lo = mid + 1;
            }
        }
        System.out.println(ans);
    }

    /* ========== 检查函数：前 mid 轮攻击后是否有战舰爆炸 ========== */

    static boolean check(int mid) {
        // 构建三维差分数组，各维度多开 2 个单位以避免边界判断
        // 维度大小：(A+2) x (B+2) x (C+2)，一维展开存储
        // sB、sC 分别为第二维和第三维的跨度（stride）
        int sB = B + 2, sC = C + 2;
        long[] diff = new long[(A + 2) * sB * sC];

        // 对前 mid 次攻击，在差分数组上做 8 个顶点的标记
        // 三维区间加法的差分原理（类比一维差分 diff[l]+=v, diff[r+1]-=v）：
        // 对子立方体 [la..ra] x [lb..rb] x [lc..rc] 统一加 h，
        // 需要在 8 个角点交替加/减 h，使得三维前缀和还原后区间内恰好为 h。
        // 符号规律：三个维度中"右边界+1"的个数为奇数时取负，偶数时取正。
        for (int t = 0; t < mid; t++) {
            int la = attacks[t][0], ra = attacks[t][1];
            int lb = attacks[t][2], rb = attacks[t][3];
            int lc = attacks[t][4], rc = attacks[t][5];
            long h = attacks[t][6];

            // 8 个顶点标记，符号由"超出右边界的维度数"的奇偶性决定
            add(diff, sB, sC, la, lb, lc, h); // 0 个越界 -> +h
            add(diff, sB, sC, la, lb, rc + 1, -h); // 1 个越界 -> -h
            add(diff, sB, sC, la, rb + 1, lc, -h); // 1 个越界 -> -h
            add(diff, sB, sC, la, rb + 1, rc + 1, h); // 2 个越界 -> +h
            add(diff, sB, sC, ra + 1, lb, lc, -h); // 1 个越界 -> -h
            add(diff, sB, sC, ra + 1, lb, rc + 1, h); // 2 个越界 -> +h
            add(diff, sB, sC, ra + 1, rb + 1, lc, h); // 2 个越界 -> +h
            add(diff, sB, sC, ra + 1, rb + 1, rc + 1, -h); // 3 个越界 -> -h
        }

        // 对差分数组求三维前缀和，还原每个位置的实际累计伤害
        // 利用容斥原理，从 7 个已计算的前缀和递推当前位置：
        // diff[i][j][k] += diff[i-1][j][k] + diff[i][j-1][k] + diff[i][j][k-1]
        // - diff[i-1][j-1][k] - diff[i-1][j][k-1] - diff[i][j-1][k-1]
        // + diff[i-1][j-1][k-1]
        // 在一维展开数组中，各偏移量对应：
        // -1 -> (i, j, k-1) 即 k 方向前一个
        // -sC -> (i, j-1, k) 即 j 方向前一个
        // -sC-1 -> (i, j-1, k-1)
        // -sB*sC -> (i-1, j, k) 即 i 方向前一个
        // -sB*sC-sC -> (i-1, j-1, k)
        // -sB*sC-1 -> (i-1, j, k-1)
        // -sB*sC-sC-1 -> (i-1, j-1, k-1)
        for (int i = 1; i <= A; i++) {
            for (int j = 1; j <= B; j++) {
                for (int k = 1; k <= C; k++) {
                    int idx = i * sB * sC + j * sC + k;
                    diff[idx] += diff[idx - sC]
                            + diff[idx - sB * sC]
                            - diff[idx - sB * sC - sC]
                            + diff[idx - 1]
                            - diff[idx - sC - 1]
                            - diff[idx - sB * sC - 1]
                            + diff[idx - sB * sC - sC - 1];
                    // 将 1-indexed 的 (i,j,k) 转换为战舰数组的 0-indexed 下标
                    int shipIdx = ((i - 1) * B + (j - 1)) * C + (k - 1);
                    // 累计伤害严格大于防御力时，战舰爆炸
                    if (diff[idx] > d[shipIdx]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    // 在差分数组的 (i, j, k) 位置加上值 v
    // 一维展开公式：index = i * sB * sC + j * sC + k
    static void add(long[] diff, int sB, int sC, int i, int j, int k, long v) {
        diff[i * sB * sC + j * sC + k] += v;
    }
}
