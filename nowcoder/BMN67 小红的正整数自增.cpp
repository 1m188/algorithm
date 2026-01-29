#include <iostream>
using namespace std;

int main() {
    uint64_t x = 0;
    cin >> x;
    cout << (10 - x % 10) % 10;
    return 0;
}
// 64 位输出请用 printf("%lld")