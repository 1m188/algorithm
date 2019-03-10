/*
02-线性结构4 Pop Sequence （25 分）
Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

Input Specification:

Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.

Output Specification:

For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

Sample Input:

5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
Sample Output:

YES
NO
NO
YES
NO
*/

#include "iostream"
#include "stack"
#include "queue"

int main()
{
    int M = 0, N = 0, K = 0;
    std::cin >> M >> N >> K;

    while (K--)
    {
        //将给出的出栈序列读入队列中
        //辅助队列
        std::queue<int> q;
        for (int i = 0; i < N; i++)
        {
            int t = 0;
            std::cin >> t;
            q.push(t);
        }

        //辅助栈
        std::stack<int> s;
        for (int i = 1; i <= N; i++)
        {
            //数字入栈
            s.push(i);
            //如果超过栈限定大小则跳出去
            if (s.size() > M)
            {
                break;
            }
            else
            {
                //否则将从栈顶开始所有和队列中预定的出栈序列的顺序相等的数字都去掉
                while (!s.empty() && s.top() == q.front())
                {
                    s.pop();
                    q.pop();
                }
            }
        }
        //如果最终栈为空，说明所有的数字都出栈了，即有这种出栈序列，否则没有
        if (s.empty())
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }

    return 0;
}