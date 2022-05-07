/*
从键盘读入n个整数放入数组中，编写函数CompactIntegers，删除数组中所有值为0的元素，其后元素向数组首端移动。
注意，CompactIntegers函数需要接受数组及其元素个数作为参数，函数返回值应为删除操作执行后数组的新元素个数。输出删除后数组中元素的个数并依次输出数组元素。
样例输入: （输入格式说明：5为输入数据的个数，3 4 0 0 2 是以空格隔开的5个整数）
5 
3 4 0 0 2
样例输出:（输出格式说明：3为非零数据的个数，3 4 2 是以空格隔开的3个非零整数）
3
3 4 2
样例输入: 
7
0 0 7 0 0 9 0
样例输出:
2
7 9
样例输入: 
3
0 0 0
样例输出:
0
*/

#include "iostream"

int CompactIntegers(int *vec, int length)
{
    //这里如果遇到了0就会从0后面开始整体前移一位，所以如果碰到了0不需要i++，前移之后直接就是下一位了
    for (int i = 0; i < length;)
    {
        if (vec[i] == 0)
        {
            //将后面的数字往前面移动
            for (int j = i + 1; j < length; j++)
            {
                vec[j - 1] = vec[j];
                //最后一位直接赋0
                if (j == length - 1)
                {
                    vec[j] = 0;
                }
            }
            //因为删掉了一个0，长度减少
            length--;
        }
        else
        {
            i++;
        }
    }
    return length;
}

int main()
{
    int n = 0;
    std::cin >> n;

    int *vec = new int[n]{0};
    for (int i = 0; i < n; i++)
    {
        std::cin >> vec[i];
    }

    //这个地方函数对数组指针操作，即直接操作数组
    int num = CompactIntegers(vec, n);
    std::cout << num;
    if (num > 0)
    {
        std::cout << std::endl;
    }
    for (int i = 0; i < num; i++)
    {
        std::cout << vec[i] << ' ';
    }

    delete[] vec; //注意回收内存

    return 0;
}