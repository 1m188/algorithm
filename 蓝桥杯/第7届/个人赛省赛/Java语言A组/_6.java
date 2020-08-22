// 寒假作业

// 现在小学的数学题目也不是那么好玩的。
// 看看这个寒假作业：

//    □ + □ = □
//    □ - □ = □
//    □ × □ = □
//    □ ÷ □ = □

//    (如果显示不出来，可以参见【图1.jpg】)

// 每个方块代表1~13中的某一个数字，但不能重复。
// 比如：
//  6  + 7 = 13
//  9  - 8 = 1
//  3  * 4 = 12
//  10 / 2 = 5

// 以及： 
//  7  + 6 = 13
//  9  - 8 = 1
//  3  * 4 = 12
//  10 / 2 = 5

// 就算两种解法。（加法，乘法交换律后算不同的方案）

// 你一共找到了多少种方案？

// 请填写表示方案数目的整数。
// 注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。

public class _6 {
    private static int[] expression = new int[12];
    private static boolean[] flag = new boolean[13];
    private static int res;

    public static void main(String[] args) {
        dfs(0);
        System.out.println(res);
    }

    public static void dfs(int ei) {
        switch (ei) {
            case 3:
                if (expression[ei - 3] + expression[ei - 2] != expression[ei - 1]) {
                    return;
                }
                break;
            case 6:
                if (expression[ei - 3] - expression[ei - 2] != expression[ei - 1]) {
                    return;
                }
                break;
            case 9:
                if (expression[ei - 3] * expression[ei - 2] != expression[ei - 1]) {
                    return;
                }
                break;
            case 12:
                // 这里有个陷阱，需要考虑除法之后的小数是否等于，如果直接用整数做比较的话会丢失小数部分
                if (expression[ei - 2] != 0
                        && (double) expression[ei - 3] / expression[ei - 2] == (double) expression[ei - 1]) {
                    res++;
                }
                return;
        }

        for (int i = 0; i < flag.length; i++) {
            if (!flag[i]) {
                flag[i] = true;
                expression[ei] = i + 1;
                dfs(ei + 1);
                flag[i] = false;
            }
        }
    }
}