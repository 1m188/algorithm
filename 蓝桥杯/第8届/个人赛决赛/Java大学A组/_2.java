/*
 * 标题：磁砖样式
 *
 * 【题目描述】
 *   小明家的一面装饰墙原来是 3*10 的小方格。
 *   现在手头有一批刚好能盖住2个小方格的长方形瓷砖。
 *   瓷砖只有两种颜色：黄色和橙色。
 *
 *   小明想知道，对于这么简陋的原料，可以贴出多少种不同的花样来。
 *   小明有个小小的强迫症：忍受不了任何2*2的小格子是同一种颜色。
 *   （瓷砖不能切割，不能重叠，也不能只铺一部分。另外，只考虑组合图案，请忽略瓷砖的拼缝）
 *   显然，对于 2*3 个小格子来说，口算都可以知道：一共10种贴法，如【p1.png所示】
 *
 *   但对于 3*10 的格子呢？肯定是个不小的数目，请你利用计算机的威力算出该数字。
 *
 *   注意：你需要提交的是一个整数，不要填写任何多余的内容（比如：说明性文字）
 *
 * 【求解思路】
 *   - 目标：求 3×10 的网格上，用 1×2 的彩色（黄/橙）瓷砖能铺出的不同颜色图案数。
 *   - 约束：(1) 瓷砖不切割不重叠，刚好铺满；(2) 任意 2×2 子网格不能全同色。
 *   - 题目要求"忽略瓷砖拼缝"，即不同铺法若产生相同最终颜色图案则只计一次。
 *   - 解法：DFS 回溯枚举所有铺砖方案，棋盘铺满时对颜色图案去重统计。
 *   - 剪枝：每次放置瓷砖后立即全局检查所有已完成 2×2 子网格是否全同色。
 *   - 已验证：2×3 参考用例得 10 种，符合题目所述。
 *   - 答案：101466。
 */

import java.util.HashSet;

public class _2 {
    // 棋盘尺寸
    static final int ROWS = 3;
    static final int COLS = 10;

    // 棋盘：-1 未填充，0 黄色，1 橙色
    static int[][] board = new int[ROWS][COLS];

    // 去重集合，将着色编码为 30 位整数
    static HashSet<Integer> patterns = new HashSet<>();

    public static void main(String[] args) {
        // 初始化棋盘为未填充状态
        for (int r = 0; r < ROWS; r++)
            for (int c = 0; c < COLS; c++)
                board[r][c] = -1;

        dfs(0, 0);
        System.out.println(patterns.size());
    }

    // 检查所有 2×2 子网格，若存在已填满且全同色的则返回 false
    static boolean check2x2() {
        for (int r = 0; r < ROWS - 1; r++)
            for (int c = 0; c < COLS - 1; c++)
                if (board[r][c] != -1 && board[r][c + 1] != -1 &&
                        board[r + 1][c] != -1 && board[r + 1][c + 1] != -1)
                    if (board[r][c] == board[r][c + 1] &&
                            board[r][c + 1] == board[r + 1][c] &&
                            board[r + 1][c] == board[r + 1][c + 1])
                        return false;
        return true;
    }

    // 将当前棋盘着色编码为整数：橙色格子 (1) 的位设为 1
    static int encode() {
        int code = 0;
        for (int r = 0; r < ROWS; r++)
            for (int c = 0; c < COLS; c++)
                if (board[r][c] == 1)
                    code |= 1 << (r * COLS + c);
        return code;
    }

    // 深度优先搜索，(r, c) 为起始搜索位置
    static void dfs(int r, int c) {
        // 跳过已填充格子，找到下一个空位
        while (r < ROWS && board[r][c] != -1) {
            if (++c == COLS) {
                c = 0;
                r++;
            }
        }

        // 全部填充完毕，记录图案
        if (r == ROWS) {
            patterns.add(encode());
            return;
        }

        int sr = r, sc = c;

        // 横放瓷砖（当前格 + 右侧格）
        if (sc + 1 < COLS && board[sr][sc + 1] == -1) {
            board[sr][sc] = board[sr][sc + 1] = 0;
            if (check2x2())
                dfs(sr, sc);
            board[sr][sc] = board[sr][sc + 1] = 1;
            if (check2x2())
                dfs(sr, sc);
            board[sr][sc] = board[sr][sc + 1] = -1;
        }

        // 竖放瓷砖（当前格 + 下方格）
        if (sr + 1 < ROWS && board[sr + 1][sc] == -1) {
            board[sr][sc] = board[sr + 1][sc] = 0;
            if (check2x2())
                dfs(sr, sc);
            board[sr][sc] = board[sr + 1][sc] = 1;
            if (check2x2())
                dfs(sr, sc);
            board[sr][sc] = board[sr + 1][sc] = -1;
        }
    }
}
