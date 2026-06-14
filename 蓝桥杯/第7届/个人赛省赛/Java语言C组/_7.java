/*
搭积木

小明最近喜欢搭数字积木，
一共有10块积木，每个积木上有一个数字，0~9。

搭积木规则：
每个积木放到其它两个积木的上面，并且一定比下面的两个积木数字小。
最后搭成4层的金字塔形，必须用完所有的积木。

下面是两种合格的搭法：

   0
  1 2
 3 4 5
6 7 8 9

   0
  3 1
 7 5 2
9 8 6 4    

请你计算这样的搭法一共有多少种？

请填表示总数目的数字。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
*/
public class _7 {
    /** 金字塔 10 个位置编号（从上到下、从左到右）：
     *       0
     *     1   2
     *   3   4   5
     * 6   7   8   9
     * 上层数必须小于下层两个数。
     */
    static int[] num = new int[10];
    static boolean[] used = new boolean[10];
    static int cnt = 0;

    // 每个位置需要大于哪些已填的上方位置
    static int[][] above = {
        {},          // 0: 无
        {0},         // 1: 大于 0
        {0},         // 2: 大于 0
        {1},         // 3: 大于 1
        {1, 2},      // 4: 大于 1 和 2
        {2},         // 5: 大于 2
        {3},         // 6: 大于 3
        {3, 4},      // 7: 大于 3 和 4
        {4, 5},      // 8: 大于 4 和 5
        {5},         // 9: 大于 5
    };

    public static void main(String[] args) {
        dfs(0);
        System.out.println(cnt);
    }

    static void dfs(int pos) {
        if (pos == 10) {
            cnt++;
            return;
        }
        for (int n = 0; n <= 9; n++) {
            if (used[n])
                continue;
            boolean ok = true;
            for (int a : above[pos]) {
                if (n <= num[a]) {           // 必须大于上方数字
                    ok = false;
                    break;
                }
            }
            if (!ok)
                continue;
            num[pos] = n;
            used[n] = true;
            dfs(pos + 1);
            used[n] = false;
        }
    }
}
