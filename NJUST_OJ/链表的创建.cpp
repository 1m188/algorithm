/*
Description
链表的结构体定义：
struct Node{
     int id;
     Node *next;
};
给定n个数，将这n个数依次加入链表，然后输出

Input
第一行输入一个t，代表t组数据，然后输入一个n，代表n个数，接下来输入n个数（均小于1000）

Output
如Sample Output格式输出链表

Sample Input
1
5
1 2 3 4 5

Sample Output
1-2-3-4-5
*/

#include "cstdio"
#include "vector"

struct Node
{
    int id;
    Node *next;
};

int main() //AC！终于AC了一道题了...
{
    int t = 0;
    scanf("%d", &t);
    int n = 0;
    scanf("%d", &n);
    std::vector<std::pair<Node *, Node *>> list(t, std::pair<Node *, Node *>(nullptr, nullptr)); //数组里每个链表做两个指针，一个指向链表的头节点，一个指向链表的尾节点
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp = 0;
            scanf("%d", &temp);
            Node *node = new Node;
            node->id = temp;
            node->next = nullptr;
            if (j == 0) //第一次，初始化头尾节点
            {
                list[i].first = node;
                list[i].second = node;
            }
            else //之后头节点不动，尾节点移动
            {
                list[i].second->next = node;
                list[i].second = list[i].second->next;
            }
        }
    }

    for (std::vector<std::pair<Node *, Node *>>::iterator it = list.begin(); it != list.end(); it++)
    {
        Node *cursor = (*it).first;
        while (cursor != (*it).second)
        {
            printf("%d-", cursor->id);
            cursor = cursor->next;
        }
        printf("%d", cursor->id);
        if (it != list.end() - 1)
        {
            printf("\n");
        }
        cursor = (*it).first;
        while (cursor != (*it).second) //释放内存，防止内存泄漏
        {
            Node *delCursor = cursor;
            cursor = cursor->next;
            delete delCursor;
        }
        delete cursor;
        (*it).first = nullptr;
        (*it).second = nullptr;
    }

    return 0;
}