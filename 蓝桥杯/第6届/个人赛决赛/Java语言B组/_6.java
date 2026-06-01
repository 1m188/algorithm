/*
 * 
 * 标题：铺瓷砖
 * 
 * 为了让蓝桥杯竞赛更顺利的进行，主办方决定给竞赛的机房重新铺放瓷砖。机房可以看成一个n*m的矩形，而这次使用的瓷砖比较特别，有两种形状，如【图1.png】所示。在铺放瓷砖时，可以旋转。
 *  
 * 主办方想知道，如果使用这两种瓷砖把机房铺满，有多少种方案。
 * 
 * 【输入格式】
 * 输入的第一行包含两个整数，分别表示机房两个方向的长度。
 * 
 * 【输出格式】
 * 输出一个整数，表示可行的方案数。这个数可能很大，请输出这个数除以65521的余数。
 * 
 * 【样例输入1】
 * 4 4
 * 【样例输出1】
 * 2
 * 【样例说明1】
 * 这两种方案如下【图2.png】所示：
 *  
 * 【样例输入2】
 * 2 6
 * 【样例输出2】
 * 4
 * 【数据规模与约定】
 * 对于20%的数据，1<=n, m<=5。
 * 对于50%的数据，1<=n<=100，1<=m<=5。
 * 对于100%的数据，1<=n<=10^15，1<=m<=6。
 *  
 * 资源约定：
 * 峰值内存消耗（含虚拟机） < 512M
 * CPU消耗  < 8000ms
 * 
 * 
 * 请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。
 * 
 * 所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
 * 注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
 * 注意：主类的名字必须是：Main，否则按无效代码处理。
 * 
 */

import java.util.*;

/**
 * 解法：状态压缩 DP（轮廓线）+ BFS 状态压缩 + 矩阵快速幂
 * 
 * 瓷砖有两种形状（均可旋转）：
 * 1. L 型三连格（tromino）：4 种旋转
 * 2. T 型四连格（tetromino）：4 种旋转
 * 共计 8 种放置形态。
 * 
 * m ≤ 6 极小，采用轮廓线 DP。
 * 状态编码：(pre1 << M) | pre0，共 2^(2M) ≤ 4096 种状态。
 * pre0 = 上一行伸入当前行的格子（必须在本行覆盖）
 * pre1 = 上上行伸入上一行的格子
 * 处理完一行后新状态 = (nxt2 << M) | (pre1 | nxt1)
 * 
 * 优化：BFS 从状态 0 出发找到所有可达状态（m=6 时仅 273/4096 个），
 * 将转移矩阵压缩到可达状态空间，大幅加速矩阵快速幂。
 * 
 * n ≤ 10^15 极大，使用矩阵快速幂 O(log n × S²) 加速状态转移。
 * 答案 = 转移矩阵^n 的 [0][0] 元素（从空状态出发回到空状态）。
 */
public class _6 {
    public static void main(String[] args) {
        Main.solve();
    }
}

class Main {

    static final int MOD = 65521;

    /**
     * 8 种瓷砖形状，每种形状是若干 (dr, dc) 相对坐标
     * dr: 0=当前行, 1=下一行, 2=下下行
     */
    static final int[][][] SHAPES = {
            // L-tromino (3 cells) × 4 rotations
            { { 0, 0 }, { 1, 0 }, { 1, 1 } }, // └
            { { 0, 0 }, { 0, 1 }, { 1, 0 } }, // ┐
            { { 0, 0 }, { 0, 1 }, { 1, 1 } }, // ┘
            { { 0, 0 }, { 1, 0 }, { 1, -1 } }, // ┌
            // T-tetromino (4 cells) × 4 rotations
            { { 0, 0 }, { 1, 0 }, { 1, 1 }, { 2, 0 } }, // ⊥ (vertical-T, left)
            { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 1 } }, // ⊤ (horizontal-T, down)
            { { 0, 0 }, { 1, 0 }, { 1, -1 }, { 2, 0 } }, // ⊢ (vertical-T, right)
            { { 0, 0 }, { 1, 0 }, { 1, 1 }, { 1, -1 } }, // ⊣ (horizontal-T, up)
    };

    static int M; // 较小的维度（轮廓线宽度）

    /**
     * 构建完整状态转移矩阵 trans[S][T]，所有 2^(2M) 个状态
     */
    static int[][] buildFullTransition() {
        int states = 1 << (2 * M);
        int[][] trans = new int[states][states];

        for (int pre0 = 0; pre0 < (1 << M); pre0++) {
            for (int pre1 = 0; pre1 < (1 << M); pre1++) {
                int s = (pre1 << M) | pre0;
                int[] counts = new int[states];
                dfsFill(0, pre0, pre1, 0, 0, 0, counts);
                for (int t = 0; t < states; t++) {
                    if (counts[t] > 0) {
                        trans[s][t] = (trans[s][t] + counts[t]) % MOD;
                    }
                }
            }
        }
        return trans;
    }

    /**
     * DFS 填满一行
     */
    static void dfsFill(int col, int pre0, int pre1, int curFilled,
            int nxt1Filled, int nxt2Filled, int[] results) {
        if (col == M) {
            // 本行必须完全填满（pre0 或 curFilled 覆盖所有格）
            if ((curFilled | pre0) == (1 << M) - 1) {
                int newState = (nxt2Filled << M) | (pre1 | nxt1Filled);
                results[newState]++;
            }
            return;
        }

        // 当前格已被 pre0 或之前的瓷砖覆盖，跳过
        if (((pre0 >> col) & 1) == 1 || ((curFilled >> col) & 1) == 1) {
            dfsFill(col + 1, pre0, pre1, curFilled, nxt1Filled, nxt2Filled, results);
            return;
        }

        // 尝试以当前格为起点放置每种瓷砖
        for (int[][] shape : SHAPES) {
            boolean ok = true;
            int nc = curFilled;
            int nn1 = nxt1Filled;
            int nn2 = nxt2Filled;

            for (int[] dd : shape) {
                int dr = dd[0], dc = dd[1];
                int tc = col + dc;
                if (tc < 0 || tc >= M) {
                    ok = false;
                    break;
                }
                int bit = 1 << tc;

                if (dr == 0) {
                    if ((pre0 & bit) != 0 || (nc & bit) != 0) {
                        ok = false;
                        break;
                    }
                    nc |= bit;
                } else if (dr == 1) {
                    if ((pre1 & bit) != 0 || (nn1 & bit) != 0) {
                        ok = false;
                        break;
                    }
                    nn1 |= bit;
                } else { // dr == 2
                    if ((nn2 & bit) != 0) {
                        ok = false;
                        break;
                    }
                    nn2 |= bit;
                }
            }

            if (ok) {
                dfsFill(col + 1, pre0, pre1, nc, nn1, nn2, results);
            }
        }
    }

    /**
     * BFS 从状态 0 出发找到所有可达状态，返回压缩映射和实际状态数
     * 
     * @param fullTrans 完整转移矩阵
     * @return [compressed matrix, mapping old_state -> new_index]
     */
    static int[][] compressStates(int[][] fullTrans, int[] mapping) {
        int totalStates = fullTrans.length;
        Arrays.fill(mapping, -1);

        // BFS 找可达状态
        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[totalStates];
        visited[0] = true;
        q.add(0);

        while (!q.isEmpty()) {
            int s = q.poll();
            for (int t = 0; t < totalStates; t++) {
                if (fullTrans[s][t] > 0 && !visited[t]) {
                    visited[t] = true;
                    q.add(t);
                }
            }
        }

        // 建立映射
        int idx = 0;
        for (int s = 0; s < totalStates; s++) {
            if (visited[s]) {
                mapping[s] = idx++;
            }
        }
        int compressedSize = idx;

        // 构建压缩转移矩阵
        int[][] comp = new int[compressedSize][compressedSize];
        for (int s = 0; s < totalStates; s++) {
            if (mapping[s] < 0)
                continue;
            int si = mapping[s];
            for (int t = 0; t < totalStates; t++) {
                if (fullTrans[s][t] > 0 && mapping[t] >= 0) {
                    comp[si][mapping[t]] = fullTrans[s][t];
                }
            }
        }

        return comp;
    }

    /**
     * 矩阵乘法（mod MOD），跳过零元加速
     */
    static int[][] matMul(int[][] a, int[][] b) {
        int n = a.length;
        int[][] res = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (a[i][k] == 0)
                    continue;
                long aik = a[i][k];
                for (int j = 0; j < n; j++) {
                    if (b[k][j] == 0)
                        continue;
                    res[i][j] = (int) ((res[i][j] + aik * b[k][j]) % MOD);
                }
            }
        }
        return res;
    }

    /**
     * 矩阵快速幂
     */
    static int[][] matPow(int[][] base, long exp) {
        int n = base.length;
        int[][] res = new int[n][n];
        for (int i = 0; i < n; i++)
            res[i][i] = 1;
        int[][] cur = base;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                res = matMul(res, cur);
            }
            cur = matMul(cur, cur);
            exp >>= 1;
        }
        return res;
    }

    /**
     * 主求解入口
     */
    public static void solve() {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long mInput = sc.nextLong();
        sc.close();

        // 取较小维度作为轮廓线宽度 M
        if (mInput < n) {
            M = (int) mInput;
        } else {
            M = (int) n;
            n = mInput;
        }

        int totalStates = 1 << (2 * M);
        int[][] fullTrans = buildFullTransition();

        // BFS 状态压缩
        int[] mapping = new int[totalStates];
        int[][] trans = compressStates(fullTrans, mapping);

        int[][] result = matPow(trans, n);

        // 从压缩后的状态 0 出发，回到状态 0
        System.out.println(result[0][0]);
    }
}
