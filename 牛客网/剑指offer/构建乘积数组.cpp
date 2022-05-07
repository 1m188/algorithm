/*题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*/

//强行模拟即可

#include "vector"

using namespace std;

class Solution
{
  public:
    vector<int> multiply(const vector<int> &A)
    {
        int size = A.size();
        vector<int> B(size, 1);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (j != i)
                {
                    B[i] *= A[j];
                }
            }
        }
        return B;
    }
};