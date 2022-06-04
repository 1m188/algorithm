/**
 * @file P5143 攀爬者.cpp
 * @date 2022-06-04
 */

/*
# 攀爬者

## 题目背景

HKE考完GDOI之后跟他的神犇小伙伴们一起去爬山。

## 题目描述

他在地形图上标记了$N$个点，每个点Pi都有一个坐标$(x_i,y_i,z_i)$。所有点对中，高度值$z$不会相等。HKE准备从最低的点爬到最高的点，他的攀爬满足以下条件：

 (1) 经过他标记的每一个点；

 (2) 从第二个点开始，他经过的每一个点高度$z$都比上一个点高；

 (3) HKE会飞，他从一个点Pi爬到Pj的距离为两个点的欧几里得距离。即，$\sqrt{(X_i-X_j)^2+(Y_i-Y_j)^2+(Z_i-Z_j)^2}$

现在，HKE希望你能求出他攀爬的总距离。

## 输入格式

第一行，一个整数$N$表示地图上的点数。

接下来N行，三个整数$x_i,y_i,z_i$表示第$i$个点的坐标。

## 输出格式

一个实数，表示HKE需要攀爬的总距离（保留三位小数）

## 样例 #1

### 样例输入 #1

```
5
2 2 2
1 1 1
4 4 4
3 3 3
5 5 5
```

### 样例输出 #1

```
6.928
```

## 提示

对于100%的数据，$1\leq N\leq 50000$，答案的范围在double范围内。
*/

/* 按z排序，之后从第2个开始计算 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

struct Node {
    int x = 0, y = 0, z = 0;

    double operator-(const Node &e) {
        return sqrt(pow(x - e.x, 2) + pow(y - e.y, 2) + pow(z - e.z, 2));
    }
};

vector<Node> vec;

int main() {

    int n = 0;
    scanf("%d", &n);

    vec.resize(n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &vec[i].x, &vec[i].y, &vec[i].z);
    }

    sort(vec.begin(), vec.end(), [](const Node &e1, const Node &e2) { return e1.z < e2.z; });

    double ans = 0;
    for (int i = 1; i < vec.size(); i++) {
        ans += vec[i] - vec[i - 1];
    }

    printf("%.3lf", ans);

    return 0;
}