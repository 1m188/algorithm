/*
描述
给定链表的头节点，旋转链表，将链表每个节点往右移动 k 个位置，原链表后 k 个位置的节点则依次移动到链表头。

即，例如链表 ： 1->2->3->4->5 k=2 则返回链表 4->5->1->2->3

数据范围：链表中节点数满足
0
≤
�
≤
1000

0≤n≤1000  ，
0
≤
�
≤
1
0
9

0≤k≤10
9

示例1
输入：
{1,2,3,4,5},2
复制
返回值：
{4,5,1,2,3}
复制
示例2
输入：
{1,2,3},3
复制
返回值：
{1,2,3}
*/

#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode *rotateLinkedList(ListNode *head, int k) {
        // write code here

        if (!head) return nullptr;

        vector<ListNode *> vec;
        ListNode *cur = head;
        while (cur) {
            vec.push_back(cur);
            cur = cur->next;
            vec.back()->next = nullptr;
        }
        k %= vec.size();

        auto reverse = [](vector<ListNode *> &vec, int left, int right) {
            while (left < right) {
                const auto tmp = vec[left];
                vec[left] = vec[right];
                vec[right] = tmp;
                left++, right--;
            }
        };

        reverse(vec, vec.size() - k, vec.size() - 1);
        reverse(vec, 0, vec.size() - k - 1);
        reverse(vec, 0, vec.size() - 1);

        head = vec[0];
        cur = head;
        for (int i = 1; i < vec.size(); i++) {
            cur->next = vec[i];
            cur = cur->next;
        }

        return head;
    }
};