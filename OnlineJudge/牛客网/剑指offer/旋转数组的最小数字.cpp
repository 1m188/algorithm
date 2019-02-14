/*
题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

//由于给出的是非减排序的数组，那么从头开始遍历只要有一个数字比前面的数字严格小就可以确定是最小的了，如果没有的话，那么说明整个数组的元素都是一样的
//直接返回最开始的元素即可

#include "vector"

using namespace std;

class Solution
{
  public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if (rotateArray.size() == 0)
        {
            return 0;
        }
        else
        {
            int num = rotateArray[0];
            for (auto cit = rotateArray.cbegin() + 1; cit != rotateArray.cend(); cit++)
            {
                if (*cit < num)
                {
                    num = *cit;
                    break;
                }
            }
            return num;
        }
    }
};