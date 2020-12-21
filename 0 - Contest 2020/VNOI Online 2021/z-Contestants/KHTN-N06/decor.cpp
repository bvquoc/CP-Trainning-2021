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

struct dsu {
    vi d;
    dsu(int n): d(n, -1) {}

    int find(int x) {return d[x]<0?x:d[x]=find(d[x]);}
    void join(int x, int y) {
        x=find(x), y=find(y);
        if(x==y) return;
        if(d[x]>d[y]) swap(x, y);
        d[x]+=d[y]; d[y]=x;
    }
};

int32_t main() {
    freopen("decor.inp", "r", stdin);
    freopen("decor.out", "w", stdout);
    fastio;
    int n, m, k; cin>>n>>m>>k;
    vb a(n);
    string s; cin>>s;
    rep(i, n) a[i]=(s[i]=='1');
    dsu d(n);
    rep(i, m) {
        int u, v; cin>>u>>v; --u, --v;
        d.join(u, v);
    }
    vi cmp(n);
    rep(i, n) cmp[i]=d.find(i);
    auto check = [&](int x) -> pii {
        vi f(n), c(n);
        auto need = [&](int i) {return max(c[i]-f[i], 0);};
        int ans=0;
        auto upd = [&](int i, int x) {
            ans-=need(i);
            c[i]+=x;
            ans+=need(i);
        };
        rep(i, n) f[cmp[i]]+=a[i];
        rep(i, x) upd(cmp[i], 1);
        if(ans<=k) return {0, x-1};
        for(int i=x; i<=n-x; i++) {
            upd(cmp[i-x], -1);
            upd(cmp[i], 1);
            if(ans<=k) return {i-x+1, i};
        }
        return {-1, -1};
    };
    pii ans={-1, -1};
    int l=0, r=n;
    while(l<r) {
        int m=(l+r+1)/2;
        auto c=check(m);
        if(~c.fi) ans=c, l=m;
        else r=m-1;
    }
    cout<<ans.fi+1<<' '<<ans.se+1<<endl;
}
