
//输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。

#include "vector"
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Solution
{
  public:
    //正向遍历链表，依次加到数组头
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> returnVec;
        while (head)
        {
            returnVec.insert(returnVec.begin(), head->val);
            head = head->next;
        }
        return returnVec;
    }
};