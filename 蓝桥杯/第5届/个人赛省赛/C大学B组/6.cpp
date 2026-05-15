/*

你一定听说过“数独”游戏。
如【图1.png】，玩家需要根据9×9盘面上的已知数字，推理出所有剩余空格的数字，并满足每一行、每一列、每一个同色九宫内的数字均含1-9，不重复。

数独的答案都是唯一的，所以，多个解也称为无解。

本图的数字据说是芬兰数学家花了3个月的时间设计出来的较难的题目。但对会使用计算机编程的你来说，恐怕易如反掌了。

本题的要求就是输入数独题目，程序输出数独的唯一解。我们保证所有已知数据的格式都是合法的，并且题目有唯一的解。

格式要求，输入9行，每行9个数字，0代表未知，其它数字为已知。
输出9行，每行9个数字表示数独的解。

例如：
输入（即图中题目）：
005300000
800000020
070010500
400005300
010070006
003200080
060500009
004000030
000009700

程序应该输出：
145327698
839654127
672918543
496185372
218473956
753296481
367542819
984761235
521839764

再例如，输入：
800000000
003600000
070090200
050007000
000045700
000100030
001000068
008500010
090000400

程序应该输出：
812753649
943682175
675491283
154237896
369845721
287169534
521974368
438526917
796318452

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 2000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。


*/

#include <cstdio>
#include <cstring>

/*
 * 数独求解 - DFS 回溯 + 位掩码加速
 *
 * 核心思路：
 *   对每一个空格（值为 0），尝试填入 1-9。
 *   使用三个 int 位掩码数组 row[9], col[9], box[9]，
 *   第 k 位为 1 表示数字 k+1 已经被占用。
 *   优先选择候选数最少的空格进行填充（MRV 启发式）以加速回溯。
 */
int board[9][9];            // 数独棋盘，0 表示空格
int row[9], col[9], box[9]; // 行/列/宫 的位掩码
bool solved;

// 获取 (r,c) 所属 3x3 宫的编号
inline int boxId(int r, int c) { return (r / 3) * 3 + c / 3; }

// 尝试在 (r,c) 填入值 v（1-9），更新掩码
inline void place(int r, int c, int v) {
    int mask = 1 << (v - 1);
    row[r] |= mask;
    col[c] |= mask;
    box[boxId(r, c)] |= mask;
}

// 撤销在 (r,c) 填入的值 v
inline void remove(int r, int c, int v) {
    int mask = ~(1 << (v - 1));
    row[r] &= mask;
    col[c] &= mask;
    box[boxId(r, c)] &= mask;
}

// 获取 (r,c) 位置的候选数字位掩码（位为 1 表示该数字可用）
inline int candidates(int r, int c) {
    return ~(row[r] | col[c] | box[boxId(r, c)]) & 0x1FF;
}

void dfs(int remain) {
    if (remain == 0) {
        solved = true;
        return;
    }

    // 选择候选数最少的空格（MRV 启发式）
    int best_r = -1, best_c = -1, best_cnt = 10;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != 0) continue;
            int cand = candidates(i, j);
            int cnt = __builtin_popcount(cand);
            if (cnt < best_cnt) {
                best_cnt = cnt;
                best_r = i;
                best_c = j;
                if (cnt == 0) return;     // 无候选，立即回溯
                if (cnt == 1) goto found; // 唯一候选，直接选它
            }
        }
    }
found:
    if (best_r == -1) return;

    int cand = candidates(best_r, best_c);
    for (int v = 1; v <= 9; ++v) {
        if (cand & (1 << (v - 1))) {
            board[best_r][best_c] = v;
            place(best_r, best_c, v);
            dfs(remain - 1);
            if (solved) return;
            remove(best_r, best_c, v);
            board[best_r][best_c] = 0;
        }
    }
}

int main() {
    char line[10];
    int remain = 0;

    // 读入棋盘
    for (int i = 0; i < 9; ++i) {
        scanf("%9s", line);
        for (int j = 0; j < 9; ++j) {
            board[i][j] = line[j] - '0';
            if (board[i][j] != 0) {
                place(i, j, board[i][j]);
            } else {
                ++remain;
            }
        }
    }

    solved = false;
    dfs(remain);

    // 输出解
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%d", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}
