/*

描述
请根据二叉树的前序遍历，中序遍历恢复二叉树，并打印出二叉树的右视图

数据范围：
0
≤
�
≤
10000
0≤n≤10000
要求： 空间复杂度
�
(
�
)
O(n)，时间复杂度
�
(
�
)
O(n)

如输入[1,2,4,5,3],[4,2,5,1,3]时，通过前序遍历的结果[1,2,4,5,3]和中序遍历的结果[4,2,5,1,3]可重建出以下二叉树：

所以对应的输出为[1,3,5]。
示例1
输入：
[1,2,4,5,3],[4,2,5,1,3]
复制
返回值：
[1,3,5]
复制
备注：
二叉树每个节点的值在区间[1,10000]内，且保证每个节点的值互不相同。

*/

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 求二叉树的右视图
     * @param preOrder int整型vector 先序遍历
     * @param inOrder int整型vector 中序遍历
     * @return int整型vector
     */
    vector<int> solve(vector<int> &preOrder, vector<int> &inOrder) {
        // write code here

        if (preOrder.empty() || inOrder.empty()) return {};

        int a = preOrder[0];
        int idx = 0;
        for (int i = 0; i < inOrder.size(); i++) {
            if (inOrder[i] == a) {
                idx = i;
                break;
            }
        }

        vector<int> inOrder1_new;
        for (int i = 0; i < idx; i++) {
            inOrder1_new.push_back(inOrder[i]);
        }
        vector<int> inOrder2_new;
        for (int i = idx + 1; i < inOrder.size(); i++) {
            inOrder2_new.push_back(inOrder[i]);
        }

        vector<int> preOrder1_new;
        for (int i = 1; i < 1 + inOrder1_new.size(); i++) {
            preOrder1_new.push_back(preOrder[i]);
        }

        vector<int> preOrder2_new;
        for (int i = 1 + inOrder1_new.size(); i < preOrder.size(); i++) {
            preOrder2_new.push_back(preOrder[i]);
        }

        auto &&v1 = solve(preOrder1_new, inOrder1_new);
        auto &&v2 = solve(preOrder2_new, inOrder2_new);

        if (v1.empty() && v2.empty()) return {a};
        if (!v1.empty() && !v2.empty()) {
            auto res = vector<int>();
            res.push_back(a);
            int i = 0;
            while (i < v1.size() && i < v2.size()) {
                res.push_back(v2[i]);
                i++;
            }
            while (i < v1.size()) {
                res.push_back(v1[i]);
                i++;
            }
            while (i < v2.size()) {
                res.push_back(v2[i]);
                i++;
            }
            return res;
        }
        if (!v2.empty()) {
            v2.insert(v2.begin(), a);
            return v2;
        } else {
            v1.insert(v1.begin(), a);
            return v1;
        }
    }
};