#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x = 0;
    cin >> x;

    string str = to_string(x);
    for (int i = 0; i <= str.size(); i++) {
        for (char n = '0'; n <= '9'; n++) {
            str.insert(str.begin() + i, n);
            if (stoll(str) % 7 == 0) {
                cout << str;
                return 0;
            }
            str.erase(str.begin() + i);
        }
    }

    return 0;
}
// 64 位输出请用 printf("%lld")