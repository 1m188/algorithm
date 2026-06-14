/*

生成树计数

给定一个 n*m 的格点图，包含 n 行 m 列共 n*m 个顶点，相邻的顶点之间有一条边。
【图1.png】给出了一个3*4的格点图的例子。


如果在图中删除部分顶点和其相邻的边，如上图删除第2行第3列和第3行第1列的顶点后，如【图2.png】所示。

图的生成树指包含图中的所有顶点和其中的一部分边，使得任意两个顶点之间都有由边构成的唯一路径。如果两个生成树包含有不同的边即被认为不同，则上图中共有31种不同的生成树，其中a边不选有10种，a边选有21种。
给出格点图中保留的顶点的信息，请计算该图一共有多少种不同的生成树。

【输入格式】
输入的第一行包含两个整数n, m，用空格分隔，表示格点图的行数和列数。
接下来n行，每行m个字母（中间没有分隔字符），每个字母必然是大写E或大写N，E表示对应的顶点存在，N表示对应的顶点不存在。保证存在至少一个顶点。

【输出格式】
输出一行，包含一个整数，表示生成树的个数。答案可能很大，你只需要计算答案除以1000000007的余数即可。

【样例输入】
3 4
EEEE
EENE
NEEE

【样例输出】
31

【数据规模与约定】
对于10%的数据，1<=n<=2。
对于30%的数据，1<=n<=3。
对于40%的数据，1<=n<=4。
对于50%的数据，1<=n<=5。
另有20%的数据，1<=n*m<=12。
另有10%的数据，1<=m<=15。
对于100%的数据，1<=n<=6，1<=m<=100000。

资源约定：
峰值内存消耗 < 256M
CPU消耗 < 8000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。

*/

import java.util.*;

public class _6 {
    static final int MOD = 1000000007;
    static int n, m;
    static boolean[][] exist; // exist[col][row]

    static int encode(int[] comp) {
        int code = 0;
        for (int i = 0; i < n; i++)
            code = code * 7 + (comp[i] + 1);
        return code;
    }

    static void decode(int code, int[] comp) {
        for (int i = n - 1; i >= 0; i--) {
            comp[i] = (code % 7) - 1;
            code /= 7;
        }
    }

    static int find(int[] uf, int x) {
        while (uf[x] != x) {
            uf[x] = uf[uf[x]];
            x = uf[x];
        }
        return x;
    }

    static int normalize(int[] comp, int[] out) {
        int fresh = 0;
        int[] mapId = new int[30];
        Arrays.fill(mapId, -1);
        for (int i = 0; i < n; i++) {
            if (comp[i] < 0) {
                out[i] = -1;
                continue;
            }
            if (mapId[comp[i]] == -1)
                mapId[comp[i]] = fresh++;
            out[i] = mapId[comp[i]];
        }
        return fresh;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        sc.nextLine();
        exist = new boolean[m][n];
        for (int i = 0; i < n; i++) {
            String line = sc.nextLine();
            for (int j = 0; j < m; j++)
                exist[j][i] = (line.charAt(j) == 'E');
        }
        sc.close();

        // DP: 键 = (encode(comp) << 1) | hasFinished, 值 = 方案数
        HashMap<Long, Long> dp = new HashMap<Long, Long>();

        // ---- 初始化第 0 列 ----
        int horz0Max = 1 << (n - 1);
        int validHorz0Mask = 0;
        for (int r = 0; r < n - 1; r++)
            if (exist[0][r] && exist[0][r + 1])
                validHorz0Mask |= (1 << r);

        for (int horz0 = 0; horz0 < horz0Max; horz0++) {
            if ((horz0 & ~validHorz0Mask) != 0)
                continue;

            int[] uf = new int[n];
            for (int i = 0; i < n; i++)
                uf[i] = i;
            boolean cycle = false;

            for (int r = 0; r < n - 1 && !cycle; r++) {
                if (!exist[0][r] || !exist[0][r + 1])
                    continue;
                if ((horz0 & (1 << r)) == 0)
                    continue;
                int a = find(uf, r), b = find(uf, r + 1);
                if (a == b)
                    cycle = true;
                else
                    uf[a] = b;
            }
            if (cycle)
                continue;

            int[] initComp = new int[n];
            int fresh = 0;
            int[] mapId = new int[30];
            Arrays.fill(mapId, -1);
            for (int r = 0; r < n; r++) {
                if (!exist[0][r]) {
                    initComp[r] = -1;
                    continue;
                }
                int root = find(uf, r);
                if (mapId[root] == -1)
                    mapId[root] = fresh++;
                initComp[r] = mapId[root];
            }

            long key = ((long) encode(initComp) << 1); // hasFinished = 0
            Long prev = dp.get(key);
            dp.put(key, Long.valueOf(((prev != null ? prev.longValue() : 0L) + 1) % MOD));
        }

        // ---- 逐列转移 ----
        int[] oldComp = new int[n];
        int[] newComp = new int[n];
        int[] norm = new int[n];

        for (int col = 1; col < m; col++) {
            HashMap<Long, Long> ndp = new HashMap<Long, Long>();

            for (Map.Entry<Long, Long> entry : dp.entrySet()) {
                long key = entry.getKey().longValue();
                long ways = entry.getValue().longValue();
                if (ways == 0)
                    continue;

                int hasFinished = (int) (key & 1);
                int oldCode = (int) (key >> 1);
                decode(oldCode, oldComp);

                int oldCnt = 0;
                for (int r = 0; r < n; r++)
                    if (oldComp[r] >= oldCnt)
                        oldCnt = oldComp[r] + 1;

                int total = 1 + oldCnt + n; // FIN(0) + 旧分量(oldCnt个) + 新顶点(n个)

                int validHorzMask = 0, validVertMask = 0;
                for (int r = 0; r < n - 1; r++)
                    if (exist[col][r] && exist[col][r + 1])
                        validHorzMask |= (1 << r);
                for (int r = 0; r < n; r++)
                    if (exist[col - 1][r] && exist[col][r])
                        validVertMask |= (1 << r);

                int horzMax = 1 << (n - 1);
                int vertMax = 1 << n;

                for (int horz = 0; horz < horzMax; horz++) {
                    if ((horz & ~validHorzMask) != 0)
                        continue;
                    for (int vert = 0; vert < vertMax; vert++) {
                        if ((vert & ~validVertMask) != 0)
                            continue;

                        int[] uf = new int[total];
                        for (int i = 0; i < total; i++)
                            uf[i] = i;
                        boolean cycle = false;

                        // 新列内部水平边
                        for (int r = 0; r < n - 1 && !cycle; r++) {
                            if (!exist[col][r] || !exist[col][r + 1])
                                continue;
                            if ((horz & (1 << r)) == 0)
                                continue;
                            int a = find(uf, 1 + oldCnt + r);
                            int b = find(uf, 1 + oldCnt + r + 1);
                            if (a == b)
                                cycle = true;
                            else
                                uf[a] = b;
                        }
                        if (cycle)
                            continue;

                        // 竖直边：旧分量连接到新列顶点
                        for (int r = 0; r < n && !cycle; r++) {
                            if (!exist[col - 1][r] || !exist[col][r])
                                continue;
                            if ((vert & (1 << r)) == 0)
                                continue;
                            int a = find(uf, 1 + oldComp[r]);
                            int b = find(uf, 1 + oldCnt + r);
                            if (a == b)
                                cycle = true;
                            else
                                uf[a] = b;
                        }
                        if (cycle)
                            continue;

                        // 旧分量中未连接到新列的，接入 FIN
                        int newHasFinished = hasFinished;
                        for (int i = 0; i < oldCnt; i++) {
                            boolean connNew = false;
                            for (int r = 0; r < n && !connNew; r++) {
                                if (!exist[col][r])
                                    continue;
                                if (find(uf, 1 + i) == find(uf, 1 + oldCnt + r))
                                    connNew = true;
                            }
                            if (!connNew) {
                                int a = find(uf, 1 + i);
                                int b = find(uf, 0);
                                // a 与 b 在未合并时一定不同（FIN 初始独立）
                                uf[a] = b;
                                newHasFinished = 1;
                            }
                        }

                        // 生成新列的分量编号
                        for (int r = 0; r < n; r++) {
                            if (!exist[col][r]) {
                                newComp[r] = -1;
                                continue;
                            }
                            newComp[r] = find(uf, 1 + oldCnt + r);
                        }
                        normalize(newComp, norm);
                        long newKey = ((long) encode(norm) << 1) | newHasFinished;

                        Long prev = ndp.get(newKey);
                        ndp.put(newKey, Long.valueOf(((prev != null ? prev.longValue() : 0L) + ways) % MOD));
                    }
                }
            }
            dp = ndp;
            if (dp.isEmpty())
                break;
        }

        // ---- 统计答案 ----
        long ans = 0;
        for (Map.Entry<Long, Long> entry : dp.entrySet()) {
            long key = entry.getKey().longValue();
            int hasFinished = (int) (key & 1);
            int code = (int) (key >> 1);
            decode(code, oldComp);

            // 最后一列存在的顶点必须全部在同一分量内
            int uni = -1;
            boolean ok = true;
            for (int r = 0; r < n; r++) {
                if (!exist[m - 1][r])
                    continue;
                if (uni == -1)
                    uni = oldComp[r];
                if (oldComp[r] != uni) {
                    ok = false;
                    break;
                }
            }
            if (!ok)
                continue;

            long w = entry.getValue().longValue();
            if (hasFinished != 0) {
                if (uni == -1) // 最后一列无顶点，所有分量均已闭合
                    ans = (ans + w) % MOD;
            } else {
                if (uni >= 0) // 未闭合情况下所有顶点同属一个分量
                    ans = (ans + w) % MOD;
            }
        }

        System.out.println(ans);
    }
}
