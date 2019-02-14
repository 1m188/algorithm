#include "iostream"
#include "list"
#include "string"
int main() //用列表，插入更有效率一些
{
    std::list<char> text{};
    std::list<char>::iterator index = text.begin();
    std::string t = "";
    while (std::cin >> t && !std::cin.eof())
    {
        for (char i : t)
        {
            if (i == '[') //Home键，光标变成头部
            {
                index = text.begin();
            }
            else if (i == ']') //end键，光标变成尾部
            {
                index = text.end();
            }
            else //在相应的地方插入数据，这里要注意插入之后原本的index会指向新的数据的后面一个，所以不必再对index进行自加之类的操作
            {
                text.insert(index, i);
            }
        }

        for (char i : text)
        {
            std::cout << i;
        }
        std::cout << std::endl;
        text.clear(); //这里注意每次计算完了一个悲剧文本之后要清空列表以用作下一次计算
    }

    return 0;
}