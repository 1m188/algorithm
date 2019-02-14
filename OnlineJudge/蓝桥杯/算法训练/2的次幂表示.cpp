/*
问题描述
　　任何一个正整数都可以用2进制表示，例如：137的2进制表示为10001001。
　　将这种2进制表示写成2的次幂的和的形式，令次幂高的排在前面，可得到如下表达式：137=2^7+2^3+2^0
　　现在约定幂次用括号来表示，即a^b表示为a（b）
　　此时，137可表示为：2（7）+2（3）+2（0）
　　进一步：7=2^2+2+2^0 （2^1用2表示）
　　3=2+2^0 
　　所以最后137可表示为：2（2（2）+2+2（0））+2（2+2（0））+2（0）
　　又如：1315=2^10+2^8+2^5+2+1
　　所以1315最后可表示为：
　　2（2（2+2（0））+2）+2（2（2+2（0）））+2（2（2）+2（0））+2+2（0）
输入格式
　　正整数（1<=n<=20000）
输出格式
　　符合约定的n的0，2表示（在表示中不能有空格）
样例输入
137
样例输出
2(2(2)+2+2(0))+2(2+2(0))+2(0)
样例输入
1315
样例输出
2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
提示
　　用递归实现会比较简单，可以一边递归一边输出
*/

#include "iostream"
#include "string"
#include "algorithm"

//输入数字转换为二进制字符串
std::string dec2Bin(int decNum)
{
    std::string bin;
    while (decNum)
    {
        bin.push_back(decNum % 2 + '0');
        decNum /= 2;
    };
    std::reverse(bin.begin(), bin.end());
    return bin;
}

//递归输出
void print(const std::string &str)
{
    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        if (str[i] == '1')
        {
            int p = size - i - 1;
            std::cout << "2";

            if (p <= 1)
            {
                if (p == 1 && str[i + 1] == '1')
                {
                    std::cout << "+2(0)";
                    break;
                }
                else if (p == 0 && str[i] == '1')
                {
                    std::cout << "(0)";
                }
            }
            else
            {
                std::cout << "(";
                print(dec2Bin(p));
                std::cout << ")";
                //这里要确定从当前位往后走还有1的话才会输出一个加号
                for (int j = i + 1; j < size; j++)
                {
                    if (str[j] == '1')
                    {
                        std::cout << "+";
                        break;
                    }
                }
            }
        }
    }
}

int main()
{
    int n = 0;
    std::cin >> n;

    print(dec2Bin(n));

    return 0;
}