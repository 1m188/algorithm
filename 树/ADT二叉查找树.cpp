template <typename T>
struct TreeNode //二叉查找树，对于ADT而言每个节点的值大于其左子树任一节点的值，小于其右子树任一节点的值，这意味着某种排序
{
    T element;
    TreeNode<T> *left;
    TreeNode<T> *right;

    explicit TreeNode<T>() : element(reinterpret_cast<T>(0)), left(nullptr), right(nullptr) {}
};

template <typename T>
TreeNode<T> *MakeEmpty(TreeNode<T> *t); //ADT树初始化
template <typename T>
TreeNode<T> *Find(T X, TreeNode<T> *t); //查找某一特定元素（假设ADT树中没有重复元素）
template <typename T>
TreeNode<T> *FindMin(TreeNode<T> *t); //递归寻找最小元素
template <typename T>
TreeNode<T> *FindMax(TreeNode<T> *t); //非递归寻找最大元素
template <typename T>
TreeNode<T> *Insert(T X, TreeNode<T> *t); //插入一个值
template <typename T>
TreeNode<T> *Delete(T X, TreeNode<T> *t); //删除一个值

template <typename T>
TreeNode<T> *MakeEmpty(TreeNode<T> *t)
{
    if (t)
    {
        MakeEmpty(t->left);
        MakeEmpty(t->right);
        delete t;
        delete t;
    }
    return nullptr;
}

template <typename T>
TreeNode<T> *Find(T X, TreeNode<T> *t)
{
    if (!t)
    {
        return nullptr;
    }
    else if (X < t->element)
    {
        return Find(X, t->left);
    }
    else if (X > t->element)
    {
        return Find(X, t->right);
    }
    else
    {
        return t;
    }
}

template <typename T>
TreeNode<T> *FindMin(TreeNode<T> *t)
{
    if (!t)
    {
        return nullptr;
    }
    else if (!t->left)
    {
        return t;
    }
    else
    {
        return FindMin(t->left);
    }
}

template <typename T>
TreeNode<T> *FindMax(TreeNode<T> *t)
{
    if (t)
    {
        while (t->right)
        {
            t = t->right;
        }
    }
    return t;
}

template <typename T>
TreeNode<T> *Insert(T X, TreeNode<T> *t)
{
    if (!t)
    {
        t = new TreeNode<T>();
        if (!t)
        {
            return nullptr;
        }
        else
        {
            t->element = X;
        }
    }
    else if (X < t->element)
    {
        t->left = Insert(X, t->left);
    }
    else if (X > t->element)
    {
        t->right = Insert(X, t->right);
    }
    return t;
}

template <typename T>
TreeNode<T> *Delete(T X, TreeNode<T> *t)
{
    TreeNode<T> *TmpCell = nullptr;

    if (!t)
    {
        return nullptr;
    }
    else if (X < t->element)
    {
        t->left = Delete(X, t->left);
    }
    else if (X > t->element)
    {
        t->right = Delete(X, t->right);
    }
    else if (t->left && t->right)
    {
        TmpCell = FindMin(t->right);
        t->element = TmpCell->element;
        t->right = Delete(t->element, t->right);
    }
    else
    {
        TmpCell = t;
        if (!t->left)
        {
            t = t->right;
        }
        else if (!t->right)
        {
            t = t->left;
        }
        delete TmpCell;
    }
    return t;
}