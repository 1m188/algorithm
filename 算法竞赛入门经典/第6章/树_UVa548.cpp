#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"

struct Node //构造树的节点信息
{
    int num;
    Node *left, *right;

    Node() : num(0), left(nullptr), right(nullptr) {}
};
Node *initTree(std::vector<int> &inOrder, std::vector<int> &postOrder); //递归根据中序遍历和后序遍历构造树
Node *findMin(Node *head, int initRight = 0, int layers = 0);           //返回一个指向它到根的路径上的权和最小的叶子的指针
void Del(Node *head);                                                   //后序遍历递归释放内存

int main()
{
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);
    while (true) //处理输入，这里每次输入两行，用空格隔开，然后把字符串转为数字
    {
        std::vector<int> inOrder{}, postOrder{};
        std::string input{};
        for (int i = 0; i < 2; i++)
        {
            std::getline(std::cin, input);
            input += ' ';
            std::string temp{};
            for (char c : input)
            {
                if (c != ' ')
                {
                    temp += c;
                }
                else
                {
                    int num = 0;
                    for (int j = temp.size() - 1; j >= 0; j--)
                    {
                        num += (temp[j] - '0') * pow(10, temp.size() - 1 - j);
                    }
                    temp.clear();
                    if (i == 0)
                    {
                        inOrder.push_back(num);
                    }
                    else
                    {
                        postOrder.push_back(num);
                    }
                }
            }
        }
        Node *head = initTree(inOrder, postOrder);
        Node *node = findMin(head);
        std::cout << node->num << std::endl;
        Del(head);
    }

    return 0;
}

Node *initTree(std::vector<int> &inOrder, std::vector<int> &postOrder) //根据后序遍历首先确定根的值，之后在两种遍历中找到根的两个子树的两种遍历，递归反复进行，直到两种遍历中没有元素，说明这个元素是叶子
{
    Node *head = new Node();
    head->num = postOrder.back();
    if (inOrder.size() <= 1 && postOrder.size() <= 1)
    {
        return head;
    }
    else
    {
        std::vector<int> in{}, po{};
        for (std::vector<int>::iterator it = std::find(inOrder.begin(), inOrder.end(), postOrder.back()) + 1; it != inOrder.end(); it++)
        {
            in.push_back(*it);
        }
        for (int i = postOrder.size() - 1 - in.size(); i < postOrder.size() - 1; i++)
        {
            po.push_back(postOrder[i]);
        }
        if (in.size() >= 1 && po.size() >= 1)
        {
            head->right = initTree(in, po);
        }

        in.clear();
        po.clear();
        for (std::vector<int>::iterator it = std::find(inOrder.begin(), inOrder.end(), postOrder.back()) - 1; it >= inOrder.begin(); it--)
        {
            in.push_back(*it);
        }
        std::reverse(in.begin(), in.end());
        for (int i = 0; i < in.size(); i++)
        {
            po.push_back(postOrder[i]);
        }
        if (in.size() >= 1 && po.size() >= 1)
        {
            head->left = initTree(in, po);
        }
        return head;
    }
}

Node *findMin(Node *head, int initRight, int layers) //一边统计一边比较最小值
{
    static int minRight = 100000000;
    static Node *minNode = nullptr;
    if (layers == 0) //这里注意为了每次的结果不受到上一次的影响，这里初始化一遍
    {
        minRight = 100000000;
        minNode = nullptr;
    }

    initRight += head->num;
    if (head->left || head->right)
    {
        if (head->left)
        {
            minNode = findMin(head->left, initRight, layers + 1);
        }
        if (head->right)
        {
            minNode = findMin(head->right, initRight, layers + 1);
        }
    }
    else
    {
        if (minRight > initRight)
        {
            minNode = head;
            minRight = initRight;
        }
        else if (minRight == initRight)
        {
            if (minNode != nullptr)
            {
                minNode = minNode->num < head->num ? minNode : head;
            }
            else
            {
                minNode = head;
            }
        }
    }
    return minNode;
}

void Del(Node *head)
{
    if (head->left)
    {
        Del(head->left);
    }
    if (head->right)
    {
        Del(head->right);
    }
    delete head;
}