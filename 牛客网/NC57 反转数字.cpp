/*

描述
给定一个32位的有符号整数num，将num中的数字部分反转，最后返回反转的结果
1.只反转数字部分，符号位部分不反转
2.反转后整数num超过 32 位的有符号整数的范围 [−231,  231 − 1] ，返回 0
3.假设本题不允许存储 64 位整数(有符号或无符号，即C++不能使用long long ，Java不能使用long等)

数据范围:
-231 <= x <= 231-1
示例1
输入：
12
复制
返回值：
21
复制
示例2
输入：
-123
复制
返回值：
-321
复制
示例3
输入：
10
复制
返回值：
1
复制
示例4
输入：
1147483649
复制
返回值：
0

*/

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param x int整型
     * @return int整型
     */
    int reverse(int x) {
        // write code here

#define MAX_VALUE 2147483647
#define MIN_VALUE -2147483648

        if (x == MIN_VALUE) return 0;

        int sign = 1;
        if (x < 0) {
            sign = -1;
            x *= -1;
        }

        int res = 0;
        while (x) {
            if (res > MAX_VALUE / 10) return 0;
            if (res == MAX_VALUE / 10 && x % 10 > 7) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }

        return sign * res;
    }
};