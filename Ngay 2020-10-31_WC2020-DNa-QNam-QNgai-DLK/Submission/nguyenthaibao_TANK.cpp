#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
const int inf = 0x3c3c3c3c;

int n, m, ans = inf;
int f[N], a[N];

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), f[i] = f[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - i + 1; j++)
            if (f[j + i - 1] - f[j - 1] >= m) {
                if (j == n - i + 1) {
                    printf("%d", i); return 0;}
            } else break;
    return 0;
}

