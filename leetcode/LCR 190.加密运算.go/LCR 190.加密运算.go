/*
 * @lc app=leetcode.cn id=LCR 190 lang=golang
 * @lcpr version=30204
 *
 * [LCR 190] 加密运算
 *
 * https://leetcode.cn/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/description/
 *
 * algorithms
 * Easy (60.54%)
 * Likes:    469
 * Dislikes: 0
 * Total Accepted:    157.2K
 * Total Submissions: 259.5K
 * Testcase Example:  '5\n-1'
 *
 * 计算机安全专家正在开发一款高度安全的加密通信软件，需要在进行数据传输时对数据进行加密和解密操作。假定 dataA 和 dataB
 * 分别为随机抽样的两次通信的数据量：
 *
 *
 * 正数为发送量
 * 负数为接受量
 * 0 为数据遗失
 *
 *
 * 请不使用四则运算符的情况下实现一个函数计算两次通信的数据量之和（三种情况均需被统计），以确保在数据传输过程中的高安全性和保密性。
 *
 *
 *
 * 示例 1:
 *
 * 输入：dataA = 5, dataB = -1
 * 输出：4
 *
 *
 *
 *
 * 提示：
 *
 *
 * dataA 和 dataB 均可能是负数或 0
 * 结果不会溢出 32 位整数
 *
 *
 *
 *
 */
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func encryptionCalculate(dataA int, dataB int) int {

	if dataA == 0 {
		return dataB
	}
	if dataB == 0 {
		return dataA
	}

	return encryptionCalculate(dataA^dataB, dataA&dataB<<1)

}

// @lc code=end

/*
// @lcpr case=start
// 5\n-1\n
// @lcpr case=end

*/
