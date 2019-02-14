//输入两个链表，找到它们第一个公共节点

#include "list"

template <typename T>
typename std::list<T>::iterator samePoint(std::list<T> &list1, std::list<T> &list2)
{
    typename std::list<T>::iterator it1 = list1.begin();
    typename std::list<T>::iterator it2 = list2.begin();

    for (;;)
    {
        if (++it1 == list1.begin())
        {
            return reinterpret_cast<typename std::list<T>::iterator>(0);
        }
        else
        {
            it1--;
        }

        if (it1 == it2)
        {
            return it1;
        }
        else
        {
            it1++;
            it2++;
        }

        if (++it1 == list1.begin())
        {
            return nullptr;
        }
        else
        {
            it1--;
        }

        if (++it2 == list2.begin())
        {
            return nullptr;
        }
        else
        {
            it2--;
        }
    }
}