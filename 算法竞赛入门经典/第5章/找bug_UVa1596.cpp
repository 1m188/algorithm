#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cmath"
#include "map"

struct arrayInfo //每个数组的相关信息
{
    std::string arrayName;         //数组名
    int size;                      //数组大小
    std::map<int, int> arrElement; //数组中已经定义的元素

    arrayInfo() : arrayName(""), size(0), arrElement(std::map<int, int>{}) {}
};
std::pair<std::string, int> RecursionResolution(std::string resoluteAim, std::vector<arrayInfo> &program); //递归解析嵌套的数组值

int main() //没有测试，有点麻烦，不过还好
{
    std::vector<arrayInfo> program{};
    int codeRowNum = 0;
    for (int i = 0; i < 1000; i++)
    {
        std::string code = "";
        std::cin >> code; //输入

        codeRowNum++;

        if (std::find(code.begin(), code.end(), "=") == code.end()) //如果是定义数组
        {
            std::string arrName = code.substr(0, code.find('['));
            std::string arrSize = code.substr(code.find('[') + 1, code.find(']') - code.find('[') - 1);
            int size = 0;
            for (int i = 0; i < arrSize.size(); i++)
            {
                size += pow(10, i) * (arrSize[arrSize.size() - i - 1] - '0');
            }
            arrayInfo t = arrayInfo();
            t.arrayName = arrName;
            t.size = size;
            program.push_back(t);
        }
        else //如果是数组赋值
        {
            std::string equalLeft = code.substr(0, code.find('=')), equalRight = code.substr(code.find('=') + 1); //获得等式左右两边的操作数
            try
            {
                std::pair<std::string, int> leftResoluteResult = RecursionResolution(equalLeft, program);   //递归解析左边的表达式
                std::pair<std::string, int> rightResoluteResult = RecursionResolution(equalRight, program); //右边的

                std::vector<arrayInfo>::iterator equalLeftIt = std::find_if(program.begin(), program.end(), [&](arrayInfo i) { return i.arrayName == leftResoluteResult.first; });   //给出左边解析结果的数组
                std::vector<arrayInfo>::iterator equalRightIt = std::find_if(program.begin(), program.end(), [&](arrayInfo i) { return i.arrayName == rightResoluteResult.first; }); //右边的

                if (equalRightIt == program.end()) //如果返回的只有一个整数
                {
                    equalLeftIt->arrElement[leftResoluteResult.second] = rightResoluteResult.second; //就说明右边没有嵌套的数组表达式
                }
                else
                {
                    equalLeftIt->arrElement[leftResoluteResult.second] = equalRightIt->arrElement[rightResoluteResult.second]; //如果有的话就给出那个值
                }
            }
            catch (...) //异常
            {
                std::cout << "The mistake is in the " << codeRowNum << " row.\n";
                break;
            }
        }
    }

    return 0;
}

std::pair<std::string, int> RecursionResolution(std::string resoluteAim, std::vector<arrayInfo> &program) //关键之处，递归解析数组的表达式类似于a[a[b[0]]]这种
{
    if (std::find(resoluteAim.begin(), resoluteAim.end(), '[') == resoluteAim.end()) //递归结束条件，当解析目标没有中括号时（即为单个常数）
    {
        int value = 0;
        for (int i = 0; i < resoluteAim.size(); i++)
        {
            value += pow(10, i) * (resoluteAim[resoluteAim.size() - i - 1] - '0');
        }
        return std::pair<std::string, int>{"", value};
    }
    else
    {
        std::string thisLayerArrName = resoluteAim.substr(0, resoluteAim.find('['));                                                                        //否则给出本层数组名
        std::string nextLayer = resoluteAim.substr(resoluteAim.find_first_of('[') + 1, resoluteAim.find_last_of(']') - resoluteAim.find_first_of('[') - 1); //下一层的解析式
        std::pair<std::string, int> num = RecursionResolution(nextLayer, program);                                                                          //解析
        int value = 0;
        std::vector<arrayInfo>::iterator it = std::find_if(program.begin(), program.end(), [&](arrayInfo i) { return i.arrayName == thisLayerArrName; }); //本层的数组对象，为了之后验证是否未定义

        if (num.first == "")
        {
            value = num.second; //单个数字
        }
        else
        {
            value = std::find_if(program.begin(), program.end(), [&](arrayInfo i) { return i.arrayName == num.first; })->arrElement[num.second]; //放回的数组值
        }

        if ((value < 0 || value >= it->size) || (it->arrElement.find(value) == it->arrElement.end()))
        {
            throw "Error"; //有超过下标或是未定义则抛异常
        }
        else
        {
            return std::pair<std::string, int>{thisLayerArrName, it->arrElement[value]}; //没有则返回本层验证过的数组名和下标序号
        }
    }
}