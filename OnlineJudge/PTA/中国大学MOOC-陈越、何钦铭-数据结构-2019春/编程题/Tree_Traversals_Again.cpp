/*
03-树3 Tree Traversals Again （25 分)
An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is to give the postorder traversal sequence of this tree.


Figure 1
Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (≤30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.

Output Specification:

For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:

6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:

3 4 2 6 5 1
*/

#include "iostream"
#include "vector"
#include "stack"
#include "string"

//树的节点
struct Node
{
    int data;
    Node *father;
    Node *left;
    Node *right;

    Node() : data(0), father(nullptr), left(nullptr), right(nullptr) {}
};
Node *head = nullptr, *cursor = nullptr;

//push和pop的栈
std::stack<Node *> s;
//后序遍历所使用的数组
std::vector<int> po;

//释放资源
void deleteTree(Node *root)
{
    if (root)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

//获取后续遍历数据顺序
void postOrder(Node *root)
{
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        po.push_back(root->data);
    }
}

//先构建树，之后后序遍历，之后释放资源，最后输出

int main()
{
    int N = 0;
    std::cin >> N;
    for (int i = 0; i < 2 * N; i++)
    {
        std::string str;
        std::cin >> str;
        if (str == "Push")
        {
            int n = 0;
            std::cin >> n;
            if (!cursor)
            {
                cursor = new Node();
                cursor->data = n;
                head = cursor;
            }
            else
            {
                if (!cursor->left)
                {
                    cursor->left = new Node();
                    cursor->left->data = n;
                    cursor->left->father = cursor;
                    cursor = cursor->left;
                }
                else
                {
                    cursor->right = new Node();
                    cursor->right->data = n;
                    cursor->right->father = cursor;
                    cursor = cursor->right;
                }
            }
            s.push(cursor);
        }
        else
        {
            cursor = s.top();
            s.pop();
        }
    }

    postOrder(head);

    deleteTree(head);

    std::cout << po[0];
    int size = po.size();
    for (int i = 1; i < size; i++)
    {
        std::cout << ' ' << po[i];
    }

    return 0;
}