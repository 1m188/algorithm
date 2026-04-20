"""
描述
 给你一个一元二次方程，你需要判断它是否有实数解。

 具体而言，你需要实现一个函数，接受参数有三个整数
a
,
b
,
c
(
−
1
0
3
≤
a
,
b
,
c
≤
1
0
3
)
a,b,c(−10
3
 ≤a,b,c≤10
3
 )，你需要返回一个布尔值，表示判断一元二次方程
a
⋅
x
2
+
b
⋅
x
+
c
=
0
a⋅x
2
 +b⋅x+c=0 是否有实数解的结果，如果有解则返回 true，无解则返回 false。
示例1
输入：
0,0,0
复制
返回值：
true
复制
示例2
输入：
1,2,2
复制
返回值：
false
"""


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 判断二元一次方程组是否有解
# @param a int整型 二次项系数
# @param b int整型 一次项系数
# @param c int整型 常数项
# @return bool布尔型
#
class Solution:
    def judgeSolutions(self, a: int, b: int, c: int) -> bool:
        # write code here

        if a == 0:
            return b != 0 or (b == 0 and c == 0)
        else:
            return b * b - 4 * a * c >= 0
