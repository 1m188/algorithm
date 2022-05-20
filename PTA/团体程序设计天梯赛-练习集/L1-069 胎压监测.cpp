/**
 * @file L1-069 胎压监测.cpp
 * @date 2022-05-20
 */

/*
小轿车中有一个系统随时监测四个车轮的胎压，如果四轮胎压不是很平衡，则可能对行车造成严重的影响。

taiya.JPG

让我们把四个车轮 —— 左前轮、右前轮、右后轮、左后轮 —— 顺次编号为 1、2、3、4。本题就请你编写一个监测程序，随时监测四轮的胎压，并给出正确的报警信息。报警规则如下：

如果所有轮胎的压力值与它们中的最大值误差在一个给定阈值内，并且都不低于系统设定的最低报警胎压，则说明情况正常，不报警；
如果存在一个轮胎的压力值与它们中的最大值误差超过了阈值，或者低于系统设定的最低报警胎压，则不仅要报警，而且要给出可能漏气的轮胎的准确位置；
如果存在两个或两个以上轮胎的压力值与它们中的最大值误差超过了阈值，或者低于系统设定的最低报警胎压，则报警要求检查所有轮胎。
输入格式：
输入在一行中给出 6 个 [0, 400] 范围内的整数，依次为 1~4 号轮胎的胎压、最低报警胎压、以及胎压差的阈值。

输出格式：
根据输入的胎压值给出对应信息：

如果不用报警，输出 Normal；
如果有一个轮胎需要报警，输出 Warning: please check #X!，其中 X 是出问题的轮胎的编号；
如果需要检查所有轮胎，输出 Warning: please check all the tires!。
输入样例 1：
242 251 231 248 230 20
输出样例 1：
Normal
输入样例 2：
242 251 232 248 230 10
输出样例 2：
Warning: please check #3!
输入样例 3：
240 251 232 248 240 10
输出样例 3：
Warning: please check all the tires!
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

int main() {

    vector<int> vec(4);
    int min_v = 0, diff_v = 0;
    scanf("%d %d %d %d %d %d", &vec[0], &vec[1], &vec[2], &vec[3], &min_v, &diff_v);

    int max_v = *max_element(vec.begin(), vec.end());

    int idx = -1;

    for (int i = 0; i < 4; i++) {
        if (abs(vec[i] - max_v) > diff_v || vec[i] < min_v) {
            if (idx == -1)
                idx = i;
            else {
                printf("Warning: please check all the tires!");
                return 0;
            }
        }
    }

    if (idx == -1)
        printf("Normal");
    else
        printf("Warning: please check #%d!", idx + 1);

    return 0;
}