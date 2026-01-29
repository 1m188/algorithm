'''
描述
IPV4地址可以用一个32位无符号整数来表示，一般用点分方式来显示，点将IP地址分成4个部分，每个部分为8位，表示成一个无符号整数（因此正号不需要出现），如10.137.17.1，是我们非常熟悉的IP地址，一个IP地址串中没有空格出现（因为要表示成一个32数字）。

现在需要你用程序来判断IP是否合法。

数据范围：数据组数：1\le t\le 18\1≤t≤18 
进阶：时间复杂度：O(n)\O(n) ，空间复杂度：O(n)\O(n) 

输入描述：
输入一个ip地址，保证不包含空格

输出描述：
返回判断的结果YES or NO

示例1
输入：
255.255.255.1000
复制
输出：
NO
'''


def judge(ip: str) -> bool:
    ipli = ip.split('.')
    if len(ipli) != 4: return False
    for _, v in enumerate(ipli):
        if not v.isnumeric(): return False
        try:
            vi = int(v)
        except:
            return False
        if len(str(vi)) != len(v): return False
        if not (vi >= 0 and vi <= 255): return False
    return True


print('YES' if judge(input()) else 'NO')
