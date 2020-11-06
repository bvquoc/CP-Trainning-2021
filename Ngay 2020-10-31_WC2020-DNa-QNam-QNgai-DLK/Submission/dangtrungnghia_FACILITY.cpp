#include<bits/stdc++.h>
using namespace std;

struct customer
{
    long long l, r, val;
} c[1000005];
long n, K, b[1000005];
long long f[1000005];

bool cmp(customer x, customer y)
{
    return x.r < y.r;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> K;
    for (long i = 1; i <= n; i++)
    {
        cin >> c[i].l >> c[i].r >> c[i].val;
        c[i].r = c[i].r + c[i].l - 1;
        c[i].r += K;
    }
    sort(c + 1, c + n + 1, cmp);
    for (long i = 1; i <= n; i++) b[i] = c[i].r;
    long long res = 0;
    for (long i = 1; i <= n; i++)
    {
        f[i] = max(f[i - 1], c[i].val);
        if (i == 1) continue;
        long t = upper_bound(b + 1, b + i, c[i].l - 1) - b - 1;
        f[i] = max(f[i], f[t] + c[i].val);
    }
    cout << f[n];
    return 0;
}
