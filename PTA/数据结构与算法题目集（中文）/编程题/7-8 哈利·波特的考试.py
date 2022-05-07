# 哈利·波特要考试了，他需要你的帮助。这门课学的是用魔咒将一种动物变成另一种动物的本事。
# 例如将猫变成老鼠的魔咒是haha，将老鼠变成鱼的魔咒是hehe等等。
# 反方向变化的魔咒就是简单地将原来的魔咒倒过来念，例如ahah可以将老鼠变成猫。
# 另外，如果想把猫变成鱼，可以通过念一个直接魔咒lalala，也可以将猫变老鼠、老鼠变鱼的魔咒连起来念：hahahehe。

# 现在哈利·波特的手里有一本教材，里面列出了所有的变形魔咒和能变的动物。
# 老师允许他自己带一只动物去考场，要考察他把这只动物变成任意一只指定动物的本事。
# 于是他来问你：带什么动物去可以让最难变的那种动物（即该动物变为哈利·波特自己带去的动物所需要的魔咒最长）需要的魔咒最短？
# 例如：如果只有猫、鼠、鱼，则显然哈利·波特应该带鼠去，因为鼠变成另外两种动物都只需要念4个字符；
# 而如果带猫去，则至少需要念6个字符才能把猫变成鱼；同理，带鱼去也不是最好的选择。

# 输入格式:
# 输入说明：输入第1行给出两个正整数N (≤100)和M，其中N是考试涉及的动物总数，M是用于直接变形的魔咒条数。为
# 简单起见，我们将动物按1~N编号。
# 随后M行，每行给出了3个正整数，分别是两种动物的编号、以及它们之间变形需要的魔咒的长度(≤100)，数字之间用空格分隔。

# 输出格式:
# 输出哈利·波特应该带去考场的动物的编号、以及最长的变形魔咒的长度，中间以空格分隔。
# 如果只带1只动物是不可能完成所有变形要求的，则输出0。如果有若干只动物都可以备选，则输出编号最小的那只。

# 输入样例:
# 6 11
# 3 4 70
# 1 2 1
# 5 4 50
# 2 6 50
# 5 6 60
# 1 3 70
# 4 6 60
# 3 6 80
# 5 1 100
# 2 4 60
# 5 2 80

# 输出样例:
# 4 70

# 代码长度限制
# 16 KB

# 时间限制
# 400 ms

# 内存限制
# 64 MB
'''
这个问题事实上在问：

给出一个图，是否连通？

如果连通，求出每一个点到其他点的最短路径，取其中的最大值，求这些最大值中的最小值及相应的起始顶点
'''


def init():
    '''
    初始化

    处理输入，设置全局的一些变量，无穷大定义等
    '''

    global N, M, graph, INF

    INF = float('inf')  # 无穷大定义

    N, M = map(int, input().split(' '))  # 顶点数目和边数目输入

    # 图 邻接矩阵
    graph = [[INF for _ in range(N + 1)] for _ in range(N + 1)]
    for i in range(1, N + 1):
        graph[i][i] = 0  # 定义自己到自己的距离为0

    # 初始化边权值
    for _ in range(M):
        v1, v2, c = map(int, input().split(' '))
        graph[v1][v2] = graph[v2][v1] = c


def bfs() -> bool:
    '''
    bfs/dfs 判断图是否连通
    '''

    que = [1]
    fs = [False for _ in range(N + 1)]
    fs[0] = fs[1] = True

    while que:
        v = que.pop(0)
        for i in range(1, N + 1):
            if graph[v][i] != INF and not fs[i]:
                fs[i] = True
                que.append(i)

    return False if False in fs else True


def dijkstra():
    '''
    dijkstra算法求单源最短路径

    由于要对每个顶点都使用一遍，因此用Floyd算法也可以
    '''

    num, length = 0, INF  # 最终结果，最小的边权值及相应起始顶点

    # 对每个顶点进行，轮流将每个顶点当作起始顶点运行算法
    for sp in range(1, N + 1):

        dist = graph[sp].copy()  # 当前起始顶点到其他顶点的最小路径
        s = set([sp])  # 已经处理的顶点

        while len(s) < N:  # 直到所有顶点被处理

            # 从不在已被处理的顶点中找出所有的顶点和起始顶点到该顶点的最小路径
            notins = [(i, dist[i]) for i in range(1, N + 1) if i not in s]

            # 取其中的最小路径的终点顶点
            v, _ = min(notins, key=lambda x: x[1])

            # 加入已被处理顶点中
            s.add(v)

            # 更新最短路径
            # 对于刚刚被加入的已处理顶点v而言，对于所有其他没有被处理的顶点i，
            # 如果起始顶点到v的路径长+从v到i的路径长小于从v直接到i的路径长，
            # 那么更新从v到i的路径长为更小的那个
            # 这里由于只涉及到起始顶点，v和i，对于其他的未涉及和未被处理的顶点无关
            # 故可以直接更新
            for i in range(1, N + 1):
                if i not in s and dist[v] + graph[v][i] < dist[i]:
                    dist[i] = dist[v] + graph[v][i]

        # 这一段找出所有最短路径中最大的那个，然后对比当前的结果，
        # 求出最大值里更小的那个
        mi = 1
        for i in range(1, N + 1):
            if dist[i] > dist[mi]: mi = i
        if dist[mi] < length:
            length = dist[mi]
            num = sp

    return num, length


if __name__ == "__main__":

    init()

    if not bfs():
        print(0)
    else:
        a, b = dijkstra()
        print(f"{a} {b}")
