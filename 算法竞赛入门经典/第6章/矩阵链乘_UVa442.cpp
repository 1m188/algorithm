#include "iostream"
#include "stack"
#include "map"
#include "string"
#include "vector"
#include "algorithm"
int main() //还是栈，做表达式解析，入栈出栈等
{
    int n = 0;
    std::cin >> n;
    std::map<char, std::pair<int, int>> matrix{}; //每个矩阵对应的行数和列数
    for (int i = 0; i < n; i++)
    {
        char name{};
        std::cin >> name;
        std::pair<int, int> ranks{};
        std::cin >> ranks.first >> ranks.second;
        matrix[name] = ranks;
    }
    std::string oper = "";
    std::cin >> oper;
    std::stack<char> s{};

    int multiplyNum = 0;
    for (char i : oper)
    {
        if (i != ')') //不是右括号的都入栈
        {
            s.push(i);
        }
        else //一旦是右括号的话把左边知道第一个左括号之间的东西都拿出来计算，给出一个中间矩阵，保存为一个特殊字符，之后压栈，直到所有的括号之间的矩阵都计算完
        {
            std::vector<char> t{};
            while (s.top() != '(')
            {
                t.push_back(s.top());
                s.pop();
            }
            s.pop();
            std::reverse(t.begin(), t.end());
            std::pair<int, int> mn{matrix[t[0]].first, matrix[t[0]].second};
            t.erase(t.begin());
            for (char j : t)
            {
                if (mn.second != matrix[j].first)
                {
                    goto end;
                }
                else
                {
                    multiplyNum += mn.first * mn.second * matrix[j].second;
                    mn.second = matrix[j].second;
                }
            }
            matrix['@'] = mn;
            s.push('@');
        }
    }

end:
    std::cout << multiplyNum << std::endl;

    return 0;
}