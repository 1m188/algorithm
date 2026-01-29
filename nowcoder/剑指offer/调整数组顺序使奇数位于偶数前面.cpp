/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

#include "vector"
using namespace std;

class Solution
{
  public:
    void reOrderArray(vector<int> &array)
    {
        int size = array.size();
        for (int i = 0; i < size; i++)
        {
            if (!(array[i] % 2))
            {
                for (int j = i + 1; j < size; j++)
                {
                    if (array[j] % 2)
                    {
                        int num = array[j];
                        for (int k = j - 1; k >= i; k--)
                        {
                            array[k + 1] = array[k];
                        }
                        array[i] = num;
                        break;
                    }
                }
            }
        }
    }
};