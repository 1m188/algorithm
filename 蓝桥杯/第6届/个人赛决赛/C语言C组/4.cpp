/*

标题：机器人繁殖

X星系的机器人可以自动复制自己。它们用1年的时间可以复制出2个自己，然后就失去复制能力。
每年X星系都会选出1个新出生的机器人发往太空。也就是说，如果X星系原有机器人5个，
1年后总数是：5 + 9 = 14
2年后总数是：5 + 9 + 17 = 31

如果已经探测经过n年后的机器人总数s，你能算出最初有多少机器人吗？

数据格式：

输入一行两个数字n和s，用空格分开，含义如上。n不大于100，s位数不超过50位。

要求输出一行，一个整数，表示最初有机器人多少个。

例如：
用户输入：
2 31

则程序应该输出：
5

再例如：
用户输入：
97 2218388550399401452619230609499

则程序应该输出：
8

资源约定：
峰值内存消耗 < 512M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。

---

推导：
设第 k 年初可复制机器人数为 a_k，初始 a_0 = x
每年：a_k 个机器人各复制 2 个 → 新增 2*a_k 个，送走 1 个 → 净增 2*a_k - 1
a_{k+1} = 2*a_k - 1  （新出生的机器人才有复制能力）

封闭解：a_k = 2^k * x - (2^k - 1)

n 年后总数：
s = x + Σ_{i=0}^{n-1} (2*a_i - 1) = x * (2^{n+1} - 1) - 2^{n+1} + n + 2

解得：x = 1 + (s - n - 1) / (2^{n+1} - 1)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 60

/* ---------- 大整数（十进制，低位在前） ---------- */
typedef struct {
    int d[MAX_DIGITS]; /* 每位存 0~9 */
    int len;           /* 实际位数 */
} BigInt;

/* 从字符串初始化（高位在前） */
void big_init(BigInt *b, const char *s) {
    int slen = (int)strlen(s);
    b->len = slen;
    for (int i = 0; i < slen; i++)
        b->d[slen - 1 - i] = s[i] - '0';
    for (int i = slen; i < MAX_DIGITS; i++)
        b->d[i] = 0;
}

/* 置零 */
void big_zero(BigInt *b) {
    b->len = 1;
    b->d[0] = 0;
    for (int i = 1; i < MAX_DIGITS; i++)
        b->d[i] = 0;
}

/* 减去一个较小的整数（b >= x） */
void big_sub_small(BigInt *b, int x) {
    int borrow = 0;
    int tmp = x;
    int pos = 0;
    while (tmp > 0 || borrow > 0) {
        int digit = tmp % 10;
        tmp /= 10;
        int sub = digit + borrow;
        if (b->d[pos] < sub) {
            b->d[pos] = b->d[pos] + 10 - sub;
            borrow = 1;
        } else {
            b->d[pos] -= sub;
            borrow = 0;
        }
        pos++;
    }
    /* 去除前导零 */
    while (b->len > 1 && b->d[b->len - 1] == 0)
        b->len--;
}

/* 加 1 */
void big_add_one(BigInt *b) {
    int carry = 1;
    for (int i = 0; i < b->len; i++) {
        b->d[i] += carry;
        if (b->d[i] >= 10) {
            b->d[i] -= 10;
            carry = 1;
        } else {
            carry = 0;
            break;
        }
    }
    if (carry) {
        b->d[b->len] = 1;
        b->len++;
    }
}

/* 计算 2^k - 1，结果存入 b */
void big_pow2_minus_1(BigInt *b, int k) {
    big_zero(b);
    b->d[0] = 1;
    b->len = 1;
    /* 计算 2^k */
    for (int i = 0; i < k; i++) {
        int carry = 0;
        for (int j = 0; j < b->len; j++) {
            int val = b->d[j] * 2 + carry;
            b->d[j] = val % 10;
            carry = val / 10;
        }
        if (carry) {
            b->d[b->len] = carry;
            b->len++;
        }
    }
    /* 减 1 */
    big_sub_small(b, 1);
}

/* 比较 a >= b？ */
int big_ge(const BigInt *a, const BigInt *b) {
    if (a->len != b->len)
        return a->len > b->len;
    for (int i = a->len - 1; i >= 0; i--) {
        if (a->d[i] != b->d[i])
            return a->d[i] > b->d[i];
    }
    return 1; /* 相等 */
}

/* a -= b，前提 a >= b */
void big_sub(BigInt *a, const BigInt *b) {
    int borrow = 0;
    for (int i = 0; i < a->len; i++) {
        int sub = (i < b->len ? b->d[i] : 0) + borrow;
        if (a->d[i] < sub) {
            a->d[i] = a->d[i] + 10 - sub;
            borrow = 1;
        } else {
            a->d[i] -= sub;
            borrow = 0;
        }
    }
    while (a->len > 1 && a->d[a->len - 1] == 0)
        a->len--;
}

/* 大整数除法：dividend / divisor，结果存入 quotient */
void big_div(const BigInt *dividend, const BigInt *divisor, BigInt *quotient) {
    BigInt rem; /* 余数 */
    big_zero(&rem);
    big_zero(quotient);

    /* 从高位到低位逐位处理 */
    for (int i = dividend->len - 1; i >= 0; i--) {
        /* rem = rem * 10 + current digit */
        for (int j = rem.len; j > 0; j--)
            rem.d[j] = rem.d[j - 1];
        rem.d[0] = dividend->d[i];
        if (rem.len > 0 && rem.d[rem.len] == 0)
            ; /* 不增加长度 */
        rem.len++;
        while (rem.len > 1 && rem.d[rem.len - 1] == 0)
            rem.len--;

        /* 计算商位 */
        int q = 0;
        while (big_ge(&rem, divisor)) {
            big_sub(&rem, divisor);
            q++;
        }
        quotient->d[i] = q;
    }

    /* 确定商的实际长度 */
    quotient->len = dividend->len;
    while (quotient->len > 1 && quotient->d[quotient->len - 1] == 0)
        quotient->len--;
}

/* 乘以 2 */
void big_mul2(BigInt *b) {
    int carry = 0;
    for (int i = 0; i < b->len; i++) {
        int val = b->d[i] * 2 + carry;
        b->d[i] = val % 10;
        carry = val / 10;
    }
    if (carry) {
        b->d[b->len] = carry;
        b->len++;
    }
}

/* 打印，高位在前 */
void big_print(const BigInt *b) {
    for (int i = b->len - 1; i >= 0; i--)
        putchar('0' + b->d[i]);
    putchar('\n');
}

int main() {
    int n;
    char s_str[60];

    scanf("%d %s", &n, s_str);

    /* dividend = s - n - 1 */
    BigInt dividend;
    big_init(&dividend, s_str);
    big_sub_small(&dividend, n + 1);

    /* divisor = 2^{n+1} - 1 */
    BigInt divisor;
    big_pow2_minus_1(&divisor, n + 1);

    /* quotient = dividend / divisor */
    BigInt result;
    big_div(&dividend, &divisor, &result);

    /* x = quotient + 1 */
    big_add_one(&result);

    big_print(&result);

    return 0;
}
