/*

标题：发现环


小明的实验室有N台电脑，编号1~N。原本这N台电脑之间有N-1条数据链接相连，恰好构成一个树形网络。在树形网络上，任意两台电脑之间有唯一的路径相连。

不过在最近一次维护网络时，管理员误操作使得某两台电脑之间增加了一条数据链接，于是网络中出现了环路。环路上的电脑由于两两之间不再是只有一条路径，使得这些电脑上的数据传输出现了BUG。

为了恢复正常传输。小明需要找到所有在环路上的电脑，你能帮助他吗？

输入
-----
第一行包含一个整数N。
以下N行每行两个整数a和b，表示a和b之间有一条数据链接相连。

对于30%的数据，1 <= N <= 1000
对于100%的数据, 1 <= N <= 100000， 1 <= a, b <= N

输入保证合法。

输出
----
按从小到大的顺序输出在环路上的电脑的编号，中间由一个空格分隔。


样例输入：
5
1 2
3 1
2 4
2 5
5 3

样例输出：
1 2 3 5

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
注意：不要使用package语句。不要使用jdk1.7及以上版本的特性。
注意：主类的名字必须是：Main，否则按无效代码处理。


*/

import java.io.*;
import java.util.*;

public class _4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        // 邻接表与度数数组
        ArrayList<Integer>[] adj = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++)
            adj[i] = new ArrayList<>();
        int[] deg = new int[N + 1];

        // 读入 N 条边（N 个节点的树 + 1 条额外边）
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj[a].add(b);
            adj[b].add(a);
            deg[a]++;
            deg[b]++;
        }

        // 拓扑排序删叶法：反复删除度为 1 的节点（叶节点）
        // 最终剩下的度数 ≥ 2 的节点即构成唯一的环
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= N; i++) {
            if (deg[i] == 1)
                q.add(i);
        }

        while (!q.isEmpty()) {
            int v = q.poll();
            deg[v] = 0; // 标记为已删除
            for (int u : adj[v]) {
                if (deg[u] > 0) {
                    deg[u]--;
                    if (deg[u] == 1)
                        q.add(u);
                }
            }
        }

        // 输出环上所有节点编号（升序）
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= N; i++) {
            if (deg[i] >= 2) {
                sb.append(i).append(' ');
            }
        }
        System.out.println(sb.toString().trim());
    }
}
