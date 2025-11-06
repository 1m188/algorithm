/*
BM20 数组中的逆序对

描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P mod 1000000007

数据范围：  对于
50
%
50% 的数据,
s
i
z
e
≤
1
0
4
size≤10
4

对于
100
%
100% 的数据,
s
i
z
e
≤
1
0
5
size≤10
5

数组中所有数字的值满足
0
≤
v
a
l
≤
1
0
9
0≤val≤10
9


要求：空间复杂度
O
(
n
)
O(n)，时间复杂度
O
(
n
l
o
g
n
)
O(nlogn)
输入描述：
题目保证输入的数组中没有的相同的数字
示例1
输入：
[1,2,3,4,5,6,7,0]
复制
返回值：
7
复制
示例2
输入：
[1,2,3]
复制
返回值：
0
*/

package main

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param nums int整型一维数组
 * @return int整型
 */
func InversePairs(nums []int) int {
	// write code here

	const mod = 1000000007

	var mergeSort func(nums []int, left, right int) int
	mergeSort = func(nums []int, left, right int) int {
		if left >= right {
			return 0
		}
		mid := (left + right) >> 1
		cnt := mergeSort(nums, left, mid) + mergeSort(nums, mid+1, right)
		tmp := make([]int, 0, right-left+1)
		i, j := left, mid+1
		for i <= mid && j <= right {
			if nums[i] <= nums[j] {
				tmp = append(tmp, nums[i])
				i++
			} else {
				tmp = append(tmp, nums[j])
				j++
				cnt = (cnt + mid - i + 1) % mod
			}
		}
		if i <= mid {
			tmp = append(tmp, nums[i:mid+1]...)
		}
		if j <= right {
			tmp = append(tmp, nums[j:right+1]...)
		}
		copy(nums[left:right+1], tmp)
		return cnt
	}

	return mergeSort(nums, 0, len(nums)-1)
}
