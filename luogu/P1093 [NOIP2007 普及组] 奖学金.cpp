/**
 * @file P1093 [NOIP2007 普及组] 奖学金.cpp
 * @date 2022-06-01
 */

/*
# [NOIP2007 普及组] 奖学金

## 题目描述

某小学最近得到了一笔赞助，打算拿出其中一部分为学习成绩优秀的前5名学生发奖学金。期末，每个学生都有3门课的成绩:语文、数学、英语。先按总分从高到低排序，如果两个同学总分相同，再按语文成绩从高到低排序，如果两个同学总分和语文成绩都相同，那么规定学号小的同学 排在前面，这样，每个学生的排序是唯一确定的。

任务：先根据输入的3门课的成绩计算总分，然后按上述规则排序，最后按排名顺序输出前五名名学生的学号和总分。注意，在前5名同学中，每个人的奖学金都不相同，因此，你必须严格按上述规则排序。例如，在某个正确答案中，如果前两行的输出数据(每行输出两个数:学号、总分) 是:

$7$  $279$  
$5$  $279$  

这两行数据的含义是:总分最高的两个同学的学号依次是$7$号、$5$号。这两名同学的总分都是 $279$ (总分等于输入的语文、数学、英语三科成绩之和) ，但学号为$7$的学生语文成绩更高一些。如果你的前两名的输出数据是:

$5$  $279$  
$7$  $279$  

则按输出错误处理，不能得分。

## 输入格式

共n+1行。

第$1$行为一个正整数$n( \le 300)$，表示该校参加评选的学生人数。

第$2$到$n+1$行，每行有$3$个用空格隔开的数字，每个数字都在$0$到$100$之间。第$j$行的$3$个数字依次表示学号为$j-1$的学生的语文、数学、英语的成绩。每个学生的学号按照输入顺序编号为$1~n$（恰好是输入数据的行号减$1$）。

所给的数据都是正确的，不必检验。


//感谢 黄小U饮品 修正输入格式

## 输出格式

共5行，每行是两个用空格隔开的正整数，依次表示前$5$名学生的学号和总分。

## 样例 #1

### 样例输入 #1

```
6
90 67 80
87 66 91
78 89 91
88 99 77
67 89 64
78 89 98
```

### 样例输出 #1

```
6 265
4 264
3 258
2 244
1 237
```

## 样例 #2

### 样例输入 #2

```
8
80 89 89
88 98 78
90 67 80
87 66 91
78 89 91
88 99 77
67 89 64
78 89 98
```

### 样例输出 #2

```
8 265
2 264
6 264
1 258
5 258
```
*/

/* 排序，但其实求的是前5大的成绩，定义成绩结构体，按照特殊的要求比较大小，可以使用
堆排序求前5大元素，最后再对这5个元素排个序即可 */

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

/**
 * @brief 成绩结构体
 */
struct Grade {
    int id = 0;      // 学号
    int chinese = 0; // 语文成绩
    int total = 0;   // 总分

    /**
     * @brief 大于比较，按照特殊规则
     * @param g 
     * @return true 
     * @return false 
     */
    bool operator>(Grade &g) {
        if (total != g.total)
            return total > g.total;
        else if (chinese != g.chinese)
            return chinese > g.chinese;
        else
            return id < g.id;
    }

    bool operator==(Grade &g) {
        return false;
    }

    bool operator<(Grade &g) {
        return !((*this) > g) && !((*this) == g);
    }

    bool operator>=(Grade &g) {
        return !((*this) < g);
    }

    bool operator<=(Grade &g) {
        return !((*this) > g);
    }
};

/* 以下两个函数是关于小顶堆建堆和调整的 */

template <typename T>
void adjust(vector<T> &vec, int x) {
    for (int k = x * 2 + 1; k < vec.size(); k = x * 2 + 1) {
        if (k + 1 < vec.size() && vec[k + 1] < vec[k])
            k = k + 1;

        if (vec[k] < vec[x])
            swap(vec[k], vec[x]);
        else
            break;

        x = k;
    }
}

template <typename T>
void build_heap(vector<T> &vec) {
    for (int i = (vec.size() - 1 - 1) / 2; i >= 0; i--)
        adjust(vec, i);
}

int main() {

    int n = 0;
    scanf("%d", &n);

    vector<Grade> vec;

    for (int i = 1; i <= 5; i++) {
        int chinese = 0, math = 0, english = 0;
        scanf("%d %d %d", &chinese, &math, &english);
        vec.push_back({i, chinese, chinese + math + english}); // 注意学号
    }

    build_heap(vec);

    for (int i = 6; i <= n; i++) {
        int c = 0, m = 0, e = 0;
        scanf("%d %d %d", &c, &m, &e);
        Grade g = {i, c, c + m + e};
        if (g > vec[0]) {
            vec[0] = g;
            adjust(vec, 0);
        }
    }

    sort(vec.rbegin(), vec.rend()); // 最后别忘了排序

    for (int i = 0; i < 5; i++)
        printf("%d %d\n", vec[i].id, vec[i].total);

    return 0;
}