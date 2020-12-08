#include <bits/stdc++.h>
typedef int64_t ll;
const int maxn = 5000010;
using namespace std;

template <typename T> inline void read(T &x) {
    x = 0; char c; bool p = false;
    while (!isdigit(c = getchar())); if (c == '-') p = true;
    do x = x * 10 + c - 48; while (isdigit(c = getchar()));
    if (p)
        x = -x;
}

ll a[maxn], b[maxn];
int Test, n, m, h[maxn];
void Solve(int l, int r) {
    ll res = 0;
    for (int i = 1; i <= n; i++)
        b[i] = h[i];
    for (int i = 1; i <= l - 1; i++)
        b[i] = 0;
    for (int i = r + 1; i <= n; i++)
        b[i] = 0;
    b[n + 1] = a[n + 1] = 0;
    while (1)
    {
        bool ok = false;
        ll pp = LLONG_MAX;
        int p1 = 0;
        for (int i = 1; i <= n; i++) {
            if (b[i] != a[i]) {
                ok = true;
                break;
            }
        }
        for (int i = 1; i <= n + 1; i++) {
            if (b[i] - a[i] == 0) {
                if (pp != LLONG_MAX) {
                    for (int j = p1 + 1; j <= i - 1; j++) {
                        b[j] += pp;
                    }
                    res += pp;
                    pp = LLONG_MAX;
                }
                p1 = i;
            }
            else {
                pp = min(pp, a[i] - b[i]);
            }
        }
        if (!ok)
            break;
    }
    cout << res << '\n';
}

int main()
{
    freopen ("construct.inp", "r", stdin);
    freopen ("construct.out", "w", stdout);
    read(Test);
    for (int iTest = 1; iTest <= Test; iTest++) {
        read(n); read(m);
        for (int i = 1; i <= n; i++)
            h[i] = 0;
        for (int i = 1; i <= n; i++)
            read(a[i]);
        for (int i = 1; i <= m; i++) {
            int pp;
            read(pp);
            if (pp == 1) {
                int L, R;
                ll k;
                read(L); read(R); read(k);
                for (int j = L; j <= R; j++) {
                    h[j] += k;
                }
            }
            else {
                int L, R;
                read(L); read(R);
                Solve(L, R);
            }
        }
    }
}
