// clang-format off
/*

标题：五星填数

如【图1.png】的五星图案节点填上数字：1~12，除去7和11。
要求每条直线上数字和相等。

如图就是恰当的填法。

           6
8      5       2       9
      3         4
           1
    10            12

请你利用计算机搜索所有可能的填法有多少种。
注意：旋转或镜像后相同的算同一种填法。

请提交表示方案数目的整数，不要填写任何其它内容。

*/
// clang-format on

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// 可选数字：1~12 除去 7 和 11
int nums[10] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 12};

// DFS 中当前位置的填值
int pos[10];
bool used[10];

// clang-format off
/*
五角星的 10 个节点编号（与示例图对应）：
|
           0
   1       2       3       4
        5         6
           7
     8           9
|
5 条直线：
L0: {0, 2, 5, 8}
L1: {0, 3, 6, 9}
L2: {1, 2, 3, 4}
L3: {1, 5, 7, 9}
L4: {4, 6, 7, 8}
|
所有数字之和 = 60，每个节点恰好在 2 条线上，
故 5 条线之和 = 2 × 60 = 120，每条线目标和 = 24。
*/
// clang-format on
int lines[5][4] = {
    {0, 2, 5, 8},
    {0, 3, 6, 9},
    {1, 2, 3, 4},
    {1, 5, 7, 9},
    {4, 6, 7, 8}};

// 计算一条直线上 4 个数字的和
int line_sum(int *l) {
    return pos[l[0]] + pos[l[1]] + pos[l[2]] + pos[l[3]];
}

// clang-format off
/*
D5 对称群（10 个元素）：
生成元: r = 顺时针旋转 72°, s = 关于过顶点 0 的竖直轴反射
|
圆周顺序（顺时针从顶点 0 开始，每步跨过一个外顶点和一个内顶点）：
0(外) → 3(内) → 4(外) → 6(内) → 9(外) → 7(内) → 8(外) → 5(内) → 1(外) → 2(内) → 0
|
旋转 r 将圆周向前推进 2 个位置。
反射 s 关于过顶点 0 的轴进行角度对称。
*/
// clang-format on
int sym[10][10];

// 存储规范解
int canon_storage[10000][10];
int canonical_count = 0;

// 复合置换: c = a ∘ b, 即 c[i] = a[b[i]]
void compose(int *a, int *b, int *result) {
    for (int i = 0; i < 10; i++)
        result[i] = a[b[i]];
}

// 字典序比较两个排列，a < b 返回 -1，相等返回 0，a > b 返回 1
int cmp_arr(int *a, int *b) {
    for (int i = 0; i < 10; i++) {
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return 1;
    }
    return 0;
}

// 对排列 arr 施加变换 t，结果存入 result
// result[t[i]] = arr[i]
void apply_sym(int *arr, int *t, int *result) {
    for (int i = 0; i < 10; i++)
        result[t[i]] = arr[i];
}

// 计算规范形：取全体 10 个对称变换中字典序最小者
void canonical(int *arr, int *best) {
    int temp[10];
    memcpy(best, arr, 10 * sizeof(int));
    for (int k = 1; k < 10; k++) {
        apply_sym(arr, sym[k], temp);
        if (cmp_arr(temp, best) < 0)
            memcpy(best, temp, 10 * sizeof(int));
    }
}

// 检查规范形是否已存在于统计列表中
bool is_duplicate(int *cand) {
    for (int i = 0; i < canonical_count; i++) {
        bool same = true;
        for (int j = 0; j < 10; j++) {
            if (cand[j] != canon_storage[i][j]) {
                same = false;
                break;
            }
        }
        if (same) return true;
    }
    return false;
}

void dfs(int idx) {
    if (idx == 10) {
        // 检查全部 5 条线是否和为 24
        for (int i = 0; i < 5; i++)
            if (line_sum(lines[i]) != 24)
                return;

        int can[10];
        canonical(pos, can);
        if (!is_duplicate(can)) {
            memcpy(canon_storage[canonical_count], can, 10 * sizeof(int));
            canonical_count++;
        }
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (used[i]) continue;
        used[i] = true;
        pos[idx] = nums[i];

        bool ok = true;
        // 填充完位置 4 后，L2 = {1,2,3,4} 可检查
        if (idx == 4) {
            if (line_sum(lines[2]) != 24) ok = false;
        }
        // 填充完位置 8 后，L0 = {0,2,5,8} 和 L4 = {4,6,7,8} 可检查
        if (ok && idx == 8) {
            if (line_sum(lines[0]) != 24 || line_sum(lines[4]) != 24) ok = false;
        }

        if (ok) dfs(idx + 1);
        used[i] = false;
    }
}

int main() {
    // 生成元 r: 顺时针旋转 72°（圆周上前进 2 位）
    int r[10] = {4, 0, 3, 6, 9, 2, 7, 5, 1, 8};
    // 生成元 s: 关于过顶点 0 的竖直轴进行角度反射
    int s_arr[10] = {0, 4, 3, 2, 1, 6, 5, 7, 9, 8};

    // 恒等变换
    for (int i = 0; i < 10; i++)
        sym[0][i] = i;

    // 旋转: r, r², r³, r⁴
    memcpy(sym[1], r, 10 * sizeof(int));
    compose(r, r, sym[2]);
    compose(sym[2], r, sym[3]);
    compose(sym[3], r, sym[4]);

    // 反射: s, sr, sr², sr³, sr⁴
    memcpy(sym[5], s_arr, 10 * sizeof(int));
    compose(s_arr, r, sym[6]);
    compose(s_arr, sym[2], sym[7]);
    compose(s_arr, sym[3], sym[8]);
    compose(s_arr, sym[4], sym[9]);

    memset(used, 0, sizeof(used));
    canonical_count = 0;

    dfs(0);

    // 输出方案数目
    printf("%d\n", canonical_count);
    return 0;
}
