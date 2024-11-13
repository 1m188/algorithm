/*
 * @lc app=leetcode.cn id=面试题 08.10 lang=golang
 * @lcpr version=30204
 *
 * [面试题 08.10] 颜色填充
 *
 * https://leetcode.cn/problems/color-fill-lcci/description/
 *
 * LCCI
 * Easy (56.09%)
 * Likes:    65
 * Dislikes: 0
 * Total Accepted:    26.5K
 * Total Submissions: 47.2K
 * Testcase Example:  '[[1,1,1],[1,1,0],[1,0,1]]\n1\n1\n2'
 *
 * 编写函数，实现许多图片编辑软件都支持的「颜色填充」功能。
 *
 * 待填充的图像用二维数组 image 表示，元素为初始颜色值。初始坐标点的行坐标为 sr 列坐标为 sc。需要填充的新颜色为 newColor 。
 *
 * 「周围区域」是指颜色相同且在上、下、左、右四个方向上存在相连情况的若干元素。
 *
 * 请用新颜色填充初始坐标点的周围区域，并返回填充后的图像。
 *
 *
 *
 * 示例：
 *
 * 输入：
 * image = [[1,1,1],[1,1,0],[1,0,1]]
 * sr = 1, sc = 1, newColor = 2
 * 输出：[[2,2,2],[2,2,0],[2,0,1]]
 * 解释:
 * 初始坐标点位于图像的正中间，坐标 (sr,sc)=(1,1) 。
 * 初始坐标点周围区域上所有符合条件的像素点的颜色都被更改成 2 。
 * 注意，右下角的像素没有更改为 2 ，因为它不属于初始坐标点的周围区域。
 *
 *
 *
 *
 * 提示：
 *
 *
 * image 和 image[0] 的长度均在范围 [1, 50] 内。
 * 初始坐标点 (sr,sc) 满足 0 <= sr < image.length 和 0 <= sc < image[0].length 。
 * image[i][j] 和 newColor 表示的颜色值在范围 [0, 65535] 内。
 *
 *
 */
package main

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
func floodFill(image [][]int, sr int, sc int, newColor int) [][]int {

	if image[sr][sc] == newColor {
		return image
	}

	m, n := len(image), len(image[0])
	oldColor := image[sr][sc]
	que := [][]int{[]int{sr, sc}}
	image[sr][sc] = newColor
	for len(que) != 0 {
		pos := que[0]
		que = que[1:]
		a, b := pos[0], pos[1]

		if a-1 >= 0 && image[a-1][b] == oldColor {
			image[a-1][b] = newColor
			que = append(que, []int{a - 1, b})
		}
		if a+1 < m && image[a+1][b] == oldColor {
			image[a+1][b] = newColor
			que = append(que, []int{a + 1, b})
		}
		if b-1 >= 0 && image[a][b-1] == oldColor {
			image[a][b-1] = newColor
			que = append(que, []int{a, b - 1})
		}
		if b+1 < n && image[a][b+1] == oldColor {
			image[a][b+1] = newColor
			que = append(que, []int{a, b + 1})
		}
	}

	return image

}

// @lc code=end

/*
// @lcpr case=start
// [[1,1,1],[1,1,0],[1,0\n1\n1\n2\n
// @lcpr case=end

*/
