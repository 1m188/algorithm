/*
描述
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
例如，如果输入长度为7的数组[2,3,1,0,2,5,3]，那么对应的输出是2或者3。
存在不合法的输入的话输出-1

数据范围：0≤n≤10000 
进阶：时间复杂度O(n) ，空间复杂度O(n)

示例1
输入：
[2,3,1,0,2,5,3]

返回值：
2

说明：
2或3都是对的    
*/

/* 保存一个长度为n的数组，每个在numbers中找到的数字，作为索引在数组中置1，如果有
重复置1的话就是重复的数字，如果有数字超过既定范围的话则为非法输入。

这个方法可以保证空间复杂度为O(n)，时间复杂度只需要遍历一遍，也是O(n) */

#include <vector>
using namespace std;

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int duplicate(vector<int> &numbers) {
        // write code here

        int ans = -1;
        vector<bool> flags(numbers.size(), false);

        for (const auto &i : numbers) {
            if (1 < 0 || i > numbers.size() - 1)
                break;

            if (!flags[i])
                flags[i] = true;
            else {
                ans = i;
                break;
            }
        }

        return ans;
    }
};