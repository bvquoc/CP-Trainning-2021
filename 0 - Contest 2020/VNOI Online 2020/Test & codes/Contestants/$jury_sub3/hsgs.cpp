#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 5;
int n, x, y;
vector<long long> a;
long long f[maxn][3];

long long Cost(int num, int gcd, int del) {
    if (del) return x;
    num %= gcd;
    if (num == 0) return 0;
    if (num == 1 || num == gcd - 1) return y;
    return 1e15;
}

long long Calc(int gcd) {
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
    //eratos
    int lim = *max_element(a.begin(), a.end());
    vector<int> p(lim + 1, 0);

    for (int i = 2; i * i <= lim; ++i) if (p[i] == 0) {
        for (int j = i * i; j <= lim; j += i)  
            p[j] = 1;
    }


    vector<int> prime;
    for (int i = 2; i <= lim; ++i) if (p[i] == 0) 
        prime.push_back(i);
    
    //ans
    long long res = 1ll * (n - 1) * x;
    for (int gcd : prime)
        res = min(res, Calc(gcd));
    cout << res;
    return 0;
}
