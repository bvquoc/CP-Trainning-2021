#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

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


int32_t main() {
    freopen("socks.inp", "r", stdin);
    freopen("socks.out", "w", stdout);
    fastio;
    int n, q; cin>>n>>q;
    vvi adj(n);
    vi a(n);
    int cnt=0;
    rep(i, n) cin>>a[i], cnt+=a[i];
    rep(i, n-1) {
        int u, v; cin>>u>>v; --u, --v;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    auto detect_sub_1 = [&]() -> bool {
        rep(i, n) if(adj[i].size()>2) return 0;
        return 1;
    };
    if(detect_sub_1()) {
        cout<<!!cnt<<endl;
        while(q--) {
            int x; cin>>x; --x;
            cnt-=a[x]; a[x]^=1; cnt+=a[x];
            cout<<!!cnt<<endl;
        }
        return 0;
    }
    auto detect_sub_2 = [&]() {
        int rt=-1;
        rep(i, n) {
            if(adj[i].size()>3) return -1;
            else if(adj[i].size()==3) {
                if(!~rt) rt=i;
                else return -1;
            }
        }
        return rt;
    };
    int sub_2_rt=detect_sub_2();
    if(~sub_2_rt) {
        vi color(n, -1);
        int st[3]={0};
        auto dfs = [&](int u, int c, int p) -> void {
            auto dfs = [&](int u, int c, int p,  const auto& __dfs) -> void {
                st[c]+=a[u];
                color[u]=c;
                for(int v: adj[u]) if(v!=p) __dfs(v, c, u, __dfs);
            };
            dfs(u, c, p, dfs);
        };
        rep(i, 3) dfs(adj[sub_2_rt][i], i, sub_2_rt);
        while(q--) {
            int x; cin>>x; --x;
            cnt-=a[x];
            st[color[x]]-=a[x];
            a[x]^=1;
            cnt+=a[x];
            st[color[x]]+=a[x];
            if(!cnt) cout<<"0\n";
            else {
                int g=0;
                rep(i, 3) g+=!!st[i];
                cout<<max(g-1, 0)<<endl;
            }
        }
        return 0;
    }
    auto process = [&]() -> void {
        if(!cnt) cout<<"0\n";
        else {
            vb in(n, 0);
            vb marked(n, 0);
            auto dfs1 = [&](int u, int p=-1) -> void {
                auto dfs = [&](int u, int p,  const auto& __dfs) -> int {
                    int sz=a[u];
                    for(int v: adj[u]) if(v!=p) sz+=__dfs(v, u, __dfs);
                    if(sz) in[u]=1;
                    return sz;
                };
                dfs(u, p, dfs);
            };
            auto dfs2 = [&](int u, int p=-1) -> void {
                auto dfs = [&](int u, int p,  const auto& __dfs) -> void {
                    int cnt=0;
                    for(int v: adj[u]) if(v!=p&&in[v]) {
                        __dfs(v, u, __dfs);
                        if(!marked[v]) {
                            if(cnt>1) marked[v]=1;
                            cnt++;
                        }
                    }
                    marked[u]=(cnt>1);
                };
                dfs(u, p, dfs);
            };
            int rt=-1;
            rep(i, n) if(a[i]) {rt=i; break;}
            dfs1(rt);
            dfs2(rt);
            cout<<accumulate(all(marked), 1)<<endl;
        }
    };
    process();
    while(q--) {
        int x; cin>>x; --x;
        cnt-=a[x]; a[x]^=1; cnt+=a[x];
        process();
    }
}
