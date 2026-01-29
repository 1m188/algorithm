/*
描述
斐波那契数列（Fibonacci Sequence）定义如下：
∙
 
∙ 
F
1
=
F
2
=
1
F 
1
​
 =F 
2
​
 =1；
∙
 
∙ 对于 
i
≧
3
i≧3，有 
F
i
=
F
i
−
1
+
F
i
−
2
F 
i
​
 =F 
i−1
​
 +F 
i−2
​
 。

给定一个正整数 
k
k，请你输出 
F
k
F 
k
​
  的值。由于这个结果可能很大，你只需要输出这个结果对 
(
1
0
9
+
7
)
(10 
9
 +7) 取模后的结果即可。
输入描述：
在一行上输入一个整数 
k
(
1
≦
k
≦
1
0
6
)
k(1≦k≦10 
6
 )。
输出描述：
输出一个整数，表示 
F
k
 
m
o
d
 
(
1
0
9
+
7
)
F 
k
​
 mod(10 
9
 +7) 的值。
示例1
输入：
19
复制
输出：
4181
*/

public class Program
{
    public static void Main()
    {
        const int MOD = 1000000000 + 7;

        var input = System.Console.ReadLine();
        var k = int.Parse(input.Trim());

        if (k == 1 || k == 2)
        {
            System.Console.WriteLine(1);
        }
        else
        {
            int a = 1, b = 1, c = 0;
            for (int i = 3; i <= k; i++)
            {
                c = (a + b) % MOD;
                a = b;
                b = c;
            }
            System.Console.WriteLine(c);
        }
    }
}
