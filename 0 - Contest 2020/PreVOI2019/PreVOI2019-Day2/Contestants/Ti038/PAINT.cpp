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

struct dsu {
    vector<int> root; int cr[26];
    void init() {rep(i, 26) cr[i]=-1;}
    void add(char a) {
        int x=a-'a';
        if(cr[x]==-1) {
            root.pb(-1); cr[x]=root.size()-1;
        }
        else {
            root.pb(cr[x]);
        }
    }
    int find(int x) {
        if (root[x]<0) return x;
        else {
            int r=find(root[x]);
            root[x]=r; return r;
        }
    }
    int crfind(char a) {return cr[a-'a'];}
    char c(int n) {
        int r=find(n);
        rep(i, 26) if(cr[i]==r) return i+'a';
        return '#';
    }
    void print() {
        rep(i, root.size()) cout<<c(i); cout<<endl;
        //rep(i, root.size()) cout<<root[i]<<" "; cout<<endl;
    }
    bool same (int x, int y) {return find(x)==find(y);}
    void join(char x, char y) {
        int rx=crfind(x), ry=crfind(y);
        if(!(rx==ry)&&!(rx==-1)) {
            if(ry==-1) {
                cr[y-'a']=rx;
            }
            else if(root[rx]<root[ry]) {
                root[rx]+=root[ry];
                root[ry]=rx;
                cr[y-'a']=rx;
            }
            else {
                root[ry]+=root[rx];
                root[rx]=ry;
            }
            cr[x-'a']=-1;
        }
    }
} D;

int32_t main() {
    fastio;
    freopen("PAINT.out", "w", stdout); freopen("PAINT.inp", "r", stdin);
    int n; cin>>n;
    D.init();
    while(n--) {
        int t; cin>>t;
        if(t==1) {
            char c; cin>>c; D.add(c);
        }
        else {
            char a, b; cin>>a>>b; D.join(a, b);
        }
    }
    D.print();
}
