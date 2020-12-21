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

constexpr int MOD=1e9+7;
#define F constexpr __attribute__((always_inline))
F int add(int a, int b) {return (a+=b)>=MOD?a-MOD:a;}
F int sub(int a, int b) {return (a-=b)<0?a+MOD:a;}
F int mul(int a, int b) {return (a*1LL*b)%MOD;}
F int exp(int a, int b) {
    int res=1;
    for(; b; b>>=1) {
        if(b&1) res=mul(res, a);
        a=mul(a, a);
    }
    return res;
}
#define div oqitht4fb3
F int div(int a, int b) {return mul(a, exp(b, MOD-2));}
#undef F

constexpr int N=2e5+5;
int fact[N], cnt[N];
int a[N];
int c[N];

void prep() {
    fact[0]=1;
    rep1(i, N-1) fact[i]=mul(fact[i-1], i);
    cnt[0]=0;
    rep1(i, N-1) cnt[i]=add(mul(div(mul(i, i-1), 2), fact[i-1]), mul(i, cnt[i-1]));
}

int solve(int n, bool incl) {
    prep();
    rep(i, n) cin>>a[i];
    ordered_set<int> rm;
    rep1(i, n) rm.insert(i);
    int ans=0;
    rep(i, n) {
        c[i]=mul(fact[n-i-1], rm.order_of_key(a[i]));
        rm.erase(a[i]);
    }
    for(int i=n-2; ~i; i--) c[i]=add(c[i], c[i+1]);
    rm.clear();
    rep(i, n-1) {
        int x=a[i]-rm.order_of_key(a[i]);
        rm.insert(a[i]);
        ans=add(ans, add(mul(div(mul(x-1, x-2), 2), fact[n-i-1]), add(mul(x-1, cnt[n-i-1]), mul(x-1, add(c[i+1], incl)))));
    }
    return ans;
}

int32_t main() {
    freopen("permeow.inp", "r", stdin);
    freopen("permeow.out", "w", stdout);
    fastio;
    prep();
    int n; cin>>n;
    int res_a=solve(n, 0);
    int res_b=solve(n, 1);
    cout<<sub(res_b, res_a)<<endl;
}
