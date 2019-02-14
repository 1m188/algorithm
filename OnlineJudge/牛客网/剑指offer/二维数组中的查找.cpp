/*
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

#include "vector"
using namespace std;

class Solution
{
  public:
    //遍历二维数组之中的每个一维数组，对其用二分查找
    bool Find(int target, vector<vector<int>> array)
    {
        int size = array[0].size();
        int start = 0, end = 0;
        int midIndex = 0;
        for (const vector<int> &v : array)
        {
            start = 0, end = size - 1;
            while (end - start >= 0)
            {
                midIndex = (end - start) / 2 + start;
                if (v[midIndex] == target)
                {
                    return true;
                }
                else if (v[midIndex] > target)
                {
                    end = midIndex - 1;
                }
                else
                {
                    start = midIndex + 1;
                }
            }
        }
        return false;
    }
};