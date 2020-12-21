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
const int N    = 500005;
const bool aut = 788480;
const int base = 521;

int n, m, k, sz[N], pa[N], it[4*N];
bool ok[N];
deque<int> dq[N];

int Find(int u) {
    if(u == pa[u])
        return u;
    return pa[u] = Find(pa[u]);
}

void update(int id, int l, int r, int pos, int val) {
    if(pos < l || pos > r)
        return;
    if(l == r) {
        it[id] = val;
        return;
    }
    int mid = l + r >> 1;
    update(id*2, l, mid, pos, val);
    update(id*2+1, mid+1, r, pos, val);
    it[id] = it[id*2] + it[id*2+1];
}

int get(int id, int l, int r, int L, int R) {
    if(R < l || r < L)
        return 0;
    if(L <= l && r <= R)
        return it[id];
    int mid = l + r >> 1;
    return get(id*2, l, mid, L, R) + get(id*2+1, mid+1, r, L, R);
}

int main() {
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define     task "decor"
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);

    string s;
    cin >> n >> m >> k >> s;
    forr(i, 1, n)
    pa[i] = i, sz[i] = s[i-1] - '0';
    forr(i, 1, m) {
        int ui, vi;
        cin >> ui >> vi;
        int x = Find(ui);
        int y = Find(vi);
        if(x != y)
            pa[x] = y, sz[y] += sz[x];
    }
    forr(i, 1, n) {
        int x = Find(i);
        if(sz[x]) {
            ok[x] = true;
            update(1, 1, n, i, 1);
            sz[x]--;
        } else if(ok[x])
            dq[x].push_back(i);
    }
    int p1 = 0, p2 = -1;
    forr(i, 1, n) {
        int L = i, R = n, res = -1;
        while(L <= R) {
            int mid = R + L >> 1;
            if(get(1, 1, n, i, mid) + k >= mid - i + 1)
                res = mid, L = mid + 1;
            else
                R = mid - 1;
        }
        if(res != -1) {
            if(p2 == -1 || res - i > p2 - p1)
                p1 = i, p2 = res;
        }
        int x = Find(i);
        if(dq[x].size())
            update(1, 1, n, dq[x].front(), 1), dq[x].pop_front();
    }
    if(p2 == -1)
        cout << -1;
    else
        cout << p1 << " " << p2;

    return 0;
}
