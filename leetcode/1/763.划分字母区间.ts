/*
 * @lc app=leetcode.cn id=763 lang=typescript
 *
 * [763] 划分字母区间
 *
 * https://leetcode.cn/problems/partition-labels/description/
 *
 * algorithms
 * Medium (76.75%)
 * Likes:    782
 * Dislikes: 0
 * Total Accepted:    126.6K
 * Total Submissions: 164.8K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：S = "ababcbacadefegdehijhklij"
 * 输出：[9,7,8]
 * 解释：
 * 划分结果为 "ababcbaca", "defegde", "hijhklij"。
 * 每个字母最多出现在一个片段中。
 * 像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * S的长度在[1, 500]之间。
 * S只包含小写字母 'a' 到 'z' 。
 * 
 * 
 */

/**
 * 递归，应该可以更快，这里是一整个字符串挨个判断字符，里面有些重复判断
 */

// @lc code=start
function partitionLabels(s: string): number[] {

    let res: number[] = [];

    let vis: Set<string> = new Set();
    let f: boolean = false;

    function recursion(start: number = 0): void {
        if (start == s.length) {
            f = true;
            return;
        }

        for (let end = start + 1; end <= s.length; end++) {
            let ts = s.substring(start, end);
            for (let c of ts)
                if (vis.has(c)) return;
            res.push(end - start);
            for (let c of ts) vis.add(c);
            recursion(end);
            if (f) return;
            for (let c of ts) vis.delete(c);
            res.pop();
        }
    }

    recursion();

    return res;

};
// @lc code=end

