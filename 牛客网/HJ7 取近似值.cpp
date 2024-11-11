#include <iostream>
using namespace std;

int main() {
    double x;
    cin >> x;

    int y = (int)x;

    double z = x - y;
    cout << ((z >= 0.5) ? y + 1 : y);

    return 0;
}
// 64 位输出请用 printf("%lld")