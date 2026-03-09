"""

今有7对数字：两个1，两个2，两个3，...两个7，把它们排成一行。
要求，两个1间有1个其它数字，两个2间有2个其它数字，以此类推，两个7之间有7个其它数字。如下就是一个符合要求的排列：

17126425374635

当然，如果把它倒过来，也是符合要求的。

请你找出另一种符合要求的排列法，并且这个排列法是以74开头的。

注意：只填写这个14位的整数，不能填写任何多余的内容，比如说明注释等。


"""

flags = [False for _ in range(7 + 1)]
flags[0] = flags[7] = flags[4] = True

ans = [0 for _ in range(14)]
ans[0] = ans[8] = 7
ans[1] = ans[6] = 4


def bfs(index: int = 2) -> bool:
    if index >= 14:
        return True
    if ans[index] > 0:
        return bfs(index + 1)

    for i in range(1, 8):
        if (
            not flags[i]
            and index < 14
            and index + i + 1 < 14
            and ans[index] == 0
            and ans[index + i + 1] == 0
        ):
            flags[i] = True
            ans[index] = ans[index + i + 1] = i
            if bfs(index + 1):
                return True
            flags[i] = False
            ans[index] = ans[index + i + 1] = 0
    return False


bfs()

print("".join(str(i) for i in ans))  # 74151643752362
