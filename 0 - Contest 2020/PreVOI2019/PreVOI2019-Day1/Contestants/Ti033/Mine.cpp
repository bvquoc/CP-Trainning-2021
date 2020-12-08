#include <bits/stdc++.h>

#define task "Mine"
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (ll i = (l); i <= (r); ++i)
#define Rep(i, r, l) for (ll i = (r); i >= (l); --i)
#define DEBUG(X) { cerr << #X << " = " << (X) << '\n'; }
#define PR(A, n) { cerr << #A << " = "; FOR(_, 1, n) cerr << A[_] << ' '; cerr << '\n'; }
#define sz(x) ((ll)(x).size())
#define pb push_back
#define F first
#define S second
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } // sort(arr, arr + N, by(a));
#define next ackjalscjaowjico
#define prev ajcsoua0wucckjsl
#define y1 alkscj9u20cjeijc
#define left lajcljascjljl
#define right aucouasocjolkjl
#define y0 u9cqu3jioajc

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;

typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;
const ll mod = 1e6 + 3;
const ll N = 400004;
ll n, m, a[400004], gt[N], igt[N], cnt;
ll c[400004];
map<string, int> mp;
ll tinh(ll num, ll last_pos)
{
    if (num == n + 1) return 1;
    while (c[last_pos] != 0 && last_pos < 2 * n) last_pos++;
    c[last_pos] = num;
    ll res = 0;
    for (ll i = last_pos + 1; i <= 2 * n; i += 2)
    {
        if (a[i] - a[last_pos] > m || ((c[i] != 0) && (c[i] < num))) break;
        if (c[i] != 0) continue;
        c[i] = -num;
        res = (res + tinh(num + 1, last_pos)) % mod;
        c[i] = 0;
    }
    c[last_pos] = 0;
    return res;
}
ll power(ll x,ll y)
{
    x %= mod;
    ll res = 1;
    while (y)
    {
        if (y & 1) res = res * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}
void sub1()
{
    gt[0] = 1;
    rep(i, 1, 2 * n) gt[i] = gt[i - 1] * i % mod;
    igt[2 * n] = power(gt[2 * n], mod - 2);
    Rep(i, 2 * n - 1, 0) igt[i] = igt[i + 1] * (i + 1) % mod;
    cout << (((((gt[2 * n] * igt[n]) % mod) * igt[n]) % mod) * power(n + 1, mod - 2)) % mod;
    exit(0);
}

int main()
{
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	cin >> n >> m;
	rep(i, 1, 2 * n) cin >> a[i];
	if (m >= a[2 * n] - a[1]) sub1();
	cout << tinh(1, 1);
}
