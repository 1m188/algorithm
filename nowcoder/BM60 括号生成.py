'''

描述
给出n对括号，请编写一个函数来生成所有的由n对括号组成的合法组合。
例如，给出n=3，解集为：
"((()))", "(()())", "(())()", "()()()", "()(())"

数据范围：
0
≤
�
≤
10
0≤n≤10
要求：空间复杂度 
�
(
�
)
O(n)，时间复杂度 
�
(
2
�
)
O(2 
n
 )
示例1
输入：
1
复制
返回值：
["()"]
复制
示例2
输入：
2
复制
返回值：
["(())","()()"]

'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param n int整型
# @return string字符串一维数组
#
class Solution:

    def generateParenthesis(self, n: int) -> List[str]:
        # write code here

        ln, rn = n, n
        res = []

        def dfs(li: list[str] = [], ln=ln, rn=rn):
            if ln == rn == 0:
                res.append(''.join(li))
                return

            if ln == rn > 0:
                ln -= 1
                li.append('(')
                dfs(li, ln, rn)
                ln += 1
                li.pop()
            else:
                if ln > 0:
                    ln -= 1
                    li.append('(')
                    dfs(li, ln, rn)
                    ln += 1
                    li.pop()

                if rn > 0:
                    rn -= 1
                    li.append(')')
                    dfs(li, ln, rn)
                    rn += 1
                    li.pop()

        dfs()
        return res
