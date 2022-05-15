/**
 * @file 1001 A + B Problem.cpp
 * @date 2022-05-15
 */

/*
Calculate a + b

Input
The input will consist of a series of pairs of integers a and b,separated by a space, 
one pair of integers per line.

Output
For each pair of input integers a and b you should output the sum of a and b in one line,
and with one line of output for each line in input.

Sample Input
1 5

Sample Output
6

Hint
Use + operator
*/

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a = 0, b = 0;
    while (cin >> a >> b) // ZOJ似乎是从文件里面读的，循环不停的cin直到读取失败
        cout << a + b << '\n';
    return 0;
}