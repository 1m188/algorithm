# 现有村落间道路的统计数据表中，列出了有可能建设成标准公路的若干条道路的成本，
# 求使每个村落都有公路连通所需要的最低成本。

# 输入格式:
# 输入数据包括城镇数目正整数N（≤1000）和候选道路数目M（≤3N）；随后的M行对应M条道路，每行给出3个正整数，
# 分别是该条道路直接连通的两个城镇的编号以及该道路改建的预算成本。为简单起见，城镇从1到N编号。

# 输出格式:
# 输出村村通需要的最低成本。如果输入数据不足以保证畅通，则输出−1，表示需要建设更多公路。

# 输入样例:
# 6 15
# 1 2 5
# 1 3 3
# 1 4 7
# 1 5 4
# 1 6 2
# 2 3 4
# 2 4 6
# 2 5 2
# 2 6 6
# 3 4 6
# 3 5 1
# 3 6 1
# 4 5 10
# 4 6 8
# 5 6 3
# 输出样例:
# 12
# 代码长度限制
# 16 KB
# 时间限制
# 400 ms
# 内存限制
# 64 MB

# 最大值 表示无穷大 两点之间没有路径连通等
MAX_VAL = 2**32 - 1


class Solution:
    '''
    这个问题其实在问

    给你一个图 判断是否连通

    如果连通 求出其最小生成树的代价
    '''

    def input(self):
        '''
        处理输入
        '''

        self.N, self.M = map(int, input().split(' '))

        # 邻接矩阵 因为点多边少 而且后面要想加速访问顶点的话还是需要邻接矩阵
        self.graph = [[MAX_VAL for _ in range(self.N + 1)]
                      for _ in range(self.N + 1)]

        # 设置连通边权重
        for _ in range(self.M):
            v1, v2, c = map(int, input().split(' '))
            self.graph[v1][v2] = self.graph[v2][v1] = c

    def bfs(self) -> bool:
        '''
        bfs判断是否连通

        这里用dfs也可以
        '''

        flags = [False for _ in range(self.N + 1)]
        flags[1] = flags[0] = True
        que = [1]
        while que:
            v = que.pop(0)
            for i in range(1, self.N + 1):
                if self.graph[v][i] != MAX_VAL and not flags[i]:
                    flags[i] = True
                    que.append(i)

        return False if False in flags else True

    def prim(self):
        '''
        Prim算法求最小生成树

        这里使用prim算法是因为图的边数最多可以达到顶点数的3倍
        
        属于是稠密图

        而prim算法对于稠密图的效率高于kruskal算法
        '''

        self.cost = 0  # 最终代价
        vertexs = set()  # 已经加入最小生成树的顶点
        vertexs.add(1)  # 初始化  从第1个顶点开始往旁边走

        # 这里非常重要  保存当前最小生成树距离其他尚未加入最小生成树的顶点的最小直接距离
        # 用来加速对最小距离及顶点的选择
        # 没有这一段的话之后循环的时间复杂度将会达到O(N^2)，而使用了这个之后就只有O(N)

        # 索引  1,2...N  为顶点号，而数组在相应索引的值为距离
        dis = [MAX_VAL for _ in range(self.N + 1)]
        for i in range(1, self.N + 1):  # 对初始化的顶点计算到其他未加入的顶点的最小直接距离
            dis[i] = self.graph[1][i]

        # 由于最终肯定能够生成最小生成树，即所有顶点一定会加入最小生成树
        # （之前会已经用bfs/dfs进行连通检验）
        # 所以直到加入最小生成树的顶点数小于所有顶点数的时候都会进行prim算法的循环
        while len(vertexs) < self.N:

            # 这一段求出当前最小生成树到其他顶点的最小直接距离
            # 保存顶点号以及距离代价
            v = 1
            for i in range(1, self.N + 1):
                if dis[i] < dis[v]:
                    v = i
            c = dis[v]

            # 这一段将距离当前最小生成树距离最小的顶点加入最小生成树
            # 并且更新总代价
            vertexs.add(v)
            self.cost += c

            # 这一段也很重要  更新当前最小生成树到其他未加入最小生成树的顶点的最小直接距离
            dis[v] = MAX_VAL  # 首先将已加入到最小生成树内部的顶点的距离设为无穷大，表示最小生成树无法到达自己内部的节点
            for i in range(1, self.N + 1):  # 对最小距离中到每个顶点的距离进行更新

                # 这里很重要，主要的判断是对更新之后的最小生成树到其余各顶点的最小距离和之前旧的最小生成树到各顶点最小距离
                # 的比较，因为加入了一个新的顶点，旧的最小生成树到其余各顶点的最小直接距离，其实就是最小生成树上某个顶点
                # 到其余各顶点的最小直接距离，所以加入新的顶点之后，如果新的顶点到其他顶点的最小直接距离比之前的小，那么
                # 就更新为这个更小的值

                # 此外，由于在进行距离比较的时候，新的节点可以到达最小生成树的内部节点，所以还需要进行节点不在
                # 最小生成树中的判断，以防止更新到了一个更小的值从而让最小生成树可以达到自己的内部
                # 从而进入一个不断加入自己已有节点的死循环

                if i not in vertexs and dis[i] > self.graph[v][i]:
                    dis[i] = self.graph[v][i]


s = Solution()
s.input()
if not s.bfs():
    print(-1)
else:
    s.prim()
    print(s.cost)
