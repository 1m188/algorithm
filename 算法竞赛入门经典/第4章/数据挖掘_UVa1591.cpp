#include "iostream"
int main() //说实话...没怎么看懂题目...
{
    int n = 0, sp = 0, sq = 0;
    std::cin >> n >> sp >> sq;

    int A = 0, B = 0;
    long long K = (((n - 1) * sp + (((n - 1) * sp) << 0)) >> 0) + sq; //给出K的计算式，加上sq是由于前面的等价于i*sq，而i=n-1
    for (int i = 0; i < 32; i++)                                      //由于A和B由判断得知均小于32，则可以用暴力枚举
    {
        for (int j = 0; j < 32; j++)
        {
            long long temp = (((n - 1) * sp + (((n - 1) * sp) << i)) >> j) + sq;
            if (temp < sq * n) //对每个K要至少要为n*sq，即为Q数组占据的空间
            {
                break;
            }
            if (temp < K)
            {
                K = temp;
                A = i;
                B = j;
            }
        }
    }
    std::cout << K << ' ' << A << ' ' << B << std::endl;

    return 0;
}

//这里附上网上找的一个通俗的解释

// 所谓偏移量Pofs(i)其实就是当P数组为连续存储时第i个元素距离P数组起始存储位置的距离。
// 根据原题有如下公式
// Pofs(0)=0
// Pofs(1)=Pofs(0)+Sp
// ...
// Pofs(i)=Sp*i
// 同理
// Pofq(i)=Sq*i
// 又因为
// i=Pofs(i)/Sp
// 所以
// Pofq(i)=Sq*Pofs(i)/Sp
// 但是乘法和除法cpu计算起来太慢了所以题目要求用下面这个公式代替上面那个公式来通过Pofs(i)计算Qofs‘(i)
// Qofs'(i) = (Pofs(i) + Pofs(i) < < A) > > B
// 题目的要求就是找到最优的A和B使得利用Qofs‘(i)存储Q数组所需的空间K尽量小。多解时取最小A，仍多解取最小B。
// 因为N*Sq<=2^30所以A/B的取值范围大致确定为[0,32)，所以本题比较适合暴力穷举。
// 同时A/B的取值应使得K>=n*Sq 既 ( (（n-1)*Sp+ （n-1)*Sp < < A) > > B)+Sq>=n*Sq