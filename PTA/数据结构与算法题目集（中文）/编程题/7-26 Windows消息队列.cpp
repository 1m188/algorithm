/**
 * @file 7-26 Windows消息队列.cpp
 * @date 2022-05-09
 */

/*
消息队列是Windows系统的基础。对于每个进程，系统维护一个消息队列。
如果在进程中有特定事件发生，如点击鼠标、文字改变等，系统将把这个消息加到队列当中。
同时，如果队列不是空的，这一进程循环地从队列中按照优先级获取消息。
请注意优先级值低意味着优先级高。请编辑程序模拟消息队列，将消息加到队列中以及从队列中获取消息。

输入格式:
输入首先给出正整数N（≤10^5），随后N行，每行给出一个指令——GET或PUT，
分别表示从队列中取出消息或将消息添加到队列中。如果指令是PUT，后面就有一个消息名称、
以及一个正整数表示消息的优先级，此数越小表示优先级越高。
消息名称是长度不超过10个字符且不含空格的字符串；
题目保证队列中消息的优先级无重复，且输入至少有一个GET。

输出格式:
对于每个GET指令，在一行中输出消息队列中优先级最高的消息的名称和参数。
如果消息队列中没有消息，输出EMPTY QUEUE!。对于PUT指令则没有输出。

输入样例:
9
PUT msg1 5
PUT msg2 4
GET
PUT msg3 2
PUT msg4 4
GET
GET
GET
GET

输出样例:
msg2
msg3
msg4
msg1
EMPTY QUEUE!

代码长度限制
16 KB

时间限制
150 ms

内存限制
64 MB
*/

/* 优先队列的运用，注意在C++里相关的设计和语法，题目不难 */

/* 这题之后也用更一般的方法，定义Message{string，int}结构体来做，
但是在第三个数据点会超时（g++），不知道为什么，
猜想大概在vector里面移动Message消耗太大了吧？ */

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

// greater使值大的优先级小，注意C++中优先级队列的用法
priority_queue<int, vector<int>, greater<int>> pque; // 优先队列
// 优先级值和消息的映射
unordered_map<int, string> msg;

int main() {

    int N = 0;
    cin >> N;
    while (N--) {
        string cmd;
        cin >> cmd;
        if (cmd == "PUT") { // 对于put加入
            string message;
            cin >> message;
            int priority = 0;
            cin >> priority;
            msg[priority] = message;
            pque.push(priority);
        } else { // 对于get先检查有没有消息，随后再取出消息，并且删掉这条消息
            if (pque.empty()) {
                cout << "EMPTY QUEUE!\n";
            } else {
                int priority = pque.top();
                pque.pop();
                cout << msg[priority] << '\n';
                msg.erase(priority);
            }
        }
    }

    return 0;
}