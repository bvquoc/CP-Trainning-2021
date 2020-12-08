#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;

int a[maxn];
long long sum[maxn], sumEven[maxn];

int n;

long long GetSumEven(int L, int R) {
    return sumEven[R] - sumEven[L - 1];
}

long long GetSumOdd(int L, int R) {
    return sum[R] - sum[L - 1] - GetSumEven(L, R);
}

long long Calc(long long X, int L, int R) {
    if (sum[R] - sum[L - 1] <= X) return X - sum[R] + sum[L - 1];
    int pos = upper_bound(sum + L, sum + R + 1, X + sum[L - 1]) - sum - 1;
    X -= sum[pos] - sum[L - 1];
    L = pos + 1;
    assert(L <= R);
    assert(X < a[L]);
    if (R & 1)
        return GetSumOdd(L, R) - GetSumEven(L, R) + (R - L + 1 & 1 ? -X : X);
    return GetSumEven(L, R)  - GetSumOdd(L, R) + (R - L + 1 & 1 ? -X : X);
}

int main(void) {
#if ONLINE_JUDGE || THEMIS
    freopen("rating.inp", "r", stdin);
    freopen("rating.out", "w", stdout);
#endif
#ifdef LDT
    freopen("input.txt", "r", stdin);
    freopen("ac.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int idSub;
    cin >> idSub;
    int q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        sumEven[i] = sumEven[i - 1];
        if (!(i & 1))
            sumEven[i] += a[i];
    }

    for (int i = 1; i <= q; ++i) {
        int x, l, r;
        cin >> x >> l >> r;
        int res;
        if (x < 0) res = Calc(abs(x - a[l]), l + 1, r);
        else 
            res = Calc(x, l, r);
        cout << res << '\n';
    }
    return 0;
}
