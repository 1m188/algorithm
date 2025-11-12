/*
BM54 三数之和

描述
给出一个有n个元素的数组S，S中是否有元素a,b,c满足a+b+c=0？找出数组S中所有满足条件的三元组。

数据范围：
0
≤
n
≤
1000
0≤n≤1000，数组中各个元素值满足
∣
v
a
l
∣
≤
100
∣val∣≤100
空间复杂度：
O
(
n
2
)
O(n
2
 )，时间复杂度
O
(
n
2
)
O(n
2
 )

注意：
三元组（a、b、c）中的元素必须按非降序排列。（即a≤b≤c）
解集中不能包含重复的三元组。
例如，给定的数组 S = {-10 0 10 20 -10 -40},解集为(-10, -10, 20),(-10, 0, 10)
示例1
输入：
[0]
复制
返回值：
[]
复制
示例2
输入：
[-2,0,1,1,2]
复制
返回值：
[[-2,0,2],[-2,1,1]]
复制
示例3
输入：
[-10,0,10,20,-10,-40]
复制
返回值：
[[-10,-10,20],[-10,0,10]]
*/

package main

import (
	"sort"
)

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param num int整型一维数组
 * @return int整型二维数组
 */
func threeSum(num []int) [][]int {
	// write code here

	res := make([][]int, 0)

	sort.Ints(num)

	for idx := 0; idx < len(num); idx++ {
		i, j := idx+1, len(num)-1
		for i >= 0 && i < len(num) && j >= 0 && j < len(num) && i < j {
			x := num[idx] + num[i] + num[j]
			if x == 0 {
				res = append(res, []int{num[idx], num[i], num[j]})
				i++
				j--
			} else if x < 0 {
				i++
			} else {
				j--
			}
		}
	}

	sort.Slice(res, func(i, j int) bool {
		if res[i][0] != res[j][0] {
			return res[i][0] < res[j][0]
		} else if res[i][1] != res[j][1] {
			return res[i][1] < res[j][1]
		} else {
			return res[i][2] < res[j][2]
		}
	})

	for i := 0; i < len(res)-1; {
		if res[i][0] == res[i+1][0] && res[i][1] == res[i+1][1] && res[i][2] == res[i+1][2] {
			res = append(res[:i+1], res[i+2:]...)
		} else {
			i++
		}
	}

	return res

}
