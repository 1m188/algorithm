/*
标题：取数位

求1个整数的第k位数字有很多种方法。
以下的方法就是一种。


// 求x用10进制表示时的数位长度
int len(int x){
        if(x<10) return 1;
        return len(x/10)+1;
}

// 取x的第k位数字
int f(int x, int k){
        if(len(x)-k==0) return x%10;
        return _____________________;  //填空
}

int main()
{
        int x = 23574;
        printf("%d\n", f(x,3));
        return 0;
}

对于题目中的测试数据，应该打印5。

请仔细分析源码，并补充划线部分所缺少的代码。

注意：只提交缺失的代码，不要填写任何已有内容或说明性的文字。
*/

/*
 * 填空解析：
 * f(x, k) 取 x 的第 k 位数字（左起，从 1 开始）。
 * 若当前位数 = k，返回 x%10（末位即所求位）。
 * 否则去掉末位（x/10），递归在被缩短的数中找第 k 位。
 * 填：f(x/10, k)
 */
#include <stdio.h>

int len(int x) {
    if (x < 10) return 1;
    return len(x / 10) + 1;
}

int f(int x, int k) {
    if (len(x) - k == 0) return x % 10;
    return f(x / 10, k); // 填空
}

int main() {
    int x = 23574;
    printf("%d\n", f(x, 3)); // 应输出 5
    return 0;
}
