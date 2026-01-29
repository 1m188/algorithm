'''
描述
大家都知道斐波那契数列，现在要求输入一个正整数 n ，请你输出斐波那契数列的第 n 项。
斐波那契数列是一个满足 fib(x)=\left\{ \begin{array}{rcl} 1 & {x=1,2}\\ fib(x-1)+fib(x-2) &{x>2}\\ \end{array} \right.fib(x)={ 
1
fib(x−1)+fib(x−2)
​
  
x=1,2
x>2
​
  的数列
数据范围：1\leq n\leq 401≤n≤40
要求：空间复杂度 O(1)O(1)，时间复杂度 O(n)O(n) ，本题也有时间复杂度 O(logn)O(logn) 的解法

输入描述：
仅输入一个正整数 n。
输出描述：
输出斐波那契数列中第 n 个数。
示例1
输入：
4
复制
输出：
3
复制
说明：
根据斐波那契数列的定义可知，fib(1)=1,fib(2)=1,fib(3)=fib(3-1)+fib(3-2)=2,fib(4)=fib(4-1)+fib(4-2)=3，所以答案为3。   
示例2
输入：
1
复制
输出：
1
复制
示例3
输入：
2
复制
输出：
1
'''


def fib(n: int) -> int:
    if n == 1 or n == 2: return 1
    # return fib(n - 1) + fib(n - 2)  # 递归
    a1, a2 = 1, 1
    for _ in range(3, n + 1):  # 非递归
        a1, a2 = a2, a1 + a2
    return a2


n = int(input())
print(fib(n))
