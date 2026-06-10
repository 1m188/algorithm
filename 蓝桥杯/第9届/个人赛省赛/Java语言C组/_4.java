/*

标题：第几个幸运数

到x星球旅行的游客都被发给一个整数，作为游客编号。
x星的国王有个怪癖，他只喜欢数字3,5和7。
国王规定，游客的编号如果只含有因子：3,5,7,就可以获得一份奖品。

我们来看前10个幸运数字是：
3 5 7 9 15 21 25 27 35 45
因而第11个幸运数字是：49

小明领到了一个幸运数字 59084709587505，他去领奖的时候，人家要求他准确地说出这是第几个幸运数字，否则领不到奖品。

请你帮小明计算一下，59084709587505是第几个幸运数字。

需要提交的是一个整数，请不要填写任何多余内容。

*/

import java.util.*;

public class _4 {

    /**
     * 第几个幸运数
     *
     * 幸运数定义为只含有质因子 3、5、7 的正整数。
     * 即所有形如 3ᵃ × 5ᵇ × 7ᶜ 的数（a,b,c ≥ 0，且不全为 0）。
     *
     * 核心思路：
     * 1. 确定各项指数的上界：
     * 3²⁸ ≈ 2.28×10¹³ ＜ target ≤ 3²⁹
     * 5¹⁹ ≈ 1.91×10¹³ ＜ target ≤ 5²⁰
     * 7¹⁶ ≈ 3.32×10¹³ ＜ target ≤ 7¹⁷
     * 2. 三重循环生成所有 ≤ target 的幸运数（约 5000 个）。
     * 3. 通过提前判断乘积是否越界 / 超限来剪枝。
     * 4. 将所有生成的数排序，二分查找目标值的位置，+1 得到序号。
     *
     * 时间复杂度：O(M log M)，M 为幸运数个数（约 1905 个）。
     * 空间复杂度：O(M)。
     */

    public static void main(String[] args) {
        long target = 59084709587505L;

        /* 存放所有 ≤ target 的幸运数 */
        List<Long> luckyNumbers = new ArrayList<Long>();

        /*
         * 预计算 3、5、7 的各次幂，避免重复运算。
         * 同时确定最大指数上界。
         */
        long p3 = 1;
        for (int a = 0;; a++) {
            /* 当 3^a 自身已超过 target 时停止 */
            if (p3 > target)
                break;

            long p5 = 1;
            for (int b = 0;; b++) {
                /*
                 * 提前剪枝：3^a × 5^b 若超过 target，
                 * 则后续更大的 b 也会超过，跳出内层循环。
                 */
                long p35 = p3 * p5;
                if (p35 > target || p35 < 0)
                    break; // p35 < 0 检查乘法溢出

                long p7 = 1;
                for (int c = 0;; c++) {
                    long value = p35 * p7;
                    if (value > target || value < 0)
                        break;

                    /*
                     * 排除 a=b=c=0 的情况（值为 1），
                     * 因为 1 不被视为幸运数（没有质因子）。
                     */
                    if (value != 1) {
                        luckyNumbers.add(value);
                    }
                    p7 *= 7;
                }
                p5 *= 5;
            }
            p3 *= 3;
        }

        /* 升序排列所有幸运数 */
        Collections.sort(luckyNumbers);

        /*
         * 二分查找 target 在列表中的位置。
         * 序号 = 索引 + 1（序号从 1 开始）。
         */
        int index = Collections.binarySearch(luckyNumbers, target);
        if (index >= 0) {
            System.out.println(index + 1);
        } else {
            System.out.println("目标数不在幸运数列表中");
        }
    }
}
