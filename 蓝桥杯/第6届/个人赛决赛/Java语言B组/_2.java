/*
 
标题：五星填数

如【图1.png】的五星图案节点填上数字：1~12，除去7和11。
要求每条直线上数字和相等。

如图就是恰当的填法。

请你利用计算机搜索所有可能的填法有多少种。
注意：旋转或镜像后相同的算同一种填法。

请提交表示方案数目的整数，不要填写任何其它内容。

*/

/**
 * 解法分析：
 *
 * 五星图案共 10 个节点（编号 0~9），填入数字 1~12（除去 7 和 11）。
 * 可选数字共 10 个：{1,2,3,4,5,6,8,9,10,12}，总和 60。
 *
 * 每个节点恰好在 2 条直线上，故 5 条线之和 = 2 × 60 = 120，每条线目标和 = 24。
 *
 * 节点编号（与示例图对应）：
 * 0
 * 1 2 3 4
 * 5 6
 * 7
 * 8 9
 *
 * 5 条直线（每条 4 个节点）：
 * L0: {0, 2, 5, 8}
 * L1: {0, 3, 6, 9}
 * L2: {1, 2, 3, 4}
 * L3: {1, 5, 7, 9}
 * L4: {4, 6, 7, 8}
 *
 * 剪枝策略：
 * - 填完位置 4 时，L2 = {1,2,3,4} 已完整，检查其和须为 24。
 * - 填完位置 8 时，L0 = {0,2,5,8} 和 L4 = {4,6,7,8} 已完整，检查其和须为 24。
 * - 全部填完后检查 L1 和 L3。
 *
 * 对称去重（D5 正二面体群，10 个变换）：
 * 圆周顺序（顺时针）：0 → 3 → 4 → 6 → 9 → 7 → 8 → 5 → 1 → 2 → 0
 * 旋转 r：圆周前进 2 位（72°）
 * 反射 s：关于过顶点 0 的竖直轴
 * 对每个合法解取 10 个对称像中字典序最小者作为规范形，用 HashSet 去重。
 */
public class _2 {

    // 可选数字：1~12 除去 7 和 11
    static final int[] NUMS = { 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 };
    static final int TARGET = 24;
    static final int N = 10;

    // 5 条直线（每条 4 个节点编号）
    static final int[][] LINES = {
            { 0, 2, 5, 8 }, // L0
            { 0, 3, 6, 9 }, // L1
            { 1, 2, 3, 4 }, // L2
            { 1, 5, 7, 9 }, // L3
            { 4, 6, 7, 8 }, // L4
    };

    // D5 对称群：10 个置换
    // 圆周顺序（顺时针从顶点 0 开始）：
    // 0(外) → 3(内) → 4(外) → 6(内) → 9(外) → 7(内) → 8(外) → 5(内) → 1(外) → 2(内) → 0
    // 旋转 r：圆周上前进 2 个位置（72°）
    // 反射 s：关于过顶点 0 的竖直轴
    static final int[][] SYM = new int[10][N];

    static {
        // 生成元
        int[] r = { 4, 0, 3, 6, 9, 2, 7, 5, 1, 8 }; // 旋转 72°
        int[] s = { 0, 4, 3, 2, 1, 6, 5, 7, 9, 8 }; // 反射

        // sym[0] = 恒等
        for (int i = 0; i < N; i++) {
            SYM[0][i] = i;
        }

        // 旋转：r, r², r³, r⁴
        System.arraycopy(r, 0, SYM[1], 0, N);
        compose(r, r, SYM[2]);
        compose(SYM[2], r, SYM[3]);
        compose(SYM[3], r, SYM[4]);

        // 反射：s, s·r, s·r², s·r³, s·r⁴
        System.arraycopy(s, 0, SYM[5], 0, N);
        compose(s, r, SYM[6]);
        compose(s, SYM[2], SYM[7]);
        compose(s, SYM[3], SYM[8]);
        compose(s, SYM[4], SYM[9]);
    }

    // 复合置换：c[i] = a[b[i]]
    static void compose(int[] a, int[] b, int[] result) {
        for (int i = 0; i < N; i++) {
            result[i] = a[b[i]];
        }
    }

    static int[] pos = new int[N]; // 当前排列
    static boolean[] used = new boolean[N]; // 对应 NUMS 中哪些已使用

    // 用 String 编码规范形以便 HashSet 去重
    static java.util.HashSet<String> canonicalSet = new java.util.HashSet<>();

    // 计算一条直线上 4 个数字的和
    static int lineSum(int[] line) {
        return pos[line[0]] + pos[line[1]] + pos[line[2]] + pos[line[3]];
    }

    /**
     * 计算规范形：遍历 10 个对称变换，取字典序最小者
     * 返回规范形的字符串编码（逗号分隔）
     */
    static String canonical() {
        String best = null;
        int[] temp = new int[N];
        StringBuilder sb = new StringBuilder();

        for (int k = 0; k < 10; k++) {
            // 对 pos 施加 sym[k]：temp[sym[k][i]] = pos[i]
            for (int i = 0; i < N; i++) {
                temp[SYM[k][i]] = pos[i];
            }

            sb.setLength(0);
            for (int i = 0; i < N; i++) {
                if (i > 0)
                    sb.append(',');
                sb.append(temp[i]);
            }
            String encoded = sb.toString();

            if (best == null || encoded.compareTo(best) < 0) {
                best = encoded;
            }
        }
        return best;
    }

    static void dfs(int idx) {
        if (idx == N) {
            // 检查最后两条线 L1 和 L3
            if (lineSum(LINES[1]) != TARGET || lineSum(LINES[3]) != TARGET) {
                return;
            }
            canonicalSet.add(canonical());
            return;
        }

        for (int i = 0; i < N; i++) {
            if (used[i])
                continue;
            used[i] = true;
            pos[idx] = NUMS[i];

            boolean ok = true;
            // 填完位置 4（即索引 4）后，L2 = {1,2,3,4} 可检查
            if (idx == 4) {
                if (lineSum(LINES[2]) != TARGET)
                    ok = false;
            }
            // 填完位置 8（即索引 8）后，L0 = {0,2,5,8} 和 L4 = {4,6,7,8} 可检查
            if (ok && idx == 8) {
                if (lineSum(LINES[0]) != TARGET || lineSum(LINES[4]) != TARGET) {
                    ok = false;
                }
            }

            if (ok) {
                dfs(idx + 1);
            }
            used[i] = false;
        }
    }

    public static void main(String[] args) {
        dfs(0);
        System.out.println(canonicalSet.size());
    }
}
