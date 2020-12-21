#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,long long>
#define fr first
#define sc second
#define pow2(i) (1<<i)
#define eb emplace_back
#define mp make_pair
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define FOR(_i, _s, _n) 	for (int _i = _s; _i <= _n; ++_i)
#define FOD(_i, _s, _n)	    for (int _i = _s; _i >= _n; --_i)
#define firstbit(_mask)     __builtin_ctz(_mask)
#define lastbit(_mask)      __builtin_clz(_mask)
#define countbit(_mask)     __builtin_popcount(_mask)
int getbit(int mask, int i) {
    return (mask >> i) & 1;
}
void flipbit(int &mask, int i) {
    mask ^= (1 << i);
}
void setbit(int &mask, int i) {
    mask |= (1 << i);
}
template <typename T> inline void read(T &x) {
    x = 0; char c;
    while (!isdigit(c = getchar()));
    do x = x*10 + c - '0';
    while (isdigit(c = getchar()));
}
template <typename T> inline void write(T x) {
    if (x > 9) write(x/10);
    putchar(x % 10 + 48);
}
const int dd[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
#define PROBLEMS            "dhaka"
#ifdef PROBLEMS
    #define cin fi
    #define cout fo
    ifstream fi (PROBLEMS".inp");
    ofstream fo (PROBLEMS".out");
#endif
#define camnguyenmeow ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
/*   /\_/\
    (= ._.)
    / >?  \>$
*/
vector<int> s[100005];
vector<pii> a[100005];
ll dis[105][105], d[100005], d2[100005];
vector<int> numwtml(vector<int> &i, vector<int> &j) {
    vector<int> tmp(i.size() + j.size());
    vector<int> univector = vector<int> (tmp.begin(), set_union(i.begin(), i.end(), j.begin(), j.end(), tmp.begin()));
    return univector;
}
int main()
{
    camnguyenmeow;
    for (int i = 0; i <= 102; ++i)
        for (int j = 0; j <= 102; ++j)
            dis[i][j] = LLONG_MAX;
    int n, m, k, l, ns;
    cin >> n >> m >> k >> l;
    for (int i = 1; i <= n; ++i) {
        cin >> ns;
        s[i].resize(ns);
        for (int &j : s[i])
            cin >> j;
        sort(s[i].begin(), s[i].end());
    }
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
        dis[u][v] = dis[v][u] = w;
    }
    for (int i = 0; i <= n; ++i)
            d[i] = LLONG_MAX;
    vector<bool> vis(n+1, false);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, 1});
    d[1] = 0;
    while (!pq.empty()) {
        int u = pq.top().sc; pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (pii v : a[u])
            if (!vis[v.fr] && d[u] < LLONG_MAX && d[v.fr] > d[u] + v.sc) {
                d[v.fr] = d[u] + v.sc;
                pq.push({d[v.fr], v.fr});
            }
    }
    if (d[n] >= LLONG_MAX) {
        cout << -1; return 0;
    }
    if (l == 0) {
        cout << d[n];
        return 0;
    }
    if (k == 1) {
        if (l > 1) {
            cout << -1; return 0;
        }
        if (!s[1].empty() || !s[n].empty()) {
            cout << d[n]; return 0;
        }
        ll ans = LLONG_MAX;
        for (int i = 2; i < n; ++i) {
            if (s[i].empty() || d[i] >= LLONG_MAX) continue;
            vector<ll> d2(n+1, LLONG_MAX);
            vector<int> viss(n+1, false);
            priority_queue<pii, vector<pii>, greater<pii> > pq2;
            pq2.push({0, i});
            d2[i] = 0;
            while (!pq2.empty()) {
                int u = pq2.top().sc; pq2.pop();
                if (viss[u]) continue;
                viss[u] = true;
                if (u == n) break;
                for (pii v : a[u])
                    if (!viss[v.fr] && d2[u] < LLONG_MAX && d2[v.fr] > d2[u] + v.sc) {
                        d2[v.fr] = d2[u] + v.sc;
                        pq2.push({d2[v.fr], v.fr});
                    }
            }
            if (d2[n] >= LLONG_MAX) continue;
            ans = min(ans, d2[n] + d[i]);
        }
        if (ans >= LLONG_MAX) cout << -1;
        else cout << ans;
        return 0;
    }
    vector<int> presum = numwtml(s[1], s[n]);
    for (int z = 1; z <= n; ++z)
        for (int i = 1; i <= n; ++i)
            for (int j = i+1; j <= n; ++j)
                if (dis[i][z] < LLONG_MAX && dis[z][j] < LLONG_MAX)
                    dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][z] + dis[z][j]);
    auto check = [&] (int mask) {
        vector<int> sum = presum;
        for (int i = 1; i < n-1; ++i)
            if (getbit(mask, i) == 1)
                sum = numwtml(sum, s[i+1]);
        if (sum.size() >= l) return true;
        return false;
    };
    ll ans = LLONG_MAX;
    for (int i = 2; i < (1<<n); ++i)
        if (check(i)) {
            vector<int> pmt;
            for (int j = 1; j < n-1; ++j)
                if (getbit(i, j) == 1)
                    pmt.push_back(j+1);
            do {
                ll sumdis = dis[1][pmt[0]];
                if (sumdis >= LLONG_MAX) continue;
                for (int j = 1; j < pmt.size(); ++j)
                    if (dis[pmt[j-1]][pmt[j]] < LLONG_MAX)
                        sumdis += dis[pmt[j-1]][pmt[j]];
                if (dis[pmt[pmt.size()-1]][n] >= LLONG_MAX) continue;
                sumdis += dis[pmt[pmt.size()-1]][n];
                ans = min(ans, sumdis);
            } while (next_permutation(pmt.begin(), pmt.end()));
        }
    if (ans >= LLONG_MAX) cout << -1;
    else cout << ans;
    return 0;
}
