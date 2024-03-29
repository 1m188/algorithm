/**
 * @file L1-058 6翻了.cpp
 * @date 2022-05-19
 */

/*
666.JPG
“666”是一种网络用语，大概是表示某人很厉害、我们很佩服的意思。最近又衍生出另一个数字“9”，意思是“6翻了”，实在太厉害的意思。如果你以为这就是厉害的最高境界，那就错啦 —— 目前的最高境界是数字“27”，因为这是 3 个 “9”！

本题就请你编写程序，将那些过时的、只会用一连串“6666……6”表达仰慕的句子，翻译成最新的高级表达。

输入格式：
输入在一行中给出一句话，即一个非空字符串，由不超过 1000 个英文字母、数字和空格组成，以回车结束。

输出格式：
从左到右扫描输入的句子：如果句子中有超过 3 个连续的 6，则将这串连续的 6 替换成 9；但如果有超过 9 个连续的 6，则将这串连续的 6 替换成 27。其他内容不受影响，原样输出。

输入样例：
it is so 666 really 6666 what else can I say 6666666666
输出样例：
it is so 666 really 9 what else can I say 27
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

#include <cstdio>
#include <string>
using namespace std;

int main() {

    string str;
    for (char c; (c = getchar()) != '\n';)
        str.push_back(c);

    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '6')
            continue;

        int j = i + 1;
        while (str[j] == '6')
            j++;

        int n = j - i;
        if (n > 9) {
            str.erase(i, n);
            str.insert(i, "27");
        } else if (n > 3) {
            str.erase(i, n);
            str.insert(i, "9");
        }
    }

    printf("%s", str.c_str());

    return 0;
}