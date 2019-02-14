#include "iostream"
#include "string"
#include "vector"
#include "algorithm"

int Gcd(int a, int b)
{
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    int c = a % b;
    while (c)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int main()
{
    int a = 0, b = 0;
    std::cin >> a;
    std::cin >> b;

    if (a == b)
    {
        std::cout << "1.(0)" << '\t' << 1 << std::endl;
    }
    else
    {
        int c = Gcd(a, b);
        a /= c;
        b /= c;

        std::string num;
        std::vector<int> divisor;

        if (a > b) //将a/b大于1的那一部分添加进字符串中
        {
            int temp = a / b;
            while (temp)
            {
                num += temp % 10 + 48;
                temp /= 10;
            }
            reverse(num.begin(), num.end());
            a %= b;
        }
        else
        {
            num += '0';
        }
        num += '.';

        for (;;)
        {
            num += a * 10 / b + 48; //将小数点后的数一个个的加入字符串以供之后判断
            a = a * 10 % b;
            divisor.push_back(a);

            if (!a)
            {
                std::cout << num << "(0)" << '\t' << 1 << std::endl;
                break;
            }

            for (int i = 0; i < divisor.size() - 1; i++) //循环小数在小数点后的数每一次做除法时的余数必定是每个循环节只循环一次，因此根据每一次做除法的余数是否在之前有过重复来断定循环节的长度
            {
                if (divisor[i] == divisor.back())
                {
                    for (int j = 0; j <= num.find('.'); j++)
                    {
                        std::cout << num[j];
                    }
                    std::cout << '(';
                    for (int j = num.find('.') + 1; j < num.size() - 1 && j < 50 + num.find('.') + 1; j++)
                    {
                        std::cout << num[j];
                    }
                    if (divisor.size() - 1 > 50)
                    {
                        std::cout << "...";
                    }
                    std::cout << ')' << '\t' << num.size() - num.find('.') - 2;
                    goto end;
                }
            }
        }
    end:;
    }

    return 0;
}