template <typename T>
struct AvlNode //AVL树，带有平衡条件的查找二叉树，此为简单实现
{
    T element;
    AvlNode<T> *left;
    AvlNode<T> *right;
    int Height;

    explicit AvlNode<T>() : element(reinterpret_cast<T>(0)), left(nullptr), right(nullptr), Height(0) {}
};

template <typename T>
AvlNode<T> *MakeEmpty(AvlNode<T> *t); //初始化
template <typename T>
AvlNode<T> *Find(T X, AvlNode<T> *t); //查找某个值
template <typename T>
AvlNode<T> *FindMin(AvlNode<T> *t); //查找最小的一个值
template <typename T>
AvlNode<T> *FindMax(AvlNode<T> *t); //查找最大的一个值
template <typename T>
AvlNode<T> *Insert(T X, AvlNode<T> *t); //插入一个值
template <typename T>
AvlNode<T> *Delete(T x, AvlNode<T> *t); //删除一个值
template <typename T>
static int Height(AvlNode<T> *t); //返回该节点的深度
template <typename T>
static AvlNode<T> *SingleRotateWithLeft(AvlNode<T> *K2); //单旋转
template <typename T>
static AvlNode<T> *DoubleRotateWithLeft(AvlNode<T> *K3); //双旋转

template <typename T>
AvlNode<T> *MakeEmpty(AvlNode<T> *t)
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
AvlNode<T> *Find(T X, AvlNode<T> *t)
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
AvlNode<T> *FindMin(AvlNode<T> *t)
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
AvlNode<T> *FindMax(AvlNode<T> *t)
{
    if (!t)
    {
        return nullptr;
    }
    else if (!t->right)
    {
        return t;
    }
    else
    {
        return FindMax(t->right);
    }
}

template <typename T>
AvlNode<T> *Insert(T X, AvlNode<T> *t)
{
    if (!t)
    {
        t = new AvlNode<T>();
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
        if (Height(t->left) - Height(t->right) == 2)
        {
            if (X < t->left->element)
            {
                t = SingleRotateWithLeft(t);
            }
            else
            {
                t = DoubleRotateWithLeft(t);
            }
        }
    }
    else if (X > t->element)
    {
        t->right = Insert(X, t->right);
        if (Height(t->right) - Height(t->left) == 2)
        {
            if (X > t->right->element)
            {
                t = SingleRotateWithLeft(t);
            }
            else
            {
                t = DoubleRotateWithLeft(t);
            }
        }
    }
    t->Height = Height(t->left) > Height(t->right) ? Height(t->left) : Height(t->right) + 1;
    return t;
}

template <typename T>
AvlNode<T> *Delete(T X, AvlNode<T> *t)
{
    AvlNode<T> *TmpCell = nullptr;

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

template <typename T>
static int Height(AvlNode<T> *t)
{
    if (!t)
    {
        return -1;
    }
    else
    {
        return t->Height;
    }
}

template <typename T>
static AvlNode<T> *SingleRotateWithLeft(AvlNode<T> *K2)
{
    AvlNode<T> *K1 = nullptr;

    K1 = K2->left;
    K2->left = K1->right;
    K1->right = K2;

    K2->Height = Height(K2->left) > Height(K2->right) ? Height(K2->left) : Height(K2->right) + 1;
    K1->Height = Height(K1->left) > Height(K1->right) ? Height(K1->left) : Height(K1->right) + 1;

    return K1;
}

template <typename T>
static AvlNode<T> *DoubleRotateWithLeft(AvlNode<T> *K3)
{
    K3->left = SingleRotateWithLeft(K3->left);
    return SingleRotateWithLeft(K3);
}