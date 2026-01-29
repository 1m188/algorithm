'''
描述
字符串旋转:
给定两字符串A和B，如果能将A从中间某个位置分割为左右两部分字符串（可以为空串），并将左边的字符串移动到右边字符串后面组成新的字符串可以变为字符串B时返回true。

例如：如果A=‘youzan’，B=‘zanyou’，A按‘you’‘zan’切割换位后得到‘zanyou’和B相同，返回true。
再如：如果A=‘abcd’，B=‘abcd’，A切成‘abcd’和''（空串），换位后可以得到B，返回true。

数据范围：A,B字符串长度满足 
n
≤
1000
n≤1000，保证字符串中仅包含小写英文字母和阿拉伯数字
进阶： 时间复杂度 
O
(
n
)
O(n)，空间复杂度 
O
(
n
)
O(n)
示例1
输入：
"youzan","zanyou"
复制
返回值：
true
复制
示例2
输入：
"youzan","zyouan"
复制
返回值：
false
复制
示例3
输入：
"nowcoder","nowcoder"
复制
返回值：
true
'''


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 旋转字符串
# @param A string字符串
# @param B string字符串
# @return bool布尔型
#
class Solution:

    def solve(self, A: str, B: str) -> bool:
        # write code here
        if A == B: return True
        for i in range(len(A) - 1):
            s = A[i + 1:] + A[0:i + 1]
            if s == B: return True
        return False
