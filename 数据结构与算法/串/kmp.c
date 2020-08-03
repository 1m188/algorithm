#include "stdio.h"
#include "string.h"

void get_next(const char *str, int next[], int length)
{
    next[0] = -1;
    for (int i = 1; i < length; i++)
    {
        int ti = next[i - 1];
        while (ti >= 0 && str[ti] != str[i - 1])
            ti = next[ti];
        next[i] = ti + 1;
    }
}

// 普通暴力查找的时间复杂度为O(m*n)，kmp为O(m+n)
int kmp(const char *str, const char *cmp)
{
    int cmpLen = strlen(cmp);
    int next[cmpLen];
    get_next(cmp, next, cmpLen);

    int si = 0, ci = 0;
    while (ci < cmpLen)
    {
        if (str[si] == cmp[ci])
            si++, ci++;
        else
        {
            ci = next[ci];
            if (ci < 0)
                si++, ci++;
        }
    }

    return ci >= cmpLen ? si - cmpLen : -1;
}

int main(int argc, char *argv[])
{
    const char *str = "ababcabcacbab", *cmp = "abcac";
    printf("%d\n", kmp(str, cmp));

    return 0;
}