#include "iostream"
#include "vector"

struct Student //学生结构体，用来记录各种数据，之所以没有使用类，是由于结构体访问数据更加方便，尤其是在学生要睡觉的时候要查看其他所有睡觉人数是否严格大于清醒人数
{
    int A;           //情形时间
    int B;           //睡觉时间
    int C;           //开始时处于周期的位置
    int nowTimeAsMe; //当前的时间处于学生周期什么地方
    bool isAwake;    //是否清醒

    Student() : A(0), B(0), C(0), nowTimeAsMe(0), isAwake(false){};
    Student(int a, int b, int c);
};
bool isAllAwake(const std::vector<Student> &student);               //判定全部同学是否清醒
bool isStartAgain(const std::vector<Student> &student, int nowTim); //判断是否回到了一开始的周期，即是否存在这样一个全部清醒的时间
void TimePassed(std::vector<Student> &student);                     //每过一分钟的处理函数

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<Student> student{};
    for (int i = 0; i < n; i++) //处理输入数据
    {
        int A = 0, B = 0, C = 0;
        std::cin >> A >> B >> C;
        Student s(A, B, C);
        student.push_back(s);
    }

    for (int nowTime = 1;; nowTime++) //从第一分钟开始
    {
        if (isAllAwake(student)) //是否全部清醒
        {
            std::cout << nowTime << std::endl;
            break;
        }
        if (isStartAgain(student, nowTime)) //是否回到周期开始，这里要注意一开始的状态不能判定的
        {
            std::cout << -1 << std::endl;
            break;
        }
        TimePassed(student); //时间流逝！
    }

    return 0;
}

Student::Student(int a, int b, int c) : A(a), B(b), C(c)
{
    nowTimeAsMe = C;
    isAwake = nowTimeAsMe <= A;
}

bool isAllAwake(const std::vector<Student> &student)
{
    for (std::vector<Student>::const_iterator it = student.begin(); it != student.end(); it++)
    {
        if (!it->isAwake)
        {
            return false;
        }
    }
    return true;
}

bool isStartAgain(const std::vector<Student> &student, int nowTime)
{
    if (nowTime == 1)
    {
        return false;
    }
    else
    {
        for (std::vector<Student>::const_iterator it = student.begin(); it != student.end(); it++)
        {
            if (it->nowTimeAsMe != it->C)
            {
                return false;
            }
        }
        return true;
    }
}

void TimePassed(std::vector<Student> &student)
{
    std::vector<std::vector<Student>::iterator> wantToSleep{}; //每一个即将睡觉的学生储存在这个里面，方便之后判断该生是否要睡觉
    int sleepStu = 0;
    for (std::vector<Student>::iterator it = student.begin(); it != student.end(); it++)
    {
        if (!it->isAwake)
        {
            sleepStu++;
        }
        it->nowTimeAsMe = (it->nowTimeAsMe + 1) % (it->A + it->B);
        if (it->nowTimeAsMe == 0) //这里注意，当nowTimeAsMe对周期取余为0的时候是周期的最后一分钟，为周期总长度
        {
            it->nowTimeAsMe = it->A + it->B;
        }
        if (it->nowTimeAsMe <= it->A) //清醒者的判定
        {
            it->isAwake = true;
        }
        else if (it->nowTimeAsMe == it->A + 1) //如果是刚要睡觉则进行判定
        {
            wantToSleep.push_back(it);
        } //之后没有睡觉的判定，是因为在刚要睡觉这里判定过了，之后要改状态的时候也在前面判定过了，所以剩下的都是睡觉之中的，既然如此，那就不要打扰他们吧
    }
    if (sleepStu > student.size() - sleepStu) //若睡觉人数严格大于清醒人数
    {
        for (std::vector<std::vector<Student>::iterator>::iterator it = wantToSleep.begin(); it != wantToSleep.end(); it++)
        {
            (*it)->isAwake = false; //睡！
        }
    }
    else
    {
        for (std::vector<std::vector<Student>::iterator>::iterator it = wantToSleep.begin(); it != wantToSleep.end(); it++)
        {
            (*it)->nowTimeAsMe = 0; //这里很关键，差点没想到，不然就要很麻烦。这里就是如果不能睡觉的话要重新认真听课A分钟重新判定，我一开始还打算给每一个学生做一个这种判定函数之类的，但是之后发现只要把学生的nowTimeAsMe重置为0即可，之后每随着一分钟流逝，其他的也不会改变，对于其他方面没有影响，到了A分钟之后还是要判定，这和他重新听A分钟课是等价的
        }
    }
}