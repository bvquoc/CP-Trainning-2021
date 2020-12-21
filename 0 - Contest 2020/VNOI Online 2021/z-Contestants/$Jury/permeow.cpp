#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
const int MOD = (int)1e9 + 7;

struct BIT {
private:
    vector<int> t;

public:
    BIT(int n) {
        t.resize(n+1);
    }

    void update(int p, int val) {
        for(int i = p; i < t.size(); i += i&(-i))
            t[i] += val;
    }

    int query(int p) {
        int res = 0;
        for(int i = p; i > 0; i -= i&(-i))
            res += t[i];
        return res;
    }

    int query(int l, int r) {
        return query(r) - query(l-1);
    }
};

long long fact[MAXN];

long long allPermutationInv(long long n) {
    long long x1 = ((n-1)*n/2) % MOD;
    long long x2 = fact[n-2];
    long long x3 = ((n-1)*n/2) % MOD;
    return ((x1 * x2) % MOD * x3) % MOD;
}

long long solve(vector<int> &a) {
    int n = a.size();
    // a1 a2 ... ai ... an
    // prefix  | x  | suffix

    BIT tPrefix(n), tSuffix(n);
    for(int i = 0; i < n; ++i)
        tSuffix.update(a[i], 1);

    long long res = 0;
    long long nInv_PrefixAll = 0;
    for(int i = 0; i < n; ++i) {
        long long x = (a[i]-1) - tPrefix.query(1, a[i]-1);
        long long nPerm = (x * fact[n-i-1]) % MOD;

        // count inversion between prefix and (prefix + x + suffix)
        long long x1 = (nPerm * nInv_PrefixAll) % MOD;
        // count inversion between x and suffix
        long long nInv_XSuffix = (x*(x-1)/2) % MOD;
        long long x2 = (fact[n-i-1] * nInv_XSuffix) % MOD;
        // count inversion between suffix and suffix
        long long x3 = (x * allPermutationInv(n-i-1)) % MOD;

        res = (res + x1 + x2 + x3) % MOD;

        tSuffix.update(a[i], -1);
        nInv_PrefixAll = (nInv_PrefixAll + tSuffix.query(1, a[i])) % MOD;
        tPrefix.update(a[i], 1);

        // count inversion for permutation a
        res = (res + tPrefix.query(a[i]+1, n)) % MOD;
    }


    return res;
}

int main() {
#define TASK "PERMEOW"
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    int n;
    scanf("%d", &n);

    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; ++i)
        scanf("%d", &b[i]);

    fact[0] = 1;
    for(int i = 1; i <= n; ++i)
        fact[i] = (fact[i-1] * i) % MOD;

    long long ans = solve(b);
    if (prev_permutation(a.begin(), a.end()))
        ans = (ans - solve(a) + MOD) % MOD;

    cout << ans;

    return 0;
}
