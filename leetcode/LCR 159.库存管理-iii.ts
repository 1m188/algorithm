/*
 * @lc app=leetcode.cn id=LCR 159 lang=typescript
 * @lcpr version=30204
 *
 * [LCR 159] 库存管理 III
 *
 * https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/description/
 *
 * algorithms
 * Easy (57.76%)
 * Likes:    595
 * Dislikes: 0
 * Total Accepted:    471.8K
 * Total Submissions: 816.9K
 * Testcase Example:  '[2,5,7,4]\n1'
 *
 * 仓库管理员以数组 stock 形式记录商品库存表，其中 stock[i] 表示对应商品库存余量。请返回库存余量最少的 cnt 个商品余量，返回
 * 顺序不限。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：stock = [2,5,7,4], cnt = 1
 * 输出：[2]
 * 
 * 
 * 示例 2：
 * 
 * 输入：stock = [0,2,3,6], cnt = 2
 * 输出：[0,2] 或 [2,0]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= cnt <= stock.length <= 10000
 * 0 <= stock[i] <= 10000
 * 
 * 
 * 
 * 
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
function inventoryManagement(stock: number[], cnt: number): number[] {

    /**调整堆 */
    const adjust = (vec: number[], index: number) => {
        let n = vec.length
        while (true) {
            let idx = index
            let left = index * 2 + 1
            let right = index * 2 + 2

            if (left >= n) break
            if (vec[left] > vec[idx]) idx = left

            if (right < n && vec[right] > vec[idx]) idx = right

            if (idx == index) break

            let tmp = vec[idx]
            vec[idx] = vec[index]
            vec[index] = tmp

            index = idx
        }
    }

    /**构建大根堆 */
    const buildHeap = (vec: number[]) => {
        for (let i = Math.floor((vec.length - 1 - 1) / 2); i >= 0; i--)
            adjust(vec, i)
    }

    let res: number[] = []
    res.length = cnt
    for (let i = 0; i < cnt; i++) res[i] = stock[i]
    buildHeap(res)
    for (let i = cnt; i < stock.length; i++) {
        if (stock[i] < res[0]) {
            res[0] = stock[i]
            adjust(res, 0)
        }
    }
    return res

};
// @lc code=end



/*
// @lcpr case=start
// [2,5,7,4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [0,2,3,6]\n2\n
// @lcpr case=end

 */

