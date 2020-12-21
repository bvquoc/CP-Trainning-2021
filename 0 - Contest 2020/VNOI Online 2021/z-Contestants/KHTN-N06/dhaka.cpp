#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma,popcnt")

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N=1e5+5, M=32;
constexpr ll INF=0x3f3f3f3f3f3f3f3f;
ll dist[N][M];
vector<pii> adj[N];
int msk[N];

int32_t main() {
    freopen("dhaka.inp", "r", stdin);
    freopen("dhaka.out", "w", stdout);
    fastio;
    int n, m, k, l; cin>>n>>m>>k>>l;
    rep(i, n) {
        int sz; cin>>sz;
        while(sz--) {
            int x; cin>>x; --x;
            msk[i]|=(1<<x);
        }
    }
    rep(i, m) {
        int u, v, w; cin>>u>>v>>w; --u, --v;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }
    bitset<M> in[N];
    memset(dist, 0x3f, sizeof(dist));
    queue<pii> Q;
    dist[0][msk[0]]=0;
    in[0][msk[0]]=1;
    Q.emplace(0, msk[0]);
    while(!Q.empty()) {
        int u=Q.front().fi, c=Q.front().se;
        Q.pop();
        in[u][c]=0;
        for(auto& __e: adj[u]) {
            int &v=__e.fi, &w=__e.se;
            if(dist[v][c|msk[v]]>dist[u][c]+w) {
                dist[v][c|msk[v]]=dist[u][c]+w;
                if(!in[v][c|msk[v]]) in[v][c|msk[v]]=1, Q.emplace(v, c|msk[v]);
            }
        }
    }
    ll ans=INF;
    rep(i, 1<<k) if(__builtin_popcount(i)>=l) ans=min(ans, dist[n-1][i]);
    cout<<(ans==INF?-1:ans)<<endl;
}
