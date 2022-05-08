/*
设已知有两个堆栈S1和S2，请用这两个堆栈模拟出一个队列Q。

所谓用堆栈模拟队列，实际上就是通过调用堆栈的下列操作函数:

int IsFull(Stack S)：判断堆栈S是否已满，返回1或0；
int IsEmpty (Stack S )：判断堆栈S是否为空，返回1或0；
void Push(Stack S, ElementType item )：将元素item压入堆栈S；
ElementType Pop(Stack S )：删除并返回S的栈顶元素。
实现队列的操作，即入队void AddQ(ElementType item)和出队ElementType DeleteQ()。

输入格式:
输入首先给出两个正整数N1和N2，表示堆栈S1和S2的最大容量。随后给出一系列的队列操作：
A item表示将item入列（这里假设item为整型数字）；D表示出队操作；T表示输入结束。

输出格式:
对输入中的每个D操作，输出相应出队的数字，或者错误信息ERROR:Empty。
如果入队操作无法执行，也需要输出ERROR:Full。每个输出占1行。

输入样例:
3 2
A 1 A 2 A 3 A 4 A 5 D A 6 D A 7 D A 8 D D D D T

输出样例:
ERROR:Full
1
ERROR:Full
2
3
4
7
8
ERROR:Empty

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 制作两个栈，一个空间大的栈一个空间小的，当要push元素的时候先往小的里面push，如果
小的满了的话，将小的挨个弹出来加入大的，然后再往小的push，如果小的满了。而且大的也有
东西，则error。当要pop元素的时候，先看大的里面有没有元素，有的话直接从大的里面pop，
否则的话看小的里面有没有，将小的里面挨个弹出来加入大的，然后从大的里面pop，
如果两个栈都为空则error。 */

#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct Stack {

    // 栈空间
    /* 这里本来是做裸指针的，后来忘记回收。后来做了回收，但感觉不如做智能指针，
    然而智能指针又有一些问题，智能指针一般是针对单个对象的，对于对象数组的需求
    一般还是用vector。而且在使用智能指针的过程中也查了一些资料，复习了一下，
    现在就是，对于智能指针，最好不要用new，对于：
    
    shared_ptr<typename> p = new typename[size]();
    
    这样的语句来说做两件事情，申请new和申请p，一方面做两次申请性能下降，
    另一方面如果new申请成功而p申请失败，则有可能导致内存泄漏，最好的
    方法是用自带的初始化方法make_ptr。如果reset则可以使用，但还是要
    小心。
    总之就是在C++里面，要么纯用裸指针，完全手动管理，要么用了智能指针
    就不要再用任何形式的new了；要么C语言，要么morden C++。 */
    vector<int> ptr;

    int size = 0; // 栈大小
    int top = -1; // 栈顶指针，指向栈最顶上的元素
};
int IsFull(const Stack &s) { return s.top == s.size - 1; }
int IsEmpty(const Stack &s) { return s.top == -1; }
void Push(Stack &s, int item) { s.ptr[++s.top] = item; }
int Pop(Stack &s) { return s.ptr[s.top--]; }

Stack sss, bss; // 小栈和大栈
int N1 = 0, N2 = 0;
vector<pair<char, int>> op;

void input() {
    cin >> N1 >> N2;
    if (N1 < N2) {
        sss.size = N1, bss.size = N2;
    } else {
        sss.size = N2, bss.size = N1;
    }
    sss.ptr.resize(sss.size);
    bss.ptr.resize(bss.size);

    char c = 0;
    while (cin >> c && c != 'T') {
        if (c == 'A') {
            int x = 0;
            cin >> x;
            op.push_back({c, x});
        } else
            op.push_back({c, 0});
    }
}

void AddQ(int item) {
    if (!IsFull(sss))
        Push(sss, item);
    else if (IsEmpty(bss)) {
        while (!IsEmpty(sss)) {
            Push(bss, Pop(sss));
        }
        Push(sss, item);
    } else {
        cout << "ERROR:Full\n";
    }
}

int DeleteQ() {
    if (!IsEmpty(bss)) {
        return Pop(bss);
    } else if (!IsEmpty(sss)) {
        while (!IsEmpty(sss)) {
            Push(bss, Pop(sss));
        }
        return Pop(bss);
    } else {
        cout << "ERROR:Empty\n";
        return INT_MIN;
    }
}

void calc() {
    for (const auto &e : op) {
        if (e.first == 'A') {
            AddQ(e.second);
        } else {
            int x = DeleteQ();
            if (x != INT_MIN)
                cout << x << '\n';
        }
    }
}

int main() {
    input();
    calc();
    return 0;
}