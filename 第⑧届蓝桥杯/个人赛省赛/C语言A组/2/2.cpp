/*
标题：跳蚱蜢

如图 p1.png 所示： 
有9只盘子，排成1个圆圈。
其中8只盘子内装着8只蚱蜢，有一个是空盘。
我们把这些蚱蜢顺时针编号为 1~8

每只蚱蜢都可以跳到相邻的空盘中，
也可以再用点力，越过一个相邻的蚱蜢跳到空盘中。

请你计算一下，如果要使得蚱蜢们的队形改为按照逆时针排列，
并且保持空盘的位置不变（也就是1-8换位，2-7换位,...），至少要经过多少次跳跃？

注意：要求提交的是一个整数，请不要填写任何多余内容或说明文字。
*/

#include "iostream"
#include "queue"

std::queue<int> queue;
std::queue<int> qu;
bool isRepeat[987654322] = {false};
int d[4] = {-2, -1, 1, 2};
int a[9]{};

int sum(int *arr)
{
    int num = 0;
    for (int i = 0; i < 9; i++)
    {
        num *= 10;
        num += arr[i];
    }
    return num;
}

void bfs()
{
    queue.push(912345678);
    isRepeat[912345678] = true;
    qu.push(1);

    while (true)
    {
        int num = queue.front();
        queue.pop();
        int index = 8;
        int zero = 0;
        int count = qu.front();
        qu.pop();
        while (num)
        {
            a[index] = num % 10;
            if (a[index] == 9)
            {
                zero = index;
            }
            index--;
            num /= 10;
        }
        for (int i = 0; i < 4; i++)
        {
            std::swap(a[zero], a[(zero + d[i] + 9) % 9]);
            int num = sum(a);
            if (!isRepeat[num])
            {
                if (num == 987654321)
                {
                    std::cout << count << std::endl;
                    return;
                }
                queue.push(num);
                isRepeat[num] = true;
                qu.push(count + 1);
            }
            std::swap(a[zero], a[(zero + d[i] + 9) % 9]);
        }
    }
}

int main()
{
    bfs();
    return 0;
}