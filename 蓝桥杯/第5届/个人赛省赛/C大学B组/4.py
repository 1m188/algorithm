'''

今有7对数字：两个1，两个2，两个3，...两个7，把它们排成一行。
要求，两个1间有1个其它数字，两个2间有2个其它数字，以此类推，两个7之间有7个其它数字。如下就是一个符合要求的排列：

17126425374635

当然，如果把它倒过来，也是符合要求的。

请你找出另一种符合要求的排列法，并且这个排列法是以74开头的。

注意：只填写这个14位的整数，不能填写任何多余的内容，比如说明注释等。


'''

sl = [0 for _ in range(14)]
sl[0] = sl[8] = 7
sl[1] = sl[6] = 4
flags = [False for _ in range(8)]
flags[7] = flags[4] = True

res = None


def dfs(cnt: int = 0):
    global res
    if cnt == 5:
        res = ''.join(map(str, sl))
        return

    for i in range(1, 8):
        if res: return
        if flags[i]: continue
        for j in range(len(sl)):
            if res: return
            if j + i + 1 >= len(sl): break
            if not sl[j] and not sl[j + i + 1]:
                flags[i] = True
                sl[j] = sl[j + i + 1] = i
                dfs(cnt + 1)
                sl[j] = sl[j + i + 1] = 0
                flags[i] = False


dfs()
print(res)  # 74151643752362

# print(74151643752362)
