#include "functional"
#include "queue"

// 二叉树节点
template <typename T>
struct BinaryTreeNode
{
    T data = reinterpret_cast<T>(0);
    BinaryTreeNode<T> *left = nullptr;
    BinaryTreeNode<T> *right = nullptr;
};

// 递归创建满二叉树
template <typename T>
BinaryTreeNode<T> *CreateBinaryTree(int deep)
{
    if (deep <= 0)
        return nullptr;

    BinaryTreeNode<T> *node = new BinaryTreeNode<T>();
    node->left = CreateBinaryTree<T>(deep - 1);
    node->right = CreateBinaryTree<T>(deep - 1);
    return node;
}

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
        Preorder(root->left);
        Preorder(root->right);
    }
}

//中序遍历
template <typename T>
void Inorder(BinaryTreeNode<T> *root, const std::function<void(BinaryTreeNode<T> *)> &visit)
{
    if (root)
    {
        Inorder(root->left);
        visit(root);
        Inorder(root->right);
    }
}

//后序遍历
template <typename T>
void Postorder(BinaryTreeNode<T> *root, const std::function<void(BinaryTreeNode<T> *)> &visit)
{
    if (root)
    {
        Postorder(root->left);
        Postorder(root->right);
        visit(root);
    }
}

// 层序遍历
template <typename T>
void Layerorder(BinaryTreeNode<T> *root, const std::function<void(BinaryTreeNode<T> *)> &visit)
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