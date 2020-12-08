#include <bits/stdc++.h>

#define name "CONSTRUCT."
#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end
#define pb push_back
#define f first
#define s second

using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
const ll N = 1e5 + 7;
const ll inf = 1e9 + 7;

int n, m, sub;
ll a[N];

void inp()
{
    cin >> n >> m;
    fu(i, 1, n) cin >> a[i];
    if (n <= 1000 && m <= 1000)
        sub = 1;
}
struct sub1
{
    ll b[N];

    void solve()
    {
        ll type, l, r, val;
        while (m--)
        {
            cin >> type >> l >> r;
            if (type == 1)
            {
                cin >> val;
                fu(i, l, r) a[i] += val;
            }
            else
            {
                ll k = 0, s = 0;
                fu(i, l, r) b[++k] = a[i], s += a[i];
                ll res = 0;

                while (s)
                {
                    int L = -1, R = 0;
                    fu(i, 0, k) if (!b[i] && b[i + 1])
                    {
                        L = i + 1;
                        break;
                    }
                    if (L == -1) break;
                    ll mi = b[L];
                    R = L;
                    while (R < k && b[R + 1]) ++R, mi = min (mi, b[R]);
                    res += mi;
                    fu(i, L, R) b[i] -= mi;
                    s -= (R - L + 1) * mi;
                }
                cout << res << '\n';
            }
        }
    }
} sub1;
struct sub2
{
    ll b[N];

    void solve()
    {
        ll type, l, r, val;
        while (m--)
        {
            cin >> type >> l >> r;
            if (type == 1)
            {
                cin >> val;
                fu(i, l, r) a[i] += val;
            }
            else
            {
                ll k = 0, s = 0;
                fu(i, l, r) b[++k] = a[i], s += a[i];
                ll mi = inf;
                fu(i, 1, k) mi = min (mi, b[i]);

                ll res = mi;
                fu(i, 1, k) b[i] -= mi;
                fu(i, 0, k)
                {
                    if (b[i] < b[i + 1])
                        res += b[i + 1] - b[i];
                    else res += b[i + 1];
                }

                ll res2 = mi;
                fd(i, k + 1, 1)
                {
                    if (b[i] < b[i - 1])
                        res2 += b[i - 1] - b[i];
                    else res2 += b[i - 1];
                }
                cout << min (res, res2) << '\n';
            }
        }
    }
} sub2;
int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(name"INP", "r", stdin);
    freopen(name"OUT", "w", stdout);

    int t; cin >> t;
    while (t--)
    {
        inp();
        sub1.solve();
    }

    return 0;
}
