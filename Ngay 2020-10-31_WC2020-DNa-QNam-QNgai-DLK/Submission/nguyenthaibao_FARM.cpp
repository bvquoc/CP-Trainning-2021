#include <bits/stdc++.h>
using namespace std;
const int N = 1001;

int n, K, Q, P, ans, f[N][N], a[N];

int main() {
    scanf("%d%d%d%d", &n, &K, &Q, &P);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= P; j++)
            f[i][j] = a[i] * j;
    for (int i = 1 + K; i <= n; i++) {
        for (int m = i - K; m >= 1; m--)
            for (int j = 1; j <= Q; j++) {
                for (int k = 1; k <= P; k++)
                    if (j - k >= 1)
                        f[i][j] = max(f[i][j], f[m][j - k] + a[i] * k);
                ans = max(ans, f[i][j]);
            }
    }
    printf("%d", ans);
    return 0;
}
