/*
 * @lc app=leetcode.cn id=93 lang=typescript
 *
 * [93] 复原 IP 地址
 *
 * https://leetcode.cn/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (56.88%)
 * Likes:    972
 * Dislikes: 0
 * Total Accepted:    250.5K
 * Total Submissions: 440.5K
 * Testcase Example:  '"25525511135"'
 *
 * 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
 * 
 * 
 * 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312"
 * 和 "192.168@1.1" 是 无效 IP 地址。
 * 
 * 
 * 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能
 * 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "25525511135"
 * 输出：["255.255.11.135","255.255.111.35"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "0000"
 * 输出：["0.0.0.0"]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "101023"
 * 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 20
 * s 仅由数字组成
 * 
 * 
 */

/**
 * 将字符串分割为4个部分，一边分割一边判断，不符合要求则回溯
 */

// @lc code=start
function restoreIpAddresses(s: string): string[] {

    if (s.length < 4) return [];

    let res: string[] = [];

    /**
     * 判断一个字符串是否是一个合法的ip数
     * @param s 
     * @returns 
     */
    function judge(s: string): boolean {
        let n = parseInt(s);
        if (isNaN(n)) return false;
        if (!(n >= 0 && n <= 255)) return false;
        if (n != 0 && s[0] == '0') return false;
        if (n == 0 && s.length != 1) return false;
        return true;
    }

    /**
     * 回溯求所有合法ip
     * @param tmp ip中每个部分缓存
     * @param idx 当前部分从哪里开始
     * @returns 
     */
    function back(tmp: string[] = [], idx: number = 0): void {
        // 前面只拆了3个部分，剩下的都是最后一部分的了
        if (tmp.length == 3) {
            let ts = s.substring(idx);
            if (judge(ts))
                res.push(tmp.join('.') + '.' + ts);
            return;
        }

        for (let i = idx + 1; i <= s.length; i++) {
            let ts = s.substring(idx, i);
            if (!judge(ts)) continue;
            tmp.push(ts);
            back(tmp, i);
            tmp.pop();
        }
    }

    back();

    return res;

};
// @lc code=end

