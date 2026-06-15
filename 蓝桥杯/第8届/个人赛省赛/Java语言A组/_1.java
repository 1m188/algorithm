/*
标题：迷宫

X星球的一处迷宫游乐场建在某个小山坡上。
它是由10x10相互连通的小房间组成的。

房间的地板上写着一个很大的字母。
我们假设玩家是面朝上坡的方向站立，则：
L表示走到左边的房间，
R表示走到右边的房间，
U表示走到上坡方向的房间，
D表示走到下坡方向的房间。

X星球的居民有点懒，不愿意费力思考。
他们更喜欢玩运气类的游戏。这个游戏也是如此！

开始的时候，直升机把100名玩家放入一个个小房间内。
玩家一定要按照地上的字母移动。

迷宫地图如下：
------------
UDDLUULRUL
UURLLLRRRU
RRUURLDLRD
RUDDDDUUUU
URUDLLRRUU
DURLRLDLRL
ULLURLLRDU
RDLULLRDDD
UUDDUDUDLL
ULRDLUURRR
------------

请你计算一下，最后，有多少玩家会走出迷宫? 
而不是在里边兜圈子。

请提交该整数，表示走出迷宫的玩家数目，不要填写任何多余的内容。

如果你还没明白游戏规则，可以参看一个简化的4x4迷宫的解说图：
p1.png


解题思路：
10x10 网格，从每个格子出发模拟走迷宫。
按字母方向移动，出界则计为走出；如果回到已访问的格子则死循环。
统计能走出的格子数。
*/
public class _1 {
    static char[][] grid = {
        "UDDLUULRUL".toCharArray(),
        "UURLLLRRRU".toCharArray(),
        "RRUURLDLRD".toCharArray(),
        "RUDDDDUUUU".toCharArray(),
        "URUDLLRRUU".toCharArray(),
        "DURLRLDLRL".toCharArray(),
        "ULLURLLRDU".toCharArray(),
        "RDLULLRDDD".toCharArray(),
        "UUDDUDUDLL".toCharArray(),
        "ULRDLUURRR".toCharArray()
    };

    public static void main(String[] args) {
        int cnt = 0;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                if (canEscape(i, j))
                    cnt++;
        System.out.println(cnt);
    }

    static boolean canEscape(int r, int c) {
        boolean[][] vis = new boolean[10][10];
        while (r >= 0 && r < 10 && c >= 0 && c < 10) {
            if (vis[r][c]) return false; // 走回已访问格子，死循环
            vis[r][c] = true;
            char dir = grid[r][c];
            if (dir == 'U') r--;
            else if (dir == 'D') r++;
            else if (dir == 'L') c--;
            else c++; // 'R'
        }
        return true; // 走出边界
    }
}
