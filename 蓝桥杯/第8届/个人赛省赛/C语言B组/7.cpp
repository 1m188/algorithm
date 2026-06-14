/*
标题：日期问题

小明正在整理一批历史文献。这些历史文献中出现了很多日期。小明知道这些日期都在1960年1月1日至2059年12月31日。令小明头疼的是，这些日期采用的格式非常不统一，有采用年/月/日的，有采用月/日/年的，还有采用日/月/年的。更加麻烦的是，年份也都省略了前两位，使得文献上的一个日期，存在很多可能的日期与其对应。

比如02/03/04，可能是2002年03月04日、2004年02月03日或2004年03月02日。

给出一个文献上的日期，你能帮助小明判断有哪些可能的日期对其对应吗？

输入
----
一个日期，格式是"AA/BB/CC"。  (0 <= A, B, C <= 9)

输出
----
输出若干个不相同的日期，每个日期一行，格式是"yyyy-MM-dd"。多个日期按从早到晚排列。

样例输入
----
02/03/04

样例输出
----
2002-03-04
2004-02-03
2004-03-02

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。
*/

/*
 * 解题思路：
 * 将输入 AA/BB/CC 按三种格式解析：
 *   1) 年-月-日: year = 1900+AA 或 2000+AA, month = BB, day = CC
 *   2) 月-日-年: year = 1900+CC 或 2000+CC, month = AA, day = BB
 *   3) 日-月-年: year = 1900+CC 或 2000+CC, month = BB, day = AA
 * 对每种格式，判断日期是否合法（年份1960~2059，月份1~12，
 *   日期有效），将合法日期存入 set 去重，
 *   最后按时间升序输出。
 */
#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

bool isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

bool valid(int y, int m, int d) {
    if (y < 1960 || y > 2059) return false;
    if (m < 1 || m > 12) return false;
    if (d < 1) return false;
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && isLeap(y)) days[2] = 29;
    return d <= days[m];
}

int main() {
    int a, b, c;
    scanf("%d/%d/%d", &a, &b, &c);

    set<int> dates; // 存储为 yyyymmdd 整数方便排序

    // 年-月-日 (AA/BB/CC)
    for (int yy : {1900 + a, 2000 + a})
        if (valid(yy, b, c))
            dates.insert(yy * 10000 + b * 100 + c);

    // 月-日-年 (AA/BB/CC)
    for (int yy : {1900 + c, 2000 + c})
        if (valid(yy, a, b))
            dates.insert(yy * 10000 + a * 100 + b);

    // 日-月-年 (AA/BB/CC)
    for (int yy : {1900 + c, 2000 + c})
        if (valid(yy, b, a))
            dates.insert(yy * 10000 + b * 100 + a);

    for (int d : dates)
        printf("%04d-%02d-%02d\n", d / 10000, d / 100 % 100, d % 100);

    return 0;
}
