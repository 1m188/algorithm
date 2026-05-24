#include <algorithm>
#include <cmath>
#include <cstdio>

const int N = 500005;
long long a[N];

int main() {
    int n;
    long long S;
    if (scanf("%d %lld", &n, &S) != 2) return 1;
    for (int i = 0; i < n; ++i)
        if (scanf("%lld", a + i) != 1) return 1;
    std::sort(a, a + n);

    double avg = (double)S / n;
    double sum_dev = 0; // sum of (bi - avg)^2

    for (int i = 0; i < n; ++i) {
        double cur = (double)S / (n - i);
        if (a[i] < cur) {
            S -= a[i];
            double d = a[i] - avg;
            sum_dev += d * d;
        } else {
            double d = cur - avg;
            sum_dev += (n - i) * d * d;
            break;
        }
    }

    printf("%.4f\n", sqrt(sum_dev / n));
    return 0;
}
