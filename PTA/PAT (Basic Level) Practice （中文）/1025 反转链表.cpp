/**
 * @file 1025 反转链表.cpp
 * @date 2023-01-12
 */

/*
给定一个常数 K 以及一个单链表 L，请编写程序将 L 中每 K 个结点反转。例如：给定 L 为 1→2→3→4→5→6，K 为 3，则输出应该为 3→2→1→6→5→4；如果 K 为 4，则输出应该为 4→3→2→1→5→6，即最后不到 K 个元素不反转。

输入格式：
每个输入包含 1 个测试用例。每个测试用例第 1 行给出第 1 个结点的地址、结点总个数正整数 N (≤10
5
 )、以及正整数 K (≤N)，即要求反转的子链结点的个数。结点的地址是 5 位非负整数，NULL 地址用 −1 表示。

接下来有 N 行，每行格式为：

Address Data Next
其中 Address 是结点地址，Data 是该结点保存的整数数据，Next 是下一结点的地址。

输出格式：
对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。

输入样例：
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
输出样例：
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct Node {
    string addr;
    int data;
};

struct Build_Node {
    int data;
    string addr_next;
};

vector<Node> build_link(map<string, Build_Node> &mp, const string &head_addr) {
    vector<Node> res;
    auto addr = head_addr;
    while (addr != "-1") {
        auto bn = mp[addr];
        res.push_back(Node{addr, bn.data});
        addr = bn.addr_next;
    }
    return res;
}

void reverse_k(vector<Node> &vec, int k) {
    int left = 0, right = k - 1;
    while (right < vec.size()) {
        int a = left, b = right;
        while (a < b) {
            swap(vec[a], vec[b]);
            a++, b--;
        }
        left = right + 1;
        right = left + k - 1;
    }
}

void out(const vector<Node> &vec) {
    for (int i = 0; i < vec.size() - 1; i++)
        cout << vec[i].addr << ' ' << vec[i].data << ' ' << vec[i + 1].addr << '\n';
    cout << vec.back().addr << ' ' << vec.back().data << " -1\n";
}

int main() {
    string head_addr;
    int n, k;
    cin >> head_addr >> n >> k;

    map<string, Build_Node> mp;
    for (int i = 0; i < n; i++) {
        string addr, addr_next;
        int data;
        cin >> addr >> data >> addr_next;
        mp[addr] = Build_Node{data, addr_next};
    }

    auto vec = build_link(mp, head_addr);
    reverse_k(vec, k);
    out(vec);

    return 0;
}