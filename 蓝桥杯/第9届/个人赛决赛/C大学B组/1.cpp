/*
 * 标题：换零钞
 *
 * 设 1 元张数为 x，则 2 元张数为 10x，5 元张数为 y。
 * 总金额：x + 2×10x + 5y = 200  →  21x + 5y = 200
 * 总张数：N = x + 10x + y = 11x + y
 *
 * 由 21x + 5y = 200 得 y = (200 - 21x) / 5 = 40 - 21x/5
 * y 必须为整数 → x 是 5 的倍数。
 * 又 y ≥ 1 → 21x/5 ≤ 39 → x ≤ 9.28 → x = 5（x = 0 不符合"必须都有"）。
 *
 * x = 5 时，y = 40 - 21 = 19，N = 11×5 + 19 = 74。
 *
 * 答案：74
 */

#include <cstdio>

int main() {
    // 直接枚举验证
    int min_bills = 1000000;
    for (int x = 1; x * 21 <= 200 - 5; x++) { // 1 元 x 张
        if (x % 5 != 0) continue;             // y 必须为整数
        int y = (200 - 21 * x) / 5;           // 5 元 y 张
        if (y >= 1) {
            int total = 11 * x + y; // 总张数
            if (total < min_bills) min_bills = total;
        }
    }
    printf("%d\n", min_bills);
    return 0;
}
