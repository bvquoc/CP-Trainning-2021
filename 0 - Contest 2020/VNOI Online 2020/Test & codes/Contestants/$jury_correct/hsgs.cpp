#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 5;
int n, x, y;
vector<long long> a;
long long f[maxn][3];

long long Cost(long long num, long long gcd, int del) {
    if (del) return x;
    num %= gcd;
    if (num == 0) return 0;
    if (num == 1 || num == gcd - 1) return y;
    return 1e15;
}

long long Calc(long long gcd) {
    f[n][0] = f[n][1] = f[n][2] = 0;
    for (int i = n - 1; i >= 0; --i) {
        long long c0 = Cost(a[i], gcd, 0);
        long long c1 = Cost(a[i], gcd, 1);
        f[i][0] = min(f[i + 1][0] + c0, f[i + 1][1] + c1);
        f[i][1] = min(f[i + 1][1] + c1, f[i + 1][2] + c0);
        f[i][2] = f[i + 1][2] + c0;
        if (f[i][0] > 1e17) f[i][0] = 1e17;
        if (f[i][1] > 1e17) f[i][1] = 1e17;
        if (f[i][2] > 1e17) f[i][2] = 1e17;
    }
    return f[0][0];
}

int main() {
#if ONLINE_JUDGE || THEMIS
    freopen("hsgs.inp", "r", stdin);
    freopen("hsgs.out", "w", stdout);
#endif

#ifdef LDT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    cin >> n >> x >> y;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> candidate;
    for (int x = -1; x <= 1; ++x) {
        candidate.push_back(a[0] + x);
        candidate.push_back(a.back() + x);
    }
    long long res = 1ll * (n - 1) * x;
    for (int gcd = 2; gcd <= 1e6; ++gcd) {
        bool ok = false;
        for (long long &x : candidate) 
            while (x % gcd == 0)
                x /= gcd, ok = 1;
        if (ok)
            res = min(res, Calc(gcd));
    }
    for (long long gcd : candidate) if (gcd != 1)
        res = min(res, Calc(gcd));
    cout << res;
    return 0;
}
