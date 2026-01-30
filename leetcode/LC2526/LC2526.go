/*
 * @lc app=leetcode.cn id=2526 lang=golang
 * @lcpr version=30204
 *
 * [2526] 找到数据流中的连续整数
 *
 * https://leetcode.cn/problems/find-consecutive-integers-from-a-data-stream/description/
 *
 * algorithms
 * Medium (55.67%)
 * Likes:    6
 * Dislikes: 0
 * Total Accepted:    6.5K
 * Total Submissions: 11.6K
 * Testcase Example:  '["DataStream","consec","consec","consec","consec"]\n[[4,3],[4],[4],[4],[3]]'
 *
 * 给你一个整数数据流，请你实现一个数据结构，检查数据流中最后 k 个整数是否 等于 给定值 value 。
 *
 * 请你实现 DataStream 类：
 *
 *
 * DataStream(int value, int k) 用两个整数 value 和 k 初始化一个空的整数数据流。
 * boolean consec(int num) 将 num 添加到整数数据流。如果后 k 个整数都等于 value ，返回 true ，否则返回
 * false 。如果少于 k 个整数，条件不满足，所以也返回 false 。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：
 * ["DataStream", "consec", "consec", "consec", "consec"]
 * [[4, 3], [4], [4], [4], [3]]
 * 输出：
 * [null, false, false, true, false]
 *
 * 解释：
 * DataStream dataStream = new DataStream(4, 3); // value = 4, k = 3
 * dataStream.consec(4); // 数据流中只有 1 个整数，所以返回 False 。
 * dataStream.consec(4); // 数据流中只有 2 个整数
 * ⁠                     // 由于 2 小于 k ，返回 False 。
 * dataStream.consec(4); // 数据流最后 3 个整数都等于 value， 所以返回 True 。
 * dataStream.consec(3); // 最后 k 个整数分别是 [4,4,3] 。
 * ⁠                     // 由于 3 不等于 value ，返回 False 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= value, num <= 10^9
 * 1 <= k <= 10^5
 * 至多调用 consec 次数为 10^5 次。
 *
 *
 */

// @lcpr-template-start
package main

import "container/list"

// @lcpr-template-end
// @lc code=start
type DataStream struct {
	Value int
	K     int
	Queue *list.List
	Map   map[int]int
}

func Constructor(value int, k int) DataStream {
	return DataStream{
		Value: value,
		K:     k,
		Queue: list.New(),
		Map:   make(map[int]int),
	}
}

func (this *DataStream) Consec(num int) bool {
	// 队列满了
	if this.Queue.Len() >= this.K {
		// 从头部删除一个元素
		e := this.Queue.Front()
		this.Queue.Remove(e)
		rm_val := e.Value.(int)
		this.Map[rm_val]--
		if this.Map[rm_val] == 0 {
			delete(this.Map, rm_val)
		}
	}

	// 从尾部插进去一个元素
	this.Queue.PushBack(num)
	this.Map[num]++

	// 数据个数不足
	if this.Queue.Len() < this.K {
		return false
	}

	return this.Map[this.Value] >= this.K
}

/**
 * Your DataStream object will be instantiated and called as such:
 * obj := Constructor(value, k);
 * param_1 := obj.Consec(num);
 */
// @lc code=end

/*
// @lcpr case=start
// ["DataStream", "consec", "consec", "consec", "consec"][[4, 3], [4], [4], [4], [3]]\n
// @lcpr case=end

*/
