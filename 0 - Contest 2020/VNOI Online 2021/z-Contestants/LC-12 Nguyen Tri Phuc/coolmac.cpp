#include <bits/stdc++.h>
#define fore(it,a)       for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define forr(i, a, b)    for(int i = (a); i <= (b); ++i)
#define ford(i, a, b)    for(int i = (a); i >= (b); --i)
#define repp(i, a, b)    for(int i = (a); i < (b); ++i)
#define repd(i, a, b)    for(int i = (a); i > (b); --i)
#define mem(a, x)        memset(x, (a), sizeof(x))
#define bitcount(x)      __builtin_popcountll((x))
#define OFFBIT(mask, i)  ((mask) &~ (1ll << (i)))
#define ONBIT(mask, i)   ((mask) | (1ll << (i)))
#define reset(x)         memset(x, 0, sizeof(x))
#define all(a)           (a).begin(), (a).end()
#define BIT(x, i)        (((x) >> (i)) & 1)
#define ii               pair<int, int>
#define MASK(i)          (1LL << (i))
#define mp               make_pair
#define se               second
#define fi               first

using namespace std;

mt19937_64 random_num(chrono::high_resolution_clock::now().time_since_epoch().count());
const int MOD  = 1000000007;
const int inf  = 2000000000;
const int mod  = 1007050321;
const double e = 0.000001;
const int N    = 100005;
const bool aut = 788480;
const int base = 521;

int n, m, d[N], t[N], l[N], r[N], it[4*N], dp[N], Min = inf;
ii a[N];

void init(int id, int l, int r) {
    if(l == r) {
        it[id] = m;
        return;
    }
    int mid = l + r >> 1;
    init(id*2, l, mid);
    init(id*2+1, mid+1, r);
    it[id] = m;
}

void update(int id, int l, int r, int pos, int val) {
    if(pos < l || pos > r)
        return;
    if(l == r) {
        it[id] = min(it[id], val);
        return;
    }
    int mid = l + r >> 1;
    update(id*2, l, mid, pos, val);
    update(id*2+1, mid+1, r, pos, val);
    it[id] = min(it[id*2], it[id*2+1]);
}

int get(int id, int l, int r, int L, int R) {
    if(R < l || r < L)
        return m;
    if(L <= l && r <= R)
        return it[id];
    int mid = l + r >> 1;
    return min(get(id*2, l, mid, L, R), get(id*2+1, mid+1, r, L, R));
}

int main() {
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define     task "coolmac"
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);

    cin >> m;
    forr(i, 1, m)
    cin >> l[i] >> r[i], d[l[i]]++, d[r[i]+1]--;
    cin >> n;
    forr(i, 1, n)
    cin >> t[i], Min = min(Min, t[i]);
    forr(i, 1, 100000)
    d[i] += d[i-1];
    forr(i, Min, 100000)
    if(!d[i]) {
        cout << -1;
        return 0;
    }

    init(1, 1, m);
    forr(i, 1, m)
    a[i] = mp(r[i], l[i]);
    sort(a+1, a+1+m);
    int ans = m;
    forr(i, 1, m)
    if(Min >= a[i].se && Min <= a[i].fi)
        dp[i] = 1;
    else
        dp[i] = m;
    a[0].fi = -1;
    forr(i, 1, m) {
        if(a[i].fi < Min) {
            dp[i] = 0;
            update(1, 1, m, i, dp[i]);
            continue;
        }
        if(a[i].fi == a[i-1].fi)
            dp[i] = min(dp[i], dp[i-1]);
        int L = 1, R = i - 1, pos = -1;
        while(L <= R) {
            int mid = L + R >> 1;
            if(a[mid].fi >= a[i].se)
                R = mid - 1, pos = mid;
            else
                L = mid + 1;
        }
        if(pos != -1)
            dp[i] = min(dp[i], get(1, 1, m, pos, i-1) + 1);
        update(1, 1, m, i, dp[i]);
        if(a[i].fi == 100000)
            ans = min(ans, dp[i]);
    }
    cout << ans;

    return 0;
}
