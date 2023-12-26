'''

描述
有一个NxN整数矩阵，请编写一个算法，将矩阵顺时针旋转90度。

给定一个NxN的矩阵，和矩阵的阶数N,请返回旋转后的NxN矩阵。

数据范围：
0
<
�
<
300
0<n<300，矩阵中的值满足 
0
≤
�
�
�
≤
1000
0≤val≤1000

要求：空间复杂度 
�
(
�
2
)
O(N 
2
 )，时间复杂度 
�
(
�
2
)
O(N 
2
 )
进阶：空间复杂度 
�
(
1
)
O(1)，时间复杂度 
�
(
�
2
)
O(N 
2
 )
示例1
输入：
[[1,2,3],[4,5,6],[7,8,9]],3
复制
返回值：
[[7,4,1],[8,5,2],[9,6,3]]

'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param mat int整型二维数组
# @param n int整型
# @return int整型二维数组
#
class Solution:

    def rotateMatrix(self, mat: List[List[int]], n: int) -> List[List[int]]:
        # write code here

        left, right, up, down = 0, n - 1, 0, n - 1

        for _ in range(n // 2):
            for _ in range(right - left):
                i, j = left, up
                tmp = mat[i][j]

                while j < right:
                    j += 1
                    mat[i][j], tmp = tmp, mat[i][j]
                while i < down:
                    i += 1
                    mat[i][j], tmp = tmp, mat[i][j]
                while j > left:
                    j -= 1
                    mat[i][j], tmp = tmp, mat[i][j]
                while i > up:
                    i -= 1
                    mat[i][j], tmp = tmp, mat[i][j]

            left += 1
            right -= 1
            up += 1
            down -= 1

        return mat
