/**
 * @file P2141 [NOIP2014 普及组] 珠心算测验.cpp
 * @date 2022-05-29
 */

/*
# [NOIP2014 普及组] 珠心算测验

## 题目描述

珠心算是一种通过在脑中模拟算盘变化来完成快速运算的一种计算技术。珠心算训练，既能够开发智力，又能够为日常生活带来很多便利，因而在很多学校得到普及。


某学校的珠心算老师采用一种快速考察珠心算加法能力的测验方法。他随机生成一个正整数集合，集合中的数各不相同，然后要求学生回答：其中有多少个数，恰好等于集合中另外两个（不同的）数之和？


最近老师出了一些测验题，请你帮忙求出答案。


(本题目为2014NOIP普及T1)

## 输入格式

共两行，第一行包含一个整数$n$，表示测试题中给出的正整数个数。


第二行有$n$个正整数，每两个正整数之间用一个空格隔开，表示测试题中给出的正整数。

## 输出格式

一个整数，表示测验题答案。

## 样例 #1

### 样例输入 #1

```
4
1 2 3 4
```

### 样例输出 #1

```
2
```

## 提示

【样例说明】


由$1+2=3,1+3=4$，故满足测试要求的答案为$2$。  

注意，加数和被加数必须是集合中的两个不同的数。


【数据说明】


对于$100\%$的数据，$3 ≤ n ≤ 100$，测验题给出的正整数大小不超过$10,000$。
*/

/* 排序之后从头往后做三重循环判断是否有两个数之和等于第三个数，

值得注意的是，有某些数等于多个两数之和，这种情况只能够算作1个 */

#include <algorithm>
#include <cstdio>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {

    int n = 0;
    scanf("%d", &n);
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &vec[i]);

    sort(vec.begin(), vec.end());

    unordered_set<int> uset; // 用来剔除重复等于两数之和的情况

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (vec[i] + vec[j] == vec[k] && uset.find(vec[k]) == uset.end()) {
                    uset.insert(vec[k]);
                    ans++;
                    break;
                } else if (vec[i] + vec[j] < vec[k]) {
                    break;
                }
            }
        }
    }

    printf("%d", ans);

    return 0;
}