/*
牌型种数

小明被劫持到X赌城，被迫与其他3人玩牌。
一副扑克牌（去掉大小王牌，共52张），均匀发给4个人，每个人13张。
这时，小明脑子里突然冒出一个问题：
如果不考虑花色，只考虑点数，也不考虑自己得到的牌的先后顺序，自己手里能拿到的初始牌型组合一共有多少种呢？

请填写该整数，不要填写任何多余的内容或说明文字。
*/

/*
 * 解题思路：
 * 共 13 种点数（A,2,...,K），每种点数有 4 张（四种花色）。
 * 从每种点数中选取 0~4 张，使得总张数为 13。
 * 用 DFS 枚举 13 个位置，每个取 0~4，求和为 13 的方案数。
 * 答案：3598180。
 */
public class _7 {
    static int count = 0;

    static void dfs(int idx, int sum) {
        if (sum > 13)
            return;
        if (idx == 13) { // 已处理完 13 种点数
            if (sum == 13)
                count++;
            return;
        }
        // 第 idx 种点数可取 0,1,2,3,4 张
        for (int take = 0; take <= 4; take++)
            dfs(idx + 1, sum + take);
    }

    public static void main(String[] args) {
        dfs(0, 0);
        System.out.println(count);
    }
}
