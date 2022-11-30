'''
描述
王强决定把年终奖用于购物，他把想买的物品分为两类：主件与附件，附件是从属于某个主件的，
下表就是一些主件与附件的例子：
主件	附件
电脑	打印机，扫描仪
书柜	图书
书桌	台灯，文具
工作椅	无
如果要买归类为附件的物品，必须先买该附件所属的主件，且每件物品只能购买一次。
每个主件可以有 0 个、 1 个或 2 个附件。附件不再有从属于自己的附件。
王强查到了每件物品的价格（都是 10 元的整数倍），而他只有 N 元的预算。除此之外，
他给每件物品规定了一个重要度，用整数 1 ~ 5 表示。他希望在花费不超过 N 元的前提下，使自己的满意度达到最大。
满意度是指所购买的每件物品的价格与重要度的乘积的总和，假设设第ii件物品的价格为v[i]v[i]，
重要度为w[i]w[i]，共选中了kk件物品，编号依次为j_1,j_2,...,j_kj 
1
​
 ,j 
2
​
 ,...,j 
k
​
 ，则满意度为：v[j_1]*w[j_1]+v[j_2]*w[j_2]+ … +v[j_k]*w[j_k]v[j 
1
​
 ]∗w[j 
1
​
 ]+v[j 
2
​
 ]∗w[j 
2
​
 ]+…+v[j 
k
​
 ]∗w[j 
k
​
 ]。（其中 * 为乘号）
请你帮助王强计算可获得的最大的满意度。


输入描述：
输入的第 1 行，为两个正整数N，m，用一个空格隔开：

（其中 N （ N<32000 ）表示总钱数， m （m <60 ）为可购买的物品的个数。）


从第 2 行到第 m+1 行，第 j 行给出了编号为 j-1 的物品的基本数据，每行有 3 个非负整数 v p q


（其中 v 表示该物品的价格（ v<10000 ）， p 表示该物品的重要度（ 1 ~ 5 ）， q 表示该物品是主件还是附件。如果 q=0 ，表示该物品为主件，如果 q>0 ，表示该物品为附件， q 是所属主件的编号）
 



输出描述：
 输出一个正整数，为张强可以获得的最大的满意度。
示例1
输入：
1000 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0
复制
输出：
2200
复制
示例2
输入：
50 5
20 3 5
20 3 5
10 3 0
10 2 0
10 1 0
复制
输出：
130
复制
说明：
由第1行可知总钱数N为50以及希望购买的物品个数m为5；
第2和第3行的q为5，说明它们都是编号为5的物品的附件；
第4~6行的q都为0，说明它们都是主件，它们的编号依次为3~5；
所以物品的价格与重要度乘积的总和的最大值为10*1+20*3+20*3=130  
'''
'''

01背包问题的dp

dp[i][j] 表示背包容量为j的时候，前i个物品所能够装满的最大价值

dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i])

这个dp公式表示，要么第i个物品不装进去，要么其装进去，当然 j - w[i] >= 0
取二者的最大值作为当前背包容量的最大值，之后继续递推

这道题类似，但由于主从件的干扰，这里只考虑所有的主件，而将从件放到和主件一起考虑
对于每个主件，有四种情况：
1. 主件
2. 主件 + 从件1
3. 主件 + 从件2
4. 主件 + 从件1 + 从件2

这四种情况按照类似于背包问题的解，求其满意度取最大值，当然，同样的
前提，预算能够买得起

'''

import sys

# n预算，m个物品（包括主从件）
n, m = map(int, sys.stdin.readline().strip('\n\r').split(' '))

# dp[i][j] 表示第i个物品，预算为j，所能得到的最大满意度
dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]  # dp数组
s = [[] for _ in range(m + 1)]  # 每个物品的从件
sf = [True for _ in range(m + 1)]  # 是否主件
value = [0 for _ in range(m + 1)]  # 物品的价格
importance = [0 for _ in range(m + 1)]  # 物品的重要性

for i in range(1, m + 1):
    # 价格 重要度 是否主从件（从件的话其主件编号）
    v, p, q = map(int, sys.stdin.readline().strip('\n\r').split(' '))
    value[i] = v
    importance[i] = p
    if q != 0:
        s[q].append(i)
        sf[i] = False

# 初始条件
# 事实上所有的位置都初始化为了0
# 按照后面的说法，物品价格 <10 的时候其满意度也应都为0，因为物品价格都是10的倍数
for i in range(m + 1):
    dp[i][0] = 0
for i in range(n + 1):
    dp[0][i] = 0

for i in range(1, m + 1):  # 第i个物品

    # 这里有一个小优化，因为预算和物品价格都是10的倍数，
    # 而后续数组中这部分的内容都是其值相减，也为10的倍数，
    # 因此只需要把10的倍数这里做好就ok了，开始条件时候前10都为0，
    # 因为物品价格都在10以上
    for j in range(10, n + 1, 10):  # 预算为j

        if not sf[i]:  # 不是主件，其就等于前面一个物品的最大满意度，这里考虑的都是主件
            dp[i][j] = dp[i - 1][j]
            continue

        # 是主件的话要考虑四种情况的满意度：
        # 1. 主件
        # 2. 主件 + 从件1
        # 3. 主件 + 从件2
        # 4. 主件 + 从件1 + 从件2
        # 按照01背包问题的解法求出四种情况的满意度取其最大值

        max_i = dp[i - 1][j]

        if j - value[i] >= 0:  # 主件
            max_i = max(max_i,
                        dp[i - 1][j - value[i]] + value[i] * importance[i])

        if len(s[i]) >= 1:  # 主件 + 从件1
            k = s[i][0]
            if j - value[i] - value[k] >= 0:
                max_i = max(
                    max_i, dp[i - 1][j - value[i] - value[k]] +
                    value[i] * importance[i] + value[k] * importance[k])

        if len(s[i]) >= 2:  # 主件 + 从件2
            k = s[i][1]
            if j - value[i] - value[k] >= 0:
                max_i = max(
                    max_i, dp[i - 1][j - value[i] - value[k]] +
                    value[i] * importance[i] + value[k] * importance[k])

        if len(s[i]) >= 2:  # 主件 + 从件1 + 从件2
            k1, k2 = s[i][0], s[i][1]
            if j - value[i] - value[k1] - value[k2] >= 0:
                max_i = max(
                    max_i, dp[i - 1][j - value[i] - value[k1] - value[k2]] +
                    value[i] * importance[i] + value[k1] * importance[k1] +
                    value[k2] * importance[k2])

        dp[i][j] = max_i

print(dp[m][n])
