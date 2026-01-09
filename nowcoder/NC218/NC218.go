/*
NC218 检测循环依赖

描述
为了毕业你需要选择 n 门课程，这 n 门课程中存在一定的依赖关系，例如想要完成 B 课程，必须先完成 A 课程，请你找出一个可以完成全部课程的顺序，如果无论如何选择都无法完成全部课程则返回空数组。

依赖关系以如下方式输入：
[[2,1],[3,2]]
即要完成课程 2 ，必须先完成 1 ， 要完成课程 3 ，必须先完成课程 2，答案 [1,2,3] 即可。
但也可能出现类似
[[2,1],[1,2]]
要完成课程 2 ，必须先完成 1 ，要完成课程 1 ，必须先完成课程 2 ，则无解，返回一个空数组即可。

数据范围：
1
≤
n
≤
2000

1≤n≤2000  ，依赖关系的数量满足
0
≤
m
≤
n
∗
(
n
−
1
)

0≤m≤n∗(n−1)  ，保证不会有一组一模一样的依赖关系。
示例1
输入：
[[1,0],[2,1]],3
复制
返回值：
[0,1,2]
复制
示例2
输入：
[[1,0],[2,1]],4
复制
返回值：
[0,1,2,3]
复制
说明：
返回 [3,0,1,2] ，[0,3,1,2] , [0,1,3,2]  也都合法
示例3
输入：
[[1,0],[0,1]],2
复制
返回值：
[]
复制
说明：
  存在环
*/

package main

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param prerequisites int整型二维数组
 * @param n int整型
 * @return int整型一维数组
 */
func findOrder(prerequisites [][]int, n int) []int {
	// write code here

	g := make(map[int]map[int]struct{}, n)
	for i := 0; i < n; i++ {
		g[i] = make(map[int]struct{}, 0)
	}
	for _, v := range prerequisites {
		g[v[0]][v[1]] = struct{}{}
	}

	res := make([]int, 0)

	for {
		key := -1
		for k, v := range g {
			if len(v) == 0 {
				key = k
				break
			}
		}

		if key != -1 {
			res = append(res, key)
			delete(g, key)
			for _, v := range g {
				delete(v, key)
			}
		} else {
			break
		}
	}

	if len(res) != n {
		return []int{}
	}
	return res
}
