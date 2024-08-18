#
# @lc app=leetcode.cn id=29 lang=python3
#
# [29] 两数相除
#
# https://leetcode.cn/problems/divide-two-integers/description/
#
# algorithms
# Medium (22.22%)
# Likes:    940
# Dislikes: 0
# Total Accepted:    175.1K
# Total Submissions: 788K
# Testcase Example:  '10\n3'
#
# 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
#
# 返回被除数 dividend 除以除数 divisor 得到的商。
#
# 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) =
# -2
#
#
#
# 示例 1:
#
# 输入: dividend = 10, divisor = 3
# 输出: 3
# 解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
#
# 示例 2:
#
# 输入: dividend = 7, divisor = -3
# 输出: -2
# 解释: 7/-3 = truncate(-2.33333..) = -2
#
#
#
# 提示：
#
#
# 被除数和除数均为 32 位有符号整数。
# 除数不为 0。
# 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
#
#
#
'''
借鉴的题解下面某人的解法：


越界问题只要对除数是1和-1单独讨论就完事了啊
关于如何提高效率快速逼近结果
举个例子：11 除以 3 。
首先11比3大，结果至少是1， 然后我让3翻倍，就是6，发现11比3翻倍后还要大，那么结果就至少是2了，那我让这个6再翻倍，得12，11不比12大，吓死我了，差点让就让刚才的最小解2也翻倍得到4了。但是我知道最终结果肯定在2和4之间。也就是说2再加上某个数，这个数是多少呢？我让11减去刚才最后一次的结果6，剩下5，我们计算5是3的几倍，也就是除法，看，递归出现了。说得很乱，不严谨，大家看个大概，然后自己在纸上画一画，或者直接看我代码就好啦！

作者：liujin-4
链接：https://leetcode.cn/problems/divide-two-integers/solution/po-su-de-xiang-fa-mei-you-wei-yun-suan-mei-you-yi-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



代码（C++）：

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1){
            if(dividend>INT_MIN) return -dividend;// 只要不是最小的那个整数，都是直接返回相反数就好啦
            return INT_MAX;// 是最小的那个，那就返回最大的整数啦
        }
        long a = dividend;
        long b = divisor;
        int sign = 1; 
        if((a>0&&b<0) || (a<0&&b>0)){
            sign = -1;
        }
        a = a>0?a:-a;
        b = b>0?b:-b;
        long res = div(a,b);
        if(sign>0)return res>INT_MAX?INT_MAX:res;
        return -res;
    }
    int div(long a, long b){  // 似乎精髓和难点就在于下面这几句
        if(a<b) return 0;
        long count = 1;
        long tb = b; // 在后面的代码中不更新b
        while((tb+tb)<=a){
            count = count + count; // 最小解翻倍
            tb = tb+tb; // 当前测试的值也翻倍
        }
        return count + div(a-tb,b);
    }
};

作者：liujin-4
链接：https://leetcode.cn/problems/divide-two-integers/solution/po-su-de-xiang-fa-mei-you-wei-yun-suan-mei-you-yi-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。




总而言之，还是使用了长整型的数据存储，算是取了巧，
首先针对1，-1，0等几种特殊情况进行讨论，之后把除数
和被除数全部取正，按照正数的除法进行处理，最后得出的
结果要做边界检测，乘以符号进行返回，那关键是如何处理
正数的除法，这里给出的方法是类似快速幂的解决方法，
除数不断乘以2，直到超过被除数，取之前一次的结果，作为
一个基础值，之后被除数和除数之差和原本的除数再一次做
这个操作，因为每次是2的幂，幂级数能够很快的收敛到结果，
保证了性能，直到最终返回0
'''


# @lc code=start
class Solution:

    def divide(self, dividend: int, divisor: int) -> int:

        MAX_INT, MIN_INT = 2**31 - 1, -2**31

        if dividend == 0: return 0
        if divisor == 1: return dividend
        if divisor == -1: return -dividend if dividend != MIN_INT else MAX_INT

        sign = 1
        if (dividend > 0 and divisor < 0) or (dividend < 0 and divisor > 0):
            sign = -1

        dividend, divisor = abs(dividend), abs(divisor)

        return sign * min(self.div(dividend, divisor), MAX_INT)

    def div(self, a, b):
        if a < b: return 0
        tb = b
        cnt = 1
        while tb * 2 <= a:
            cnt *= 2
            tb *= 2
        return cnt + self.div(a - tb, b)


# @lc code=end
