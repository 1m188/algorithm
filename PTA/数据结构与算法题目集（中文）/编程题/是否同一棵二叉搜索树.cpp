/*
7-4 是否同一棵二叉搜索树 （25 分）
给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。

输入格式:

输入包含若干组测试数据。每组数据的第1行给出两个正整数N (≤10)和L，分别是每个序列插入元素的个数和需要检查的序列个数。第2行给出N个以空格分隔的正整数，作为初始插入序列。最后L行，每行给出N个插入的元素，属于L个需要检查的序列。

简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，这组数据不要处理。

输出格式:

对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。

输入样例:

4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
输出样例:

Yes
No
No
*/

#include "iostream"

//树节点定义
struct Node
{
    int val;
    Node *left;
    Node *right;

    Node() : val(0), left(nullptr), right(nullptr) {}
};

//插入
Node *insert(Node *root, int val)
{
    if (!root)
    {
        root = new Node();
        root->val = val;
    }
    else
    {
        if (val < root->val)
        {
            root->left = insert(root->left, val);
        }
        else if (val > root->val)
        {
            root->right = insert(root->right, val);
        }
    }
    return root;
}

//传入根节点，删除整个树
void del(Node *root)
{
    if (root)
    {
        del(root->left);
        del(root->right);
        delete root;
    }
}

//传入两个树的根节点，比较两个树是否相等
bool compare(Node *r1, Node *r2)
{
    if (r1 && r2)
    {
        if (r1->val == r2->val)
        {
            bool b1 = compare(r1->left, r2->left), b2 = compare(r1->right, r2->right);
            return b1 && b2;
        }
        else
        {
            return false;
        }
    }
    else if (!r1 && !r2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int N = 0;
    while (std::cin >> N && N)
    {
        int L = 0;
        std::cin >> L;

        Node *origin = nullptr;
        for (int i = 0; i < N; i++)
        {
            int temp = 0;
            std::cin >> temp;
            origin = insert(origin, temp); //这里和下面的待判断的树的插入操作记得要拿原来的变量接着
        }

        for (int i = 0; i < L; i++)
        {
            Node *example = nullptr;
            for (int i = 0; i < N; i++)
            {
                int temp = 0;
                std::cin >> temp;
                example = insert(example, temp);
            }
            if (compare(origin, example))
            {
                std::cout << "Yes\n";
            }
            else
            {
                std::cout << "No\n";
            }
            del(example);
        }
        del(origin);
    }

    return 0;
}