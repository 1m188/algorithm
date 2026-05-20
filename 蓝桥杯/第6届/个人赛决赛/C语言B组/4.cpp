/*

标题：密文搜索

福尔摩斯从X星收到一份资料，全部是小写字母组成。
他的助手提供了另一份资料：许多长度为8的密码列表。
福尔摩斯发现，这些密码是被打乱后隐藏在先前那份资料中的。

请你编写一个程序，从第一份资料中搜索可能隐藏密码的位置。要考虑密码的所有排列可能性。

数据格式：

输入第一行：一个字符串s，全部由小写字母组成，长度小于1024*1024
紧接着一行是一个整数n,表示以下有n行密码，1<=n<=1000
紧接着是n行字符串，都是小写字母组成，长度都为8

要求输出：
一个整数, 表示每行密码的所有排列在s中匹配次数的总和。

例如：
用户输入：
aaaabbbbaabbcccc
2
aaaabbbb
abcabccc

则程序应该输出：
4

这是因为：第一个密码匹配了3次，第二个密码匹配了1次，一共4次。


资源约定：
峰值内存消耗 < 512M
CPU消耗  < 3000ms


请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。

*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n;
    cin >> n;

    // 读取所有密码
    string passwords[1000];
    for (int i = 0; i < n; i++) {
        cin >> passwords[i];
    }

    int len = s.length();

    // 滑动窗口统计每种字符频率的出现次数
    // key: 26字节的字符串，每个字节代表对应字母的出现次数
    map<string, int> freqCount;

    if (len >= 8) {
        int cnt[26] = {0};
        for (int i = 0; i < 8; i++) {
            cnt[s[i] - 'a']++;
        }

        string key(26, '\0');
        for (int j = 0; j < 26; j++)
            key[j] = (char)cnt[j];
        freqCount[key]++;

        for (int i = 8; i < len; i++) {
            cnt[s[i - 8] - 'a']--;
            cnt[s[i] - 'a']++;

            for (int j = 0; j < 26; j++)
                key[j] = (char)cnt[j];
            freqCount[key]++;
        }
    }

    // 对每个密码查表累加
    int total = 0;
    for (int i = 0; i < n; i++) {
        int cnt[26] = {0};
        for (char c : passwords[i]) {
            cnt[c - 'a']++;
        }

        string key(26, '\0');
        for (int j = 0; j < 26; j++)
            key[j] = (char)cnt[j];

        total += freqCount[key];
    }

    cout << total << endl;

    return 0;
}
