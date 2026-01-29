
//请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

class Solution
{
  public:
    //遍历字符串，碰到了空格就从后往前处理，将所有的字符向后移动2个位置，之后从当前空格开始（包括空格），向后
    //三个字符替换成%20即可
    void replaceSpace(char *str, int length)
    {
        for (int i = 0; i < length;)
        {
            if (str[i] == ' ')
            {
                length += 2;
                for (int j = length; j >= i + 3; j--)
                {
                    str[j] = str[j - 2];
                }
                str[i++] = '%';
                str[i++] = '2';
                str[i++] = '0';
            }
            else
            {
                i++;
            }
        }
    }
};