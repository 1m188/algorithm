/**
 * @file NC2 重排链表.cpp
 * @date 2023-12-24
 */

/*

描述
将给定的单链表

�
 L：
�
0
→
�
1
→
…
→
�
�
−
1
→
�
�
L
0
​
 →L
1
​
 →…→L
n−1
​
 →L
n
​

重新排序为：
�
0
→
�
�
→
�
1
→
�
�
−
1
→
�
2
→
�
�
−
2
→
…
L
0
​
 →L
n
​
 →L
1
​
 →L
n−1
​
 →L
2
​
 →L
n−2
​
 →…
要求使用原地算法，不能只改变节点内部的值，需要对实际的节点进行交换。

数据范围：链表长度
0
≤
�
≤
20000
0≤n≤20000 ，链表中每个节点的值满足
0
≤
�
�
�
≤
1000
0≤val≤1000

要求：空间复杂度
�
(
�
)
O(n) 并在链表上进行操作而不新建链表，时间复杂度
�
(
�
)
O(n)
进阶：空间复杂度
�
(
1
)
O(1) ， 时间复杂度
�
(
�
)
O(n)
示例1
输入：
{1,2,3,4}
复制
返回值：
{1,4,2,3}
复制
说明：
给定head链表1->2->3->4, 重新排列为 1->4->2->3,会取head链表里面的值打印输出 1
示例2
输入：
{1,2,3,4,5}
复制
返回值：
{1,5,2,4,3}
复制
说明：
给定head链表1->2->3->4->5, 重新排列为 1->5>2->4->3,会取head链表里面的值打印输出
示例3
输入：
{}
复制
返回值：
{}

*/

#include <cstddef>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {

        vector<ListNode *> vec;

        auto cur = head;
        while (cur) {
            vec.push_back(cur);
            cur = cur->next;
            vec.back()->next = nullptr;
        }

        int i = 0, j = vec.size() - 1;
        while (i < j) {
            vec[i]->next = vec[j];
            i++;
            if (i >= j) break;
            vec[j]->next = vec[i];
            j--;
            if (i >= j) break;
        }
    }
};