/*

有如下的加法算式。其中每个汉字代表一个数字。
（如果存在对齐问题，可参见【图1.png】）

               年
             大年
           过大年
         能过大年
       怎能过大年
     我怎能过大年
+  让我怎能过大年
------------------
   能能能能能能能

请填写“让我怎能过大年” 所代表的整数。
所有数字连在一起，中间不要空格。例如："3125697"。当然，这个不是正确的答案。

注意：只填写一个整数，不要填写任何多余的内容。




*/

#include <cmath>
#include <iostream>
using namespace std;

int main() {

    for (int num = 1000000; num <= 9999999; num++) {
        int neng = (num / 1000) % 10;
        int target = neng * 1111111;
        int sums = num + num % 1000000 + num % 100000 + num % 10000 + num % 1000 + num % 100 + num % 10;

        if (sums == target) {
            cout << num << '\n'; // 1572836
        }
    }

    return 0;
}
