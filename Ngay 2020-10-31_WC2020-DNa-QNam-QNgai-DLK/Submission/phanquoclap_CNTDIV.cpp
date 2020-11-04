#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

vector<int> prime, lpf;
void sieve(int n)
{
    prime.assign(1, 2);
    lpf.assign(n + 1, 2);

    lpf[0] = lpf[1] = 0;
    for (int i = 3; i <= n; i += 2) {
        if (lpf[i] == 2) prime.push_back(lpf[i] = i);
        for (int j = 0; j < int(prime.size()) && prime[j] <= lpf[i] && prime[j] * i <= n; ++j)
            lpf[prime[j] * i] = prime[j];
    }
}

void fact(int n, vector<pi> &S)
{
    int k = __builtin_ctz(n);
    if (k > 0) S.push_back(make_pair(2, k));
    n >>= k;

    while (n > 1)
    {
        int p = lpf[n], f = 0;
        do n /= lpf[n], ++f;
        while (p == lpf[n]);

        S.push_back(make_pair(p, f));
    }
}

int n;
ll T;
vector<pi> S;
ll magic(int i = 0, ll val = 1, bool ok = false)
{
    if (i == S.size()) return ok;

    int v = S[i].first;
    int f = S[i].second;

    ll res = 0;
    ll x = 1;
    int lim = f << 1;
    for (int t = 0; t <= lim; ++t)
    {
        if (val > T / x) break;
        res += magic(i + 1, val * x, ok | (t > f));
        x *= v;
    }
    return res;
}

vector<pi> merge(const vector<pi> &b, const vector<pi> &c)
{
    vector<pi> a;
    int ib = 0, nb = b.size();
    int ic = 0, nc = c.size();
    while (ib < nb && ic < nc)
    {
        int vb = b[ib].first;
        int vc = c[ic].first;
        if (vb != vc)
            a.push_back((vb < vc) ? b[ib++] : c[ic++]);
        else 
            a.push_back(make_pair(vb, b[ib++].second + c[ic++].second));
    }

    for (; ib < nb; a.push_back(b[ib++]));
    for (; ic < nc; a.push_back(c[ic++]));
    // for (const pair<int, int> &e : b) cout << e.first << ' ' << e.second << " | "; cout << endl;
    // for (const pair<int, int> &e : c) cout << e.first << ' ' << e.second << " | "; cout << endl;
    // for (const pair<int, int> &e : a) cout << e.first << ' ' << e.second << " | "; cout << endl;
    // cout << endl;
    return a;
}

int query()
{
    cin >> n;
    T = 1LL * (n + 0) * (n + 1) * (n + 2);

    vector<pi> S0, S1, S2;
    fact(n + 0, S0);
    fact(n + 1, S1);
    fact(n + 2, S2);

    S = merge(S0, S1);
    S = merge(S2, S);

    ll D1 = 1, D2 = 1;
    for (const pair<int, int> &e : S)
    {
        int v = e.first;
        int f1 = e.second;
        int f2 = 2 * f1;
        D1 *= (f1 + 1);
        D2 *= (f2 + 1);
    }

    cout << D2 / 2 - (D1 - 1) << '\n';
}

int main()
{
    sieve(1e6 + 1000);

    int q;
    cin >> q;

    while (q-->0)
    {
        query();
        

    }


    return 0;
}