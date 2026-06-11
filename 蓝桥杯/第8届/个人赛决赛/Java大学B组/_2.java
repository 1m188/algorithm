/*

标题：生命游戏

康威生命游戏是英国数学家约翰·何顿·康威在1970年发明的细胞自动机。  
这个游戏在一个无限大的2D网格上进行。

初始时，每个小方格中居住着一个活着或死了的细胞。
下一时刻每个细胞的状态都由它周围八个格子的细胞状态决定。

具体来说：

1. 当前细胞为存活状态时，当周围低于2个（不包含2个）存活细胞时， 该细胞变成死亡状态。（模拟生命数量稀少）
2. 当前细胞为存活状态时，当周围有2个或3个存活细胞时， 该细胞保持原样。
3. 当前细胞为存活状态时，当周围有3个以上的存活细胞时，该细胞变成死亡状态。（模拟生命数量过多）
4. 当前细胞为死亡状态时，当周围有3个存活细胞时，该细胞变成存活状态。 （模拟繁殖）

当前代所有细胞同时被以上规则处理后, 可以得到下一代细胞图。按规则继续处理这一代的细胞图，可以得到再下一代的细胞图，周而复始。

例如假设初始是:(X代表活细胞，.代表死细胞)
.....
.....
.XXX.
.....

下一代会变为:
.....
..X..
..X..
..X..
.....

康威生命游戏中会出现一些有趣的模式。例如稳定不变的模式：

....
.XX.
.XX.
....

还有会循环的模式：

......      ......       ......
.XX...      .XX...       .XX...
.XX...      .X....       .XX...
...XX.   -> ....X.  ->   ...XX.
...XX.      ...XX.       ...XX.
......      ......       ......


本题中我们要讨论的是一个非常特殊的模式，被称作"Gosper glider gun"：

......................................
.........................X............
.......................X.X............
.............XX......XX............XX.
............X...X....XX............XX.
.XX........X.....X...XX...............
.XX........X...X.XX....X.X............
...........X.....X.......X............
............X...X.....................
.............XX.......................
......................................

假设以上初始状态是第0代，请问第1000000000(十亿)代一共有多少活着的细胞？

注意：我们假定细胞机在无限的2D网格上推演，并非只有题目中画出的那点空间。
当然，对于遥远的位置，其初始状态一概为死细胞。

注意：需要提交的是一个整数，不要填写多余内容。


*/

import java.util.*;

public class _2 {
    // 目标代数
    static final long TARGET = 1000000000L;

    public static void main(String[] args) {
        // 第0代初始配置（Gosper glider gun）
        String[] init = {
                "......................................",
                ".........................X............",
                ".......................X.X............",
                ".............XX......XX............XX.",
                "............X...X....XX............XX.",
                ".XX........X.....X...XX...............",
                ".XX........X...X.XX....X.X............",
                "...........X.....X.......X............",
                "............X...X.....................",
                ".............XX.......................",
                "......................................",
        };

        // 用 Set 存储活细胞坐标
        Set<Long> live = new HashSet<Long>();
        for (int r = 0; r < init.length; r++) {
            for (int c = 0; c < init[r].length(); c++) {
                if (init[r].charAt(c) == 'X') {
                    live.add(pack(r, c));
                }
            }
        }

        // 基准数组：前 30 代每代活细胞数（在第 1 个 glider 分离前）
        int[] base = new int[30];
        base[0] = live.size();

        // 模拟前 30 代，记录基准值
        for (int gen = 1; gen < 30; gen++) {
            live = nextGeneration(live);
            base[gen] = live.size();
        }

        // 利用周期性公式计算第 10^9 代的活细胞数
        // 每 30 代产生一个 glider（5 个活细胞），枪体自身周期 = 30
        int phase = (int) (TARGET % 30);
        long gliders = TARGET / 30;
        long answer = base[phase] + 5 * gliders;

        System.out.println(answer);
    }

    /** 将坐标 (r, c) 打包为单个 long */
    static long pack(int r, int c) {
        return ((long) r << 32) | (c & 0xFFFFFFFFL);
    }

    /** 计算下一代活细胞集合 */
    static Set<Long> nextGeneration(Set<Long> live) {
        // 收集所有候选细胞（活细胞及其八邻域）
        Map<Long, Integer> neighborCount = new HashMap<Long, Integer>();
        for (long cell : live) {
            int r = (int) (cell >> 32);
            int c = (int) cell;
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    long key = pack(r + dr, c + dc);
                    Integer cnt = neighborCount.get(key);
                    neighborCount.put(key, (cnt == null ? 0 : cnt) + 1);
                }
            }
        }

        Set<Long> next = new HashSet<Long>();
        for (Map.Entry<Long, Integer> e : neighborCount.entrySet()) {
            long cell = e.getKey();
            int nbrs = e.getValue();
            boolean wasAlive = live.contains(cell);
            // 自身也算在邻居计数中（dr=0,dc=0），需要排除
            if (wasAlive)
                nbrs--;

            if (wasAlive && (nbrs == 2 || nbrs == 3))
                next.add(cell);
            else if (!wasAlive && nbrs == 3)
                next.add(cell);
        }
        return next;
    }
}
