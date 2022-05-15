/**
 * @file JZ12 矩阵中的路径.cpp
 * @date 2022-05-15
 */

/*
描述
请设计一个函数，用来判断在一个n乘m的矩阵中是否存在一条包含某长度为len的字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
例如

[ a b c e ]
[ s f c s ]
[ a d e e ]

​
矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
数据范围：0≤n,m≤20 ,1≤len≤25 

示例1
输入：
[[a,b,c,e],[s,f,c,s],[a,d,e,e]],"abcced"

返回值：
true

示例2
输入：
[[a,b,c,e],[s,f,c,s],[a,d,e,e]],"abcb"

返回值：
false
*/

/* dfs，递归，深度优先遍历，注意递归出口及相关的正确判断 */

#include <string>
#include <vector>
using namespace std;

class Solution {
  private:
    vector<vector<bool>> flags; // 是否访问过的标志位
    string nowstr;              // 当前做的str
    string aimstr;              // 目标要达到的str

    /**
     * @brief 递归深度优先遍历dfs
     * @param matrix 待寻路矩阵
     * @param x 当前符合要求的行索引
     * @param y 当前符合要求的列索引
     * @return true 存在
     * @return false 不存在
     */
    bool dfs(vector<vector<char>> &matrix, int x, int y) {
        flags[x][y] = true;
        nowstr.push_back(matrix[x][y]);

        if (nowstr.size() == aimstr.size()) { // 递归出口
            flags[x][y] = false;
            nowstr.pop_back();
            return true;
        }

        /* 以下依次判断四个方向是否符合要求，一旦符合要求直接返回，否则最后返回false */

        bool f = false;
        if (x - 1 >= 0 && !flags[x - 1][y] && matrix[x - 1][y] == aimstr[nowstr.size()])
            f = dfs(matrix, x - 1, y);
        if (f) {
            flags[x][y] = false;
            nowstr.pop_back();
            return true;
        }
        if (x + 1 < matrix.size() && !flags[x + 1][y] && matrix[x + 1][y] == aimstr[nowstr.size()])
            f = dfs(matrix, x + 1, y);
        if (f) {
            flags[x][y] = false;
            nowstr.pop_back();
            return true;
        }
        if (y - 1 >= 0 && !flags[x][y - 1] && matrix[x][y - 1] == aimstr[nowstr.size()])
            f = dfs(matrix, x, y - 1);
        if (f) {
            flags[x][y] = false;
            nowstr.pop_back();
            return true;
        }
        if (y + 1 < matrix[0].size() && !flags[x][y + 1] && matrix[x][y + 1] == aimstr[nowstr.size()])
            f = dfs(matrix, x, y + 1);
        flags[x][y] = false;
        nowstr.pop_back();
        return f;
    }

  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix char字符型vector<vector<>> 
     * @param word string字符串 
     * @return bool布尔型
     */
    bool hasPath(vector<vector<char>> &matrix, string word) {
        // write code here

        if (!matrix.size())
            return false;

        int n = matrix.size(), m = matrix[0].size();
        flags.resize(n, vector<bool>(m));
        aimstr = word;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == word[0]) {
                    if (dfs(matrix, i, j))
                        return true;
                }

        return false;
    }
};