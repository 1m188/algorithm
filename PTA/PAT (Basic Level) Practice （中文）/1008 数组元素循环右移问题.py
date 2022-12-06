'''
一个数组A中存有N（>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（≥0）个位置，即将A中的数据由（A 
0
​
 A 
1
​
 ⋯A 
N−1
​
 ）变换为（A 
N−M
​
 ⋯A 
N−1
​
 A 
0
​
 A 
1
​
 ⋯A 
N−M−1
​
 ）（最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？

输入格式:
每个输入包含一个测试用例，第1行输入N（1≤N≤100）和M（≥0）；第2行输入N个整数，之间用空格分隔。

输出格式:
在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。

输入样例:
6 2
1 2 3 4 5 6
输出样例:
5 6 1 2 3 4
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
'''


def reverse(li: list, a: int, b: int):
    if a >= b or a < 0 or a >= len(li) or b < 0 or b >= len(li): return
    while a < b:
        li[a], li[b] = li[b], li[a]
        a += 1
        b -= 1


param = input().split(' ')  # 这里的格式问题真是莫名其妙，似乎不能够用map那一套
n = int(param[0])
m = int(param[1])
nums = input().split(' ')
m %= n
reverse(nums, n - m, n - 1)
reverse(nums, 0, n - m - 1)
reverse(nums, 0, n - 1)
print(' '.join(nums))
