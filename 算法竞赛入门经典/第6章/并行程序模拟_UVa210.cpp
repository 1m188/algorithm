#include "iostream"
#include "queue"
#include "string"
#include "vector"
#include "map"
#include "sstream"

struct Program //程序信息
{
    int num;                                     //编号
    std::vector<std::string> words;              //语句
    std::vector<std::string>::iterator nextOper; //即将要执行的指令
    int time;                                    //所用时间

    Program() : num(0), words(std::vector<std::string>{}), nextOper(words.begin()), time(0) {}
};

int main() //直接模拟，用STL的双端队列，没有测试
{
    int n = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, Q = 0;
    std::cin >> n >> t1 >> t2 >> t3 >> t4 >> t5 >> Q;
    std::cin.get();

    std::deque<Program> waitQueue{};
    std::queue<Program> stopQueue{};
    std::map<std::string, int> variableToValue{};
    bool isOneLock = false;

    for (int i = 0; i < n; i++) //处理输入
    {
        Program p = Program();
        p.num = i + 1;
        std::string t = "";
        while (std::getline(std::cin, t) && !std::cin.eof())
        {
            p.words.push_back(t);
        }
        waitQueue.push_back(p);
    }

    while (!waitQueue.empty())
    {
        Program program = waitQueue.front();
        waitQueue.pop_front();
        while (program.time < Q) //当所用时间小于Q的时候
        {
            if (*(program.nextOper) == "end") //各个指令的判断
            {
                program.time += t5;
            }
            else if (*(program.nextOper) == "unlock")
            {
                isOneLock = false;
                waitQueue.push_front(stopQueue.front());
                stopQueue.pop();
                program.time += t4;
            }
            else if (*(program.nextOper) == "lock")
            {
                if (isOneLock)
                {
                    stopQueue.push(program);
                    break;
                }
                else
                {
                    isOneLock = true;
                    program.time += t3;
                }
            }
            else if ((program.nextOper)->find("print") != std::string::npos)
            {
                std::cout << program.num << ' ' << variableToValue[(program.nextOper)->substr((program.nextOper)->find(' ') + 1)];
                program.time += t2;
            }
            else if ((program.nextOper)->find("=") != std::string::npos)
            {
                std::stringstream ss((program.nextOper)->substr((program.nextOper)->find('=') + 1)); //获取等号之后的值
                int value = 0;
                ss >> value;
                variableToValue[(program.nextOper)->substr(0, (program.nextOper)->find('='))] = value; //赋值，用映射保存
                program.time += t1;
            }
            else if (program.nextOper == program.words.end())
            {
                break; //程序执行完则跳出
            }
            program.nextOper++;
        }

        if (program.time >= Q) //只有配额用完了的程序才能进去下一次被执行的队列，没有用完而跳出循环的程序必定是有其他的原因终止，或是去阻止队列，或是已经结束
        {
            program.time = 0;
            waitQueue.push_back(program);
        }
    }

    return 0;
}