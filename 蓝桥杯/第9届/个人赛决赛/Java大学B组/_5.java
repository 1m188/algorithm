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

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] first = br.readLine().split(" ");
        int N = Integer.parseInt(first[0]);
        int Q = Integer.parseInt(first[1]);

        // 邻接表建树
        ArrayList<Integer>[] graph = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < N - 1; i++) {
            String[] edge = br.readLine().split(" ");
            int u = Integer.parseInt(edge[0]);
            int v = Integer.parseInt(edge[1]);
            graph[u].add(v);
            graph[v].add(u);
        }

        // 欧拉序（Euler Tour）：tin[x] 表示进入节点 x 的时间戳，
        // tout[x] 表示离开节点 x 时已用掉的最大时间戳。
        // x 是 y 的祖先 ⟺ tin[x] <= tin[y] && tout[y] <= tout[x]
        int[] tin = new int[N + 1];
        int[] tout = new int[N + 1];
        int timer = 0;

        // 迭代 DFS（避免 N=100000 时递归栈溢出）
        int[] stack = new int[N + 1];
        int[] parent = new int[N + 1];
        int[] childIdx = new int[N + 1]; // 每个节点当前处理到第几个孩子
        int top = 0;

        // 从根节点 1 开始
        parent[1] = 0;
        childIdx[1] = 0;
        timer++;
        tin[1] = timer;
        stack[top] = 1;
        top++;

        while (top > 0) {
            int u = stack[top - 1];
            ArrayList<Integer> children = graph[u];

            // 找下一个未访问的孩子
            boolean hasChild = false;
            while (childIdx[u] < children.size()) {
                int v = children.get(childIdx[u]);
                childIdx[u]++;
                if (v != parent[u]) {
                    parent[v] = u;
                    childIdx[v] = 0;
                    timer++;
                    tin[v] = timer;
                    stack[top] = v;
                    top++;
                    hasChild = true;
                    break;
                }
            }

            if (!hasChild) {
                // 所有孩子处理完毕，弹出栈并记录 tout
                tout[u] = timer;
                top--;
            }
        }

        // 处理 Q 个查询
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < Q; i++) {
            String[] query = br.readLine().split(" ");
            int x = Integer.parseInt(query[0]);
            int y = Integer.parseInt(query[1]);

            if (tin[x] <= tin[y] && tout[y] <= tout[x]) {
                sb.append("YES\n");
            } else {
                sb.append("NO\n");
            }
        }
        System.out.print(sb);
    }
}
