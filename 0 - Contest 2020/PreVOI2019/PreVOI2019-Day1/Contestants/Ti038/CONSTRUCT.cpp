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

int a[100001];

void update(int l, int r, int k) {
    for(int i=l-1; i<r; i++) a[i]+=k;
}

int solve(int n, int l, int r) {
    stack<int> s; int ans=0;
    int b[n];
    for(int i=0; i<l-1; i++) b[i]=0; for(int i=l-1; i<r; i++) b[i]=a[i]; for(int i=r; i<n; i++) b[i]=0;
    rep(i, n) {
        if(s.empty()||b[i]>s.top()) s.push(b[i]);
        else {
            while(!s.empty()&&b[i]<=s.top()) {
                int x=s.top(); s.pop();
                if(s.empty()||b[i]>s.top()) ans+=x-b[i]; else ans+=x-s.top();
            }
            s.push(b[i]);
        }
    }
    while(!s.empty()) {
        int x=s.top(); s.pop();
        if(s.empty()) ans+=x; else ans+=x-s.top();
    }
    return ans;
}

int32_t main() {
    fastio;
    freopen("construct.out", "w", stdout); freopen("construct.inp", "r", stdin);
    int q; cin>>q; while(q--) {
        memset(a, 0, sizeof(a));
        int n, m; cin>>n>>m; rep(i, n) cin>>a[i];
        rep(i, m) {
            int t; cin>>t;
            if(t==1) {
                int l, r, k; cin>>l>>r>>k;
                update(l, r, k);
            }
            else {
                int l, r; cin>>l>>r;
                cout<<solve(n, l, r)<<endl;
            }
        }
    }
}
