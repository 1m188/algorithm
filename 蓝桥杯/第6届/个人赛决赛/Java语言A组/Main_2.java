/*
 
标题：四阶幻方

把1~16的数字填入4x4的方格中，使得行、列以及两个对角线的和都相等，满足这样的特征时称为：四阶幻方。

四阶幻方可能有很多方案。如果固定左上角为1，请计算一共有多少种方案。
比如：
  1  2 15 16
 12 14  3  5
 13  7 10  4
  8 11  6  9

以及：
  1 12 13  8
  2 14  7 11
 15  3 10  6
 16  5  4  9
 
就可以算为两种不同的方案。

请提交左上角固定为1时的所有方案数字，不要填写任何多余内容或说明文字。

*/

/**
 * 分析：
 * 幻和 = (1+16)*16/2 / 4 = 34
 * grid[0] = 1 固定。
 *
 * 枚举策略：
 * 按行优先遍历 16 个位置，仅枚举 8 个自由格：
 * {1, 2, 4, 5, 6, 8, 9, 10}
 * 剩余 7 个格子 {3, 7, 11, 12, 13, 14, 15} 由行列和约束自动计算。
 * 所有格子确定后再验证两条对角线。
 */
public class Main_2 {
    static final int SUM = 34;
    static int[] grid = new int[16];
    static boolean[] used = new boolean[17]; // 1..16
    static int count = 0;

    // 需要枚举的位置（自由格）
    static boolean isEnumerate(int pos) {
        return pos == 1 || pos == 2 || pos == 4 || pos == 5 || pos == 6
                || pos == 8 || pos == 9 || pos == 10;
    }

    public static void main(String[] args) {
        grid[0] = 1;
        used[1] = true;
        dfs(1);
        System.out.println(count);
    }

    static void dfs(int pos) {
        if (pos == 16) {
            // 所有行列约束已满足，只需验证两条对角线
            if (grid[0] + grid[5] + grid[10] + grid[15] == SUM &&
                    grid[3] + grid[6] + grid[9] + grid[12] == SUM) {
                count++;
            }
            return;
        }

        // 判断当前格子是由约束计算还是需要枚举
        if (isEnumerate(pos)) {
            // 枚举：尝试 2..16 中未使用的数字
            for (int v = 2; v <= 16; v++) {
                if (!used[v]) {
                    used[v] = true;
                    grid[pos] = v;
                    dfs(pos + 1);
                    used[v] = false;
                }
            }
        } else {
            // 由行列和约束计算
            int val = compute(pos);
            if (val >= 1 && val <= 16 && !used[val]) {
                used[val] = true;
                grid[pos] = val;
                dfs(pos + 1);
                used[val] = false;
            }
            // 计算出的值无效：回溯（不递归）
        }
    }

    /** 根据行列和约束计算位置的应填值 */
    static int compute(int pos) {
        switch (pos) {
            case 3:
                return SUM - grid[0] - grid[1] - grid[2]; // 第0行
            case 7:
                return SUM - grid[4] - grid[5] - grid[6]; // 第1行
            case 11:
                return SUM - grid[8] - grid[9] - grid[10]; // 第2行
            case 12:
                return SUM - grid[0] - grid[4] - grid[8]; // 第0列
            case 13:
                return SUM - grid[1] - grid[5] - grid[9]; // 第1列
            case 14:
                return SUM - grid[2] - grid[6] - grid[10]; // 第2列
            case 15:
                return SUM - grid[3] - grid[7] - grid[11]; // 第3列
            default:
                return -1;
        }
    }
}
