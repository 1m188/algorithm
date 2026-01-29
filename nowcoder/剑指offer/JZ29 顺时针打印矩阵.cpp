/**
 * @file JZ29 顺时针打印矩阵.cpp
 * @date 2022-05-27
 */

/*
描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵：
[[1,2,3,4],
[5,6,7,8],
[9,10,11,12],
[13,14,15,16]]
则依次打印出数字
[1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10]
数据范围:
0 <= matrix.length <= 100
0 <= matrix[i].length <= 100

示例1
输入：
[[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
复制
返回值：
[1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10]
复制
示例2
输入：
[[1,2,3,1],[4,5,6,1],[4,5,6,1]]
复制
返回值：
[1,2,3,1,1,1,6,5,4,4,5,6]
*/

#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> printMatrix(vector<vector<int>> matrix) {

        if (matrix.empty())
            return {};

        vector<int> ans;

        int left = 0,
            right = matrix[0].size(),
            up = 0,
            down = matrix.size();

        while (true) {

            if (left >= right)
                break;

            for (int i = left; i < right; i++)
                ans.push_back(matrix[up][i]);

            up++;

            if (up >= down)
                break;

            for (int i = up; i < down; i++)
                ans.push_back(matrix[i][right - 1]);

            right--;

            if (left >= right)
                break;

            for (int i = right - 1; i >= left; i--)
                ans.push_back(matrix[down - 1][i]);

            down--;

            if (up >= down)
                break;

            for (int i = down - 1; i >= up; i--)
                ans.push_back(matrix[i][left]);

            left++;
        }

        return ans;
    }
};