#include "iostream"
#include "vector"
#include "tuple"
#include "string"
#include "algorithm"
#include "iomanip"

typedef std::tuple<unsigned int, std::string, unsigned int, std::string, unsigned int, unsigned int, unsigned int, unsigned int> data;
typedef std::vector<data> database;

void DisplayMainMenu();
void Add();
void Remove();
void Query();
void Show_ranking();
void Show_Statistics();
void Exit();

database student{};

int main() //呼...一开始还以为是多简单的一个程序，没想到居然是靠工作量来堆难度的...有些地方还可以再优化，有些地方写得不太好...懒得改了...而且这个题目名字...就连书上都不愿意写题目的背景...
{
    DisplayMainMenu();
    int num = 0;
    while (std::cin >> num && num)
    {
        if (num == 1)
        {
            Add();
        }
        else if (num == 2)
        {
            Remove();
        }
        else if (num == 3)
        {
            Query();
        }
        else if (num == 4)
        {
            Show_ranking();
        }
        else if (num == 5)
        {
            Show_Statistics();
        }
        DisplayMainMenu();
    }

    return 0;
}

void DisplayMainMenu()
{
    std::cout << "Welcome to Student Performance Management System (SPMS).";
    std::cout << std::endl
              << std::endl;
    std::cout << "1 - Add\n";
    std::cout << "2 - Remove\n";
    std::cout << "3 - Query\n";
    std::cout << "4 - Show ranking\n";
    std::cout << "5 - Show Statistics\n";
    std::cout << "0 - Exit\n";
}

void Add()
{
    std::cout << "please enter SID, CID, name and four scores. Enter 0 to finish.\n";
    std::string stuInfo = "";
    std::cin >> stuInfo;
    while (stuInfo != "0")
    {
        unsigned int num = 0;
        std::string SID = "";
        unsigned int CID = 0;
        std::string name = "";
        unsigned int chinese = 0, math = 0, english = 0, programing = 0;
        std::cin >> SID >> CID >> name >> chinese >> math >> english >> programing;
        auto temp = std::make_tuple(num, SID, CID, name, chinese, math, english, programing);
        for (database::iterator it = student.begin(); it != student.end(); it++)
        {
            if (std::get<1>(temp) == std::get<1>(*it))
            {
                std::cout << "Duplicated SID.\n";
                goto again;
            }
        }
        std::get<0>(temp) = student.size() + 1;
        student.push_back(temp);
    again:
        std::cout << "please enter SID, CID, name and four scores. Enter 0 to finish.\n";
        std::cin >> stuInfo;
    }
}

void Remove()
{
    std::cout << "Please enter SID or name. Enter 0 to finish.\n";
    std::string in = "";
    std::cin >> in;
    while (in != "0")
    {
        int num = 0;
        for (database::iterator it = student.begin(); it != student.end(); it++)
        {
            if (std::get<1>(*it) == in || std::get<3>(*it) == in)
            {
                student.erase(it);
                num++;
            }
        }
        std::cout << num << " student(s) removed.\n";
        std::sort(student.begin(), student.end(), [=](data a, data b) -> bool { return std::get<0>(a) > std::get<0>(b); });
        for (int i = 0; i < student.size(); i++)
        {
            std::get<0>(student[i]) = i + 1;
        }
        std::cout << "Please enter SID or name. Enter 0 to finish.\n";
        std::cin >> in;
    }
}

void Query()
{
    std::cout << "Please enter SID or name. Enter 0 to finish.\n";
    std::string in = "";
    std::cin >> in;
    while (in != "0")
    {
        std::vector<std::tuple<data, unsigned int, unsigned int, double>> temp{};
        std::sort(student.begin(), student.end(), [=](data a, data b) -> bool { return (std::get<4>(b) + std::get<5>(b) + std::get<6>(b) + std::get<7>(b)) < (std::get<4>(a) + std::get<5>(a) + std::get<6>(a) + std::get<7>(a)); });
        for (database::iterator it = student.begin(); it != student.end(); it++)
        {
            if (std::get<1>(*it) == in || std::get<3>(*it) == in)
            {
                unsigned int total = std::get<4>(*it) + std::get<5>(*it) + std::get<6>(*it) + std::get<7>(*it);
                unsigned int num = std::distance(student.begin(), it) + 1;
                temp.push_back(make_tuple(*it, num, total, static_cast<double>(total) / 4));
                if (std::get<2>(temp.back()) == std::get<2>(*(temp.end() - 2)))
                {
                    std::get<1>(temp.back()) = std::get<1>(*(temp.end() - 2));
                }
            }
        }
        if (!temp.empty())
        {
            std::sort(temp.begin(), temp.end(), [=](std::tuple<data, unsigned int, unsigned int, double> a, std::tuple<data, unsigned int, unsigned int, double> b) -> bool { return std::get<0>(std::get<0>(b)) < std::get<0>(std::get<0>(a)); });
            for (int i = 0; i < temp.size(); i++)
            {
                std::cout << std::get<1>(temp[i]) << ' ';
                std::cout << std::get<1>(std::get<0>(temp[i])) << ' ';
                std::cout << std::get<2>(std::get<0>(temp[i])) << ' ';
                std::cout << std::get<3>(std::get<0>(temp[i])) << ' ';
                std::cout << std::get<4>(std::get<0>(temp[i])) << ' ';
                std::cout << std::get<5>(std::get<0>(temp[i])) << ' ';
                std::cout << std::get<6>(std::get<0>(temp[i])) << ' ';
                std::cout << std::get<7>(std::get<0>(temp[i])) << ' ';
                std::cout << std::get<2>(temp[i]) << ' ';
                std::cout.setf(std::ios::fixed);
                std::cout << std::setprecision(2);
                std::cout << std::get<3>(temp[i]) << std::endl;
                std::cout.unsetf(std::ios::fixed);
                std::cout << std::setprecision(6);
            }
        }
        std::cout << "Please enter SID or name. Enter 0 to finish.\n";
        std::cin >> in;
    }
}

void Show_ranking()
{
    std::cout << "Showing the ranklist hurts students's self-esteem. Don't do that.\n";
}

void Show_Statistics()
{
    std::cout << "Please enter class ID, 0 for the whole statistics.\n";
    int in = 0;
    std::cin >> in;
    if (in)
    {
        std::vector<data> temp{};
        double chineseAverage = 0, mathAverage = 0, englishAverage = 0, programingAverage = 0;
        int chinesePass = 0, chineseFail = 0, mathPass = 0, mathFail = 0, englishPass = 0, englishFail = 0, programingPass = 0, programingFail = 0;
        int passAll = 0, pass3 = 0, pass2 = 0, pass1 = 0, failAll = 0;
        for (database::iterator it = student.begin(); it != student.end(); it++)
        {
            if (std::get<2>(*it) == in)
            {
                int passNum = 0;
                temp.push_back(*it);
                chineseAverage += std::get<4>(temp.back());
                mathAverage += std::get<5>(temp.back());
                englishAverage += std::get<6>(temp.back());
                programingAverage += std::get<7>(temp.back());
                std::get<4>(temp.back()) >= 60 ? chinesePass++, passNum++ : chineseFail++;
                std::get<5>(temp.back()) >= 60 ? mathPass++, passNum++ : mathFail--;
                std::get<6>(temp.back()) >= 60 ? englishPass++, passNum++ : englishFail--;
                std::get<7>(temp.back()) >= 60 ? programingPass++, passNum++ : programingFail--;
                if (passNum == 4)
                {
                    passAll++;
                }
                else if (passNum == 3)
                {
                    pass3++;
                }
                else if (passNum == 2)
                {
                    pass2++;
                }
                else if (passNum == 1)
                {
                    pass1++;
                }
                else
                {
                    failAll++;
                }
            }
        }
        chineseAverage /= chinesePass + chineseFail;
        mathAverage /= mathPass + mathFail;
        englishAverage /= englishPass + englishFail;
        programingAverage /= programingPass + programingFail;

        std::vector<std::tuple<std::string, double, int, int>> output{std::make_tuple("Chinese", chineseAverage, chinesePass, chineseFail), std::make_tuple("Math", mathAverage, mathPass, mathFail), std::make_tuple("English", englishAverage, englishPass, englishFail), std::make_tuple("Programing", programingAverage, programingPass, programingFail)};

        for (std::vector<std::tuple<std::string, double, int, int>>::iterator it = output.begin(); it != output.end(); it++)
        {
            std::cout.setf(std::ios::fixed);
            std::cout << std::setprecision(2);
            std::cout << std::get<0>(*it) << std::endl;
            std::cout << "Average Score: " << std::get<1>(*it) << std::endl;
            std::cout.unsetf(std::ios::fixed);
            std::cout << std::setprecision(6);
            std::cout << "Number of passed students: " << std::get<2>(*it) << std::endl;
            std::cout << "Number of failed students: " << std::get<3>(*it) << std::endl;
        }

        std::cout << "OverAll:\n";
        std::cout << "Number of students who passed all subjects: " << passAll << std::endl;
        std::cout << "Number of students who passed 3 or more subjects: " << passAll + pass3 << std::endl;
        std::cout << "Number of students who passed 2 or more subjects: " << passAll + pass3 + pass2 << std::endl;
        std::cout << "Number of students who passed 1 or more subjects: " << passAll + pass3 + pass2 + pass1 << std::endl;
        std::cout << "Number of students who failed all subjects: " << failAll << std::endl;
    }
    else
    {
        double chineseAverage = 0, mathAverage = 0, englishAverage = 0, programingAverage = 0;
        int chinesePass = 0, chineseFail = 0, mathPass = 0, mathFail = 0, englishPass = 0, englishFail = 0, programingPass = 0, programingFail = 0;
        int passAll = 0, pass3 = 0, pass2 = 0, pass1 = 0, failAll = 0;
        for (database::iterator it = student.begin(); it != student.end(); it++)
        {
            int passNum = 0;
            chineseAverage += std::get<4>(*it);
            mathAverage += std::get<5>(*it);
            englishAverage += std::get<6>(*it);
            programingAverage += std::get<7>(*it);
            std::get<4>(*it) >= 60 ? chinesePass++, passNum++ : chineseFail++;
            std::get<5>(*it) >= 60 ? mathPass++, passNum++ : mathFail--;
            std::get<6>(*it) >= 60 ? englishPass++, passNum++ : englishFail--;
            std::get<7>(*it) >= 60 ? programingPass++, passNum++ : programingFail--;
            if (passNum == 4)
            {
                passAll++;
            }
            else if (passNum == 3)
            {
                pass3++;
            }
            else if (passNum == 2)
            {
                pass2++;
            }
            else if (passNum == 1)
            {
                pass1++;
            }
            else
            {
                failAll++;
            }
        }
        chineseAverage /= chinesePass + chineseFail;
        mathAverage /= mathPass + mathFail;
        englishAverage /= englishPass + englishFail;
        programingAverage /= programingPass + programingFail;

        std::vector<std::tuple<std::string, double, int, int>> output{std::make_tuple("Chinese", chineseAverage, chinesePass, chineseFail), std::make_tuple("Math", mathAverage, mathPass, mathFail), std::make_tuple("English", englishAverage, englishPass, englishFail), std::make_tuple("Programing", programingAverage, programingPass, programingFail)};

        for (std::vector<std::tuple<std::string, double, int, int>>::iterator it = output.begin(); it != output.end(); it++)
        {
            std::cout.setf(std::ios::fixed);
            std::cout << std::setprecision(2);
            std::cout << std::get<0>(*it) << std::endl;
            std::cout << "Average Score: " << std::get<1>(*it) << std::endl;
            std::cout.unsetf(std::ios::fixed);
            std::cout << std::setprecision(6);
            std::cout << "Number of passed students: " << std::get<2>(*it) << std::endl;
            std::cout << "Number of failed students: " << std::get<3>(*it) << std::endl;
        }

        std::cout << "OverAll:\n";
        std::cout << "Number of students who passed all subjects: " << passAll << std::endl;
        std::cout << "Number of students who passed 3 or more subjects: " << passAll + pass3 << std::endl;
        std::cout << "Number of students who passed 2 or more subjects: " << passAll + pass3 + pass2 << std::endl;
        std::cout << "Number of students who passed 1 or more subjects: " << passAll + pass3 + pass2 + pass1 << std::endl;
        std::cout << "Number of students who failed all subjects: " << failAll << std::endl;
    }
}