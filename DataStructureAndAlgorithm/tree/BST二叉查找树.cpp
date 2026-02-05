/*

Binary Search Tree - BST

二叉查找树BST，对于BST而言每个节点的值大于其左子树任一节点的值，小于其右子树任一节点的值，这意味着某种排序

*/

// 二叉查找树节点
template <typename T>
struct TreeNode
{
    T element = reinterpret_cast<T>(0);
    TreeNode<T> *left = nullptr;
    TreeNode<T> *right = nullptr;
};

// 删除一颗二叉查找树
template <typename T>
void MakeEmpty(TreeNode<T> *&t)
{
    if (t)
    {
        MakeEmpty(t->left);
        MakeEmpty(t->right);
        delete t;
        t = nullptr;
    }
}

// 查找某个值所在节点
template <typename T>
TreeNode<T> *Find(const T &X, TreeNode<T> *t)
{
    if (!t)
        return nullptr;

    if (X < t->element)
        return Find(X, t->left);
    else if (X > t->element)
        return Find(X, t->right);
    else
        return t;
}

// 查找最小值所在节点
template <typename T>
TreeNode<T> *FindMin(TreeNode<T> *t)
{
    if (!t)
        return nullptr;

    return !t->left ? t : FindMin(t->left);
}

// 查找最大值所在节点
template <typename T>
TreeNode<T> *FindMax(TreeNode<T> *t)
{
    if (t)
        while (t->right)
            t = t->right;
    return t;
}

// 插入一个值
template <typename T>
TreeNode<T> *Insert(const T &X, TreeNode<T> *t)
{
    if (!t)
    {
        t = new TreeNode<T>;
        if (!t)
            return nullptr;
        else
            t->element = X;
    }
    else if (X < t->element)
        t->left = Insert(X, t->left);
    else if (X > t->element)
        t->right = Insert(X, t->right);
    return t;
}

// 删除一个值
template <typename T>
TreeNode<T> *Delete(const T &X, TreeNode<T> *t)
{
    if (!t)
        return nullptr;
    else if (X < t->element)
        t->left = Delete(X, t->left);
    else if (X > t->element)
        t->right = Delete(X, t->right);
    else if (t->left && t->right)
    {
        TreeNode<T> *TmpCell = FindMin(t->right);
        t->element = TmpCell->element;
        t->right = Delete(TmpCell->element, t->right);
    }
    else
    {
        TreeNode<T> *TmpCell = t;
        t = t->left ? t->left : t->right;
        delete TmpCell;
    }
    return t;
}