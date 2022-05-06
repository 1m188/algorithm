/*
实现QQ新帐户申请和老帐户登陆的简化版功能。最大挑战是：据说现在的QQ号码已经有10位数了。

输入格式:
输入首先给出一个正整数N（≤10^5），随后给出N行指令。
每行指令的格式为：“命令符（空格）QQ号码（空格）密码”。
其中命令符为“N”（代表New）时表示要新申请一个QQ号，后面是新帐户的号码和密码；
命令符为“L”（代表Login）时表示是老帐户登陆，后面是登陆信息。
QQ号码为一个不超过10位、但大于1000（据说QQ老总的号码是1001）的整数。
密码为不小于6位、不超过16位、且不包含空格的字符串。

输出格式:
针对每条指令，给出相应的信息：

1）若新申请帐户成功，则输出“New: OK”；

2）若新申请的号码已经存在，则输出“ERROR: Exist”；

3）若老帐户登陆成功，则输出“Login: OK”；

4）若老帐户QQ号码不存在，则输出“ERROR: Not Exist”；

5）若老帐户密码错误，则输出“ERROR: Wrong PW”。

输入样例:
5
L 1234567890 myQQ@qq.com
N 1234567890 myQQ@qq.com
N 1234567890 myQQ@qq.com
L 1234567890 myQQ@qq
L 1234567890 myQQ@qq.com

输出样例:
ERROR: Not Exist
New: OK
ERROR: Exist
ERROR: Wrong PW
Login: OK

代码长度限制
16 KB

时间限制
1200 ms

内存限制
64 MB
*/

/* 直接模拟，注意qq号的长度 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int N = 0;
unordered_map<long long, string> db; // 数据库，用无序map加快速度

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        char cmd = 0;
        long long qq = 0;
        string pass;
        cin >> cmd >> qq >> pass;

        if (cmd == 'N') {
            if (db.find(qq) == db.end()) {
                db[qq] = pass;
                cout << "New: OK\n";
            } else {
                cout << "ERROR: Exist\n";
            }
        } else {
            auto it = db.find(qq);
            if (it == db.end())
                cout << "ERROR: Not Exist\n";
            else if (it->second != pass) {
                cout << "ERROR: Wrong PW\n";
            } else {
                cout << "Login: OK\n";
            }
        }
    }
}

int main() {
    input();
    return 0;
}