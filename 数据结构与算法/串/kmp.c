/*

2021王道数据结构 串

*/

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

void get_nextval(const char *str, int nextval[], int length)
{
    nextval[0] = -1;
    for (int i = 1; i < length; i++)
    {
        int ti = nextval[i - 1];
        while (ti >= 0 && str[ti] != str[i - 1])
            ti = nextval[ti];
        nextval[i] = str[ti + 1] != str[i - 1] ? ti + 1 : nextval[ti + 1];
    }
}

// 普通暴力查找的时间复杂度为O(m*n)，kmp为O(m+n)
int kmp(const char *str, const char *cmp, void (*get_next)(const char *, int[], int))
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
    printf("next kmp: %d\n", kmp(str, cmp, get_next));
    printf("nextval kmp: %d\n", kmp(str, cmp, get_nextval));

    return 0;
}