/*

标题：表达式计算

虽然我们学了许久的程序设计，但对于简单的四则混合运算式，如果让我们完全白手起家地编程来解析，还是有点棘手。

这里，我们简化一下问题，假设只有加法和乘法，并且没有括号来改变优先级。
再假设参加运算的都是正整数。

在这么多的限制条件下，表达式的解析似乎简单了许多。
下面的代码解决了这个问题。请仔细阅读源码，并填写划线部分缺少的代码。


#include <stdio.h>

int f3(const char* s, int begin, int end)
{
        int sum = 0;
        int i;
        for(i=begin; i<end; i++){
                if(s[i]==' ') continue;
                sum = sum * 10 + (s[i]-'0');
        }
        return sum;
}

int f2(const char* s, int begin, int end)
{
        int p = begin;
        int pro = 1;
        while(1){
                int p0 = p;
                while(p!=end && s[p]!='*') p++;
                pro *= _______________________________;  //填空
                if(p==end) break;
                p++;
        }
        printf("f2: pro=%d\n", pro);
        return pro;
}

int f(const char* s)
{
        int p = 0;
        int sum = 0;
        while(1){
                int p0 = p;
                while(s[p]!=0 && s[p]!='+') p++;
                sum += f2(s,p0,p);
                if(s[p]==0) break;
                p++;
        }

        return sum;
}

int main()
{
        int x = f("12+18+5*4*3+10");
        printf("%d\n", x);
        return 0;
}

注意：只填写划线处缺少的内容，不要填写已有的代码或符号，也不要填写任何解释说明文字等。


*/

#include <stdio.h>

/**
 * @brief 将字符串 s 的 [begin, end) 区间解析为一个正整数
 *
 * 从 begin 位置开始，逐字符读取，跳过空格，将连续的数字字符
 * 按十进制逐位累加的方式转换为整数值。
 *
 * @param s     源字符串
 * @param begin 子串的起始下标（含）
 * @param end   子串的结束下标（不含）
 * @return 解析得到的整数值
 */
int f3(const char *s, int begin, int end) {
    int sum = 0;
    int i;
    for (i = begin; i < end; i++) {
        if (s[i] == ' ') continue;     // 忽略空格字符
        sum = sum * 10 + (s[i] - '0'); // 十进制逐位累加
    }
    return sum;
}

/**
 * @brief 计算一个仅含乘法运算的子表达式的值
 *
 * 在字符串 s 的 [begin, end) 区间内，以 '*' 作为分隔符，
 * 将区间划分为多个纯数字段，分别解析后连续相乘。
 *
 * 例如：对于 "5*4*3"，该函数解析出 5、4、3 三个数并返回 60。
 *
 * @param s     源字符串
 * @param begin 乘法段的起始下标（含）
 * @param end   乘法段的结束下标（不含）
 * @return 该乘法段内所有因子相乘的结果
 */
int f2(const char *s, int begin, int end) {
    int p = begin; // 当前扫描指针
    int pro = 1;   // 累积乘积，初始为 1（乘法单位元）
    while (1) {
        int p0 = p; // 记录当前因子的起始位置
        // 向后扫描，直到遇到 '*' 或到达区间末尾
        while (p != end && s[p] != '*')
            p++;
        // 将 [p0, p) 区间内的数字字符串解析为整数，并乘入 pro
        pro *= f3(s, p0, p); // 填空：提取当前乘法因子并累乘
        if (p == end) break; // 已处理完整个乘法段，退出循环
        p++;                 // 跳过 '*' 字符，准备处理下一个因子
    }
    printf("f2: pro=%d\n", pro);
    return pro;
}

/**
 * @brief 计算一个仅含加法和乘法的表达式的值（无括号）
 *
 * 以 '+' 作为分隔符，将整个表达式划分为若干个乘法段，
 * 分别调用 f2 求值后，再将各段结果累加求和。
 *
 * 调用链：f → f2 → f3
 *   - f  负责按 '+' 拆分加法段并累加
 *   - f2 负责按 '*' 拆分乘法因子并累乘
 *   - f3 负责将数字子串解析为整数值
 *
 * @param s 待计算的表达式字符串（以 '\0' 结尾）
 * @return 表达式的计算结果
 */
int f(const char *s) {
    int p = 0;   // 当前扫描指针
    int sum = 0; // 累加和
    while (1) {
        int p0 = p; // 记录当前加法段的起始位置
        // 向后扫描，直到遇到 '+' 或到达字符串末尾
        while (s[p] != 0 && s[p] != '+')
            p++;
        // 对 [p0, p) 区间（一个乘法段）调用 f2 求积，累加到 sum
        sum += f2(s, p0, p);
        if (s[p] == 0) break; // 已到字符串末尾，退出循环
        p++;                  // 跳过 '+' 字符，处理下一个加法段
    }
    return sum;
}

/**
 * @brief 主函数：运行题目样例并输出计算结果
 *
 * 表达式 "12+18+5*4*3+10" 的计算过程：
 *   f2("12") = 12, f2("18") = 18, f2("5*4*3") = 60, f2("10") = 10
 *   最终结果 = 12 + 18 + 60 + 10 = 100
 *
 * @return 0 正常退出
 */
int main() {
    int x = f("12+18+5*4*3+10");
    printf("%d\n", x);
    return 0;
}
