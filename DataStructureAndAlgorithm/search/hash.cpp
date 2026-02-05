/*

散列表

*/

#include "algorithm"
#include "functional"
#include "iostream"
#include "list"
#include "vector"
using namespace std;

/**********************************************************************************************************/

// 一些散列函数

// 除留余数法
// x为待插入的数据，m为被mod的数
// 一般取m为比散列表长度小的最大质数
uint remain(uint x, uint m)
{
    return x % m;
}

// 直接定址法
// 数字分析法
// 平方取中法

// 处理冲突的方法

// 开放定址法

// 线性探测法   使用除留余数作为哈希函数
bool linear_detect_storge(vector<pair<bool, int>> &vec, const int &dat, const function<uint(const vector<pair<bool, int>> &, const int &)> &hash)
{
    uint idx = hash(vec, dat);
    while (vec[idx].first && idx < vec.size())
        idx++;
    if (idx >= vec.size())
        return false;
    vec[idx].first = true;
    vec[idx].second = dat;
    return true;
}

int linear_detect_search(const vector<pair<bool, int>> &vec, const int &dat, const function<uint(const vector<pair<bool, int>> &, const int &)> &hash)
{
    uint idx = hash(vec, dat);
    while (vec[idx].first && vec[idx].second != dat && idx < vec.size())
        idx++;
    return idx >= vec.size() ? -1 : idx;
}

// 平方探测法
// 双散列法
// 伪随机序列法

// 分离链址法
void lnkAddr(vector<list<int>> &vec, const int &dat, const function<uint(const vector<list<int>> &, const int &)> &hash)
{
    uint idx = hash(vec, dat);
    vec[idx].push_back(dat);
}

/**********************************************************************************************************/

int main(int argc, char *argv[])
{
    const vector<int> data{19, 14, 23, 01, 68, 20, 84, 27, 55, 11, 10, 79};
    const int hashLen = 16;
    const int reInt = 13;

    // 线性探测法

    vector<pair<bool, int>> vec(hashLen, {false, 0});
    for_each(data.cbegin(), data.cend(), [&](const int &e) {
        linear_detect_storge(vec, e, [](const vector<pair<bool, int>> &vec, const int &t) {
            return remain(t, reInt);
        });
    });

    for_each(vec.cbegin(), vec.cend(), [](const pair<bool, int> &e) {
        if (e.first)
            cout << e.second;
        else
            cout << "null";
        cout << ' ';
    });
    cout << endl;

    int res = linear_detect_search(vec, 20, [](const vector<pair<bool, int>> &vec, const int &t) {
        return remain(t, reInt);
    });
    cout << "20 res: " << res << endl;

    cout << endl;

    // 分离链址法

    const int lnkhashlen = 13;

    vector<list<int>> lvec(lnkhashlen);
    for_each(data.cbegin(), data.cend(), [&](const int &e) {
        lnkAddr(lvec, e, [](const vector<list<int>> &vec, const int &t) {
            return remain(t, reInt);
        });
    });

    for_each(lvec.cbegin(), lvec.cend(), [](const list<int> &e) {
        if (e.empty())
            cout << "null\n";
        else
        {
            for_each(e.cbegin(), e.cend(), [](const int &n) {
                cout << n << ' ';
            });
            cout << endl;
        }
    });

    return 0;
}