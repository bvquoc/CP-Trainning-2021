#include<bits/stdc++.h>
using namespace std;

long long n, Q, P, a[10005], f[10001][10001], g[10002][10002];
long k;

void sub1()
{
    f[0][0] = 0;
    for (long i = 1; i <= n; i++)
    {
        for (long j = 1; j <= Q; j++)
        {
            f[i][j] = f[i - 1][j];
            for (long long t = 1; t <= j && t <= P; t++)
            {
                f[i][j] = max(f[i][j], f[max((long)0, i - k)][j - t] + t * a[i]);
            }
        }
    }
    cout << f[n][Q];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k >> Q >> P;
    long cnt = Q / P + (Q % P != 0);
    for (long i = 1; i <= n; i++) cin >> a[i];

    if (n <= 1000)
    {
        sub1();
        return 0;
    }


    for (long i = 1; i <= n; i++)
    {
        for (long c = 1; c <= cnt && c <= i; c++)
        {
            f[i][c] = max(f[i - 1][c], f[max((long)0, i - k)][c - 1] + a[i] * P);
        }
    }

    for (long i = n; i >= 1; i--)
    {
        for (long c = 1; c <= cnt && c <= i; c++)
        {
            g[i][c] = max(g[i + 1][c], g[min((long)n + 1, i + k)][c - 1] + a[i] * P);
        }
    }

    long sur = Q / P;
    sur = Q - sur * P;
    long long res = 0;
    for (long i = 1; i <= n; i++)
    {
        for (long t = 0; t <= cnt - 1; t++)
        {
            res = max(res, a[i] * sur + f[max((long)0, i - k)][t] + g[min((long)n + 1, i + k)][cnt - 1 - t]);
        }
    }
    cout << res;
    return 0;
}
