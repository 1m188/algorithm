/*
 * @lc app=leetcode.cn id=面试题 03.06 lang=golang
 * @lcpr version=30204
 *
 * [面试题 03.06] 动物收容所
 *
 * https://leetcode.cn/problems/animal-shelter-lcci/description/
 *
 * LCCI
 * Easy (58.08%)
 * Likes:    54
 * Dislikes: 0
 * Total Accepted:    22.2K
 * Total Submissions: 38.3K
 * Testcase Example:  '["AnimalShelf", "enqueue", "enqueue", "dequeueCat", "dequeueDog", "dequeueAny"]\n' +
  '[[], [[0, 0]], [[1, 0]], [], [], []]'
 *
 *
 * 动物收容所。有家动物收容所只收容狗与猫，且严格遵守“先进先出”的原则。在收养该收容所的动物时，收养人只能收养所有动物中“最老”（由其进入收容所的时间长短而定）的动物，或者可以挑选猫或狗（同时必须收养此类动物中“最老”的）。换言之，收养人不能自由挑选想收养的对象。请创建适用于这个系统的数据结构，实现各种操作方法，比如enqueue、dequeueAny、dequeueDog和dequeueCat。允许使用Java内置的LinkedList数据结构。
 *
 * enqueue方法有一个animal参数，animal[0]代表动物编号，animal[1]代表动物种类，其中 0 代表猫，1 代表狗。
 *
 * dequeue*方法返回一个列表[动物编号, 动物种类]，若没有可以收养的动物，则返回[-1,-1]。
 *
 * 示例1:
 *
 * ⁠输入：
 * ["AnimalShelf", "enqueue", "enqueue", "dequeueCat", "dequeueDog",
 * "dequeueAny"]
 * [[], [[0, 0]], [[1, 0]], [], [], []]
 * ⁠输出：
 * [null,null,null,[0,0],[-1,-1],[1,0]]
 *
 *
 * 示例2:
 *
 * ⁠输入：
 * ["AnimalShelf", "enqueue", "enqueue", "enqueue", "dequeueDog", "dequeueCat",
 * "dequeueAny"]
 * [[], [[0, 0]], [[1, 0]], [[2, 1]], [], [], []]
 * ⁠输出：
 * [null,null,null,null,[2,1],[0,0],[1,0]]
 *
 *
 * 说明:
 *
 *
 * 收纳所的最大容量为20000
 *
 *
*/
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
type AnimalShelf struct {
	cats [][]int
	dogs [][]int
}

func Constructor() AnimalShelf {
	return AnimalShelf{}
}

func (this *AnimalShelf) Enqueue(animal []int) {
	if animal[1] == 0 {
		this.cats = append(this.cats, animal)
	} else {
		this.dogs = append(this.dogs, animal)
	}
}

func (this *AnimalShelf) DequeueAny() []int {
	if len(this.cats) == 0 && len(this.dogs) == 0 {
		return []int{-1, -1}
	} else {
		if len(this.cats) == 0 {
			x := this.dogs[0]
			this.dogs = this.dogs[1:]
			return x
		}
		if len(this.dogs) == 0 {
			x := this.cats[0]
			this.cats = this.cats[1:]
			return x
		}
		cat := this.cats[0]
		dog := this.dogs[0]
		if cat[0] < dog[0] {
			this.cats = this.cats[1:]
			return cat
		} else {
			this.dogs = this.dogs[1:]
			return dog
		}
	}
}

func (this *AnimalShelf) DequeueDog() []int {
	if len(this.dogs) == 0 {
		return []int{-1, -1}
	} else {
		dog := this.dogs[0]
		this.dogs = this.dogs[1:]
		return dog
	}
}

func (this *AnimalShelf) DequeueCat() []int {
	if len(this.cats) == 0 {
		return []int{-1, -1}
	} else {
		dog := this.cats[0]
		this.cats = this.cats[1:]
		return dog
	}
}

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Enqueue(animal);
 * param_2 := obj.DequeueAny();
 * param_3 := obj.DequeueDog();
 * param_4 := obj.DequeueCat();
 */
// @lc code=end

/*
// @lcpr case=start
// ["AnimalShelf", "enqueue", "enqueue", "dequeueCat", "dequeueDog", "dequeueAny"][[], [[0, 0]], [[1, 0]], [], [], []]\n
// @lcpr case=end

// @lcpr case=start
// ["AnimalShelf", "enqueue", "enqueue", "enqueue", "dequeueDog", "dequeueCat", "dequeueAny"][[], [[0, 0]], [[1, 0]], [[2, 1]], [], [], []]\n
// @lcpr case=end

*/
