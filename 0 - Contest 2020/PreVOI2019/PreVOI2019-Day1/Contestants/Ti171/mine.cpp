#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ( (int)(x).size() )
#define fi first
#define se second
using LL = long long;
const int mod = 1e6 + 3;

struct Num {
    int a;
    Num(int _a) : a(_a) {}

    Num operator + (const Num& _) const {
        int ret = a + _.a;
        return ret < mod ? Num(ret) : Num(ret - mod);
    }
    void operator += (const Num& _) { *this = *this + _; }
    Num operator - (const Num& _) const { return *this + Num(mod - _.a); }
    Num operator * (const Num& _) const { return (int)( (LL)a * _.a % mod); }
};
vector<Num> inv, fact, invFact, f;

Num C(int n, int k) { return fact[n] * invFact[k] * invFact[n - k]; }
Num Cat(int n) { return C(n << 1, n) * inv[n + 1]; }

int n, m;
vector<int> a;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("mine.INP", "r", stdin);
    freopen("mine.OUT", "w", stdout);

    cin >> n >> m;

    a.assign(n << 1, 0);
    for (int i = 0; i < sz(a); ++i) cin >> a[i];

    fact.assign( (n + 5) << 1, Num(1) );
    for (int i = 1; i < sz(fact); ++i) fact[i] = fact[i - 1] * Num(i);
    inv.assign(sz(fact), 0); inv[1] = 1;
    for (int i = 2; i < sz(inv); ++i) inv[i] = Num(mod - mod / i) * inv[mod % i];
    invFact.assign(sz(fact), 0); invFact[0] = 1;
    for (int i = 1; i < sz(invFact); ++i) invFact[i] = invFact[i - 1] * inv[i];

    if (m == 1000000) {
        cout << Cat(n).a;
        return 0;
    }

    f.assign(n << 1, 0);
    for (int i = 0; i < (n << 1); ++i) {
        for (int j = i - 1; j >= 0; j -= 2) if (a[i] - a[j] <= m) {
            f[i] += Cat( (i - j - 1) >> 1) * (j ? f[j - 1] : Num(1) );
        }
    }

    cout << f.back().a;

    return 0;
}

