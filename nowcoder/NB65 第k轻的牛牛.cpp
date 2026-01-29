/*
描述
在农场里，农民们有一群牛，每头牛的体重不同。农民们将所有牛的体重记录在一个数组中。现在农民们想要知道，如果将这些牛的体重从小到大排序，那么第k小的体重是多少。请你编写一个程序，找出数组中第k小的元素。

你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
示例1
输入：
[600,500,800,700,550,650],3
复制
返回值：
600
复制
备注：
1 <= k <= weights.length <= 10000
0 <= weights[i] <= 5000
*/

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param weights int整型vector
     * @param k int整型
     * @return int整型
     */
    int findKthSmallest(vector<int> &weights, int k) {
        // write code here

        // 调整堆
        auto adjust = [](vector<int> &vec, int idx) {
            int length = vec.size();
            while (true) {
                int x = idx * 2 + 1, y = x + 1;
                if (x >= length) break;
                int a = x;
                if (y < length && vec[y] > vec[x]) a = y;
                if (vec[a] <= vec[idx]) break;
                swap(vec[a], vec[idx]);
                idx = a;
            }
        };

        // 构建堆
        auto build_heap = [&](vector<int> &vec) {
            for (int i = (vec.size() - 1) / 2; i >= 0; i--) {
                adjust(vec, i);
            }
        };

        vector<int> heap(k);
        for (int i = 0; i < k; i++)
            heap[i] = weights[i];
        build_heap(heap);

        for (int i = k; i < weights.size(); i++) {
            if (weights[i] < heap[0]) {
                heap[0] = weights[i];
                adjust(heap, 0);
            }
        }

        return *max_element(heap.begin(), heap.end());
    }
};