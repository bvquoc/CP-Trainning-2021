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

constexpr int MOD=998244353;
#define F constexpr __attribute__((always_inline))
F int add(int a, int b, int m=MOD) {return (a+=b)>=m?a-m:a;}
F int sub(int a, int b, int m=MOD) {return (a-=b)<0?a+m:a;}
F int mul(int a, int b, int m=MOD) {return (a*1LL*b)%m;}
#undef F

constexpr int N=2005;
int fact[N];

int32_t main() {
    freopen("gift11.inp", "r", stdin);
    freopen("gift11.out", "w", stdout);
    fastio;
    fact[0]=1; rep1(i, N-1) fact[i]=mul(fact[i-1], i);
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        vi odd, even;
        rep(i, n) {
            string s; cin>>s;
            int par=0;
            rep(i, s.length()) {
                if(i&1) par=sub(par, s[i]-'0', 11);
                else par=add(par, s[i]-'0', 11);
            }
            if(s.size()&1) odd.pb(par);
            else even.pb(par);
        }
        int m=odd.size();
        int dp_odd[2][(m+1)/2+1][11];
        int dp[2][n+2][11];
        memset(dp, 0, sizeof(dp));
        memset(dp_odd, 0, sizeof(dp_odd));
        dp_odd[0][0][0]=1;
        for(int v: odd) {
            memset(dp_odd[1], 0, sizeof(dp_odd[1]));
            rep(j, 11) {
                rep(i, (m+1)/2) dp_odd[1][i+1][add(j, v, 11)]=add(dp_odd[1][i+1][add(j, v, 11)], dp_odd[0][i][j]);
                rep(i, (m+1)/2+1) dp_odd[1][i][sub(j, v, 11)]=add(dp_odd[1][i][sub(j, v, 11)], dp_odd[0][i][j]);
            }
            memcpy(dp_odd[0], dp_odd[1], sizeof(dp_odd[0]));
        }
        rep(i, 11) dp[0][m/2+1][i]=mul(dp_odd[0][(m+1)/2][i], mul(fact[(m+1)/2], fact[m/2]));
        for(int v: even) {
            ++m;
            memset(dp[1], 0, sizeof(dp[1]));
            rep(j, 11) {
                for(int i=1; i<=n; i++) if(dp[0][i][j]) {
                    dp[1][i+1][add(j, v, 11)]=add(dp[1][i+1][add(j, v, 11)], mul(dp[0][i][j], i));
                    dp[1][i][sub(j, v, 11)]=add(dp[1][i][sub(j, v, 11)], mul(dp[0][i][j], m-i));
                }
            }
            memcpy(dp[0], dp[1], sizeof(dp[0]));
        }
        int ans=0;
        rep1(i, n) ans=add(ans, dp[0][i][0]);
        cout<<ans<<endl;
    }
}
