/*

牌型种数

小明被劫持到X赌城，被迫与其他3人玩牌。
一副扑克牌（去掉大小王牌，共52张），均匀发给4个人，每个人13张。
这时，小明脑子里突然冒出一个问题：
如果不考虑花色，只考虑点数，也不考虑自己得到的牌的先后顺序，自己手里能拿到的初始牌型组合一共有多少种呢？

请填写该整数，不要填写任何多余的内容或说明文字。

*/

#include <cstring>
#include <iostream>

// DP解法：dp[i][j]表示从前i种点数中选取j张牌的方案数
// 每种点数最多4张，共计13种点数
long long count_card_combinations() {
    const int TYPES = 13;       // 点数种类（A,2,3,4,5,6,7,8,9,10,J,Q,K）
    const int CARDS = 13;       // 每人手牌数
    const int MAX_PER_TYPE = 4; // 每种点数最多4张（4种花色）

    // dp[j] = 取j张牌的方案数，滚动数组优化
    long long dp[CARDS + 1];
    std::memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 0; i < TYPES; i++) {
        // 从大到小更新，保证每轮每种点数只被使用一次
        for (int j = CARDS; j >= 0; j--) {
            long long ways = 0;
            for (int k = 0; k <= MAX_PER_TYPE && k <= j; k++) {
                ways += dp[j - k];
            }
            dp[j] = ways;
        }
    }

    return dp[CARDS];
}

int main(int argc, char *argv[]) {
    long long result = count_card_combinations();
    std::cout << result;

    return 0;
}
