#include <iostream>
using namespace std;

int main() {
    int x = 0;
    cin >> x;

    bool flags[10];
    int y = 0;
    while (x) {
        int z = x % 10;
        x /= 10;
        if (flags[z]) continue;
        flags[z] = true;
        y = y * 10 + z;
    }
    cout << y;

    return 0;
}
// 64 位输出请用 printf("%lld")