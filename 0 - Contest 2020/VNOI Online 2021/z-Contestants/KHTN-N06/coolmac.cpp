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
    freopen("coolmac.inp", "r", stdin);
    freopen("coolmac.out", "w", stdout);
    fastio;
    int n; cin>>n;
    pii a[n];
    rep(i, n) cin>>a[i].fi>>a[i].se;
    sort(a, a+n);
    int l=1e5, r=1e5;
    int m; cin>>m;
    rep(_, m) {int x; cin>>x; l=min(l, x);}
    priority_queue<int> s;
    int ans=0, ptr=0;
    while(l<r) {
        for(; ptr<n&&a[ptr].fi<=l; ptr++) s.push(a[ptr].se);
        if(s.top()<=l) return puts("-1"), 0;
        ans++, l=s.top(); s.pop();
    }
    cout<<ans<<endl;
}
