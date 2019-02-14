/*
生日蜡烛

某君从某年开始每年都举办一次生日party，并且每次都要吹熄与年龄相同根数的蜡烛。

现在算起来，他一共吹熄了236根蜡烛。

请问，他从多少岁开始过生日party的？

请填写他开始过生日party的年龄数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
*/

#include "iostream"

int main()
{
    int age = 0;
    int num = 0;
    for (;; age++)
    {
        for (int j = age;; j++)
        {
            num += j;
            if (num > 236)
            {
                break;
            }
            else if (num == 236)
            {
                goto end;
            }
        }
        num = 0;
    }
end:
    std::cout << age << std::endl;

    return 0;
}