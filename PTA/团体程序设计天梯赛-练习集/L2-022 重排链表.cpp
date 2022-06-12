/**
 * @file L2-022 重排链表.cpp
 * @date 2022-06-12
 */

/*
给定一个单链表 L 
1
​
 →L 
2
​
 →⋯→L 
n−1
​
 →L 
n
​
 ，请编写程序将链表重新排列为 L 
n
​
 →L 
1
​
 →L 
n−1
​
 →L 
2
​
 →⋯。例如：给定L为1→2→3→4→5→6，则输出应该为6→1→5→2→4→3。

输入格式：
每个输入包含1个测试用例。每个测试用例第1行给出第1个结点的地址和结点总个数，即正整数N (≤10 
5
 )。结点的地址是5位非负整数，NULL地址用−1表示。

接下来有N行，每行格式为：

Address Data Next
其中Address是结点地址；Data是该结点保存的数据，为不超过10 
5
 的正整数；Next是下一结点的地址。题目保证给出的链表上至少有两个结点。

输出格式：
对每个测试用例，顺序输出重排后的结果链表，其上每个结点占一行，格式与输入相同。

输入样例：
00100 6
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
输出样例：
68237 6 00100
00100 1 99999
99999 5 12309
12309 2 00000
00000 4 33218
33218 3 -1
代码长度限制
16 KB
时间限制
500 ms
内存限制
64 MB
*/

/* 用map来做地址到其内容的映射，添加向前的指针，保存整个链表后前后交替着输出，向前的指针可以确保
从后向前遍历，直到两个指针相撞，此时为目标链表的最后一个节点 */

#include <cstdio>
#include <unordered_map>
using namespace std;

struct Node {
    int data = 0;
    int next_addr = -1;
    int pre_addr = -1;
};

int root_addr = 0, last_addr = 0;
int n = 0;
unordered_map<int, Node> ump;

void input() {
    scanf("%d %d", &root_addr, &n);
    for (int i = 0; i < n; i++) {
        int addr = 0;
        scanf("%d", &addr);
        auto &x = ump[addr];
        scanf("%d %d", &x.data, &x.next_addr);
        if (x.next_addr != -1) {
            ump[x.next_addr].pre_addr = addr;
        } else {
            last_addr = addr;
        }
    }
}

void calc() {
    while (last_addr != root_addr) {
        printf("%05d %d %05d\n", last_addr, ump[last_addr].data, root_addr);
        last_addr = ump[last_addr].pre_addr;
        if (last_addr == root_addr) break;
        printf("%05d %d %05d\n", root_addr, ump[root_addr].data, last_addr);
        root_addr = ump[root_addr].next_addr;
    }
    printf("%05d %d -1", root_addr, ump[root_addr].data);
}

int main() {
    input();
    calc();
    return 0;
}