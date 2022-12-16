'''
描述
Redraiment是走梅花桩的高手。Redraiment可以选择任意一个起点，从前到后，但只能从低处往高处的桩子走。他希望走的步数最多，你能替Redraiment研究他最多走的步数吗？

数据范围：每组数据长度满足 1 \le n \le 200 \1≤n≤200  ， 数据大小满足 1 \le val \le 350 \1≤val≤350 


输入描述：
数据共2行，第1行先输入数组的个数，第2行再输入梅花桩的高度

输出描述：
输出一个结果

示例1
输入：
6
2 5 1 5 4 5 
复制
输出：
3
复制
说明：
6个点的高度各为 2 5 1 5 4 5
如从第1格开始走,最多为3步, 2 4 5 ，下标分别是 1 5 6
从第2格开始走,最多只有1步,5
而从第3格开始走最多有3步,1 4 5， 下标分别是 3 5 6
从第5格开始走最多有2步,4 5， 下标分别是 5 6
所以这个结果是3。     
'''

n = int(input())
height = list(map(int, input().split()))
dp = [1 for _ in range(n)]

for i in range(n - 1, -1, -1):
    for j in range(i + 1, n):
        if height[j] > height[i]: dp[i] = max(dp[i], dp[j] + 1)
print(max(dp))
