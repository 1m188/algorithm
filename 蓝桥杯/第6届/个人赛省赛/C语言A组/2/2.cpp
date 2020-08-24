
// 星系炸弹

// 在X星系的广袤空间中漂浮着许多X星人造“炸弹”，用来作为宇宙中的路标。
// 每个炸弹都可以设定多少天之后爆炸。
// 比如：阿尔法炸弹2015年1月1日放置，定时为15天，则它在2015年1月16日爆炸。
// 有一个贝塔炸弹，2014年11月9日放置，定时为1000天，请你计算它爆炸的准确日期。

// 请填写该日期，格式为 yyyy-mm-dd  即4位年份2位月份2位日期。比如：2015-02-19
// 请严格按照格式书写。不能出现其它文字或符号。

#include "iostream"
#include "string"
#include "vector"

// 判断闰年
bool leapyear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? true : false;
}

// 转换日期格式
std::string date(int year, int month, int day)
{
    std::string ys = std::to_string(year), ms = std::to_string(month), ds = std::to_string(day);
    while (ys.size() < 4)
        ys.insert(ys.begin(), '0');
    while (ms.size() < 2)
        ms.insert(ms.begin(), '0');
    while (ds.size() < 2)
        ds.insert(ds.begin(), '0');
    return ys + '-' + ms + '-' + ds;
}

const std::vector<int> mday{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 获取当月天数
int monthday(int year, int month)
{
    return leapyear(year) && month == 2 ? 29 : mday[month];
}

int main(int argc, char *argv[])
{

    int year = 2014, month = 11, day = 9;
    int days = 1000;

    while (days--)
        if (++day > monthday(year, month))
        {
            day = 1;

            if (++month == 13)
                month = 1, year++;
        }

    std::cout << date(year, month, day);

    return 0;
}