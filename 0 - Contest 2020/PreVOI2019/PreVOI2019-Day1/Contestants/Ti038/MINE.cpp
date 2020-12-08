#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#pragma 03

using namespace std;
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define gcd __gcd
int lcm(int x, int y) {return x*y/gcd(x, y);}
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define rep(i, n) for (int (i)=0; (i)<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int a[100001];

int32_t main() {
    fastio;
    freopen("mine.out", "w", stdout); freopen("mine.inp", "r", stdin);
    int n, m, ans=0; cin>>n>>m; n*=2; int a[n]; rep(i, n) cin>>a[i];
    for(int mask=0; mask<1<<n; mask++) {
        if(2*__builtin_popcount(mask)!=n) continue;
        bool s[n];
        rep(i, n) s[i]=mask&(1<<i);
        stack<pair<bool, int>> st;
        rep(i, n) {
            if(s[i]==1) st.push(mp(s[i], a[i]));
            else if(s[i]==0&&!st.empty()&&st.top().fi==1&&a[i]-st.top().se<=m) st.pop();
            else st.push(mp(s[i], a[i]));
        }
        if(st.empty()) ans++;
    }
    cout<<ans%1000003<<endl;
}
