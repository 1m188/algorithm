#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

const int lengthOfFib = 40;    //匹配斐波那契数时候最多匹配的位数
const int lengthOfGetFib = 60; //计算斐波那契数的时候最多保存的位数
struct DictTree                //每一个字典树节点
{
    int bitNum;                   //该处的位上的数字
    int number;                   //对应索引到该处时候的最小的斐波那契数
    std::vector<DictTree *> next; //指向子节点的指针

    DictTree() : bitNum(-1), number(-1), next(std::vector<DictTree *>(10, nullptr)) {}
};
std::string NumAdd(const std::string &a, const std::string &b); //对于字符串的加法，模拟手工竖式
void AddNum(DictTree &root, std::string num, int number);       //将每个斐波那契数加到字典树里去
void Del(DictTree *root);                                       //递归删除字典树（即new出来的东西），释放内存

int main() //高精度代码会超时，所以这里在计算斐波那契数的时候用的是大数加法（即字符串模拟手工竖式）并且计算的时候只取前60位，题目输入不会产生精度问题，而前60位也可以保证前40位的正确性，另外就是使用字典树对每一个斐波那契数进行索引
{
    DictTree *root = new DictTree();
    std::string num1 = "1", num2 = "1", num = "";
    AddNum(*root, "1", 0);
    for (int i = 2; i < 100000; i++)
    {
        num = NumAdd(num1, num2);
        AddNum(*root, num, i);
        num1 = num2;
        num2 = num;
    }

    std::ios_base::sync_with_stdio(false); //取消和C语言stdio的IO同步（输入输出速度会更快）

    int n = 0;
    std::cin >> n;
    std::vector<std::string> input(n, "");
    for (int i = 0; i < n; i++) //处理输入
    {
        std::cin >> input[i];
    }

    for (std::vector<std::string>::iterator it = input.begin(); it != input.end(); it++) //遍历输入，在字典树中索引
    {
        DictTree *cursor = root;
        int size = it->size();
        for (int i = 0; i < size && i < lengthOfFib; i++)
        {
            cursor = cursor->next[(*it)[i] - '0'];
            if (cursor == nullptr)
            {
                std::cout << "Case #" << std::distance(input.begin(), it) + 1 << ": " << -1 << std::endl;
                goto next;
            }
        }
        std::cout << "Case #" << std::distance(input.begin(), it) + 1 << ": " << cursor->number << std::endl;
    next:;
    }

    Del(root); //释放内存

    return 0;
}

std::string NumAdd(const std::string &a, const std::string &b)
{
    std::string::const_iterator ita = a.end() - 1;
    std::string::const_iterator itb = b.end() - 1;
    std::string result = "";
    int nextBit = 0;
    while (ita >= a.begin() && itb >= b.begin())
    {
        int num = *ita - '0' + *itb - '0' + nextBit;
        result += num % 10 + '0';
        if (result.size() > lengthOfGetFib)
        {
            goto end;
        }
        nextBit = num / 10 % 10;
        ita--, itb--;
    }
    while (ita >= a.begin())
    {
        int num = *ita - '0' + nextBit;
        result += num % 10 + '0';
        if (result.size() > lengthOfGetFib)
        {
            goto end;
        }
        nextBit = num / 10 % 10;
        ita--;
    }
    while (itb >= b.begin())
    {
        int num = *itb - '0' + nextBit;
        result += num % 10 + '0';
        if (result.size() > lengthOfGetFib)
        {
            goto end;
        }
        nextBit = num / 10 % 10;
        itb--;
    }
    if (nextBit == 1)
    {
        result += '1';
    }
end:
    std::reverse(result.begin(), result.end());
    return result;
}

void AddNum(DictTree &root, std::string num, int number)
{
    int size = num.size();
    DictTree *cursor = &root;
    for (int i = 0; i < size && i < lengthOfFib; i++)
    {
        int x = num[i] - '0';
        if (cursor->next[x] == nullptr)
        {
            DictTree *node = new DictTree();
            node->bitNum = x;
            cursor->next[x] = node;
            cursor = node;
            break;
        }
        else
        {
            cursor = cursor->next[x];
        }
    }
    if (cursor->number == -1)
    {
        cursor->number = number;
    }
}

void Del(DictTree *root)
{
    for (std::vector<DictTree *>::iterator it = root->next.begin(); it != root->next.end(); it++)
    {
        if (*it != nullptr)
        {
            Del(*it);
        }
    }
    delete root;
}