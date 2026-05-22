/*
 
标题：铺瓷砖

为了让蓝桥杯竞赛更顺利的进行，主办方决定给竞赛的机房重新铺放瓷砖。机房可以看成一个n*m的矩形，而这次使用的瓷砖比较特别，有两种形状，如【图1.png】所示。在铺放瓷砖时，可以旋转。
 
主办方想知道，如果使用这两种瓷砖把机房铺满，有多少种方案。

【输入格式】
输入的第一行包含两个整数，分别表示机房两个方向的长度。

【输出格式】
输出一个整数，表示可行的方案数。这个数可能很大，请输出这个数除以65521的余数。

【样例输入1】
4 4
【样例输出1】
2
【样例说明1】
这两种方案如下【图2.png】所示：
 
【样例输入2】
2 6
【样例输出2】
4
【数据规模与约定】
对于20%的数据，1<=n, m<=5。
对于50%的数据，1<=n<=100，1<=m<=5。
对于100%的数据，1<=n<=10^15，1<=m<=6。
 
资源约定：
峰值内存消耗（含虚拟机） < 512M
CPU消耗  < 8000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。

*/

import java.util.*;

class Main_6 {
    public static void main(String[] args) {
        Main.solve();
    }
}

class Main {

    static final int MOD = 65521;

    // All 8 tile shapes (L-tromino × 4 rotations + T-tetromino × 4 rotations)
    // Each shape is an array of (dr, dc) relative to starting cell (row, col)
    static final int[][][] SHAPES = {
            // L-tromino (3 cells)
            { { 0, 0 }, { 1, 0 }, { 1, 1 } }, // └
            { { 0, 0 }, { 0, 1 }, { 1, 0 } }, // ┐
            { { 0, 0 }, { 0, 1 }, { 1, 1 } }, // ┘
            { { 0, 0 }, { 1, 0 }, { 1, -1 } }, // ┌
            // T-tetromino (4 cells)
            { { 0, 0 }, { 1, 0 }, { 1, 1 }, { 2, 0 } }, // vertical T, left protrusion
            { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 1 } }, // horizontal T, down protrusion
            { { 0, 0 }, { 1, 0 }, { 1, -1 }, { 2, 0 } }, // vertical T, right protrusion
            { { 0, 0 }, { 1, 0 }, { 1, 1 }, { 1, -1 } }, // horizontal T, up protrusion
    };

    static int M; // small dimension (profile width)

    // Build 2-row transition matrix
    // State: (pre1 << M) | pre0, where:
    // pre0 = cells in current row pre-filled from previous row
    // pre1 = cells in next row pre-filled
    // After processing one row: new state = (nxt2 << M) | (pre1 | nxt1)
    static int[][] buildTransition() {
        int states = 1 << (2 * M);
        int[][] trans = new int[states][states];

        for (int pre0 = 0; pre0 < (1 << M); pre0++) {
            for (int pre1 = 0; pre1 < (1 << M); pre1++) {
                int s = (pre1 << M) | pre0;
                // Use int array of size 1 as mutable counter accumulator
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

    static void dfsFill(int col, int pre0, int pre1, int curFilled,
            int nxt1Filled, int nxt2Filled, int[] results) {
        if (col == M) {
            if ((curFilled | pre0) == (1 << M) - 1) {
                int newState = (nxt2Filled << M) | (pre1 | nxt1Filled);
                results[newState]++;
            }
            return;
        }

        // Cell already filled (by pre0 or current placement)
        if (((pre0 >> col) & 1) == 1 || ((curFilled >> col) & 1) == 1) {
            dfsFill(col + 1, pre0, pre1, curFilled, nxt1Filled, nxt2Filled, results);
            return;
        }

        // Try each shape at this cell
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
                } else if (dr == 2) {
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

    // Matrix multiplication (mod MOD)
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

    // Matrix fast exponentiation
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

    public static void solve() {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long mInput = sc.nextLong();
        sc.close();

        // Make M the smaller dimension for efficiency
        if (mInput < n) {
            M = (int) mInput;
        } else {
            M = (int) n;
            n = mInput;
        }

        int[][] trans = buildTransition();
        int[][] result = matPow(trans, n);

        // Start from state 0 (no pre-filled cells), end at state 0 (no protrusions)
        System.out.println(result[0][0]);
    }
}
