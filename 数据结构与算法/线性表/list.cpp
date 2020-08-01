/*

链表

*/

#include "iostream"

/*************************************************************************************************************/

// 单向链表
template <typename T>
class List
{
private:
    struct Node // 数据节点
    {
        T dat = reinterpret_cast<T>(0);
        Node *next = nullptr;
        bool isHead = false;
    };
    Node *head = new Node{reinterpret_cast<T>(0), nullptr, true};

public:
    List() = default;
    List(const List<T> &) = delete;
    List<T> &operator=(const List<T> &) = delete;
    List(const List<T> &&) = delete;
    List<T> &operator=(const List<T> &&) = delete;
    ~List()
    {
        while (head)
        {
            Node *tmp = head->next;
            delete head;
            head = tmp;
        }
    }

    // 添加数据
    bool addNode(const T &dat)
    {
        Node *node = new Node;
        if (!node)
            return false;
        node->dat = dat;

        Node *cur = head;
        while (cur->next)
            cur = cur->next;
        cur->next = node;
        return true;
    }

    // 删除数据
    bool delNode(const T &dat)
    {
        for (Node *cur = head; cur->next; cur = cur->next)
            if (cur->next->dat == dat)
            {
                Node *tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
                return true;
            }
        return false;
    }

    // 修改数据
    bool setVal(const T &dat, const T &val)
    {
        for (Node *cur = head->next; cur; cur = cur->next)
            if (cur->dat == dat)
            {
                cur->dat = val;
                return true;
            }
        return false;
    }

    // 查找数据
    const Node *search(const T &dat) const
    {
        for (Node *cur = head->next; cur; cur = cur->next)
            if (cur->dat == dat)
                return cur;
        return nullptr;
    }

    // 判断表空
    bool isEmpty() const
    {
        return !head->next;
    }

    // 获取表长
    int size() const
    {
        int num = 0;
        for (Node *cur = head->next; cur; cur = cur->next)
            num++;
        return num;
    }
};

/*************************************************************************************************************/

// 双向链表
template <typename T>
class DList
{
private:
    struct Node // 数据节点
    {
        T dat = reinterpret_cast<T>(0);
        Node *next = nullptr;
        Node *prior = nullptr;
        bool isHead = false;
    };
    Node *head = new Node{reinterpret_cast<T>(0), nullptr, nullptr, true};

public:
    DList() = default;
    DList(const DList<T> &) = delete;
    DList<T> &operator=(const DList<T> &) = delete;
    DList(const DList<T> &&) = delete;
    DList<T> &operator=(const DList<T> &&) = delete;
    ~DList()
    {
        while (head)
        {
            Node *tmp = head->next;
            delete head;
            head = tmp;
        }
    }

    // 添加数据
    bool addNode(const T &dat)
    {
        Node *node = new Node;
        if (!node)
            return false;
        node->dat = dat;

        Node *cur = head;
        while (cur->next)
            cur = cur->next;
        cur->next = node;
        node->prior = cur;
        return true;
    }

    // 删除数据
    bool delNode(const T &dat)
    {
        for (Node *cur = head->next; cur; cur = cur->next)
            if (cur->dat == dat)
            {
                Node *next = cur->next, *prior = cur->prior;
                prior->next = next;
                if (next) // 注意删除最后一个元素的情况
                    next->prior = prior;
                delete cur;
                return true;
            }
        return false;
    }

    // 修改数据
    bool setVal(const T &dat, const T &val)
    {
        for (Node *cur = head->next; cur; cur = cur->next)
            if (cur->dat == dat)
            {
                cur->dat = val;
                return true;
            }
        return false;
    }

    // 查找数据
    const Node *search(const T &dat) const
    {
        for (Node *cur = head->next; cur; cur = cur->next)
            if (cur->dat == dat)
                return cur;
        return nullptr;
    }

    // 判断表空
    bool isEmpty() const
    {
        return !head->next;
    }

    // 获取表长
    int size() const
    {
        int num = 0;
        for (Node *cur = head->next; cur; cur = cur->next)
            num++;
        return num;
    }
};

/*************************************************************************************************************/

// 循环单向链表
template <typename T>
class CList
{
private:
    struct Node // 数据节点
    {
        T dat = reinterpret_cast<T>(0);
        Node *next = nullptr;
        bool isHead = false;
    };
    Node *head = new Node;

public:
    CList()
    {
        head->isHead = true;
        head->next = head;
    }
    CList(const CList<T> &) = delete;
    CList<T> &operator=(const CList<T> &) = delete;
    CList(const CList<T> &&) = delete;
    CList<T> &operator=(const CList<T> &&) = delete;
    ~CList()
    {
        for (Node *cur = head->next; cur != head;)
        {
            Node *tmp = cur->next;
            delete cur;
            cur = tmp;
        }
        delete head;
    }

    // 添加数据
    bool addNode(const T &dat)
    {
        Node *node = new Node;
        if (!node)
            return false;
        node->dat = dat;

        Node *cur = head;
        while (cur->next != head)
            cur = cur->next;
        cur->next = node;
        node->next = head;
        return true;
    }

    // 删除数据
    bool delNode(const T &dat)
    {
        for (Node *cur = head; cur->next != head; cur = cur->next)
            if (cur->next->dat == dat)
            {
                Node *tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
                return true;
            }
        return false;
    }

    // 修改数据
    bool setVal(const T &dat, const T &val)
    {
        for (Node *cur = head->next; cur != head; cur = cur->next)
            if (cur->dat == dat)
            {
                cur->dat = val;
                return true;
            }
        return false;
    }

    // 查找数据
    const Node *search(const T &dat) const
    {
        for (Node *cur = head->next; cur != head; cur = cur->next)
            if (cur->dat == dat)
                return cur;
        return nullptr;
    }

    // 判断表空
    bool isEmpty() const
    {
        return head->next == head;
    }

    // 获取表长
    int size() const
    {
        int num = 0;
        for (Node *cur = head->next; cur != head; cur = cur->next)
            num++;
        return num;
    }
};

/*************************************************************************************************************/

// 循环双向链表
template <typename T>
class CDList
{
private:
    struct Node // 数据节点
    {
        T dat = reinterpret_cast<T>(0);
        Node *next = nullptr;
        Node *prior = nullptr;
        bool isHead = false;
    };
    Node *head = new Node;

public:
    CDList()
    {
        head->isHead = true;
        head->next = head->prior = head;
    }
    CDList(const CDList<T> &) = delete;
    CDList<T> &operator=(const CDList<T> &) = delete;
    CDList(const CDList<T> &&) = delete;
    CDList<T> &operator=(const CDList<T> &&) = delete;
    ~CDList()
    {
        for (Node *cur = head->next; cur != head;)
        {
            Node *tmp = cur->next;
            delete cur;
            cur = tmp;
        }
        delete head;
    }

    // 添加数据
    bool addNode(const T &dat)
    {
        Node *node = new Node;
        if (!node)
            return false;
        node->dat = dat;

        Node *tail = head->prior;
        tail->next = node;
        node->next = head;
        node->prior = tail;
        head->prior = node;
        return true;
    }

    // 删除数据
    bool delNode(const T &dat)
    {
        for (Node *cur = head->next; cur != head; cur = cur->next)
            if (cur->dat == dat)
            {
                cur->prior->next = cur->next;
                cur->next->prior = cur->prior;
                delete cur;
                return true;
            }
        return false;
    }

    // 修改数据
    bool setVal(const T &dat, const T &val)
    {
        for (Node *cur = head->next; cur != head; cur = cur->next)
            if (cur->dat == dat)
            {
                cur->dat = val;
                return true;
            }
        return false;
    }

    // 查找数据
    const Node *search(const T &dat) const
    {
        for (Node *cur = head->next; cur != head; cur = cur->next)
            if (cur->dat == dat)
                return cur;
        return nullptr;
    }

    // 判断表空
    bool isEmpty() const
    {
        return head->next == head;
    }

    // 获取表长
    int size() const
    {
        int num = 0;
        for (Node *cur = head->next; cur != head; cur = cur->next)
            num++;
        return num;
    }
};

/*************************************************************************************************************/

int main(int argc, char *argv[])
{
    List<int> list;
    std::cout << "List\n";
    std::cout << "isEmpty: " << list.isEmpty() << "  "
              << "size: " << list.size() << '\n';
    std::cout << "add 1 result: " << list.addNode(1) << '\n';
    std::cout << "add 2 result: " << list.addNode(2) << '\n';
    std::cout << "isEmpty: " << list.isEmpty() << "  "
              << "size: " << list.size() << '\n';
    std::cout << "search 1: " << list.search(1) << '\n';
    std::cout << "del 1 result: " << list.delNode(1) << '\n';
    std::cout << "isEmpty: " << list.isEmpty() << "  "
              << "size: " << list.size() << '\n';
    std::cout << "search 1: " << list.search(1) << '\n';
    std::cout << "set 2 to 3: " << list.setVal(2, 3) << '\n';
    std::cout << "search 3: " << list.search(3) << '\n';
    std::cout << "del 3 result: " << list.delNode(3) << '\n';
    std::cout << "isEmpty: " << list.isEmpty() << "  "
              << "size: " << list.size() << '\n';

    std::cout << std::endl;

    DList<int> dlist;
    std::cout << "DList\n";
    std::cout << "isEmpty: " << dlist.isEmpty() << "  "
              << "size: " << dlist.size() << '\n';
    std::cout << "add 1 result: " << dlist.addNode(1) << '\n';
    std::cout << "add 2 result: " << dlist.addNode(2) << '\n';
    std::cout << "isEmpty: " << dlist.isEmpty() << "  "
              << "size: " << dlist.size() << '\n';
    std::cout << "search 1: " << dlist.search(1) << '\n';
    std::cout << "del 1 result: " << dlist.delNode(1) << '\n';
    std::cout << "isEmpty: " << dlist.isEmpty() << "  "
              << "size: " << dlist.size() << '\n';
    std::cout << "search 1: " << dlist.search(1) << '\n';
    std::cout << "set 2 to 3: " << dlist.setVal(2, 3) << '\n';
    std::cout << "search 3: " << dlist.search(3) << '\n';
    std::cout << "del 3 result: " << dlist.delNode(3) << '\n';
    std::cout << "isEmpty: " << dlist.isEmpty() << "  "
              << "size: " << dlist.size() << '\n';

    std::cout << std::endl;

    CList<int> clist;
    std::cout << "CList\n";
    std::cout << "isEmpty: " << clist.isEmpty() << "  "
              << "size: " << clist.size() << '\n';
    std::cout << "add 1 result: " << clist.addNode(1) << '\n';
    std::cout << "add 2 result: " << clist.addNode(2) << '\n';
    std::cout << "isEmpty: " << clist.isEmpty() << "  "
              << "size: " << clist.size() << '\n';
    std::cout << "search 1: " << clist.search(1) << '\n';
    std::cout << "del 1 result: " << clist.delNode(1) << '\n';
    std::cout << "isEmpty: " << clist.isEmpty() << "  "
              << "size: " << clist.size() << '\n';
    std::cout << "search 1: " << clist.search(1) << '\n';
    std::cout << "set 2 to 3: " << clist.setVal(2, 3) << '\n';
    std::cout << "search 3: " << clist.search(3) << '\n';
    std::cout << "del 3 result: " << clist.delNode(3) << '\n';
    std::cout << "isEmpty: " << clist.isEmpty() << "  "
              << "size: " << clist.size() << '\n';

    std::cout << std::endl;

    CDList<int> cdlist;
    std::cout << "CDList\n";
    std::cout << "isEmpty: " << cdlist.isEmpty() << "  "
              << "size: " << cdlist.size() << '\n';
    std::cout << "add 1 result: " << cdlist.addNode(1) << '\n';
    std::cout << "add 2 result: " << cdlist.addNode(2) << '\n';
    std::cout << "isEmpty: " << cdlist.isEmpty() << "  "
              << "size: " << cdlist.size() << '\n';
    std::cout << "search 1: " << cdlist.search(1) << '\n';
    std::cout << "del 1 result: " << cdlist.delNode(1) << '\n';
    std::cout << "isEmpty: " << cdlist.isEmpty() << "  "
              << "size: " << cdlist.size() << '\n';
    std::cout << "search 1: " << cdlist.search(1) << '\n';
    std::cout << "set 2 to 3: " << cdlist.setVal(2, 3) << '\n';
    std::cout << "search 3: " << cdlist.search(3) << '\n';
    std::cout << "del 3 result: " << cdlist.delNode(3) << '\n';
    std::cout << "isEmpty: " << cdlist.isEmpty() << "  "
              << "size: " << cdlist.size() << '\n';

    std::cout << std::endl;

    return 0;
}