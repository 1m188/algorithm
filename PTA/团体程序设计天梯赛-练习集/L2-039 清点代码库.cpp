/**
 * @file L2-039 清点代码库.cpp
 * @date 2022-06-19
 */

/*
code.jpg
上图转自新浪微博：“阿里代码库有几亿行代码，但其中有很多功能重复的代码，比如单单快排就被重写了几百遍。请设计一个程序，能够将代码库中所有功能重复的代码找出。各位大佬有啥想法，我当时就懵了，然后就挂了。。。”

这里我们把问题简化一下：首先假设两个功能模块如果接受同样的输入，总是给出同样的输出，则它们就是功能重复的；其次我们把每个模块的输出都简化为一个整数（在 int 范围内）。于是我们可以设计一系列输入，检查所有功能模块的对应输出，从而查出功能重复的代码。你的任务就是设计并实现这个简化问题的解决方案。

输入格式：
输入在第一行中给出 2 个正整数，依次为 N（≤10 
4
 ）和 M（≤10 
2
 ），对应功能模块的个数和系列测试输入的个数。

随后 N 行，每行给出一个功能模块的 M 个对应输出，数字间以空格分隔。

输出格式：
首先在第一行输出不同功能的个数 K。随后 K 行，每行给出具有这个功能的模块的个数，以及这个功能的对应输出。数字间以 1 个空格分隔，行首尾不得有多余空格。输出首先按模块个数非递增顺序，如果有并列，则按输出序列的递增序给出。

注：所谓数列 { A 
1
​
 , ..., A 
M
​
  } 比 { B 
1
​
 , ..., B 
M
​
  } 大，是指存在 1≤i<M，使得 A 
1
​
 =B 
1
​
 ，...，A 
i
​
 =B 
i
​
  成立，且 A 
i+1
​
 >B 
i+1
​
 。

输入样例：
7 3
35 28 74
-1 -1 22
28 74 35
-1 -1 22
11 66 0
35 28 74
35 28 74
输出样例：
4
3 35 28 74
2 -1 -1 22
1 11 66 0
1 28 74 35
代码长度限制
16 KB
Java (javac)
时间限制
1500 ms
内存限制
128 MB
Python (python3)
时间限制
1500 ms
内存限制
64 MB
其他编译器
时间限制
500 ms
内存限制
64 MB
*/

/* 关键是对vector的处理，如何判定大小和重合，这里使用map来做，vector里如果是基本数据类型是可以比较
大小的，所以自动由小到大排列，并且还可以方便的对其数目进行增减，最后做成vector再对num进行一次
排序，注意选择稳定排序，除了num不同的元素外其他元素的相对位置都要保持稳定，最后输出 */

#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

struct Node {
    vector<int> output;
    int num = 0;
};

int n = 0, m = 0;
vector<Node> vec;
map<vector<int>, int> mp;

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        vector<int> tmp(m);
        for (int j = 0; j < m; j++)
            scanf("%d", &tmp[j]);

        mp[tmp]++;
    }

    for (const auto &e : mp) {
        vec.push_back({e.first, e.second});
    }

    stable_sort(vec.begin(), vec.end(), [](const Node &e1, const Node &e2) {
        return e1.num > e2.num;
    });

    printf("%zu\n", vec.size());
    for (const auto &e : vec) {
        printf("%d ", e.num);
        printf("%d", e.output[0]);
        for (int i = 1; i < m; i++)
            printf(" %d", e.output[i]);
        printf("\n");
    }

    return 0;
}