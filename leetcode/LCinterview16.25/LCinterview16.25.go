/*
 * @lc app=leetcode.cn id=面试题 16.25 lang=golang
 * @lcpr version=30204
 *
 * [面试题 16.25] LRU 缓存
 *
 * https://leetcode.cn/problems/lru-cache-lcci/description/
 *
 * LCCI
 * Medium (55.91%)
 * Likes:    206
 * Dislikes: 0
 * Total Accepted:    61.5K
 * Total Submissions: 110.1K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 *
 * 设计和构建一个“最近最少使用”缓存，该缓存会删除最近最少使用的项目。缓存应该从键映射到值(允许你插入和检索特定键对应的值)，并在初始化时指定最大容量。当缓存被填满时，它应该删除最近最少使用的项目。
 *
 * 它应该支持以下操作： 获取数据 get 和 写入数据 put 。
 *
 * 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
 * 写入数据 put(key, value) -
 * 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。
 *
 * 示例：
 *
 * LRUCache cache = new LRUCache( 2 /* 缓存容量 */ /* );
 *
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // 返回  1
 * cache.put(3, 3);    // 该操作会使得密钥 2 作废
 * cache.get(2);       // 返回 -1 (未找到)
 * cache.put(4, 4);    // 该操作会使得密钥 1 作废
 * cache.get(1);       // 返回 -1 (未找到)
 * cache.get(3);       // 返回  3
 * cache.get(4);       // 返回  4
 *
 *
 */

// @lcpr-template-start
package main

// @lcpr-template-end
// @lc code=start
type LRUCache struct {
	cache  [][]int
	mindex map[int]int
	cap    int
}

func Constructor(capacity int) LRUCache {
	return LRUCache{cache: make([][]int, 0, capacity), mindex: make(map[int]int), cap: capacity}
}

func (this *LRUCache) Get(key int) int {
	if index, ok := this.mindex[key]; !ok {
		return -1
	} else {
		val := this.cache[index]
		for i := index + 1; i < len(this.cache); i++ {
			this.mindex[this.cache[i][0]]--
		}
		this.cache = append(this.cache[:index], this.cache[index+1:]...)
		this.cache = append(this.cache, val)
		this.mindex[key] = len(this.cache) - 1
		return val[1]
	}
}

func (this *LRUCache) Put(key int, value int) {
	if index, ok := this.mindex[key]; ok {
		val := this.cache[index]
		val[1] = value
		for i := index + 1; i < len(this.cache); i++ {
			this.mindex[this.cache[i][0]]--
		}
		this.cache = append(this.cache[:index], this.cache[index+1:]...)
		this.cache = append(this.cache, val)
		this.mindex[key] = len(this.cache) - 1
	} else {
		if len(this.cache) == this.cap {
			delete(this.mindex, this.cache[0][0])
			this.cache = this.cache[1:]
			for index := range this.mindex {
				this.mindex[index]--
			}
		}
		this.cache = append(this.cache, []int{key, value})
		this.mindex[key] = len(this.cache) - 1
	}
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
// @lc code=end
