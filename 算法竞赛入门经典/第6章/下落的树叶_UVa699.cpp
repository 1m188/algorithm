#include "iostream"
#include "vector"

void build(int p, std::vector<int> &tree);

int main()
{
    int kase = 0;
    while (true)
    {
        std::vector<int> tree(10000, 0);
        build(tree.size() / 2, tree);
        if (tree == std::vector<int>(10000, 0))
        {
            break;
        }
        else
        {
            std::cout << "Case " << ++kase << ':' << std::endl;
            for (int i : tree)
            {
                if (i != 0)
                {
                    std::cout << i << ' ';
                }
            }
            std::cout << std::endl
                      << std::endl;
        }
    }

    return 0;
}

void build(int p, std::vector<int> &tree)
{
    int v = 0;
    std::cin >> v;
    if (v != -1)
    {
        tree[p] += v;       //将每次位置相同的节点的值加在一起，所以用一维的数组
        build(p - 1, tree); //由于是先序输入，所以是先递归左边的子节点
        build(p + 1, tree);
    }
}