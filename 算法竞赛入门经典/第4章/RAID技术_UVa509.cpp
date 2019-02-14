#include "iostream"
#include "string"
#include "vector"
#include "cmath"
#include "algorithm"

bool Ex(std::vector<std::vector<std::string>> &dataBlock, std::string kindOfEx); //判断校验正确以及数据是否可以恢复
std::string Recovery(std::vector<std::vector<std::string>> &dataBlock);          //具体恢复数据的操作，将校验码置空，之后将其他的部分按照顺序连接成二进制的数据，并转换成十六进制
std::string Two2Sixteen(std::string two);                                        //二进制字符串转十六进制字符串的函数

int main()
{
    int d = 0, s = 0, b = 0;
    std::string kindOfEx = "";
    std::cin >> d >> s >> b >> kindOfEx;                                                 //处理相关数据的输入
    std::vector<std::vector<std::string>> dataBlock(d, std::vector<std::string>(b, "")); //做磁盘，要注意的是每个磁盘的输入是在同一行，但是后面判断比较的时候要在每个磁盘之间不同的变换
    for (int i = 0; i < d; i++)
    {
        std::string temp = "";
        std::cin >> temp;
        for (int j = 0; j < b; j++)
        {
            dataBlock[i][j] = temp.substr(s * j, s);
        }
    }

    if (Ex(dataBlock, kindOfEx)) //如果判断出来可以恢复
    {
        std::string data = Recovery(dataBlock); //恢复
        std::cout << data << std::endl;
    }
    else
    {
        std::cout << "Disk invalid" << std::endl; //不然就输出相关信息
    }

    return 0;
}

bool Ex(std::vector<std::vector<std::string>> &dataBlock, std::string kindOfEx)
{
    int d = dataBlock.size(), b = dataBlock[0].size(), s = dataBlock[0][0].size();
    std::string differOr = "";
    for (int i = 0; i < s; i++)
    {
        differOr += '0';
    }
    for (int i = 0; i < b; i++)
    {
        std::vector<std::pair<int, int>> badData{};
        for (int j = 0; j < d; j++)
        {
            if (std::find(dataBlock[j][i].begin(), dataBlock[j][i].end(), '?') == dataBlock[j][i].end())
            {
                for (int k = 0; k < s; k++)
                {
                    differOr[k] = (dataBlock[j][i][k] != differOr[k]) + '0';
                }
            }
            else
            {
                badData.push_back(std::pair<int, int>{j, i}); //这里将每一列的损坏数据的坐标存储
            }
        }

        if (badData.size() > 1) //每一列大于1个损坏数据则无法恢复
        {
            return false;
        }
        else if (badData.size() == 1) //如果恰好只有一个损坏数据时可以恢复
        {
            if (kindOfEx == "E")
            {
                for (int k = 0; k < s; k++) //按照当列其他的数据异或结果以及校验方式来判定损坏数据
                {
                    dataBlock[badData[0].first][badData[0].second][k] = differOr[k];
                }
            }
            else
            {
                for (int k = 0; k < s; k++)
                {
                    dataBlock[badData[0].first][badData[0].second][k] = !(differOr[k] - '0') + '0';
                }
            }
            for (int k = 0; k < s; k++) //用恢复数据和剩下的数据异或结果进行异或，得到全1或全0
            {
                differOr[k] = (dataBlock[badData[0].first][badData[0].second][k] != differOr[k]) + '0';
            }
        }

        for (int j = 0; j < s; j++)
        {
            if ((kindOfEx == "E" && differOr[j] != '0') || (kindOfEx == "O" && differOr[j] != '1'))
            {
                return false; //如果最后异或结果和校验模式不符则返回false
            }
        }
    }
    return true;
}

std::string Recovery(std::vector<std::vector<std::string>> &dataBlock)
{
    int d = dataBlock.size(), b = dataBlock[0].size();
    for (int i = 0; i < b; i++)
    {
        dataBlock[i % d][i] = "";
    }

    std::string data = "";
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (dataBlock[j][i] != "")
            {
                data += dataBlock[j][i];
            }
        }
    }

    int eightBitNum = data.size() / 8;
    data += ' ';
    for (int i = 0; i < eightBitNum; i++)
    {
        std::string temp = data.substr(i * 8, 8);
        data += Two2Sixteen(temp);
    }
    return data.substr(data.find(' ') + 1, data.size() - data.find(' ') - 1);
}

std::string Two2Sixteen(std::string two)
{
    long long ten = 0;
    for (int i = 0; i < two.size(); i++)
    {
        ten += pow(2, two.size() - i - 1) * (two[i] - '0');
    }

    const char sixt[16]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    std::string sixteen = "";
    while (true)
    {
        sixteen += sixt[ten % 16];
        ten /= 16;
        if (ten < 16)
        {
            sixteen += sixt[ten];
            break;
        }
    }
    std::reverse(sixteen.begin(), sixteen.end());
    return sixteen;
}