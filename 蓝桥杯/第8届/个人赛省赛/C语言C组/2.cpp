/*
标题：兴趣小组

为丰富同学们的业余文化生活，某高校学生会创办了3个兴趣小组
（以下称A组，B组，C组）。
每个小组的学生名单分别在"A.txt","B.txt"和"C.txt"中。
每个文件中存储的是学生的学号。

由于工作需要，我们现在想知道：
    既参加了A组，又参加了B组，但是没有参加C组的同学一共有多少人？

请你统计该数字并通过浏览器提交答案。

注意：答案是一个整数，不要提交任何多余的内容。
*/

/*
 * 解题思路：
 * 读取 A.txt、B.txt、C.txt 中的学号，存入 set。
 * 计算 |A ∩ B| − |A ∩ B ∩ C|。
 * 即同时出现在 A 和 B 中但不在 C 中的学号数。
 * 学号可能有前导零，用 string 存储。
 */
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;

int main() {
    set<string> A, B, C;
    string line, id;

    // 读取 A.txt
    ifstream fa("2/A.txt");
    while (getline(fa, line)) {
        istringstream iss(line);
        while (getline(iss, id, ',')) {
            // 去除前后空格
            size_t s = id.find_first_not_of(" \t\r");
            if (s != string::npos) {
                size_t e = id.find_last_not_of(" \t\r");
                id = id.substr(s, e - s + 1);
            }
            if (!id.empty()) A.insert(id);
        }
    }
    fa.close();

    // 读取 B.txt
    ifstream fb("2/B.txt");
    while (getline(fb, line)) {
        istringstream iss(line);
        while (getline(iss, id, ',')) {
            size_t s = id.find_first_not_of(" \t\r");
            if (s != string::npos) {
                size_t e = id.find_last_not_of(" \t\r");
                id = id.substr(s, e - s + 1);
            }
            if (!id.empty()) B.insert(id);
        }
    }
    fb.close();

    // 读取 C.txt
    ifstream fc("2/C.txt");
    while (getline(fc, line)) {
        istringstream iss(line);
        while (getline(iss, id, ',')) {
            size_t s = id.find_first_not_of(" \t\r");
            if (s != string::npos) {
                size_t e = id.find_last_not_of(" \t\r");
                id = id.substr(s, e - s + 1);
            }
            if (!id.empty()) C.insert(id);
        }
    }
    fc.close();

    int ans = 0;
    for (const string &s : A)
        if (B.count(s) && !C.count(s))
            ans++;

    cout << ans << endl;
    return 0;
}
