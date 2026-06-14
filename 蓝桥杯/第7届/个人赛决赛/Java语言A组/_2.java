/*

凑平方数

把0~9这10个数字，分成多个组，每个组恰好是一个平方数，这是能够办到的。
比如：0, 36, 5948721

再比如：
1098524736
1, 25, 6390784
0, 4, 289, 15376
等等...

注意，0可以作为独立的数字，但不能作为多位数字的开始。
分组时，必须用完所有的数字，不能重复，不能遗漏。

如果不计较小组内数据的先后顺序，请问有多少种不同的分组方案？

注意：需要提交的是一个整数，不要填写多余内容。

*/

import java.util.ArrayList;
import java.util.List;

public class _2 {
    // 10 个数字全部被使用的位掩码（位0~9分别对应数字0~9）
    static final int FULL_MASK = (1 << 10) - 1;
    // 所有各位数字互不相同的平方数及其使用的数字掩码
    static List<Long> squares = new ArrayList<>();
    static List<Integer> masks = new ArrayList<>();
    // 满足条件的分组方案总数
    static int answer = 0;

    public static void main(String[] args) {
        // 1. 生成所有平方数，筛选出各位数字互不相同的
        long maxSq = 9876543210L; // 使用全部10个数字的最大可能数
        for (long i = 0; i * i <= maxSq; i++) {
            long s = i * i;
            int mask = digitMask(s);
            if (mask != -1) { // 各位数字无重复
                squares.add(s);
                masks.add(mask);
            }
        }

        // 2. DFS 搜索所有不相交的分组方案
        dfs(0, 0);

        // 3. 输出答案
        System.out.println(answer);
    }

    // 计算数字s的位掩码：若各位数字无重复则返回掩码，否则返回-1
    static int digitMask(long s) {
        if (s == 0)
            return 1; // 数字0 → 位0
        int mask = 0;
        while (s > 0) {
            int d = (int) (s % 10);
            if ((mask & (1 << d)) != 0)
                return -1; // 出现重复数字
            mask |= (1 << d);
            s /= 10;
        }
        return mask;
    }

    // depth-first search：mask-已使用数字的集合，idx-当前搜索起始下标
    static void dfs(int mask, int idx) {
        if (mask == FULL_MASK) { // 10个数字全部用完
            answer++;
            return;
        }
        // 按索引递增顺序选取，避免不同排列被重复计数
        for (int i = idx; i < masks.size(); i++) {
            int m = masks.get(i);
            if ((mask & m) == 0) { // 新组的数字与已选组无重叠
                dfs(mask | m, i + 1);
            }
        }
    }
}
