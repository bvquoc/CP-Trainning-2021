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
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int coins[] = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};

int f(int n) {
    int ans=0, curr=14;
    while(n>0) {
        while(coins[curr]>n) curr--;
        ans+=n/coins[curr]; n%=coins[curr];
    }
    return ans;
}

int solve(int n, int x) {
    int ans=f(n), tg=min(f(n), n/x)+1;
    rep(i, tg) ans=min(ans, f(n-i*x)+i);
    return ans;
}

int32_t main() {
    fastio;
    freopen("oddcoin.out", "w", stdout); freopen("oddcoin.inp", "r", stdin);
    int q; cin>>q; while(q--) {
        int n, x; cin>>x>>n; cout<<solve(n, x)<<endl;
    }
}
