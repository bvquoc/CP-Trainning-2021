#include <bits/stdc++.h>

#define taskname "construct"
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <ld> cd;
typedef vector <cd> vcd;
typedef vector <int> vi;

template<class T> using v2d = vector <vector <T> >;
template<class T> bool uin(T &a, T b)
{
    return a > b ? (a = b, true) : false;
}
template<class T> bool uax(T &a, T b)
{
    return a < b ? (a = b, true) : false;
}

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int maxN = 1e5 + 1;

int n, m;

ll a[maxN];

ll dt[maxN];

ll f[maxN * 4];

ll d[maxN];

void change(int x, ll delta)
{
    for (; x <= n; x += x & -x)
    {
        d[x] += delta;
    }
}

ll gt(int x)
{
    ll res = 0;
    for (; x > 0; x &= x - 1)
    {
        res += d[x];
    }
    return res;
}

int idx, L, R;
ll val;

void build(int x, int low, int high)
{
    if (low == high)
    {
        f[x] = max(dt[low], (ll)0);
        return;
    }
    int mid = (low + high) / 2;
    build(x * 2, low, mid);
    build(x * 2 + 1, mid + 1, high);
    f[x] = f[x * 2] + f[x * 2 + 1];
}

void update(int x, int low, int high)
{
    if (idx > high || idx < low)
    {
        return;
    }
    if (low == high)
    {
        f[x] = max(val, (ll)0);
        return;
    }
    int mid = (low + high) / 2;
    update(x * 2, low, mid);
    update(x * 2 + 1, mid + 1, high);
    f[x] = f[x * 2] + f[x * 2 + 1];
}

ll query(int x, int low, int high)
{
    if (L > high || R < low)
    {
        return 0;
    }
    if (low >= L && high <= R)
    {
        return f[x];
    }
    int mid = (low + high) / 2;
    return query(x * 2, low, mid) + query(x * 2 + 1, mid + 1, high);
}

void init()
{
    build(1, 1, n);
    for1(i, n)
    {
        d[i] = 0;
    }
    for1(i, n)
    {
        d[i] += dt[i];
        if (i + (i & -i) <= n)
        {
            d[i + (i & -i)] += d[i];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for1(i, n)
        {
            cin >> a[i];
            dt[i] = a[i] - a[i - 1];
        }
        init();
        while (m--)
        {
            int type;
            cin >> type >> L >> R;
            if (type == 1)
            {
                ll k;
                cin >> k;
                change(L, k);
                val = dt[L] += k;
                idx = L;
                update(1, 1, n);
                if (R < n)
                {
                    change(R + 1, -k);
                    val = dt[R + 1] -= k;
                    idx = R + 1;
                    update(1, 1, n);
                }
            }
            else
            {
                ll res = query(1, 1, n);
                if (L > 1)
                {
                    if (dt[L] >= 0)
                    {
                        res += gt(L - 1);
                    }
                    else
                    {
                        res += gt(L);
                    }
                }
                cout << res << '\n';
            }
        }
    }
    return 0;
}
