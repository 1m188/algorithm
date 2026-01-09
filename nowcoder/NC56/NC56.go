/*
NC56 回文数字

描述
在不使用额外的内存空间的条件下判断一个整数是否是回文。
回文指逆序和正序完全相同。


数据范围：
−
2
31
≤
n
≤
2
31
−
1
−2
31
 ≤n≤2
31
 −1
进阶： 空间复杂度
O
(
1
)
O(1)，时间复杂度
O
(
l
e
n
(
n
)
)
O(len(n))

提示：
负整数可以是回文吗？（比如-1）
如果你在考虑将数字转化为字符串的话，请注意一下不能使用额外空间的限制
你可以将整数翻转。但是，如果你做过题目“反转数字”，你会知道将整数翻转可能会出现溢出的情况，你怎么处理这个问题？
示例1
输入：
121
复制
返回值：
true
复制
示例2
输入：
122
复制
返回值：
false
*/

package main

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param x int整型
 * @return bool布尔型
 */
func isPalindrome(x int) bool {
	// write code here

	if x < 0 {
		return false
	}
	if x == 0 {
		return true
	}

	rev := func(x uint64) uint64 {
		res := uint64(0)
		for x > 0 {
			res = res*10 + x%10
			x /= 10
		}
		return res
	}

	return rev(uint64(x)) == uint64(x)
}
