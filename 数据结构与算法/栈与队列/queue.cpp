/*

队列的顺序存储实现和链式存储实现

*/

#include "iostream"

/********************************************************************************************************************/

// 数组循环队列
template <typename T>
class ArrayQueue
{
private:
    static const int arrLen = 100;         // 数组长度
    int front = 0, rear = 0;               // 队列头尾指针索引
    T vec[arrLen]{reinterpret_cast<T>(0)}; // 队列内部数组实现

public:
    ArrayQueue() = default;
    ArrayQueue(const ArrayQueue<T> &q) = delete;
    ArrayQueue<T> &operator=(const ArrayQueue<T> &q) = delete;
    ArrayQueue(const ArrayQueue<T> &&q) = delete;
    ArrayQueue<T> &operator=(const ArrayQueue<T> &&q) = delete;
    ~ArrayQueue() = default;

    // 入队
    bool push(const T &data);

    // 出队
    bool pop();

    // 获取头部元素
    const T &get() const;

    // 判断队列是否为空
    bool isEmpty() const;

    // 获取队列元素个数
    int size() const;
};

template <typename T>
bool ArrayQueue<T>::push(const T &data)
{
    int idx = (rear + 1) % arrLen;
    if (idx != front)
    {
        rear = idx;
        vec[rear] = data;
        return true;
    }
    else
        return false;
}

template <typename T>
bool ArrayQueue<T>::pop()
{
    if (front != rear)
    {
        front = (front + 1) % arrLen;
        return true;
    }
    else
        return false;
}

template <typename T>
const T &ArrayQueue<T>::get() const
{
    return vec[(front + 1) % arrLen];
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const
{
    return front == rear;
}

template <typename T>
int ArrayQueue<T>::size() const
{
    return (rear - front + arrLen) % arrLen;
}

/********************************************************************************************************************/

// 链表队列
template <typename T>
class LinkQueue
{
private:
    struct Node // 节点
    {
        T data = reinterpret_cast<T>(0);
        Node *next = nullptr;
    };
    struct Head // 头部节点
    {
        int size = 0;          // 队列元素个数
        Node *first = nullptr; // 队头
    };
    Head head;
    Node *front = nullptr, *rear = nullptr;

public:
    LinkQueue() = default;
    LinkQueue(const LinkQueue<T> &q) = delete;
    LinkQueue<T> &operator=(const LinkQueue<T> &q) = delete;
    LinkQueue(const LinkQueue<T> &&q) = delete;
    LinkQueue<T> &operator=(const LinkQueue<T> &&q) = delete;
    ~LinkQueue();

    // 入队
    bool push(const T &data);

    // 出队
    bool pop();

    // 获取头部元素
    const T &get() const;

    // 判断队列是否为空
    bool isEmpty() const;

    // 获取队列元素个数
    int size() const;
};

template <typename T>
LinkQueue<T>::~LinkQueue()
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
bool LinkQueue<T>::push(const T &data)
{
    Node *node = new Node;
    if (!node)
        return false;
    node->data = data;
    node->next = nullptr;
    if (isEmpty())
        front = rear = head.first = node;
    else
        rear = rear->next = node;
    head.size++;
    return true;
}

template <typename T>
bool LinkQueue<T>::pop()
{
    if (isEmpty())
        return false;
    head.first = front->next;
    head.size--;
    delete front;
    front = head.first;
    return true;
}

template <typename T>
const T &LinkQueue<T>::get() const
{
    return front->data;
}

template <typename T>
bool LinkQueue<T>::isEmpty() const
{
    return !head.first;
}

template <typename T>
int LinkQueue<T>::size() const
{
    return head.size;
}

/********************************************************************************************************************/

int main(int argc, char *argv[])
{
    ArrayQueue<int> arrq;
    std::cout << "Array Queue\n";
    std::cout << "empty: " << arrq.isEmpty() << "  "
              << "size: " << arrq.size() << '\n';
    for (int i = 0; i < 5; i++)
        std::cout << "push result: " << arrq.push(i) << "  "
                  << "size: " << arrq.size() << "  "
                  << "empty: " << arrq.isEmpty() << '\n';
    std::cout << "front: " << arrq.get() << '\n';
    for (int i = 0; i < 3; i++)
        std::cout << "pop result: " << arrq.pop() << "  "
                  << "size: " << arrq.size() << "  "
                  << "empty: " << arrq.isEmpty() << '\n';
    std::cout << "front: " << arrq.get() << '\n';

    std::cout << std::endl;

    LinkQueue<int> linq;
    std::cout << "Link Queue\n";
    std::cout << "empty: " << linq.isEmpty() << "  "
              << "size: " << linq.size() << '\n';
    for (int i = 0; i < 5; i++)
        std::cout << "push result: " << linq.push(i) << "  "
                  << "size: " << linq.size() << "  "
                  << "empty: " << linq.isEmpty() << '\n';
    std::cout << "front: " << linq.get() << '\n';
    for (int i = 0; i < 3; i++)
        std::cout << "pop result: " << linq.pop() << "  "
                  << "size: " << linq.size() << "  "
                  << "empty: " << linq.isEmpty() << '\n';
    std::cout << "front: " << linq.get() << '\n';

    return 0;
}