/*
标题：图形排版

    小明需要在一篇文档中加入 N 张图片，其中第 i 张图片的宽度是 Wi，高度是 Hi。  
假设纸张的宽度是 M，小明使用的文档编辑工具会用以下方式对图片进行自动排版：

    1. 按图片顺序，在宽度 M 以内将尽可能多的图片排在一行。行高为行内最高图片的高度。
    2. 如果当前行剩余宽度大于0且小于下一张图片宽度，下一张图片按比例缩放到剩余宽度。
    3. 如果剩余宽度为0，从下一行开始继续排版。

    小明从 N 张图片中选择一张删除以降低总高度，求最低排版高度。

输入：第一行 M N，接下来 N 行 Wi Hi (1≤N≤100000, 1≤M,Wi,Hi≤100)
输出：删除一张图片后的最低排版高度

样例：4 3 / 2 2 / 2 3 / 2 2 → 2
     2 10 / ... → 17

资源约定：峰值内存消耗 < 256M，CPU消耗 < 2000ms
主类的名字必须是：Main


解题思路：
O(N*M) 后缀 DP。M ≤ 100 较小。
定义后缀函数 f(i, rw, rh) = max(rh, A_i[rw]) + B_i[rw]（关于 rh 的线性-max 形式）。
从右到左预处理 (A_i[rw], B_i[rw]) 对。

前缀模拟布局，记录每个位置的总高和当前行状态。
删除位置 d 的答案 = pre_h[d] + suffix(d+1, pre_rw[d], pre_rh[d])。
取所有 d 的最小值。
*/
import java.util.*;

public class _10 {
    static final int MAXN = 100005, MAXM = 105;
    static int[] W = new int[MAXN], H = new int[MAXN];
    static int[][] A = new int[MAXN][MAXM], B = new int[MAXN][MAXM];
    static int[] S = new int[MAXN];
    static int[] preH = new int[MAXN], preRw = new int[MAXN], preRh = new int[MAXN];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int M = sc.nextInt(), N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            W[i] = sc.nextInt();
            H[i] = sc.nextInt();
        }
        sc.close();

        // ---- 后缀 DP ----
        for (int rw = 0; rw <= M; rw++)
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
                        A[i][rw] = Math.max(h, A[i + 1][nrw]);
                        B[i][rw] = B[i + 1][nrw];
                    }
                } else {
                    int sh = (h * rw + w - 1) / w; // 向上取整
                    A[i][rw] = sh;
                    B[i][rw] = S[i + 1];
                }
            }
            S[i] = A[i][M] + B[i][M];
        }

        // ---- 前缀模拟 ----
        int totalH = 0, rw = M, rh = 0;
        for (int i = 0; i < N; i++) {
            preH[i] = totalH;
            preRw[i] = rw;
            preRh[i] = rh;

            int w = W[i], h = H[i];
            if (rw >= w) {
                rh = Math.max(rh, h);
                rw -= w;
            } else {
                int sh = (h * rw + w - 1) / w;
                rh = Math.max(rh, sh);
                rw = 0;
            }
            if (rw == 0) {
                totalH += rh;
                rw = M;
                rh = 0;
            }
        }

        // ---- 枚举删除 ----
        int ans = Integer.MAX_VALUE;
        for (int d = 0; d < N; d++) {
            int curH = preH[d];
            int curRw = preRw[d];
            int curRh = preRh[d];
            if (curRw == M || curRw == 0) {
                curH += S[d + 1];
            } else {
                curH += Math.max(curRh, A[d + 1][curRw]) + B[d + 1][curRw];
            }
            if (curH < ans) ans = curH;
        }
        System.out.println(ans);
    }
}
