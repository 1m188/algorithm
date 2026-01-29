/**
 * @file REAL827 密码强度检查.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-08-21
 *
 * @copyright Copyright (c) 2025
 *
 */

/*
描述
在网络安全中，评估密码的强度是重要的基本操作。请根据给定的密码字符串，判断其强度级别。
强度评估规则如下：
∙
 
∙ 如果密码长度小于
8
8，则强度为
Weak
Weak；
∙
 
∙ 否则，检查密码中包含的字符类型（共四种）：小写字母（
a-z
a-z）、大写字母（
A-Z
A-Z）、数字（
0-9
0-9）和特殊字符（非字母、非数字的可见字符）；
∙
 
∙ 如果包含所有四种类型，则强度为
Strong
Strong；
∙
 
∙ 如果包含正好三种类型，则强度为
Medium
Medium；
∙
 
∙ 其他情况，强度为
Weak
Weak。

现在，给定多个密码字符串，请为每个密码输出其强度级别。

【名词解释】
可见字符集为 ASCII 码在
33
33 到
126
126 范围内的可见字符。您可以参阅下表获得其详细信息（您可能关注的内容是，这其中不包含空格、换行）。

../图片/AllAscii.png
输入描述：
每个测试文件均包含多组测试数据。第一行输入一个整数
T
(
1
≦
T
≦
100
)
T(1≦T≦100) 代表数据组数，每组测试数据描述如下：
在一行上输入一个由可见字符集构成的字符串
s
(
1
≦
l
e
n
g
t
h
(
s
)
≦
20
)
s(1≦length(s)≦20)，表示密码。
输出描述：
对于每一组测试数据，新起一行。输出一个字符串，表示该密码的强度级别（
Strong
Strong、
Medium
Medium 或
Weak
Weak）。
示例1
输入：
3
Abc123!@
abc123
Password1!
复制
输出：
Strong
Weak
Strong

*/

#include <iostream>
#include <string>
using namespace std;

int main() {

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if (s.size() < 8) {
            cout << "Weak\n";
        } else {
            int A = 0, a = 0, num = 0, other = 0; // A大写字母，a小写字母，num数字，other其他
            for (const auto &c : s) {
                if (c >= 'A' && c <= 'Z')
                    A = 1;
                else if (c >= 'a' && c <= 'z')
                    a = 1;
                else if (c >= '0' && c <= '9')
                    num = 1;
                else if (c >= 33 && c <= 126)
                    other = 1;
            }
            int x = A + a + num + other;
            cout << (x == 4 ? "Strong\n" : (x == 3 ? "Medium\n" : "Weak\n"));
        }
    }

    return 0;
}