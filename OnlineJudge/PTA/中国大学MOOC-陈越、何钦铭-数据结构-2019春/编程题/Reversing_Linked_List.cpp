/*
02-线性结构3 Reversing Linked List （25 分）
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.

Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤10
​5
​​ ) which is the total number of nodes, and a positive K (≤N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next
where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:

For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:

00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:

00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

int main()
{
    //加速std输入输出流
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    //输入
    int address = 0, N = 0, K = 0;
    std::cin >> address >> N >> K;
    std::vector<std::pair<int, int>> vec(100000 + 1); //空间换时间，用下标来做当前地址，里面的内容第一个是数据，第二个是下一个地址
    for (int i = 0; i < N; i++)
    {
        int a = 0, d = 0, n = 0;
        std::cin >> a >> d >> n;
        vec[a].first = d;
        vec[a].second = n;
    }

    //给出按顺序的表
    //这里构建链表的时间复杂度就只有N了
    std::vector<std::pair<int, int>> list; //第一个内容是当前地址，第二个内容是当前数据
    while (address != -1)
    {
        list.push_back({address, vec[address].first});
        address = vec[address].second;
    }

    //每K个反转一次，不足K不反转
    auto it = list.begin();
    while (it + K <= list.end())
    {
        std::reverse(it, it + K);
        it += K;
    }

    //输出
    //补满5位地址
    std::string t(std::to_string(list[0].first));
    while (t.size() < 5)
    {
        t.insert(t.begin(), '0');
    }
    std::cout << t << ' ' << list[0].second << ' ';
    for (int i = 1; i < list.size(); i++)
    {
        t = std::to_string(list[i].first);
        while (t.size() < 5)
        {
            t.insert(t.begin(), '0');
        }
        std::cout << t << '\n'
                  << t << ' ' << list[i].second << ' ';
    }
    std::cout << -1;

    return 0;
}