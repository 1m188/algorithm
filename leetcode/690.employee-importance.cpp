/*
 * @lc app=leetcode.cn id=690 lang=cpp
 * @lcpr version=30204
 *
 * [690] 员工的重要性
 *
 * https://leetcode.cn/problems/employee-importance/description/
 *
 * algorithms
 * Medium (66.15%)
 * Likes:    320
 * Dislikes: 0
 * Total Accepted:    78.8K
 * Total Submissions: 115.7K
 * Testcase Example:  '[[1,5,[2,3]],[2,3,[]],[3,3,[]]]\n1'
 *
 * 你有一个保存员工信息的数据结构，它包含了员工唯一的 id ，重要度和直系下属的 id 。
 *
 * 给定一个员工数组 employees，其中：
 *
 *
 * employees[i].id 是第 i 个员工的 ID。
 * employees[i].importance 是第 i 个员工的重要度。
 * employees[i].subordinates 是第 i 名员工的直接下属的 ID 列表。
 *
 *
 * 给定一个整数 id 表示一个员工的 ID，返回这个员工和他所有下属的重要度的 总和。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
 * 输出：11
 * 解释：
 * 员工 1 自身的重要度是 5 ，他有两个直系下属 2 和 3 ，而且 2 和 3 的重要度均为 3 。因此员工 1 的总重要度是 5 + 3 + 3 =
 * 11 。
 *
 *
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：employees = [[1,2,[5]],[5,-3,[]]], id = 5
 * 输出：-3
 * 解释：员工 5 的重要度为 -3 并且没有直接下属。
 * 因此，员工 5 的总重要度为 -3。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= employees.length <= 2000
 * 1 <= employees[i].id <= 2000
 * 所有的 employees[i].id 互不相同。
 * -100 <= employees[i].importance <= 100
 * 一名员工最多有一名直接领导，并可能有多名下属。
 * employees[i].subordinates 中的 ID 都有效。
 *
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee *> employees, int id) {

        unordered_map<int, Employee *> umap;
        for (Employee *p : employees) {
            umap[p->id] = p;
        }

        int res = 0;

        queue<Employee *> que;
        que.push(umap[id]);
        while (!que.empty()) {
            Employee *p = que.front();
            que.pop();
            res += p->importance;
            for (int x : p->subordinates) {
                que.push(umap[x]);
            }
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,5,[2,3]],[2,3,[]],[3,3,[]]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,[5]],[5,-3,[]]]\n5\n
// @lcpr case=end

 */
