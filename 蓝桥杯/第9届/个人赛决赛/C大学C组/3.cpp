/*

标题：全排列

标题：全排列

对于某个串，比如："1234"，求它的所有全排列。
并且要求这些全排列一定要按照字母的升序排列。
对于"1234"，应该输出(一共4!=24行)：
1234
1243
1324
1342
1423
1432
2134
2143
2314
2341
2413
2431
3124
3142
3214
3241
3412
3421
4123
4132
4213
4231
4312
4321

下面是实现程序，请仔细分析程序逻辑，并填写划线部分缺少的代码。

#include <stdio.h>
#include <string.h>

//轮换前n个，再递归处理
void permu(char* data, int cur)
{
        int i,j;

        if(data[cur]=='\0'){
                printf("%s\n", data);
                return;
        }

        for(i=cur; data[i]; i++){
                char tmp = data[i];
                for(j=i-1; j>=cur; j--) data[j+1] = data[j];
                data[cur] = tmp;

                permu(data, cur+1);

                tmp = data[cur];
                ___________________________________ ;  //填空
                data[i] = tmp;
        }
}

int main()
{
        char a[] = "1234";
        permu(a,0);
        return 0;
}

请注意：只需要填写划线部分缺少的内容，不要抄写已有的代码或符号。


*/

#include <cstdio>
#include <cstring>

// 轮换前n个，再递归处理
void permu(char *data, int cur) {
    int i, j;

    if (data[cur] == '\0') {
        printf("%s\n", data);
        return;
    }

    for (i = cur; data[i]; i++) {
        // 将 data[i] 轮换到 data[cur] 位置：右侧元素依次右移一位
        char tmp = data[i];
        for (j = i - 1; j >= cur; j--)
            data[j + 1] = data[j];
        data[cur] = tmp;

        permu(data, cur + 1);

        // 还原：将 data[cur..i-1] 左移一位，data[i] 放回 tmp
        tmp = data[cur];
        for (j = cur; j < i; j++)
            data[j] = data[j + 1]; // 填空
        data[i] = tmp;
    }
}

int main() {
    char a[] = "1234";
    permu(a, 0);
    return 0;
}
