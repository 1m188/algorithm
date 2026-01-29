/**
 * @file P1104 生日.cpp
 * @date 2022-06-05
 */

/*
# 生日

## 题目描述

cjf 君想调查学校 OI 组每个同学的生日，并按照年龄从大到小的顺序排序。但`cjf`君最近作业很多，没有时间，所以请你帮她排序。

## 输入格式

有$2$行，

第$1$行为`OI`组总人数$n$；

第$2$行至第$n+1$行分别是每人的姓名$s$、出生年$y$、月$m$、日$d$。

## 输出格式

有$n$行，

即$n$个生日从大到小同学的姓名。(如果有两个同学生日相同,输入靠后的同学先输出)

## 样例 #1

### 样例输入 #1

```
3
Yangchu 1992 4 23
Qiujingya 1993 10 13
Luowen 1991 8 1
```

### 样例输出 #1

```
Luowen
Yangchu
Qiujingya
```

## 提示

数据规模

$1<n<100$

$length(s)<20$
*/

/* 只知道出生年份，按照年龄排序。需要注意的是如果使用内置的sort，由于不知道其实现细节，在
排序的时候可能还需要指定输入的先后顺序，当年龄相同的时候按照输入先后顺序排序 */

#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief 生日信息
 */
struct Info {
    string name = string(20, '\0'); // 名字
    int y = 0,                      // 年
        m = 0,                      // 月
        d = 0;                      // 日
    int id = 0;                     // 输入顺序，越靠后的越大

    bool operator>(const Info &e) const {
        if (y != e.y) return y < e.y;
        if (m != e.m) return m < e.m;
        if (d != e.d) return d < e.d;
        return id > e.id;
    }
};

vector<Info> vec;

void input() {
    int n = 0;
    scanf("%d", &n);

    vec.resize(n);

    for (int i = 0; i < n; i++) {
        Info &e = vec[i];
        e.id = i;
        scanf("%s %d %d %d", &e.name[0], &e.y, &e.m, &e.d);
        for (int i = 0; i < e.name.size(); i++) { // 把输入的名字字符串去掉多余末尾
            if (e.name[i] == '\0') {
                e.name.resize(i);
                break;
            }
        }
    }
}

int main() {
    input();
    sort(vec.begin(), vec.end(), [](const Info &e1, const Info &e2) { return e1 > e2; });
    for (const Info &e : vec)
        printf("%s\n", e.name.c_str());
    return 0;
}