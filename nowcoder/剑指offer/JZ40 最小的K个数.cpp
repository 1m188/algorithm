/**
 * @file JZ40 最小的K个数.cpp
 * @date 2022-05-29
 */

/*
描述
给定一个长度为 n 的可能有重复值的数组，找出其中不去重的最小的 k 个数。例如数组元素是4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4(任意顺序皆可)。
数据范围：0\le k,n \le 100000≤k,n≤10000，数组中每个数的大小0 \le val \le 10000≤val≤1000
要求：空间复杂度 O(n)O(n) ，时间复杂度 O(nlogn)O(nlogn)

示例1
输入：
[4,5,1,6,2,7,3,8],4 
复制
返回值：
[1,2,3,4]
复制
说明：
返回最小的4个数即可，返回[1,3,2,4]也可以        
示例2
输入：
[1],0
复制
返回值：
[]
复制
示例3
输入：
[0,1,2,1,2],3
复制
返回值：
[0,1,1]
*/

/* 堆，求前k小的数用大顶堆，读入k个数建堆，之后挨个读入数据，如果和堆顶（最大的）
更小，则代替，并且重新从根部向下调整，直到最后一个数字，所有大的都会被剔除，留下
的都是小的，即为前k小的数 */

#include <vector>
using namespace std;

class Solution {

  private:
    /**
     * @brief 从大顶堆的某处索引处向下调整
     * @tparam T 
     * @param vec 大顶堆
     * @param x 待调整的根部索引
     */
    template <typename T>
    void adjust(vector<T> &vec, int x) {
        T tmp = vec[x];

        int k = x * 2 + 1;
        while (k < vec.size()) {
            if (k + 1 < vec.size() && vec[k + 1] > vec[k])
                k = k + 1;

            if (vec[k] > tmp) {
                vec[x] = vec[k];
            } else
                break;

            x = k;
            k = x * 2 + 1;
        }

        vec[x] = tmp;
    }

    /**
     * @brief 建立大顶堆
     * @tparam T 
     * @param vec 
     */
    template <typename T>
    void build_heap(vector<T> &vec) {
        for (int i = (vec.size() - 1 - 1) / 2; i >= 0; i--)
            adjust(vec, i);
    }

  public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {

        if (k == 0 || input.empty())
            return {};
        else if (k >= input.size())
            return input;

        vector<int> heap(k);
        for (int i = 0; i < k; i++)
            heap[i] = input[i];

        build_heap(heap);

        for (int i = k; i < input.size(); i++) {
            if (input[i] < heap[0]) {
                heap[0] = input[i];
                adjust(heap, 0);
            }
        }

        return heap;
    }
};