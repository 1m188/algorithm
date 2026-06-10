/*

标题：填字母游戏

小明经常玩 LOL 游戏上瘾，一次他想挑战K大师，不料K大师说：
"我们先来玩个空格填字母的游戏，要是你不能赢我，就再别玩LOL了"。

K大师在纸上画了一行n个格子，要小明和他交替往其中填入字母。

并且：

1. 轮到某人填的时候，只能在某个空格中填入L或O
2. 谁先让字母组成了"LOL"的字样，谁获胜。
3. 如果所有格子都填满了，仍无法组成LOL，则平局。

小明试验了几次都输了，他很惭愧，希望你能用计算机帮他解开这个谜。

本题的输入格式为：
第一行，数字n（n<10），表示下面有n个初始局面。
接下来，n行，每行一个串(长度<20)，表示开始的局面。
  比如："******", 表示有6个空格。
  "L****",   表示左边是一个字母L，它的右边是4个空格。

要求输出n个数字，表示对每个局面，如果小明先填，当K大师总是用最强着法的时候，小明的最好结果。
1 表示能赢
-1 表示必输
0 表示可以逼平


例如，
输入：
4
***
L**L
L**L***L
L*****L

则程序应该输出：
0
-1
1
1

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms

请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。

*/

#include <stdio.h>
#include <string.h>

#include <unordered_map>
using namespace std;

// 类型别名：使用 64 位无符号整数编码整个棋盘状态
// 每格占用 2 位（00 = '*' 空格, 01 = 'L', 10 = 'O', 11 = 保留未用）
// 最大长度 19，共需 38 位，可安全放入 uint64_t
typedef unsigned long long State;

/**
 * @brief 将字符串形式的棋盘状态编码为 64 位整数
 *
 * 编码规则：从低位到高位每 2 位表示一个格子
 *   - 00 表示空格 '*'
 *   - 01 表示字母 'L'
 *   - 10 表示字母 'O'
 *
 * @param s 棋盘状态字符串（由 'L', 'O', '*' 组成）
 * @param n 字符串长度（格子数）
 * @return 编码后的 State 值
 */
State encode(const char *s, int n) {
    State code = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            code |= (1ULL << (2 * i)); // 01
        } else if (s[i] == 'O') {
            code |= (2ULL << (2 * i)); // 10
        }
        // '*' 保持 00，无需操作
    }
    return code;
}

/**
 * @brief 快速检测当前棋盘是否包含子串 "LOL"
 *
 * 使用位运算逐窗口检查：对于连续的三个位置 i, i+1, i+2，
 * "LOL" 的编码为 01, 10, 01 即二进制序列：
 *   位置i → 01, 位置i+1 → 10, 位置i+2 → 01
 *
 * @param code 编码后的棋盘状态
 * @param n    棋盘长度
 * @return 若存在 "LOL" 子串返回 true，否则返回 false
 */
inline bool hasLOL(State code, int n) {
    for (int i = 0; i <= n - 3; i++) {
        // 提取三个连续格子的值（每格 2 位掩码为 3）
        int a = (int)((code >> (2 * i)) & 3);
        int b = (int)((code >> (2 * (i + 1))) & 3);
        int c = (int)((code >> (2 * (i + 2))) & 3);
        // L=1, O=2, L=1 → 完整匹配 "LOL"
        if (a == 1 && b == 2 && c == 1) {
            return true;
        }
    }
    return false;
}

/**
 * @brief 检查棋盘是否已无空格（所有位置均被填满）
 *
 * 遍历每个格子的 2 位编码，若发现 00（空格）则说明还有空位。
 *
 * @param code 编码后的棋盘状态
 * @param n    棋盘长度
 * @return 无空格返回 true，否则返回 false
 */
inline bool isFull(State code, int n) {
    for (int i = 0; i < n; i++) {
        if (((code >> (2 * i)) & 3) == 0) {
            return false;
        }
    }
    return true;
}

/**
 * @brief 极小化极大（Minimax）搜索：计算当前局面对先手的结果
 *
 * 这是解决双人零和博弈的核心递归函数，采用深度优先搜索 + 记忆化。
 *
 * 算法逻辑：
 *   1. 若已缓存当前状态的结果，直接返回（记忆化）
 *   2. 若棋盘已满且无 "LOL"，返回 0（平局）
 *   3. 遍历所有空格位置，尝试填入 'L' 和 'O'：
 *      a. 若填入后立即构成 "LOL" → 当前玩家获胜（返回 1）
 *      b. 否则递归求解对手局面下的结果 r，对当前玩家而言结果为 -r
 *         （零和博弈：对手赢 = 我输，对手平 = 我平，对手输 = 我赢）
 *      c. 取所有可行着法中的最大值作为最佳结果
 *   4. 若找到必胜着法（best == 1），立即返回以触发剪枝
 *
 * @param code 当前棋盘状态的编码
 * @param n    棋盘长度
 * @param memo 记忆化缓存：映射"状态编码 → 先手最佳结果"
 * @return 1（必胜）、0（平局）、-1（必败）
 */
int dfs(State code, int n, unordered_map<State, int> &memo) {
    // 记忆化：若已计算过，直接返回缓存结果
    auto it = memo.find(code);
    if (it != memo.end()) {
        return it->second;
    }

    // 终止条件：棋盘已满且未出现 "LOL"（否则在上一步就已检测到）
    if (isFull(code, n)) {
        return memo[code] = 0;
    }

    int best = -1; // 初始化为最差结果（必输）

    // 遍历所有格子
    for (int i = 0; i < n; i++) {
        // 提取当前格子的状态
        int cell = (int)((code >> (2 * i)) & 3);
        if (cell != 0) {
            continue; // 非空格，跳过
        }

        // --- 尝试填入 'L' (编码为 1) ---
        State nextL = code | (1ULL << (2 * i));
        if (hasLOL(nextL, n)) {
            best = 1; // 立即获胜
        } else {
            int opponent = dfs(nextL, n, memo);
            if (-opponent > best) {
                best = -opponent;
            }
        }
        if (best == 1) {
            // 已找到必胜着法，提前返回（Alpha 剪枝）
            return memo[code] = 1;
        }

        // --- 尝试填入 'O' (编码为 2) ---
        State nextO = code | (2ULL << (2 * i));
        if (hasLOL(nextO, n)) {
            best = 1;
        } else {
            int opponent = dfs(nextO, n, memo);
            if (-opponent > best) {
                best = -opponent;
            }
        }
        if (best == 1) {
            return memo[code] = 1;
        }
    }

    // 缓存并返回最佳结果
    return memo[code] = best;
}

/**
 * @brief 主函数：读取输入并对每个局面输出博弈分析结果
 *
 * 输入格式：
 *   第一行：整数 n（局面个数，n < 10）
 *   接下来 n 行：每行一个长度 < 20 的字符串（由 'L', 'O', '*' 组成）
 *
 * 输出格式：
 *   每行一个整数：1（先手胜）、0（平局）、-1（先手败）
 *
 * @return 0 正常退出
 */
int main() {
    int caseCount;
    scanf("%d", &caseCount);

    while (caseCount--) {
        char buf[32];
        scanf("%s", buf);
        int len = (int)strlen(buf);

        State code = encode(buf, len);

        // 每个测试局面的记忆化缓存独立分配以控制内存上限
        // 预分配桶数：经验上混合局面（含字母）访问状态极少（< 10^4），
        // 全空格局面最多访问约 10^7 状态，预留 2^20 = 1M 桶以平衡内存与性能
        unordered_map<State, int> memo;
        memo.reserve(1 << 20);

        int result = dfs(code, len, memo);
        printf("%d\n", result);
    }

    return 0;
}
