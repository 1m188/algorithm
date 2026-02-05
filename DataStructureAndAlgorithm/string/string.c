/*

串——天勤2021数据结构

*/

#include "stdio.h"
#include "stdbool.h"
#include "malloc.h"

/**********************************************  串  ****************************************************/

// 这里的所有串的结构体中，字符串本身最后会带有一个'\0'的结束标志，同时也会用length字符串长度来指示字符串结束

#define MAX_SIZE 100

// 定长顺序存储表示
typedef struct
{
    // 这里多加一位是为了保存字符串最后的'\0'，虽然length可以指示字符串的结束位置，但是这里两种都用
    char str[MAX_SIZE + 1];
    int length;
} Strf;

// 变长分配存储方式（也是下述主要使用的方式）
typedef struct
{
    char *ch;
    int length;
} Str;

// 基本操作

// 赋值操作
bool strassign(Str *s, char *ch)
{
    if (s->ch)
    {
        free(s->ch);
        s->ch = NULL;
        s->length = 0;
    }

    if (!ch) // 串为null直接返回
        return true;

    int len = 0;
    for (int i = 0; ch[i] != '\0'; i++) // 测试字符串长度（不包括串尾的'\0'）
        len++;

    if (len) // 如果空串直接返回
    {
        s->ch = (char *)malloc(sizeof(char) * (len + 1)); // 这里多+1是为了放置'\0'
        if (!s->ch)                                       // 内存申请失败
            return false;

        for (int i = 0; i <= len; i++) // 循环条件的<=，是为了把ch最后的'\0'也加进去
            s->ch[i] = ch[i];
        s->length = len;
    }
    return true;
}

// 取串长度操作
int strlength(Str *s)
{
    return s->length;
}

// 串大小比较操作
// s1>s2: >0
// s1<s2: <0
// s1==s2: =0
// 先结束的串为较小串
int strcompare(Str *s1, Str *s2)
{
    for (int i = 0, j = 0; i < s1->length && j < s2->length; i++, j++)
    {
        if (s1->ch[i] != s2->ch[j])
            return s1->ch[i] - s2->ch[j];
    }
    return s1->length - s2->length;
}

// 串连接操作
bool concat(Str *s, Str *s1, Str *s2)
{
    // 释放原串空间
    if (s->ch)
    {
        free(s->ch);
        s->ch = NULL;
        s->length = 0;
    }

    s->ch = (char *)malloc(sizeof(char) * (s1->length + s2->length + 1));
    if (!s->ch)
        return false;

    for (int i = 0; i < s1->length; i++)
        s->ch[i] = s1->ch[i];
    for (int i = 0; i < s2->length; i++)
        s->ch[i + s1->length] = s2->ch[i];
    s->ch[s1->length + s2->length] = '\0';
    s->length = s1->length + s2->length;
    return true;
}

// 求子串操作
// 从str字符串的pos索引位置开始，长度为len的子串（包括左边而不包括右变，左闭右开），子串通过substr返回
bool substring(Str *substr, Str *str, int pos, int len)
{
    // 检查子串合法性
    if (pos < 0 || pos >= str->length || len < 0 || len > str->length - pos)
        return false;

    // 释放原串空间
    if (substr->ch)
    {
        free(substr->ch);
        substr->ch = NULL;
        substr->length = 0;
    }

    // 返回一个空串
    if (!len)
        return true;

    substr->ch = (char *)malloc(sizeof(char) * (len + 1));
    if (!substr->ch)
        return false;
    for (int i = pos; i < pos + len; i++)
        substr->ch[i - pos] = str->ch[i];
    substr->ch[len] = '\0';
    substr->length = len;
    return true;
}

// 串清空
bool clearstring(Str *s)
{
    if (s->ch)
    {
        free(s->ch);
        s->ch = NULL;
    }
    s->length = 0;
    return true;
}

/********************************************************************************************************/

/**********************************************  串的模式匹配算法  ****************************************************/

// 为了便于讲解，本节串中的字符存储在1-length的位置上

// 简单模式匹配算法
// 效率很低
int indexx(Str *str, Str *substr)
{
    int i = 1, j = 1, k = 1; // 串从数组下标为1的地方开始算起
    while (i <= str->length && j <= substr->length)
    {
        if (str->ch[i] == substr->ch[j])
            i++, j++;
        else
            j = 1, i = ++k; // 匹配失败，i从主串的下一位置开始，k中记录了上一次的起始匹配位置
    }
    if (j > substr->length)
        return k;
    else
        return 0; // 0为开始索引的前一位，用0来表示无结果的情况
}

// *** kmp ***

// 获得next数组
void getnext(Str *substr, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < substr->length)
    {
        if (j == 0 || substr->ch[i] == substr->ch[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

// kmp
int KMP(Str *str, Str *substr, int next[])
{
    int i = 1, j = 1;
    while (i <= str->length && j <= substr->length)
    {
        if (j == 0 || str->ch[i] == substr->ch[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if (j > substr->length)
        return i - substr->length;
    else
        return 0;
}

// 改进的kmp算法
// 用一个nextval数组在一次跳转中跳过多个比较过程
void getnextval(Str *substr, int nextval[])
{
    int i = 1, j = 0;
    nextval[1] = 0;
    while (i < substr->length)
    {
        if (j == 0 || substr->ch[i] == substr->ch[j])
        {
            i++;
            j++;
            if (substr->ch[i] != substr->ch[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        }
        else
            j = nextval[j];
    }
}

/********************************************************************************************************/

int main(int argc, char *argv[])
{
    // 字符串赋值
    printf("str assign\n");
    Str s;
    s.ch = NULL;
    s.length = 0;
    printf("str assign result is: %d\n", strassign(&s, "cur input"));
    printf("str after assign is: %s\n", s.ch);

    printf("\n");

    // 串连接
    printf("str concat\n");
    Str s1;
    s1.ch = NULL;
    s1.length = 0;
    strassign(&s1, "asd");

    Str s2;
    s2.ch = NULL;
    s2.length = 0;
    strassign(&s2, " qwe");

    printf("original strings:\ns1: %s\ns2: %s\n", s1.ch, s2.ch);

    printf("The result of str concat is: %d\n", concat(&s, &s1, &s2));
    printf("str after concat: %s\n", s.ch);

    printf("\n");

    // 求子串
    printf("substring\n");
    printf("The result of substring to s1 from 0 and len is 2 is: %d\n", substring(&s, &s1, 0, 2));
    printf("The substring is: %s\n", s.ch);

    printf("\n");

    // 简单模式匹配
    printf("match\n");
    strassign(&s, " ABABCABCACBAB");
    s.length--;
    strassign(&s1, " ABCAC");
    s1.length--;
    printf("The simple match pos is: %d\n", indexx(&s, &s1));

    return 0;
}
