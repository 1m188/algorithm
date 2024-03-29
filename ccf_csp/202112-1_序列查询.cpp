/**
 * @file 202112-1_序列查询.cpp
 * @date 2022-05-09
 */

/*
题目背景
西西艾弗岛的购物中心里店铺林立，商品琳琅满目。
为了帮助游客根据自己的预算快速选择心仪的商品，IT 部门决定研发一套商品检索系统，
支持对任意给定的预算 ，查询在该预算范围内（）价格最高的商品。
如果没有商品符合该预算要求，便向游客推荐可以免费领取的西西艾弗岛定制纪念品。

假设购物中心里有  件商品，价格从低到高依次为 
，则根据预算  检索商品的过程可以抽象为如下序列查询问题。

题目描述
 是一个由  个  范围内整数组成的序列，满足 
。（这个定义中蕴含了  一定小于 。）

基于序列 ，对于  范围内任意的整数 ，查询  定义为：序列  中小于等于  的整数里最大的数的下标。
具体来说有以下两种情况：

存在下标  满足 
此时序列  中从 
 到 
 均小于等于 ，其中最大的数为 
，其下标为 ，故 。

此时序列  中所有的数都小于等于 ，其中最大的数为 
，故 。

令  表示  到  的总和，即：
 
 

对于给定的序列 ，试计算 。

输入格式
从标准输入读入数据。

输入的第一行包含空格分隔的两个正整数  和 。

输入的第二行包含  个用空格分隔的整数 
。

注意 
 固定为 ，因此输入数据中不包括 
。

输出格式
输出到标准输出。

仅输出一个整数，表示  的值。

样例1输入
3 10
2 5 8
Data
样例1输出
15
Data
样例1解释

如上表所示，。

考虑到 、、 以及 ，亦可通过如下算式计算 ：

样例2输入
9 10
1 2 3 4 5 6 7 8 9
Data
样例2输出
45
Data
子任务
 的测试数据满足  且 ；

全部的测试数据满足  且 
。

提示
若存在区间  满足 ，使用乘法运算  代替将  到  逐个相加，或可大幅提高算法效率。
*/

/* 很简单的题目，仔细观察能够找出规律，对于遍历数组中的每个元素来说，其索引为i，
那么f(i)就应该为i，而对于sum=f(0)+...+f(N-1)来说，要做的就是找出i和i+1之间
每个元素的f(x)，对于i<=x<i+1而言，f(x)又等于f(i)，所以答案就不言而喻了。 */

#include <iostream>
#include <vector>
using namespace std;

int n = 0, N = 0;
vector<int> A;

/**
 * @brief 处理输入
 */
void input() {
    cin >> n >> N;
    A.resize(n + 1);             // 默认初始化元素为0
    for (int i = 1; i <= n; i++) // 这里直接从1开始，0的地方已经初始化为0了
        cin >> A[i];
}

/**
 * @brief 计算f(0)+...+f(N-1)
 * @return int 返回最终结果
 */
int sum() {
    int ans = 0;
    for (int i = 0; i < n; i++) { // 对于包括0在内的前n个元素而言，两个元素之间需要被计算的元素数目是后者-前者
        ans += i * (A[i + 1] - A[i]);
    }
    ans += n * (N - A.back()); // 对于最后一个元素，他所在的区间应该是[最后一个元素，N]
    return ans;
}

int main() {
    input();
    cout << sum();
    return 0;
}