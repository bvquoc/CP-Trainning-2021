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

int solve(string s, int l, int r) {
    l--; r--; int diff=0, ans=0;
    for(int i=l; i<=r; i++) {
        if(s[i]=='(') diff++; else diff--;
        if(diff<0) {ans-=diff; diff=0;}
    }
    ans+=diff;
    return ans;
}

int32_t main() {
    fastio;
    freopen("FIXSTR.out", "w", stdout); freopen("FIXSTR.inp", "r", stdin);
    string s; int n; cin>>s>>n;
    vector<string> v(n+1, ""); v[0]=s;
    for(int i=1; i<=n; i++) {
        char t; cin>>t;
        if(t=='C') {
            int k; cin>>k;
            v[i]=v[i-1];
            v[i][k-1]=v[i][k-1]=='('?')':'(';
        }
        else if (t=='Q') {
            int l, r; cin>>l>>r;
            v[i]=v[i-1];
            cout<<solve(v[i], l, r)<<endl;
        }
        else {
            int k; cin>>k; v[i]=v[k-1];
        }
    }
}
