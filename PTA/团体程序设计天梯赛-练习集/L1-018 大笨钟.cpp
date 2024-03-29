/**
 * @file L1-018 大笨钟.cpp
 * @date 2022-05-18
 */

/*
微博上有个自称“大笨钟V”的家伙，每天敲钟催促码农们爱惜身体早点睡觉。
不过由于笨钟自己作息也不是很规律，所以敲钟并不定时。
一般敲钟的点数是根据敲钟时间而定的，如果正好在某个整点敲，那么“当”数就等于那个整点数；
如果过了整点，就敲下一个整点数。另外，虽然一天有24小时，钟却是只在后半天敲1~12下。
例如在23:00敲钟，就是“当当当当当当当当当当当”，而到了23:01就会是“当当当当当当当当当当当当”。
在午夜00:00到中午12:00期间（端点时间包括在内），笨钟是不敲的。

下面就请你写个程序，根据当前时间替大笨钟敲钟。

输入格式：
输入第一行按照hh:mm的格式给出当前时间。其中hh是小时，在00到23之间；mm是分钟，在00到59之间。

输出格式：
根据当前时间替大笨钟敲钟，即在一行中输出相应数量个Dang。如果不是敲钟期，则输出：

Only hh:mm.  Too early to Dang.
其中hh:mm是输入的时间。

输入样例1：
19:05

输出样例1：
DangDangDangDangDangDangDangDang

输入样例2：
07:05

输出样例2：
Only 07:05.  Too early to Dang.

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 注意提取时间 */

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int hh = 0, mm = 0;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    hh = (s[0] - '0') * 10 + s[1] - '0';
    mm = (s[3] - '0') * 10 + s[4] - '0';
}

void calc() {
    if (hh <= 12) {
        cout << "Only "
             << setw(2) << setfill('0') << hh
             << ':'
             << setw(2) << setfill('0') << mm
             << ".  Too early to Dang.";
        return;
    }

    hh -= 12;
    if (mm > 0)
        hh++;
    for (int i = 0; i < hh; i++)
        cout << "Dang";
}

int main() {
    input();
    calc();
    return 0;
}