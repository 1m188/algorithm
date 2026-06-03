/*
 * 标题：采油
 * 
 * LQ公司是世界著名的石油公司，为世界供应优质石油。
 * 最近，LQ公司又在森林里发现了一大片区域的油田，可以在这个油田中开采n个油井。
 * LQ公司在这n个油井之间修建了n-1条道路，每条道路连接两个油井，路径中间不会路过任何油井，而且这些道路将所有油井连通。
 * 建立油井的时候需要使用一台大型设备，运输起来非常麻烦，LQ公司准备在其中的一个油井位置建立一个空运站，先将设备空运到空运站，之后每次经过他们建立的道路来运输这个大型设备以建立不同的油井，当油井建立完毕后再从空运站将大型设备运走。
 * 为了减少运输的麻烦，公司要求大型设备在道路上运输的总路程是最短的。
 * 
 * 在建立油井和采油的过程中需要花费一些人力，第i个油井需要花费Bi个人，而一旦油井建成，就需要Si个人一直坚守在油井上进行维护。
 * 当然，如果一个人参与了油井的建设，他可以直接留下来维护油井，或者参与下一个油井的建设，但是在维护油井的人不能再参加后续油井的建设了。
 * 
 * 现在LQ公司想知道，大型设备运输的总路径长度最短是多少？在保证总路径长度最短的情况下，LQ公司至少需要花费多少人力才能完成所有油井的建立与维护。
 * 
 * 【输入格式】
 * 　　输入的第一行包含一个整数n，表示油井的数量。油井由1到n依次标号。
 * 　　第二行包含n个整数，依次表示B1, B2, …, Bn，相邻的整数之间用一个空格分隔。
 * 　　第三行包含n个整数，依次表示S1, S2, …, Sn，相邻的整数之间用一个空格分隔。
 * 　　接下来n-1行描述油井之间的道路，其中的第i行包含两个整数a，b，用一个空格分隔，表示一条道路的起点为i+1、终点为a，长度为b，道路是双向的，设备可以从任意一端运送到另一端，每条道路都可以经过任意多次。数据保证任意两个油井之间都可以通过道路连接。
 * 
 * 【输出格式】
 * 　　输出包含两个整数，用一个空格分隔，表示最优情况下大型设备需要运输的总路程，以及在总路程最短的情况下最少需要花费的人力数量。
 * 
 * 【样例输入】
 * 2
 * 10 20
 * 15 15
 * 1 8
 * 
 * 【样例输出】
 * 16 30
 * 
 * 【样例说明】
 * 　　有两种方案达到最优。
 * 　　方案一：在油井2建立空运站，先建立油井2，再将大型设备运输到油井1建立油井1，最后将大型设备运回油井2。
 * 　　方案二：在油井1建立空运站，先将大型设备运输到油井2建立油井2，再将大型设备运送到油井1建立油井1。
 * 
 * 【样例输入】
 * 6
 * 3 10 20 7 15 9
 * 2 6 10 4 8 7
 * 1 9
 * 1 2
 * 2 5
 * 3 4
 * 3 7
 * 
 * 【样例输出】
 * 54 38
 * 
 * 【数据规模和约定】
 * 　　对于20%的数据：n不超过10；
 * 　　另外20%的数据：每个油井最多和两个油井之间有道路直接连接；
 * 　　另外10%的数据：有n-1个油井只有一条道路与其他油井连接；
 * 　　对于100%的数据：n不超过100000，B、S、c均为不超过10000的正整数。
 * 
 * 资源约定：
 * 峰值内存消耗（含虚拟机） < 256M
 * CPU消耗  < 1000ms
 * 
 * 请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。
 * 
 * 所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
 * 不要使用package语句。不要使用jdk1.7及以上版本的特性。
 * 主类的名字必须是：Main，否则按无效代码处理。
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

public class Main {

    static int n;
    static long[] B, S;
    static long[] c, d;
    static long[] down_C, down_D;
    static long[] up_C, up_D;
    static ArrayList<long[]>[] adj;
    static long totalWeight;
    static long sumS;
    static long ans;

    // 聚合函数：给定一组 (C, D) 对，计算 (best_C, total_D)
    // 将项目按 C 降序排列后，best_C = max_i (C_i - sum_{j>i} D_j)
    static long[] aggregate(ArrayList<long[]> items) {
        if (items.isEmpty()) {
            return new long[] { 0, 0 };
        }
        // 按 C 降序排序
        Collections.sort(items, new Comparator<long[]>() {
            public int compare(long[] a, long[] b) {
                if (a[0] < b[0])
                    return 1;
                if (a[0] > b[0])
                    return -1;
                return 0;
            }
        });
        long totalD = 0;
        for (int i = 0, sz = items.size(); i < sz; i++) {
            totalD += items.get(i)[1];
        }
        long suffix = totalD;
        long bestC = Long.MIN_VALUE;
        for (int i = 0, sz = items.size(); i < sz; i++) {
            long[] it = items.get(i);
            suffix -= it[1];
            long val = it[0] - suffix;
            if (val > bestC) {
                bestC = val;
            }
        }
        return new long[] { bestC, totalD };
    }

    // 合并两组聚合值：先处理组 a，再处理组 b
    static long[] mergeTwo(long[] a, long[] b) {
        if (a[1] == 0 && b[1] == 0) {
            return new long[] { 0, 0 };
        }
        long newC = Math.max(a[0] - b[1], b[0]);
        return new long[] { newC, a[1] + b[1] };
    }

    // 第一次 DFS：自底向上计算 down_C 和 down_D
    static void dfs1(int u, int p) {
        ArrayList<long[]> items = new ArrayList<long[]>();
        items.add(new long[] { c[u], d[u] });
        for (int i = 0, sz = adj[u].size(); i < sz; i++) {
            long[] edge = adj[u].get(i);
            int v = (int) edge[0];
            if (v == p)
                continue;
            dfs1(v, u);
            items.add(new long[] { down_C[v], down_D[v] });
        }
        long[] res = aggregate(items);
        down_C[u] = res[0];
        down_D[u] = res[1];
    }

    // 第二次 DFS：换根 DP，枚举每个节点作为空运站，更新答案
    static void dfs2(int u, int p) {
        // —— 以 u 为根计算答案 ——
        {
            ArrayList<long[]> items = new ArrayList<long[]>();
            items.add(new long[] { c[u], d[u] });
            if (p != 0) {
                items.add(new long[] { up_C[u], up_D[u] });
            }
            for (int i = 0, sz = adj[u].size(); i < sz; i++) {
                long[] edge = adj[u].get(i);
                int v = (int) edge[0];
                if (v == p)
                    continue;
                items.add(new long[] { down_C[v], down_D[v] });
            }
            long[] res = aggregate(items);
            long curAns = sumS + res[0];
            if (curAns < ans) {
                ans = curAns;
            }
        }

        // —— 收集孩子并按 down_C 降序排序 ——
        int deg = 0;
        for (int i = 0, sz = adj[u].size(); i < sz; i++) {
            long[] edge = adj[u].get(i);
            int v = (int) edge[0];
            if (v == p)
                continue;
            deg++;
        }

        final long[][] childVals = new long[deg][2];
        final int[] childIds = new int[deg];
        int idx = 0;
        for (int i = 0, sz = adj[u].size(); i < sz; i++) {
            long[] edge = adj[u].get(i);
            int v = (int) edge[0];
            if (v == p)
                continue;
            childVals[idx][0] = down_C[v];
            childVals[idx][1] = down_D[v];
            childIds[idx] = v;
            idx++;
        }

        // 按 C 降序排列孩子
        Integer[] order = new Integer[deg];
        for (int i = 0; i < deg; i++) {
            order[i] = i;
        }
        Arrays.sort(order, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                long ca = childVals[a][0];
                long cb = childVals[b][0];
                if (ca < cb)
                    return 1;
                if (ca > cb)
                    return -1;
                return 0;
            }
        });

        // 前缀合并
        long[][] pref = new long[deg + 1][2];
        pref[0][0] = 0;
        pref[0][1] = 0;
        for (int i = 0; i < deg; i++) {
            long[] childVal = childVals[order[i]];
            long[] merged = mergeTwo(pref[i], childVal);
            pref[i + 1][0] = merged[0];
            pref[i + 1][1] = merged[1];
        }

        // 后缀合并
        long[][] suff = new long[deg + 1][2];
        suff[deg][0] = 0;
        suff[deg][1] = 0;
        for (int i = deg - 1; i >= 0; i--) {
            long[] childVal = childVals[order[i]];
            long[] merged = mergeTwo(childVal, suff[i + 1]);
            suff[i][0] = merged[0];
            suff[i][1] = merged[1];
        }

        // 为每个孩子计算 up 值并递归
        for (int i = 0; i < deg; i++) {
            int v = childIds[order[i]];
            ArrayList<long[]> itemsUp = new ArrayList<long[]>();
            itemsUp.add(new long[] { c[u], d[u] });
            if (p != 0) {
                itemsUp.add(new long[] { up_C[u], up_D[u] });
            }
            // 只添加 D 非零的分组（零分组的 (0,0) 不影响聚合结果）
            if (pref[i][1] != 0) {
                itemsUp.add(new long[] { pref[i][0], pref[i][1] });
            }
            if (suff[i + 1][1] != 0) {
                itemsUp.add(new long[] { suff[i + 1][0], suff[i + 1][1] });
            }
            long[] res = aggregate(itemsUp);
            up_C[v] = res[0];
            up_D[v] = res[1];
            dfs2(v, u);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine().trim());

        B = new long[n + 1];
        S = new long[n + 1];
        c = new long[n + 1];
        d = new long[n + 1];
        down_C = new long[n + 1];
        down_D = new long[n + 1];
        up_C = new long[n + 1];
        up_D = new long[n + 1];

        String[] bStr = br.readLine().split(" ");
        for (int i = 1; i <= n; i++) {
            B[i] = Long.parseLong(bStr[i - 1]);
        }
        String[] sStr = br.readLine().split(" ");
        for (int i = 1; i <= n; i++) {
            S[i] = Long.parseLong(sStr[i - 1]);
        }

        adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<long[]>();
        }

        totalWeight = 0;
        for (int i = 1; i < n; i++) {
            String[] edgeStr = br.readLine().split(" ");
            int a = Integer.parseInt(edgeStr[0]);
            long b = Long.parseLong(edgeStr[1]);
            adj[i + 1].add(new long[] { a, b });
            adj[a].add(new long[] { i + 1, b });
            totalWeight += b;
        }

        sumS = 0;
        for (int i = 1; i <= n; i++) {
            d[i] = Math.min(B[i], S[i]);
            c[i] = Math.max(0, B[i] - S[i]);
            sumS += S[i];
        }

        // 使用较大栈空间运行递归，防止链状树栈溢出
        Thread solver = new Thread(null, new Runnable() {
            public void run() {
                dfs1(1, 0);
                ans = sumS + down_C[1];
                dfs2(1, 0);
                System.out.println((2 * totalWeight) + " " + ans);
            }
        }, "Solver", 1 << 26); // 64 MB 栈空间
        solver.start();
        solver.join();
    }
}
