'''

kmp

'''


# 获取next数组
def get_next(s: str) -> tuple:
    next = [0] * len(s)
    next[0] = -1
    for i in range(1, len(next)):
        idx = next[i - 1]
        while idx >= 0 and s[idx] != s[i - 1]:
            idx = next[idx]
        next[i] = idx + 1
    return tuple(next)


# kmp
def kmp(string: str, s: str) -> int:
    next = get_next(s)
    stri, si = 0, 0
    while stri < len(string) and si < len(s):
        if string[stri] != s[si]:
            si = next[si]
            if si == -1:
                si += 1
                stri += 1
        else:
            si += 1
            stri += 1
    return stri - len(s) if si >= len(s) else -1


if __name__ == "__main__":
    string = "googlogooglgoogle"
    s = "google"
    print(kmp(string, s))

    sstring = "asdfgjf"
    ss = "asf"
    print(kmp(sstring, ss))
