/*
标题： Excel地址

Excel单元格的地址表示很有趣，它使用字母来表示列号。
比如，
A表示第1列，
B表示第2列，
Z表示第26列，
AA表示第27列，
AB表示第28列，
BA表示第53列，
....

当然Excel的最大列号是有限度的，所以转换起来不难。
如果我们想把这种表示法一般化，可以把很大的数字转换为很长的字母序列呢？

本题目即是要求对输入的数字, 输出其对应的Excel地址表示方式。

例如，
输入：
26
则程序应该输出：
Z

再例如，
输入：
2054
则程序应该输出：
BZZ

我们约定，输入的整数范围[1,2147483647]

资源约定：
峰值内存消耗 < 256M
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
 * 这是 1-indexed 26 进制转换，但略有不同（没有 0）。
 * 循环：n > 0
 *   n--（转为 0-indexed）
 *   当前位 = n % 26 + 'A'
 *   n /= 26
 * 最后反转结果。
 */
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    long long n;
    cin >> n;

    string ans;
    while (n > 0) {
        n--; // 0-indexed
        ans += (char)(n % 26 + 'A');
        n /= 26;
    }
    reverse(ans.begin(), ans.end());

    cout << ans << endl;
    return 0;
}
