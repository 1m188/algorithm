/**
 * @file JZ36 二叉搜索树与双向链表.cpp
 * @date 2022-05-10
 */

/*
描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。如下图所示


数据范围：输入二叉树的节点数 0≤n≤1000，二叉树中每个节点的值 0≤val≤1000
要求：空间复杂度O(1)（即在原树上操作），时间复杂度 O(n)

注意:
1.要求不能创建任何新的结点，只能调整树中结点指针的指向。
当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继
2.返回链表中的第一个节点的指针
3.函数返回的TreeNode，有左右指针，其实可以看成一个双向链表的数据结构
4.你不用输出双向链表，程序会根据你的返回值自动打印输出
输入描述：
二叉树的根节点
返回值描述：
双向链表的其中一个头节点。
示例1
输入：
{10,6,14,4,8,12,16}

返回值：
From left to right are:4,6,8,10,12,14,16;From right to left are:16,14,12,10,8,6,4;

说明：
输入题面图中二叉树，输出的时候将双向链表的头节点返回即可。     
示例2
输入：
{5,4,#,3,#,2,#,1}

返回值：
From left to right are:1,2,3,4,5;From right to left are:5,4,3,2,1;

说明：
                    5
                  /
                4
              /
            3
          /
        2
      /
    1
树的形状如上图
*/

/* 非递归中序遍历，注意前向节点指针的保存 */

#include <cstddef>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

/**
 * @brief 非递归中序遍历
 */
/*
class Solution {
  public:
    TreeNode *Convert(TreeNode *pRootOfTree) {
        if (!pRootOfTree)
            return nullptr;

        stack<TreeNode *> st;

        while (pRootOfTree) {
            st.push(pRootOfTree);
            pRootOfTree = pRootOfTree->left;
        }

        TreeNode *head = st.top();

        TreeNode *ptr = nullptr, *pre = nullptr;
        while (!st.empty()) {
            ptr = st.top();
            st.pop();

            if (pre) {
                ptr->left = pre;
                pre->right = ptr;
            }
            pre = ptr;

            if (ptr->right) {
                ptr = ptr->right;
                while (ptr) {
                    st.push(ptr);
                    ptr = ptr->left;
                }
            }
        }

        return head;
    }
};
*/

/**
 * @brief 另一种版本，将每一次向左遍历到底的部分也分散在一个循环之中
 */
class Solution {
  public:
    TreeNode *Convert(TreeNode *pRootOfTree) {
        if (!pRootOfTree)
            return nullptr;

        stack<TreeNode *> st;
        TreeNode *ptr = pRootOfTree, *pre = nullptr, *head = nullptr;

        while (!st.empty() || ptr) {
            if (ptr) {
                st.push(ptr);
                ptr = ptr->left;
            } else {
                ptr = st.top();
                st.pop();

                if (pre) {
                    pre->right = ptr;
                    ptr->left = pre;
                } else {
                    head = ptr;
                }
                pre = ptr;

                ptr = ptr->right;
            }
        }

        return head;
    }
};