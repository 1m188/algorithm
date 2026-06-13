/*

碱基

生物学家正在对n个物种进行研究。
其中第i个物种的DNA序列为s[i]，其中的第j个碱基为s[i][j],碱基一定是A、T、G、C之一。
生物学家想找到这些生物中一部分生物的一些共性，他们现在关注那些至少在m个生物中出现的长度为k的连续碱基序列。准确的说，科学家关心的序列用2m元组(i1,p1,i2,p2....im,pm)表示，
满足:
1<=i1<i2<....<im<=n;
且对于所有q(0<=q<k), s[i1][p1+q]=s[i2][p2+q]=....=s[im][pm+q]。

现在给定所有生物的DNA序列，请告诉科学家有多少的2m元组是需要关注的。如果两个2m元组有任何一个位置不同，则认为是不同的元组。

【输入格式】
输入的第一行包含三个整数n、m、k，两个整数之间用一个空格分隔，意义如题目所述。
接下来n行，每行一个字符串表示一种生物的DNA序列。
DNA序列从1至n编号，每个序列中的碱基从1开始依次编号，不同的生物的DNA序列长度可能不同。

【输出格式】
输出一个整数，表示关注的元组个数。
答案可能很大，你需要输出答案除以1000000007的余数。

【样例输入】
3 2 2
ATC
TCG
ACG

【样例输出】
2

再例如：
【样例输入】
4 3 3
AAA
AAAA
AAA
AAA

【样例输出】
7


【数据规模与约定】
对于20%的数据，k<=5,所有字符串总长L满足L <=100
对于30%的数据，L<=10000
对于60%的数据，L<=30000
对于100%的数据，n<=5,m<=5,1<=k<=L<=100000
保证所有DNA序列不为空且只会包含'A' 'G' 'C' 'T'四种字母

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms

请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。

*/

#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

typedef unsigned long long ull;

const ull BASE = 131; // 滚动哈希基数（>4即可，131为常见质数）
const int MOD = 1000000007;

// 碱基到哈希值的编码映射（A=1,C=2,G=3,T=4，均小于BASE）
inline int encode(char c) {
    switch (c) {
    case 'A':
        return 1;
    case 'C':
        return 2;
    case 'G':
        return 3;
    case 'T':
        return 4;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    // 全局哈希表：子串的滚动哈希值 -> 各物种中的出现次数
    unordered_map<ull, array<int, 5>> global;

    // 预计算 BASE^k（用于滚动窗口移除最左字符）
    ull pow_base_k = 1;
    for (int i = 0; i < k; ++i)
        pow_base_k *= BASE;

    for (int sp = 0; sp < n; ++sp) {
        string dna;
        cin >> dna;
        int len = (int)dna.size();
        if (len < k)
            continue; // 序列长度不足k，不产生任何长度为k的子串

        // 初始化第一个长度为k的子串哈希
        ull hash = 0;
        for (int i = 0; i < k; ++i)
            hash = hash * BASE + encode(dna[i]);

        ++global[hash][sp]; // 记录该子串在当前物种中的一次出现

        // 滑动窗口遍历剩余位置
        for (int i = k; i < len; ++i) {
            hash = hash * BASE + encode(dna[i]);     // 加入右侧新字符
            hash -= encode(dna[i - k]) * pow_base_k; // 移除左侧旧字符
            ++global[hash][sp];
        }
    }

    // 枚举所有子串模式，计算贡献
    long long result = 0;

    for (auto &entry : global) {
        auto &cnt = entry.second; // cnt[i] = 该模式在物种i中的出现次数

        // 枚举所有恰好包含 m 个物种的选取方案（共 C(n,m) 种）
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (__builtin_popcount(mask) != m)
                continue;

            long long prod = 1;
            bool valid = true;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    if (cnt[i] == 0) {
                        valid = false;
                        break;
                    }
                    prod = (prod * cnt[i]) % MOD;
                }
            }
            if (valid)
                result = (result + prod) % MOD;
        }
    }

    cout << result << endl;
    return 0;
}
