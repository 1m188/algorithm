/*
标题：青蛙跳杯子

    X星球的流行宠物是青蛙，一般有两种颜色：白色和黑色。
    X星球的居民喜欢把它们放在一排茶杯里，这样可以观察它们跳来跳去。
    如下图，有一排杯子，左边的一个是空着的，右边的杯子，每个里边有一只青蛙。

*WWWBBB

    其中，W字母表示白色青蛙，B表示黑色青蛙，*表示空杯子。

    X星的青蛙很有些癖好，它们只做3个动作之一：
    1. 跳到相邻的空杯子里。
    2. 隔着1只其它的青蛙（随便什么颜色）跳到空杯子里。
    3. 隔着2只其它的青蛙（随便什么颜色）跳到空杯子里。

    对于上图的局面，只要1步，就可跳成下图局面：

WWW*BBB

本题的任务就是已知初始局面，询问至少需要几步，才能跳成另一个目标局面。

输入为2行，2个串，表示初始局面和目标局面。
输出要求为一个整数，表示至少需要多少步的青蛙跳。

例如：
输入：*WWBB \n WWBB* → 输出：2
输入：WWW*BBB \n BBB*WWW → 输出：10

我们约定，输入的串的长度不超过15

资源约定：峰值内存消耗 < 256M，CPU消耗 < 1000ms
主类的名字必须是：Main


解题思路：
BFS 搜索最短步数。
每个状态：字符串（长度 ≤ 15）。
青蛙可以跳 1/2/3 步到空位（可左可右）。
用 HashMap 记录已访问状态和步数。
*/
import java.util.*;

public class _9 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String start = sc.next();
        String target = sc.next();
        sc.close();

        int n = start.length();
        Queue<String> q = new LinkedList<>();
        Map<String, Integer> dist = new HashMap<>();
        q.add(start);
        dist.put(start, 0);

        while (!q.isEmpty()) {
            String cur = q.poll();
            int d = dist.get(cur);
            if (cur.equals(target)) {
                System.out.println(d);
                return;
            }
            int starPos = cur.indexOf('*');
            // 尝试所有可能的跳跃
            for (int frogPos = 0; frogPos < n; frogPos++) {
                if (frogPos == starPos) continue;
                char c = cur.charAt(frogPos);
                if (c == '*') continue;
                int dists = Math.abs(frogPos - starPos);
                if (dists >= 1 && dists <= 3) {
                    // 青蛙从 frogPos 跳到 starPos
                    char[] arr = cur.toCharArray();
                    arr[starPos] = c;
                    arr[frogPos] = '*';
                    String next = new String(arr);
                    if (!dist.containsKey(next)) {
                        dist.put(next, d + 1);
                        q.add(next);
                    }
                }
            }
        }
        System.out.println(-1);
    }
}
