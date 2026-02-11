#include "functional"
#include "iostream"
#include "queue"
#include "stack"

// 二叉树节点
template <typename T>
struct BinaryTreeNode
{
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode<T>(const T &d = reinterpret_cast<T>(0), BinaryTreeNode<T> *l = nullptr, BinaryTreeNode<T> *r = nullptr) : data(d), left(l), right(r) {}
};

// 删除二叉树
template <typename T>
void DelBinaryTree(BinaryTreeNode<T> *root)
{
    if (root)
    {
        DelBinaryTree(root->left);
        DelBinaryTree(root->right);
        delete root;
    }
}

//先序遍历
template <typename T>
void Preorder(BinaryTreeNode<T> *root, const std::function<void(BinaryTreeNode<T> *)> &visit)
{
    if (root)
    {
        visit(root);
        Preorder(root->left, visit);
        Preorder(root->right, visit);
    }
}

//中序遍历
template <typename T>
void Inorder(BinaryTreeNode<T> *root, const std::function<void(BinaryTreeNode<T> *)> &visit)
{
    if (root)
    {
        Inorder(root->left, visit);
        visit(root);
        Inorder(root->right, visit);
    }
}

//后序遍历
template <typename T>
void Postorder(BinaryTreeNode<T> *root, const std::function<void(BinaryTreeNode<T> *)> &visit)
{
    if (root)
    {
        Postorder(root->left, visit);
        Postorder(root->right, visit);
        visit(root);
    }
}

// 层序遍历
template <typename T>
void Levelorder(BinaryTreeNode<T> *root, const std::function<void(BinaryTreeNode<T> *)> &visit)
{
    if (!root)
        return;

    std::queue<BinaryTreeNode<T> *> que;
    que.push(root);
    while (!que.empty())
    {
        BinaryTreeNode<T> *n = que.front();
        que.pop();
        visit(n);
        if (n->left)
            que.push(n->left);
        if (n->right)
            que.push(n->right);
    }
}

// 非递归先序遍历
template <typename T>
void preorder_c(BinaryTreeNode<T> *root, const std::function<void(BinaryTreeNode<T> *)> &visit)
{
    std::stack<BinaryTreeNode<T> *> st;
    while (root || !st.empty())
        if (root)
        {
            visit(root);
            st.push(root);
            root = root->left;
        }
        else
        {
            root = st.top();
            st.pop();
            root = root->right;
        }
}

// 非递中归序遍历
template <typename T>
void inorder_c(BinaryTreeNode<T> *root, const std::function<void(BinaryTreeNode<T> *)> &visit)
{
    std::stack<BinaryTreeNode<T> *> st;
    while (root || !st.empty())
        if (root)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            root = st.top();
            st.pop();
            visit(root);
            root = root->right;
        }
}

// 非递归后序遍历
template <typename T>
void postorder_c(BinaryTreeNode<T> *root, const std::function<void(BinaryTreeNode<T> *)> &visit)
{
    std::stack<BinaryTreeNode<T> *> st;
    BinaryTreeNode<T> *t = nullptr;
    while (root || !st.empty())
        if (root)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            root = st.top();
            if (root->right && t != root->right)
                root = root->right;
            else
            {
                visit(root);
                st.pop();
                t = root;
                root = nullptr;
            }
        }
}

int main(int argc, char *argv[])
{
    /*

        1
       / \
      2   3
     /     \
    4       5

    */

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->right->right = new BinaryTreeNode<int>(5);

    const std::function<void(BinaryTreeNode<int> *)> visit = [](BinaryTreeNode<int> *bn) { std::cout << bn->data << ' '; };

    Preorder(root, visit);
    std::cout << '\n';
    Inorder(root, visit);
    std::cout << '\n';
    Postorder(root, visit);
    std::cout << '\n';
    Levelorder(root, visit);
    std::cout << '\n';

    std::cout << '\n';

    preorder_c(root, visit);
    std::cout << '\n';
    inorder_c(root, visit);
    std::cout << '\n';
    postorder_c(root, visit);
    std::cout << '\n';

    DelBinaryTree(root);

    return 0;
}