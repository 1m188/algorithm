#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<int> h(n + 1);
    vector<int> primes;
    vector<bool> is_comp(n + 1);

    h[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!is_comp[i]) {
            primes.push_back(i);
            h[i] = (1LL * i * i - 1) % MOD;
        }
        for (int j = 0; j < (int)primes.size(); j++) {
            int p = primes[j];
            long long nxt = 1LL * i * p;
            if (nxt > n) break;
            is_comp[nxt] = true;
            if (i % p == 0) {
                h[nxt] = 1LL * h[i] * (1LL * p * p % MOD) % MOD;
                break;
            } else {
                h[nxt] = 1LL * h[i] * h[p] % MOD;
            }
        }
    }

    long long ans = 0;
    for (int T = 1; T <= n; T++) {
        long long k = n / T;
        ans = (ans + k * k % MOD * h[T]) % MOD;
    }

    cout << ans << endl;
    return 0;
}
