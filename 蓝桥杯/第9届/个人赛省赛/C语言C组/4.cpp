/*

 标题：第几个幸运数

 到x星球旅行的游客都被发给一个整数，作为游客编号。
 x星的国王有个怪癖，他只喜欢数字3,5和7。
 国王规定，游客的编号如果只含有因子：3,5,7,就可以获得一份奖品。

 我们来看前10个幸运数字是：
 3 5 7 9 15 21 25 27 35 45
 因而第11个幸运数字是：49

 小明领到了一个幸运数字 59084709587505，他去领奖的时候，人家要求他准确地说出这是第几个幸运数字，否则领不到奖品。

 请你帮小明计算一下，59084709587505是第几个幸运数字。

 需要提交的是一个整数，请不要填写任何多余内容。

 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main() {
    const ull target = 59084709587505ULL;
    vector<ull> lucky;

    // 枚举所有形如 3^a * 5^b * 7^c 且不超过 target 的数
    for (ull a = 1; a <= target; a *= 3) {
        for (ull b = 1; b <= target / a; b *= 5) {
            ull ab = a * b;
            for (ull c = 1; c <= target / ab; c *= 7) {
                ull val = ab * c;
                if (val > 1) { // 排除 1（1 不含因子 3/5/7，不属于幸运数）
                    lucky.push_back(val);
                }
            }
        }
    }

    // 排序
    sort(lucky.begin(), lucky.end());

    // 二分查找目标值的排名（1-indexed）
    int rank = lower_bound(lucky.begin(), lucky.end(), target) - lucky.begin() + 1;

    cout << rank << endl;

    return 0;
}
