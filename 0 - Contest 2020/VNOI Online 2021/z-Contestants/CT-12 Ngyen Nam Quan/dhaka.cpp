#include<bits/stdc++.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define pri(a) printf("%d ", a)
#define pril(a) printf("%d\n", a)
#define fto(i, a, b) for(int i = a; i <= b; ++i)
#define fdto(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define pb push_back
#define sz(a) (int)a.size()
#define pi pair<int, int>
#define ff first
#define sd second
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define oo 1000000007
#define maxN 100005

using namespace std;

int n, m, k, l;
vi dh[maxN];
vector<pi> ke[maxN];
ll dp[maxN][(1<<6)];

struct Node {
    ll w;
    int s, id;
    bool operator < (const Node &o) const {
        return w > o.w;
    }
};
Node make_node(ll weight, int state, int id) {Node x = {weight, state, id}; return x;}

void dijkstra() {
    fto(i, 1, n) fto(j, 0, (1<<k)-1) dp[i][j] = (ll)oo*oo;
    int cur = 0;
    fto(i, 0, sz(dh[1])-1) (cur |= (1 << dh[1][i]));
    dp[1][cur] = 0;
    priority_queue<Node> pq;
    pq.push(make_node(0, cur, 1));

    while(pq.size()) {
        Node top = pq.top(); pq.pop();
        if(top.w != dp[top.id][top.s]) continue;

        int u = top.id, cur_state = top.s;
        fto(i, 0, sz(ke[u])-1) {
            int v = ke[u][i].ff, w = ke[u][i].sd;
            
            int nw_state = cur_state;
            fto(j, 0, sz(dh[v])-1) (nw_state |= (1 << dh[v][j]));

            if(dp[v][nw_state] > dp[u][cur_state] + w) {
                dp[v][nw_state] = dp[u][cur_state] + w;
                pq.push(make_node(dp[v][nw_state], nw_state, v));
            }
        }
    }
}

void solve() {
    dijkstra();
    ll ans = (ll)oo*oo;
    fto(s, 0, (1 << k)-1) {
        int cnt = 0;
        fto(l, 0, k-1) if((s & (1 << l))) ++cnt;
        if(cnt >= l) ans = min(ans, dp[n][s]);
    }
    if(ans == (ll)oo*oo) ans = -1;
    cout << ans;
}

int main() {
    freopen("dhaka.inp", "r", stdin);
    freopen("dhaka.out", "w", stdout);

    scii(n, m); scii(k, l);

    fto(i, 1, n) {
        int s;
        sci(s);
        fto(j, 1, s) {
            int x;
            sci(x);
            --x;
            dh[i].pb(x);
        }
    }

    fto(i, 1, m) {
        int u, v, w;
        scii(u, v); sci(w);
        ke[u].pb(mp(v, w));
        ke[v].pb(mp(u, w));
    }

    solve();

    return 0;
}