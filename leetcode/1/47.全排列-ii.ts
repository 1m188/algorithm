/*
 * @lc app=leetcode.cn id=47 lang=typescript
 *
 * [47] 全排列 II
 *
 * https://leetcode.cn/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (64.76%)
 * Likes:    1123
 * Dislikes: 0
 * Total Accepted:    345.2K
 * Total Submissions: 531.6K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,2]
 * 输出：
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 * 
 * 
 */

/*
官方题解

此题是「46. 全排列」的进阶，序列中包含了重复的数字，要求我们返回不重复的全排列，那么我们依然可以选择使用搜索回溯的方法来做。

我们将这个问题看作有 nn 个排列成一行的空格，我们需要从左往右依次填入题目给定的 nn 个数，每个数只能使用一次。那么很直接的可以想到一种穷举的算法，即从左往右每一个位置都依此尝试填入一个数，看能不能填完这 nn 个空格，在程序中我们可以用「回溯法」来模拟这个过程。

我们定义递归函数 \textit{backtrack}(\textit{idx}, \textit{perm})backtrack(idx,perm) 表示当前排列为 \textit{perm}perm，下一个待填入的位置是第 \textit{idx}idx 个位置（下标从 00 开始）。那么整个递归函数分为两个情况：

如果 \textit{idx} = nidx=n，说明我们已经填完了 nn 个位置，找到了一个可行的解，我们将 \textit{perm}perm 放入答案数组中，递归结束。
如果 \textit{idx} < nidx<n，我们要考虑第 \textit{idx}idx 个位置填哪个数。根据题目要求我们肯定不能填已经填过的数，因此很容易想到的一个处理手段是我们定义一个标记数组 \textit{vis}vis 来标记已经填过的数，那么在填第 \textit{idx}idx 个数的时候我们遍历题目给定的 nn 个数，如果这个数没有被标记过，我们就尝试填入，并将其标记，继续尝试填下一个位置，即调用函数 \textit{backtrack}(\textit{idx} + 1, \textit{perm})backtrack(idx+1,perm)。搜索回溯的时候要撤销该个位置填的数以及标记，并继续尝试其他没被标记过的数。
但题目解到这里并没有满足「全排列不重复」 的要求，在上述的递归函数中我们会生成大量重复的排列，因为对于第 \textit{idx}idx 的位置，如果存在重复的数字 ii，我们每次会将重复的数字都重新填上去并继续尝试导致最后答案的重复，因此我们需要处理这个情况。

要解决重复问题，我们只要设定一个规则，保证在填第 \textit{idx}idx 个数的时候重复数字只会被填入一次即可。而在本题解中，我们选择对原数组排序，保证相同的数字都相邻，然后每次填入的数一定是这个数所在重复数集合中「从左往右第一个未被填过的数字」，即如下的判断条件：


if (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]) {
    continue;
}



首先排序，便于去重

其次开始按照一般的全排列套路进行求解全排列

中间的如何去重是重点，对于有重复元素的部分，如果当前元素和前面的一个元素相同，
而前面的元素没有访问，那么当前也不访问，过。

为什么：因为整个数组是从左往右访问的，如果前面的已经访问过了，说明上一层
选数的时候选了，那么作为第一次的一个排列，可以加入结果之中，但是如果前面的
元素没有选，说明之前本元素选过前面的一个元素，而这个元素和前面的元素又重合，
其实就是将两个元素为止调一下，发现其实还是一样的，因此不选
*/

// @lc code=start
function permuteUnique(nums: number[]): number[][] {

    nums.sort();

    let res: number[][] = [];
    let temp: number[] = new Array(nums.length);
    let vis: boolean[] = [];
    for (let i = 0; i < nums.length; i++) vis.push(false);

    function backtrack(idx: number): void {
        if (idx == nums.length) {
            res.push([...temp]);
            return;
        }

        for (let i = 0; i < nums.length; i++) {

            /**注意关键部分，!vis[i - 1] 条件的判定 */
            if (i != 0 && nums[i] == nums[i - 1] && !vis[i - 1]) continue;

            if (!vis[i]) {
                vis[i] = true;
                temp[idx] = nums[i];
                backtrack(idx + 1);
                vis[i] = false;
            }
        }
    }

    backtrack(0);

    return res;
};
// @lc code=end

