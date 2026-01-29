/*
题目描述
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
*/

#include "vector"

using namespace std;

class Solution
{
  public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        int maxValue = array[0];
        int size = array.size();
        //对数组从头开始遍历，从第m位加到第n位，比较结果大小，n慢慢的减小到m，n==m之后m自加，这样获取整个数组的所有连续子向量之和
        for (int i = 0; i < size; i++)
        {
            for (int j = size - 1; j >= i; j--)
            {
                int num = 0;
                for (int k = i; k <= j; k++)
                {
                    num += array[k];
                }
                if (num > maxValue)
                {
                    maxValue = num;
                }
            }
        }
        return maxValue;
    }
};