/*
 * @lc app=leetcode.cn id=187 lang=typescript
 *
 * [187] 重复的DNA序列
 *
 * https://leetcode.cn/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (52.88%)
 * Likes:    391
 * Dislikes: 0
 * Total Accepted:    108.3K
 * Total Submissions: 204.8K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * DNA序列 由一系列核苷酸组成，缩写为 'A', 'C', 'G' 和 'T'.。
 * 
 * 
 * 例如，"ACGAATTCCG" 是一个 DNA序列 。
 * 
 * 
 * 在研究 DNA 时，识别 DNA 中的重复序列非常有用。
 * 
 * 给定一个表示 DNA序列 的字符串 s ，返回所有在 DNA 分子中出现不止一次的 长度为 10 的序列(子字符串)。你可以按 任意顺序
 * 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * 输出：["AAAAACCCCC","CCCCCAAAAA"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "AAAAAAAAAAAAA"
 * 输出：["AAAAAAAAAA"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 10^5
 * s[i]=='A'、'C'、'G' or 'T'
 * 
 * 
 */

/**
 * 遍历所有子串，map储存其串和数目的映射关系，最后
 * 统一处理
 */

// @lc code=start
function findRepeatedDnaSequences(s: string): string[] {

    if (s.length < 10) return [];

    let map: Map<string, number> = new Map();

    for (let i = 0; i <= s.length - 10; i++) {
        let str = s.substring(i, i + 10);
        let v = map.get(str);
        if (v === undefined) map.set(str, 1);
        else map.set(str, v + 1);
    }

    let res: string[] = [];
    for (let [k, v] of map.entries())
        if (v > 1) res.push(k);
    return res;

};
// @lc code=end

