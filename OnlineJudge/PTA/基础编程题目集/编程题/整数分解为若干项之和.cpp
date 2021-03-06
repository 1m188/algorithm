/*
7-37 整数分解为若干项之和 （20 分）
将一个正整数N分解成几个正整数相加，可以有多种分解方法，例如7=6+1，7=5+2，7=5+1+1，…。编程求出正整数N的所有整数分解式子。

输入格式：

每个输入包含一个测试用例，即正整数N (0<N≤30)。

输出格式：

按递增顺序输出N的所有整数分解式子。递增顺序是指：对于两个分解序列N
​1
​​ ={n
​1
​​ ,n
​2
​​ ,⋯}和N
​2
​​ ={m
​1
​​ ,m
​2
​​ ,⋯}，若存在i使得n
​1
​​ =m
​1
​​ ,⋯,n
​i
​​ =m
​i
​​ ，但是n
​i+1
​​ <m
​i+1
​​ ,则N
​1
​​ 序列必定在N
​2
​​ 序列之前输出。每个式子由小到大相加，式子间用分号隔开，且每输出4个式子后换行。

输入样例：

7
输出样例：

7=1+1+1+1+1+1+1;7=1+1+1+1+1+2;7=1+1+1+1+3;7=1+1+1+2+2
7=1+1+1+4;7=1+1+2+3;7=1+1+5;7=1+2+2+2
7=1+2+4;7=1+3+3;7=1+6;7=2+2+3
7=2+5;7=3+4;7=7
*/

#include "cstdio"

int count = 0, N = 0, nums[31], index = 0, sum = 0;

//dfs分解数字
void decomposition(int n = 1)
{
    //如果和sum等于N的话直接输出
    if (sum == N)
    {
        printf("%d=%d", N, nums[0]);
        //这里记得要<index，因为在下面的赋值了之后index自加了，所以这里万一等于N的话最后一个值只在index-1
        for (int i = 1; i < index; i++)
        {
            printf("+%d", nums[i]);
        }
        count++;
        if (count == 4)
        {
            count = 0;
            printf("\n");
        }
        //这里注意，最后一行不论满没满4个都输出换行
        else if (index == 1)
        {
            printf("\n");
        }
        else
        {
            printf(";");
        }
    }
    else
    {
        //否则从当前的n开始继续加（为了不重复）
        for (int i = n; i <= N; i++)
        {
            //如果有<=N的数字的话加上去
            if (sum + i <= N)
            {
                nums[index] = i; //记录数字，最后一把输出
                sum += i;
                index++;
                decomposition(i);
                sum -= i; //这里注意sum要减回原来的数字
                index--;
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    scanf("%d", &N);

    decomposition();

    return 0;
}