"""
描述
给定三个整数
a
,
b
,
c
a,b,c（
1
≦
a
,
b
,
c
≦
1
0
6
1≦a,b,c≦10
6
 ），请输出它们中的最大值和最小值。
输入描述：
在一行中输入三个整数
a
,
b
,
c
a,b,c（
1
≦
a
,
b
,
c
≦
1
0
6
1≦a,b,c≦10
6
 ），用空格隔开。
输出描述：
输出两行：
第一行输出 `The maximum number is : X`，其中
X
X 为最大值；
第二行输出 `The minimum number is : Y`，其中
Y
Y 为最小值。
示例1
输入：
1 2 3
复制
输出：
The maximum number is : 3
The minimum number is : 1
复制
说明：
输入为
1
,
2
,
3
1,2,3，最大值为
3
3，最小值为
1
1。
备注：
注意输出内容的冒号前后均有空格。
"""

a, b, c = map(int, input().split())
print("The maximum number is :", max(a, b, c))
print("The minimum number is :", min(a, b, c))
