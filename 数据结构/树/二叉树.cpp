#include "iostream"

template <typename T>
struct BinaryTreeNode //一个糟糕的节点，一颗平衡二叉树
{
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    explicit BinaryTreeNode<T>() : data(reinterpret_cast<T>(0)), left(nullptr), right(nullptr) {}
};

template <typename T>
BinaryTreeNode<T> *CreateBinaryTree(int deep)
{
    if (deep < 0)
    {
        return nullptr;
    }
    else
    {
        T value = reinterpret_cast<T>(0);
        std::cin >> value;
        BinaryTreeNode<T> *node = new BinaryTreeNode<T>();
        node->data = value;
        node->left = CreateBinaryTree<T>(deep - 1);
        node->right = CreateBinaryTree<T>(deep - 1);
        return node;
    }
}

template <typename T>
void DelBinaryTree(BinaryTreeNode<T> *root)
{
    if (root)
    {
        DelBinaryTree(root->left);
        DelBinaryTree(root->right);
        delete root;
        delete root;
    }
}

template <typename T>
void Preorder(BinaryTreeNode<T> *root) //先序遍历
{
    if (root)
    {
        std::cout << root->data << '\t';
        Preorder(root->left);
        Preorder(root->right);
    }
}

template <typename T>
void Inorder(BinaryTreeNode<T> *root) //中序遍历
{
    if (root)
    {
        Inorder(root->left);
        std::cout << root->data << '\t';
        Inorder(root->right);
    }
}

template <typename T>
void Postorder(BinaryTreeNode<T> *root) //后序遍历
{
    if (root)
    {
        Postorder(root->left);
        Postorder(root->right);
        std::cout << root->data << '\t';
    }
}