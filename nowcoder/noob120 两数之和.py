"""
描述
给定一个整数序列
a
=
[
a
1
,
a
2
,
…
,
a
n
]
a=[a
1
​
 ,a
2
​
 ,…,a
n
​
 ] 和目标整数
T
T，寻找一对下标
(
i
,
j
)
(i,j) 满足
1
≦
i
<
j
≦
n
1≦i<j≦n 且
a
i
+
a
j
=
T
a
i
​
 +a
j
​
 =T。
测试数据保证恰有一组解，你需要求出对应的下标对
(
i
,
j
)
(i,j) 作为序列并返回。

传入参数：
∙

∙整数序列
a
a，长度满足
2
≦
n
≦
1
0
5
2≦n≦10
5
  且
0
≦
a
i
≦
1
0
9
0≦a
i
​
 ≦10
9
 ；
∙

∙目标整数
T
T，满足
0
≦
T
≦
1
0
9
0≦T≦10
9
 。

返回值：
一对整数下标
(
i
,
j
)
(i,j) 构成的序列，满足
a
i
+
a
j
=
T
a
i
​
 +a
j
​
 =T。
示例1
输入：
[0,7,2,1],9
复制
返回值：
[2,3]
复制
说明：
a
2
+
a
3
=
7
+
2
=
9
a
2
​
 +a
3
​
 =7+2=9。
"""

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param nums int整型一维数组
# @param target int整型
# @return int整型一维数组
#
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # write code here

        nums = sorted([(i + 1, v) for i, v in enumerate(nums)], key=lambda x: x[1])
        for i in range(len(nums) - 1):
            for j in range(i + 1, len(nums)):
                if nums[i][1] + nums[j][1] == target:
                    return sorted([nums[i][0], nums[j][0]])
                elif nums[i][1] + nums[j][1] > target:
                    break
