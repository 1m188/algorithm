/*

栈的顺序存储和链式存储

*/

#include "iostream"

/*****************************************************************************************************************/

// 顺序存储栈
template <typename T>
class ArrayStack
{
private:
    static const int len = 100;         // 栈最大元素个数
    T vec[len]{reinterpret_cast<T>(0)}; // 内部数组实现
    int idx = -1;                       // 栈顶指针索引

public:
    ArrayStack() = default;
    ArrayStack(const ArrayStack<T> &) = delete;
    ArrayStack<T> &operator=(const ArrayStack<T> &) = delete;
    ArrayStack(const ArrayStack<T> &&) = delete;
    ArrayStack<T> &operator=(const ArrayStack<T> &&) = delete;
    ~ArrayStack() = default;

    // 压栈
    bool push(const T &data);

    // 弹栈
    bool pop();

    // 获取栈顶元素
    const T &top() const;

    // 获取栈内元素数目
    int size() const;

    // 判断栈空
    bool isEmpty() const;
};

template <typename T>
bool ArrayStack<T>::push(const T &data)
{
    if (idx < len - 1)
    {
        vec[++idx] = data;
        return true;
    }
    return false;
}

template <typename T>
bool ArrayStack<T>::pop()
{
    if (idx > -1)
    {
        idx--;
        return true;
    }
    return false;
}

template <typename T>
const T &ArrayStack<T>::top() const
{
    return vec[idx];
}

template <typename T>
int ArrayStack<T>::size() const
{
    return idx + 1;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const
{
    return idx == -1;
}

/*****************************************************************************************************************/

// 链式存储栈
template <typename T>
class LinkStack
{
private:
    struct Node // 元素节点
    {
        T data = reinterpret_cast<T>(0);
        Node *next = nullptr;
    };
    struct Head // 头节点
    {
        int size = 0;
        Node *first = nullptr;
    };
    Head head;

public:
    LinkStack() = default;
    LinkStack(const LinkStack<T> &) = delete;
    LinkStack<T> &operator=(const LinkStack<T> &) = delete;
    LinkStack(const LinkStack<T> &&) = delete;
    LinkStack<T> &operator=(const LinkStack<T> &&) = delete;
    ~LinkStack();

    // 压栈
    bool push(const T &data);

    // 弹栈
    bool pop();

    // 获取栈顶元素
    const T &top() const;

    // 获取栈内元素数目
    int size() const;

    // 判断栈空
    bool isEmpty() const;
};

template <typename T>
LinkStack<T>::~LinkStack()
{
    Node *cur = head.first;
    head.first = nullptr;
    while (cur)
    {
        Node *tmp = cur->next;
        delete cur;
        cur = tmp;
    }
}

template <typename T>
bool LinkStack<T>::push(const T &data)
{
    Node *node = new Node;
    if (!node)
        return false;
    node->data = data;
    node->next = head.first;
    head.first = node;
    head.size++;
    return true;
}

template <typename T>
bool LinkStack<T>::pop()
{
    if (!head.first)
        return false;
    Node *tmp = head.first->next;
    delete head.first;
    head.first = tmp;
    head.size--;
    return true;
}

template <typename T>
const T &LinkStack<T>::top() const
{
    return head.first->data;
}

template <typename T>
int LinkStack<T>::size() const
{
    return head.size;
}

template <typename T>
bool LinkStack<T>::isEmpty() const
{
    return head.size == 0;
}

/*****************************************************************************************************************/

int main(int argc, char *argv[])
{
    ArrayStack<int> arrs;
    std::cout << "Array Stack\n";
    std::cout << "empty: " << arrs.isEmpty() << "  "
              << "size: " << arrs.size() << '\n';
    for (int i = 0; i < 5; i++)
        std::cout << "push result: " << arrs.push(i) << "  "
                  << "size: " << arrs.size() << "  "
                  << "empty: " << arrs.isEmpty() << '\n';
    std::cout << "top: " << arrs.top() << '\n';
    for (int i = 0; i < 3; i++)
        std::cout << "pop result: " << arrs.pop() << "  "
                  << "size: " << arrs.size() << "  "
                  << "empty: " << arrs.isEmpty() << '\n';
    std::cout << "top: " << arrs.top() << '\n';

    std::cout << std::endl;

    LinkStack<int> lnks;
    std::cout << "Link Stack\n";
    std::cout << "empty: " << lnks.isEmpty() << "  "
              << "size: " << lnks.size() << '\n';
    for (int i = 0; i < 5; i++)
        std::cout << "push result: " << lnks.push(i) << "  "
                  << "size: " << lnks.size() << "  "
                  << "empty: " << lnks.isEmpty() << '\n';
    std::cout << "top: " << lnks.top() << '\n';
    for (int i = 0; i < 3; i++)
        std::cout << "pop result: " << lnks.pop() << "  "
                  << "size: " << lnks.size() << "  "
                  << "empty: " << lnks.isEmpty() << '\n';
    std::cout << "top: " << lnks.top() << '\n';

    return 0;
}