
// 输入一个字符串，求它包含多少个单词。单词间以一个或者多个空格分开。
// 第一个单词前，最后一个单词后也可能有0到多个空格。
// 比如：" abc    xyz" 包含两个单词，"ab   c   xyz    "  包含3个单词。

// 如下的程序解决了这个问题，请填写划线部分缺失的代码。

// 注意：只填写划线部分的代码，不要填写任何多余的内容。比如已经存在的小括号，注释或说明文字等。

// int get_word_num(char* buf)
// {
// 	int n = 0;
// 	int tag = 1;
// 	char* p = buf;

// 	for(;*p!=0 && *p!=13 && *p!=10;p++){
// 		if(*p==' ' && tag==0) tag=1;
// 		if( _____________________ ) { n++; tag=0; }   //填空
// 	}

// 	return n;
// }

// int main()
// {
// 	char buf[1000];
// 	fgets(buf,1000,stdin);

// 	printf("%d\n", get_word_num(buf));
// 	return 0;
// }

#include <stdio.h>

int get_word_num(char *buf)
{
    int n = 0;
    int tag = 1;
    char *p = buf;

    for (; *p != 0 && *p != 13 && *p != 10; p++)
    {
        if (*p == ' ' && tag == 0)
            tag = 1;
        if (*p != ' ' && tag == 1)
        {
            n++;
            tag = 0;
        } //填空

        /*

        这里分两种情况

        对于  " abc    xyz"  字符串来说，最开始碰到空格，而此时tag==1，跳过，直到
        碰到了字符，此时n++，并且tag=0，然后碰到字符是tag==0，跳过，直到再次碰到空格，tag=1，
        然后反复

        对于   "ab   c   xyz    "   字符串来说，最开始碰到字符，tag==1，则n++，并且tag=0，
        然后碰到字符是tag==0，直到再次碰到空格，tag=1，然后碰到空格都跳过，直到再次碰到字符，
        然后反复
        
        */
    }

    return n;
}

int main()
{
    char buf[1000];
    fgets(buf, 1000, stdin);

    printf("%d\n", get_word_num(buf));
    return 0;
}