/*

 标题：穿越雷区

 X星的坦克战车很奇怪，它必须交替地穿越正能量辐射区和负能量辐射区才能保持正常运转，否则将报废。
 某坦克需要从A区到B区去（A，B区本身是安全区，没有正能量或负能量特征），怎样走才能路径最短？

 已知的地图是一个方阵，上面用字母标出了A，B区，其它区都标了正号或负号分别表示正负能量辐射区。
 例如：
 A + - + -
 - + - - +
 - + + + -
 + - + - +
 B + - + -

 坦克车只能水平或垂直方向上移动到相邻的区。

 数据格式要求：

 输入第一行是一个整数n，表示方阵的大小， 4<=n<100
 接下来是n行，每行有n个数据，可能是A，B，+，-中的某一个，中间用空格分开。
 A，B都只出现一次。

 要求输出一个整数，表示坦克从A区到B区的最少移动步数。
 如果没有方案，则输出-1

 例如：
 用户输入：
 5
 A + - + -
 - + - - +
 - + + + -
 + - + - +
 B + - + -

 则程序应该输出：
 10

 资源约定：
 峰值内存消耗 < 512M
 CPU消耗  < 1000ms


 请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

 所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

 注意: main函数需要返回0
 注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
 注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

 提交时，注意选择所期望的编译器类型。



 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_N 100

typedef struct {
    int r, c;
    int type; /* 0 = '+', 1 = '-' */
    int dist;
} State;

char grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N][2];
State queue[MAX_N * MAX_N * 2];
int head, tail;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(int n, int sr, int sc, int tr, int tc) {
    head = 0;
    tail = 0;
    memset(visited, 0, sizeof(visited));

    /* 从 A 出发，向四个方向探索第一步 */
    for (int d = 0; d < 4; d++) {
        int nr = sr + dir[d][0];
        int nc = sc + dir[d][1];
        if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
        if (nr == tr && nc == tc) {
            return 1; /* A 与 B 相邻，一步即可到达 */
        }
        char ch = grid[nr][nc];
        if (ch == '+' || ch == '-') {
            int tp = (ch == '+') ? 0 : 1;
            if (!visited[nr][nc][tp]) {
                visited[nr][nc][tp] = true;
                queue[tail].r = nr;
                queue[tail].c = nc;
                queue[tail].type = tp;
                queue[tail].dist = 1;
                tail++;
            }
        }
    }

    while (head < tail) {
        State cur = queue[head++];
        int next_type = 1 - cur.type; /* 下一步需要的类型：+ → - 或 - → + */
        char next_ch = (next_type == 0) ? '+' : '-';

        for (int d = 0; d < 4; d++) {
            int nr = cur.r + dir[d][0];
            int nc = cur.c + dir[d][1];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if (nr == tr && nc == tc) {
                return cur.dist + 1;
            }
            char ch = grid[nr][nc];
            if (ch == next_ch && !visited[nr][nc][next_type]) {
                visited[nr][nc][next_type] = true;
                queue[tail].r = nr;
                queue[tail].c = nc;
                queue[tail].type = next_type;
                queue[tail].dist = cur.dist + 1;
                tail++;
            }
        }
    }

    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    char buf[4];
    int sr = -1, sc = -1, tr = -1, tc = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%s", buf);
            grid[i][j] = buf[0];
            if (buf[0] == 'A') {
                sr = i;
                sc = j;
            } else if (buf[0] == 'B') {
                tr = i;
                tc = j;
            }
        }
    }

    int ans = bfs(n, sr, sc, tr, tc);
    printf("%d\n", ans);

    return 0;
}
