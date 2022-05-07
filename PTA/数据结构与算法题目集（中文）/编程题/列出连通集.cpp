/*
7-6 列出连通集 （25 分）
给定一个有N个顶点和E条边的无向图，请用DFS和BFS分别列出其所有的连通集。假设顶点从0到N−1编号。进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。

输入格式:

输入第1行给出2个整数N(0<N≤10)和E，分别是图的顶点数和边数。随后E行，每行给出一条边的两个端点。每行中的数字之间用1空格分隔。

输出格式:

按照"{ v
​1
​​  v
​2
​​  ... v
​k
​​  }"的格式，每行输出一个连通集。先输出DFS的结果，再输出BFS的结果。

输入样例:

8 6
0 7
0 1
2 0
4 1
2 4
3 5
输出样例:

{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }
{ 0 1 2 7 4 }
{ 3 5 }
{ 6 }
*/

//自己没想出来，还是靠着网上的思路写的。用一个二维数组保存图，用小的数来索引大的对象，对列遍历，通过对每一个行的对应元素的状态判断是否是下一个节点，
//而且每次遍历都是从小到大，也顺便解决了从小到大输出的要求

#include "iostream"
#include "queue"
#include "vector"

int N = 0, E = 0;
std::vector<std::vector<bool>> map;
std::vector<bool> is;

//递归的dfs
void dfs(int num = 0)
{
    std::cout << ' ' << num;
    for (int i = 0; i < N; i++)
    {
        if (!is[i] && map[num][i])
        {
            is[i] = true;
            dfs(i);
        }
    }
}

//常规队列bfs
void bfs(int num)
{
    std::queue<int> q;
    q.push(num);
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        std::cout << ' ' << n;
        for (int i = 0; i < N; i++)
        {
            if (!is[i] && map[n][i])
            {
                is[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    std::cin >> N >> E;
    map.resize(N, std::vector<bool>(N, false));
    is.resize(N, false);
    for (int i = 0; i < E; i++)
    {
        int x = 0, y = 0;
        std::cin >> x >> y;
        map[x][y] = map[y][x] = true;
    }

    for (int i = 0; i < N; i++)
    {
        if (!is[i])
        {
            is[i] = true;
            std::cout << "{";
            dfs(i);
            std::cout << " }\n";
        }
    }
    is.assign(N, false);

    for (int i = 0; i < N; i++)
    {
        if (!is[i])
        {
            is[i] = true;
            std::cout << "{";
            bfs(i);
            std::cout << " }\n";
        }
    }

    return 0;
}