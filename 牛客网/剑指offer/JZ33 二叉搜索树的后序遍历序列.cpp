/**
 * @file JZ33 二叉搜索树的后序遍历序列.cpp
 * @date 2022-05-10
 */

/*
描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则返回 true ,否则返回 false 。假设输入的数组的任意两个数字都互不相同。

数据范围： 节点数量 0≤n≤1000 ，节点上的值满足 1≤val≤10^5，保证节点上的值各不相同
要求：空间复杂度 O(n) ，时间时间复杂度 O(n^2)
提示：
1.二叉搜索树是指父亲节点大于左子树中的全部节点，但是小于右子树中的全部节点的树。
2.该题我们约定空树不是二叉搜索树
3.后序遍历是指按照 “左子树-右子树-根节点” 的顺序遍历
4.参考下面的二叉搜索树，示例 1

示例1
输入：
[1,3,2]

返回值：
true

说明：
是上图的后序遍历 ，返回true        
示例2
输入：
[3,1,2]

返回值：
false

说明：
不属于上图的后序遍历，从另外的二叉搜索树也不能后序遍历出该序列 ，因为最后的2一定是根节点，前面一定是孩子节点，可能是左孩子，右孩子，根节点，也可能是全左孩子，根节点，也可能是全右孩子，根节点，但是[3,1,2]的组合都不能满足这些情况，故返回false   
示例3
输入：
[5,7,6,9,11,10,8]

返回值：
true
*/

/* 递归，按照二叉搜索树后序遍历的特点进行数组的划分和判定 */

#include <vector>
using namespace std;

class Solution {
  private:
    /**
     * @brief 对一个数组中指定索引[left,right]的范围判定是不是二叉搜索树
     * @param vec 待判断二叉搜索树的后序遍历序列
     * @param left 左边界（可取到）
     * @param right 有边界（可取到）
     * @return true 是
     * @return false 否
     */
    bool judge(vector<int> &vec, int left, int right) {
        if (right <= left) // 递归边界出口
            return true;

        // 拿到根节点，左右子树的内容都跟根节点比较
        // right--为了从子树中排除根节点
        int root = vec[right--];

        int idx = left;
        while (idx <= right && vec[idx] < root) // 左边开始是左子树，找到第一个大于根节点的节点，也就是右子树的开头
            idx++;

        // 整个右子树如果还有小于根节点的就不是二叉搜索树
        for (int i = idx; i <= right; i++)
            if (vec[i] < root)
                return false;

        // 递归判定两棵子树
        return judge(vec, left, idx - 1) && judge(vec, idx, right);
    }

  public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0)
            return false;
        return judge(sequence, 0, sequence.size() - 1);
    }
};