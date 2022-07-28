/*
 * @lc app=leetcode.cn id=295 lang=typescript
 *
 * [295] 数据流的中位数
 *
 * https://leetcode-cn.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (52.64%)
 * Likes:    675
 * Dislikes: 0
 * Total Accepted:    81.6K
 * Total Submissions: 155K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n[[],[1],[2],[],[3],[]]'
 *
 * 中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
 * 
 * 例如，
 * 
 * [2,3,4] 的中位数是 3
 * 
 * [2,3] 的中位数是 (2 + 3) / 2 = 2.5
 * 
 * 设计一个支持以下两种操作的数据结构：
 * 
 * 
 * void addNum(int num) - 从数据流中添加一个整数到数据结构中。
 * double findMedian() - 返回目前所有元素的中位数。
 * 
 * 
 * 示例：
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 进阶:
 * 
 * 
 * 如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
 * 如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
 * 
 * 
 */

/**
 * 搞一个数组存储所有数，需要中位数的时候实时计算
 */

// @lc code=start
class MedianFinder {

    vec: number[] = [];

    constructor() {
    }

    addNum(num: number): void {
        for (let i = 0; i < this.vec.length; i++) {
            if (this.vec[i] > num) {
                this.vec.splice(i, 0, num);
                return;
            }
        }
        this.vec.push(num);
    }

    findMedian(): number {
        let idx = Math.floor(this.vec.length / 2);
        if (this.vec.length % 2)
            return this.vec[idx];
        else
            return (this.vec[idx] + this.vec[idx - 1]) / 2;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * var obj = new MedianFinder()
 * obj.addNum(num)
 * var param_2 = obj.findMedian()
 */
// @lc code=end

