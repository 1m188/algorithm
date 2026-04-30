"""
描述
给定一个由正整数构成的序列
a
a，如果其中某一个元素
a
i
a
i
​
  满足
a
i
−
1
<
a
i
>
a
i
+
1
a
i−1
​
 <a
i
​
 >a
i+1
​
 （
0
<
i
<
n
−
1
0<i<n−1），则称该元素
a
i
a
i
​
  为数组的一个峰点；如果其中某一个元素
a
i
a
i
​
  满足
a
i
−
1
>
a
i
<
a
i
+
1
a
i−1
​
 >a
i
​
 <a
i+1
​
 （
0
<
i
<
n
−
1
0<i<n−1），则称该元素
a
i
a
i
​
  为数组的一个谷点。

你需要实现一个函数，接受的参数为一个由正整数构成的序列
a
a，你需要求出这个序列中峰点和谷点的总数，并作为该函数的返回值。
示例1
输入：
[1,1,4,5,1,4]
复制
返回值：
2
复制
备注：
数据保证序列
a
a 中元素的数量不超过
1
0
5
10
5
  个。
"""

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 求序列a中的峰、谷点的个数
# @param a int整型一维数组 序列a
# @return int整型
#
class Solution:
    def countPeakPoint(self, a: List[int]) -> int:
        # write code here

        return sum(
            1 if a[i - 1] < a[i] > a[i + 1] or a[i - 1] > a[i] < a[i + 1] else 0
            for i in range(1, len(a) - 1)
        )
