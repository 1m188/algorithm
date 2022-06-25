/**
 * @file P1085 [NOIP2004 普及组] 不高兴的津津.cpp
 * @date 2022-06-25
 */

/*
# [NOIP2004 普及组] 不高兴的津津

## 题目描述

津津上初中了。妈妈认为津津应该更加用功学习，所以津津除了上学之外，还要参加妈妈为她报名的各科复习班。另外每周妈妈还会送她去学习朗诵、舞蹈和钢琴。但是津津如果一天上课超过八个小时就会不高兴，而且上得越久就会越不高兴。假设津津不会因为其它事不高兴，并且她的不高兴不会持续到第二天。请你帮忙检查一下津津下周的日程安排，看看下周她会不会不高兴；如果会的话，哪天最不高兴。

## 输入格式

输入包括$7$行数据，分别表示周一到周日的日程安排。每行包括两个小于$10$的非负整数，用空格隔开，分别表示津津在学校上课的时间和妈妈安排她上课的时间。

## 输出格式

一个数字。如果不会不高兴则输出$0$，如果会则输出最不高兴的是周几（用$1, 2, 3, 4, 5, 6, 7$分别表示周一，周二，周三，周四，周五，周六，周日）。如果有两天或两天以上不高兴的程度相当，则输出时间最靠前的一天。

## 样例 #1

### 样例输入 #1

```
5 3
6 2
7 2
5 3
5 4
0 4
0 6
```

### 样例输出 #1

```
3
```

## 提示

NOIP2004 普及组第 1 题

- 2021-10-27：增加一组 hack 数据
- 2022-06-05：又增加一组 hack 数据
*/

#include <cstdio>
using namespace std;

int main() {

    int x = -1, d = 0;

    for (int i = 1; i <= 7; i++) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        if (a + b > x) {
            x = a + b;
            d = i;
        }
    }

    if (x > 8)
        printf("%d", d);
    else
        printf("0");

    return 0;
}