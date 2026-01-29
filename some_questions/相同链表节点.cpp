/*

输入两个链表，找到它们第一个公共节点

*/

#include "iostream"
#include "memory"
#include "string"

// 链表节点
template <typename T>
struct Node
{
    T dat = reinterpret_cast<T>(0);
    std::shared_ptr<Node<T>> next;

    static std::shared_ptr<Node<T>> makeNode()
    {
        return std::shared_ptr<Node<T>>(new Node<T>);
    }

    static std::shared_ptr<Node<T>> makeNode(const T &dat)
    {
        Node<T> *n = new Node<T>;
        n->dat = dat;
        return std::shared_ptr<Node<T>>(n);
    }

    void print(const std::string &prefix = "")
    {
        if (!prefix.empty())
            std::cout << prefix;
        std::cout << dat;
        for (auto c = next; c; c = c->next)
            std::cout << ' ' << c->dat;
        std::cout << '\n';
    }
};

template <typename T>
std::shared_ptr<Node<T>> samePoint(std::shared_ptr<Node<T>> ah, std::shared_ptr<Node<T>> bh) // 带头节点
{
    int alen = 0, blen = 0;
    for (auto c = ah; c->next; c = c->next)
        alen++;
    for (auto c = bh; c->next; c = c->next)
        blen++;

    if (alen < blen)
        std::swap(alen, blen), std::swap(ah, bh);

    for (int i = 0; i < alen - blen; i++)
        ah = ah->next;
    while (ah && bh && ah != bh)
        ah = ah->next, bh = bh->next;
    return ah;
}

int main(int argc, char *argv[])
{
    const auto ah = Node<int>::makeNode(), bh = Node<int>::makeNode();
    auto ca = ah, cb = bh;
    for (int i = 1; i <= 5; i++)
    {
        ca->next = Node<int>::makeNode(i);
        ca = ca->next;

        cb->next = Node<int>::makeNode(i);
        cb = cb->next;
    }

    ca->next = Node<int>::makeNode(6);
    ca = ca->next;
    cb->next = ca;
    for (int i = 7; i <= 10; i++)
    {
        ca->next = Node<int>::makeNode(i);
        ca = ca->next;
    }

    ah->next->print("link list a: ");
    bh->next->print("link list b: ");
    std::cout << "same point at 6\n";

    std::cout << "same point res: " << samePoint(bh, ah)->dat << "\n\n";

    cb->next = nullptr;

    ah->next->print("link list a: ");
    bh->next->print("link list b: ");
    std::cout << "no same point\n";

    std::cout << "same point res: " << samePoint(bh, ah) << '\n';

    return 0;
}