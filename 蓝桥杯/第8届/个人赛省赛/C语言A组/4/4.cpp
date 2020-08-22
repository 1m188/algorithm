/*
标题：方格分割

6x6的方格，沿着格子的边线剪开成两部分。
要求这两部分的形状完全相同。

如图：p1.png, p2.png, p3.png 就是可行的分割法。

试计算：
包括这3种分法在内，一共有多少种不同的分割方法。
注意：旋转对称的属于同一种分割法。

请提交该整数，不要填写任何多余的内容或说明文字。

*/

/*
方法用的是走线，将点看成基本的单位，从中间的(3,3)点开始向四周走，直到走到边界，而在走线的过程中另外有一个和它关于
中心(3,3)点完全对称的线也在走，那么走到最后的时候就可以将整个方格分成两块完全一模一样的了，但是要注意由于旋转对称
也算相同，那么最后的结果要/4，使用dfs，每次一条路走到底，之后再回来走别的路。
*/

#include "iostream"
#include "stack"
#include "vector"

//方案数目
int num = 0;
//判断当前的点是否被线走过了
bool judge[7][7]{false};
//每次向上下左右四个方向走
const std::vector<std::pair<int, int>> choice{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int row = 3, int col = 3)
{
    //如果走到底了则数目+1
    if (row == 0 || row == 6 || col == 0 || col == 6)
    {
        num++;
    }
    else
    {
        //否则对四种方向的选择走过，记得标记
        for (const std::pair<int, int> &pair : choice)
        {
            int newRow = row + pair.first;
            int newCol = col + pair.second;
            if (!judge[newRow][newCol])
            {
                judge[newRow][newCol] = true;
                judge[3 * 2 - newRow][3 * 2 - newCol] = true;
                dfs(newRow, newCol);
                judge[newRow][newCol] = false;
                judge[3 * 2 - newRow][3 * 2 - newCol] = false;
            }
        }
    }
}

int main()
{
    //初始点
    judge[3][3] = true;
    dfs();
    //最后的结果/4，因为旋转对称也算一样的
    std::cout << num / 4 << std::endl;
    return 0;
}