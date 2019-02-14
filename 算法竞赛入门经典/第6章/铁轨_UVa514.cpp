#include "iostream"
#include "stack"
#include "vector"
int main() //用栈模拟
{
    int n = 0;
    std::cin >> n;
    std::vector<int> target(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> target[i]; //输入火车出站顺序
    }

    std::stack<int> s{};
    bool isOk = true;
    for (int A = 1, B = 0; B < n;) //A从1到n，B从0到n-1
    {
        if (A < target[B]) //如果A小于出站的B的顺序，那么A进栈，之后自加
        {
            s.push(A);
            A++;
        }
        else if (A == target[B]) //当等于的时候，表示刚好这个车厢可以进站之后直接出站
        {
            A++, B++;
        }
        else if (!s.empty() && s.top() == target[B]) //如果栈非空而最顶上的元素又等于出站的火车车厢的编号的话，说明要出栈一个
        {
            s.pop();
            B++;
        }
        else if (A <= n) //如果A还小于等于n的话，A进栈
        {
            s.push(A);
            A++;
        }
        else //如果以上情形都不满足而此时B小于n-1的话，说明A那里的火车车厢已经无法满足B中剩下的出站顺序了，于是失败
        {
            isOk = false;
            break;
        }
    }

    if (isOk) //不然的话就不会改变isOk的值，那么便可以如此出站
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }

    return 0;
}