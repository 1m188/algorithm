/*
01-复杂度2 Maximum Subsequence Sum （25 分）
Given a sequence of K integers { N
​1
​​ , N
​2
​​ , ..., N
​K
​​  }. A continuous subsequence is defined to be { N
​i
​​ , N
​i+1
​​ , ..., N
​j
​​  } where 1≤i≤j≤K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (≤10000). The second line contains K numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:

10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:

10 1 4
*/

#include "iostream"
#include "vector"

int main()
{
    int K = 0;
    std::cin >> K;
    std::vector<int> vec(K);
    bool isAllNegative = true;
    for (int i = 0; i < K; i++)
    {
        std::cin >> vec[i];
        if (vec[i] >= 0)
        {
            isAllNegative = false;
        }
    }

    if (isAllNegative)
    {
        std::cout << 0 << ' ' << vec[0] << ' ' << vec.back();
    }
    else
    {
        int first = 0, last = 0, tFirst = 0, tLast = 0;
        int max = 0, sum = 0;
        first = last = tFirst = tLast = vec[0];
        max = sum = vec[0];
        for (int i = 1; i < K; i++)
        {
            //这个地方要注意<0，如果出现类似于0000123的序列，那么最大的值应该是从最开始的0开始，题目要求取尽可能小的索引（这里真是困了我好久...）
            //而如果这里<0了的话，那么在初始定义sum和其他变量的时候都要相应的赋予第一个值，之后从第二个值开始判断
            if (sum < 0)
            {
                sum = vec[i];
                tFirst = vec[i];
                tLast = vec[i];
            }
            else
            {
                sum += vec[i];
                tLast = vec[i];
            }
            if (sum > max)
            {
                max = sum;
                first = tFirst;
                last = tLast;
            }
        }
        std::cout << max << ' ' << first << ' ' << last;
    }

    return 0;
}