/*

标题：版本分支

小明负责维护公司一个奇怪的项目。这个项目的代码一直在不断分支(branch)但是从未发生过合并(merge)。
现在这个项目的代码一共有N个版本，编号1~N，其中1号版本是最初的版本。
除了1号版本之外，其他版本的代码都恰好有一个直接的父版本；即这N个版本形成了一棵以1为根的树形结构。  

如下图就是一个可能的版本树：

    1
   / \
  2   3
  |  / \
  5 4   6

现在小明需要经常检查版本x是不是版本y的祖先版本。你能帮助小明吗？

输入
----
第一行包含两个整数N和Q，代表版本总数和查询总数。  
以下N-1行，每行包含2个整数u和v，代表版本u是版本v的直接父版本。  
再之后Q行，每行包含2个整数x和y，代表询问版本x是不是版本y的祖先版本。  

对于30%的数据，1 <= N <= 1000  1 <= Q <= 1000  
对于100%的数据，1 <= N <= 100000  1 <= Q <= 100000  

输出
----
对于每个询问，输出YES或NO代表x是否是y的祖先。  

【样例输入】
6 5
1 2
1 3
2 5
3 6
3 4
1 1
1 4
2 6
5 2
6 4

【样例输出】
YES
YES
NO
NO
NO

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
不要使用package语句。不要使用jdk1.7及以上版本的特性。
主类的名字必须是：Main，否则按无效代码处理。


*/

import java.io.*;
import java.util.*;

public class _4 {
    // 迭代 DFS 生成 tin/tout 时间戳，避免递归爆栈
    static int[] tin, tout;
    static int timer;
    static List<Integer>[] adj;

    static void dfs(int root) {
        int n = adj.length - 1;
        tin = new int[n + 1];
        tout = new int[n + 1];
        // 用栈模拟 DFS：(node, parent, state)
        // state=0 表示进入节点，state=1 表示离开节点
        int[][] stack = new int[2 * n + 5][3];
        int top = 0;
        stack[top][0] = root;
        stack[top][1] = 0;
        stack[top][2] = 0;
        top++;
        boolean[] visited = new boolean[n + 1];

        while (top > 0) {
            top--;
            int u = stack[top][0];
            int p = stack[top][1];
            int state = stack[top][2];

            if (state == 0) {
                // 进入节点
                if (visited[u])
                    continue;
                visited[u] = true;
                tin[u] = ++timer;

                // 先压入离开标记
                stack[top][0] = u;
                stack[top][1] = p;
                stack[top][2] = 1;
                top++;

                // 再压入子节点
                for (int v : adj[u]) {
                    if (v == p)
                        continue;
                    stack[top][0] = v;
                    stack[top][1] = u;
                    stack[top][2] = 0;
                    top++;
                }
            } else {
                // 离开节点
                tout[u] = ++timer;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int q = Integer.parseInt(line[1]);

        adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++)
            adj[i] = new ArrayList<>();

        for (int i = 0; i < n - 1; i++) {
            line = br.readLine().split(" ");
            int u = Integer.parseInt(line[0]);
            int v = Integer.parseInt(line[1]);
            adj[u].add(v);
            adj[v].add(u);
        }

        timer = 0;
        dfs(1);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < q; i++) {
            line = br.readLine().split(" ");
            int x = Integer.parseInt(line[0]);
            int y = Integer.parseInt(line[1]);
            // x 是 y 的祖先当且仅当 tin[x] <= tin[y] && tout[x] >= tout[y]
            if (tin[x] <= tin[y] && tout[x] >= tout[y]) {
                sb.append("YES\n");
            } else {
                sb.append("NO\n");
            }
        }
        System.out.print(sb);
    }
}
