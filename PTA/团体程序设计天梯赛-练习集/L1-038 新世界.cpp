/**
 * @file L1-038 新世界.cpp
 * @date 2022-05-19
 */

/*
这道超级简单的题目没有任何输入。

你只需要在第一行中输出程序员钦定名言“Hello World”，
并且在第二行中输出更新版的“Hello New World”就可以了。

输入样例：
无

输出样例：
Hello World
Hello New World

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

#include <cstdio>
using namespace std;

int main() {
    printf("%s\n%s", "Hello World", "Hello New World");
    return 0;
}