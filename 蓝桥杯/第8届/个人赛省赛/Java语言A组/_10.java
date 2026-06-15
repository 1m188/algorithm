/*
标题：油漆面积

X星球的一批考古机器人正在一片废墟上考古。
该区域的地面坚硬如石、平整如镜。
管理人员为方便，建立了标准的直角坐标系。

每个机器人都各有特长、身怀绝技。它们感兴趣的内容也不相同。
经过各种测量，每个机器人都会报告一个或多个矩形区域，作为优先考古的区域。

矩形的表示格式为(x1,y1,x2,y2)，代表矩形的两个对角点坐标。

为了醒目，总部要求对所有机器人选中的矩形区域涂黄色油漆。
小明并不需要当油漆工，只是他需要计算一下，一共要耗费多少油漆。

其实这也不难，只要算出所有矩形覆盖的区域一共有多大面积就可以了。
注意，各个矩形间可能重叠。

本题的输入为若干矩形，要求输出其覆盖的总面积。

输入格式：
第一行，一个整数n，表示有多少个矩形(1<=n<10000)
接下来的n行，每行有4个整数x1 y1 x2 y2，空格分开，表示矩形的两个对角顶点坐标。
(0<= x1,y1,x2,y2 <=10000)

输出格式：
一行一个整数，表示矩形覆盖的总面积。

例如，
输入：
3
1 5 10 10
3 1 20 20
2 7 15 17

程序应该输出：
340

再例如，
输入：
3
5 2 10 6
2 7 12 10
8 1 15 15

程序应该输出：
128

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 2000ms


解题思路：
由于坐标范围 ≤ 10000 且矩形数 < 10000，采用扫描线 + 覆盖计数。
- 收集所有唯一的 y 坐标（压缩用，但此处因为范围小我们直接用原始坐标）
- 用 int[] yCnt 记录每个 y 单位区间被覆盖的次数
- 将所有矩形事件按 x 排序（左边界 +1，右边界 -1）
- 从左到右扫描 x，维护 activeY（当前被覆盖的 y 单位总数）
- 累加面积：(nextX - curX) × activeY

每添加/删除区间时更新 yCnt 并增量式维护 activeY。
*/
import java.util.*;

public class _10 {
    static final int MAX = 10001;

    static class Event implements Comparable<Event> {
        int x, type, y1, y2; // type=1 进入, -1 离开

        Event(int x, int t, int y1, int y2) {
            this.x = x;
            this.type = t;
            this.y1 = y1;
            this.y2 = y2;
        }

        public int compareTo(Event o) { return x - o.x; }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Event[] events = new Event[2 * n];
        int idx = 0;
        for (int i = 0; i < n; i++) {
            int x1 = sc.nextInt(), y1 = sc.nextInt();
            int x2 = sc.nextInt(), y2 = sc.nextInt();
            if (x1 > x2) { int t = x1; x1 = x2; x2 = t; }
            if (y1 > y2) { int t = y1; y1 = y2; y2 = t; }
            events[idx++] = new Event(x1, 1, y1, y2);
            events[idx++] = new Event(x2, -1, y1, y2);
        }
        sc.close();
        Arrays.sort(events);

        int[] yCnt = new int[MAX + 2];
        int activeY = 0;
        int curX = events[0].x;
        long totalArea = 0;
        int ei = 0;

        while (ei < events.length) {
            int nextX = events[ei].x;
            totalArea += (long) activeY * (nextX - curX);
            curX = nextX;

            // 处理当前 x 的所有事件
            while (ei < events.length && events[ei].x == curX) {
                Event e = events[ei++];
                for (int y = e.y1; y < e.y2; y++) {
                    if (e.type == 1) {
                        if (yCnt[y] == 0)
                            activeY++;
                        yCnt[y]++;
                    } else {
                        yCnt[y]--;
                        if (yCnt[y] == 0)
                            activeY--;
                    }
                }
            }
        }
        System.out.println(totalArea);
    }
}
