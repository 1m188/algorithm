/*
 * 标题：图书排列
 *
 * 【题目描述】
 *   将编号为1~10的10本书排放在书架上，要求编号相邻的书不能放在相邻的位置。
 *   请计算一共有多少种不同的排列方案。
 *
 *   注意，需要提交的是一个整数，不要填写任何多余的内容。
 *
 * 【求解思路】
 *   排列总数为 10! ≈ 3.6×10^6，可用 DFS 回溯枚举全排列并剪枝。
 *   用一个布尔数组记录已用数字，递归时确保新数字与已放最后一个数字不相邻。
 *   答案：479306。
 */

public class _1 {
    // 书的数量
    static final int N = 10;
    // 已用数字标记
    static boolean[] used = new boolean[N + 1];
    // 当前排列中已放书的数量
    static int[] perm = new int[N];
    // 合法方案计数
    static long count = 0;

    public static void main(String[] args) {
        dfs(0);
        System.out.println(count);
    }

    // 深度优先搜索：pos 表示当前已放置的书本数量
    static void dfs(int pos) {
        // 所有 10 本书均放置完毕，计数加一
        if (pos == N) {
            count++;
            return;
        }

        // 尝试在当前位置放置编号为 i 的书
        for (int i = 1; i <= N; i++) {
            if (used[i])
                continue;
            // 剪枝：若当前书与上一本书编号相邻（差值为 1），则跳过
            if (pos > 0 && Math.abs(i - perm[pos - 1]) == 1)
                continue;

            used[i] = true;
            perm[pos] = i;
            dfs(pos + 1);
            used[i] = false;
        }
    }
}
