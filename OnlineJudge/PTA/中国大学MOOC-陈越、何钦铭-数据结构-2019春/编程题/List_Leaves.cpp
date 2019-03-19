/*
03-树2 List Leaves （25 分)
Given a tree, you are supposed to list all the leaves in the order of top down, and left to right.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (≤10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1. Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.

Output Specification:

For each test case, print in one line all the leaves' indices in the order of top down, and left to right. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

Sample Input:

8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:

4 1 5
*/

#include "iostream"
#include "vector"
#include "queue"

int main()
{
    int N = 0;
    std::cin >> N;
    std::vector<std::pair<int, int>> vec(N);
    for (int i = 0; i < N; i++)
    {
        char a = '\0', b = '\0';
        std::cin >> a >> b;
        vec[i].first = a == '-' ? -1 : a - '0';
        vec[i].second = b == '-' ? -1 : b - '0';
    }

    std::vector<bool> is(N);
    for (const auto &p : vec)
    {
        if (p.first != -1)
        {
            is[p.first] = true;
        }
        if (p.second != -1)
        {
            is[p.second] = true;
        }
    }

    int root = 0;
    for (int i = 0; i < N; i++)
    {
        if (!is[i])
        {
            root = i;
            break;
        }
    }

    std::vector<int> leaves;
    std::queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        bool flag = false;
        if (vec[n].first != -1)
        {
            q.push(vec[n].first);
            flag = true;
        }
        if (vec[n].second != -1)
        {
            q.push(vec[n].second);
            flag = true;
        }
        if (!flag)
        {
            leaves.push_back(n);
        }
    }

    int size = leaves.size();
    for (int i = 0; i < size; i++)
    {
        std::cout << leaves[i];
        if (i != size - 1)
        {
            std::cout << ' ';
        }
    }

    return 0;
}