#include "cstdio"
#include "cstring"

const int maxn = 100 + 5;

int n, m, t, G[maxn][maxn], c[maxn], topo[maxn];

bool dfs(int u)
{
    c[u] = -1;
    for (int v = 1; v <= n; v++)
    {
        if (G[u][v])
        {
            if (c[v] < 0)
            {
                return false;
            }
            else if (!c[v] && !dfs(v))
            {
                return false;
            }
        }
    }
    c[u] = 1;
    topo[--t] = u;
    return true;
}

bool toposort()
{
    t = n;
    memset(c, 0, sizeof(c));
    for (int u = 0; u < n; u++)
    {
        if (!c[u])
        {
            if (!dfs(u))
            {
                return false;
            }
        }
    }
    return true;
}

int main() //拓扑排序？
{
    while (scanf("%d%d", &n, &m) == 2 && n)
    {
        memset(G, 0, sizeof(G));
        for (int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u][v] = 1;
        }
        toposort();
        printf("%d", topo[0]);
        for (int i = 1; i < n; i++)
        {
            printf(" %d", topo[i]);
        }
        printf("\n");
    }

    return 0;
}