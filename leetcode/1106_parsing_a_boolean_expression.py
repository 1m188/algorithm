#
# @lc app=leetcode.cn id=1106 lang=python3
# @lcpr version=30204
#
# [1106] 解析布尔表达式
#
# https://leetcode.cn/problems/parsing-a-boolean-expression/description/
#
# algorithms
# Hard (67.97%)
# Likes:    217
# Dislikes: 0
# Total Accepted:    30.6K
# Total Submissions: 45K
# Testcase Example:  '"&(|(f))"'
#
# 布尔表达式 是计算结果不是 true 就是 false 的表达式。有效的表达式需遵循以下约定：
#
#
# 't'，运算结果为 true
# 'f'，运算结果为 false
# '!(subExpr)'，运算过程为对内部表达式 subExpr 进行 逻辑非（NOT）运算
# '&(subExpr1, subExpr2, ..., subExprn)'，运算过程为对 2 个或以上内部表达式 subExpr1, subExpr2,
# ..., subExprn 进行 逻辑与（AND）运算
# '|(subExpr1, subExpr2, ..., subExprn)'，运算过程为对 2 个或以上内部表达式 subExpr1, subExpr2,
# ..., subExprn 进行 逻辑或（OR）运算
#
#
# 给你一个以字符串形式表述的 布尔表达式 expression，返回该式的运算结果。
#
# 题目测试用例所给出的表达式均为有效的布尔表达式，遵循上述约定。
#
#
#
# 示例 1：
#
# 输入：expression = "&(|(f))"
# 输出：false
# 解释：
# 首先，计算 |(f) --> f ，表达式变为 "&(f)" 。
# 接着，计算 &(f) --> f ，表达式变为 "f" 。
# 最后，返回 false 。
#
#
# 示例 2：
#
# 输入：expression = "|(f,f,f,t)"
# 输出：true
# 解释：计算 (false OR false OR false OR true) ，结果为 true 。
#
#
# 示例 3：
#
# 输入：expression = "!(&(f,t))"
# 输出：true
# 解释：
# 首先，计算 &(f,t) --> (false AND true) --> false --> f ，表达式变为 "!(f)" 。
# 接着，计算 !(f) --> NOT false --> true ，返回 true 。
#
#
#
#
# 提示：
#
#
# 1 <= expression.length <= 2 * 10^4
# expression[i] 为 '('、')'、'&'、'|'、'!'、't'、'f' 和 ',' 之一
#
#
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        stack = []
        for ch in expression:
            if ch == ")":
                # 收集当前子表达式中的所有布尔值
                vals = []
                while stack[-1] != "(":
                    vals.append(stack.pop())
                stack.pop()  # 弹出 '('
                op = stack.pop()  # 弹出操作符
                if op == "!":
                    # NOT：只有一个操作数，取反
                    res = "f" if vals[0] == "t" else "t"
                elif op == "&":
                    # AND：全为 t 才为 t
                    res = "t" if all(v == "t" for v in vals) else "f"
                else:  # op == '|'
                    # OR：有一个 t 即为 t
                    res = "t" if any(v == "t" for v in vals) else "f"
                stack.append(res)
            elif ch != ",":
                stack.append(ch)
        return stack[0] == "t"


# @lc code=end


#
# @lcpr case=start
# "&(|(f))"\n
# @lcpr case=end

# @lcpr case=start
# "|(f,f,f,t)"\n
# @lcpr case=end

# @lcpr case=start
# "!(&(f,t))"\n
# @lcpr case=end

#
