#include <bits/stdc++.h>

using namespace std;

//#include <ext/rope>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;
//typedef tree< double, int, less<double>, rb_tree_tag, tree_order_statistics_node_update> map_t;

/// Shortcut

#define TASK "TEST2"
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for (ll i = l; i <= r; i++)
#define FORTYPE(type, i, l, r) for (type i = l; i <= r; i++)
#define FODTYPE(type, i, l, r) for (type i = l; i >= r; i--)
#define FOD(i, l, r) for (ll i = l; i >= r; i--)
#define FORAUTO(i, a) for (auto i : a)

/// Functions

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define upper upper_bound
#define lower lower_bound
#define itr iterator
#define rtr reverse_iterator
#define memset(a,x) memset(a, x, sizeof(a))
#define memsetf(a) memset(a, 0x3f, sizeof(a))
#define fillV(v, x) fill(v.begin(), v.end(), x)
#define fillArr(arr, n, x) fill(arr, arr + n, x)
#define fillA(a, n, x) fill(a + 1, a + n + 1, x)

/// Data Structure

#define um unordered_map
#define us unordered_set
#define pq priority_queue

/// BIT

#define cntBit(n) __builtin_popcount(n)
#define cntBitll(n) __builtin_popcountll(n)

/// EDIT

const ll MAX = 1005;
const ll MOD = 1e9 + 7;
const ll BASE = 1000;
const ll DIGIT = 4;
const ll LIM = (1 << 24);
const ll INF = 1e9 + 5;
const ll LIMIT = (1 << 30);

/// ================================ - MAIN - ================================

int n, m, k, cur;
ll dist[MAX][MAX], r, l;
vl Edge[MAX];
ll d[MAX][MAX];
int MatchX[MAX], Used[MAX];

bool DFS(int u, int val){
    if (Used[u] == cur) return 0;
    Used[u] = cur;
    for (int v : Edge[u])
        if (d[u][v] >= val)
            if (MatchX[v] == 0|| DFS(MatchX[v], val)){
                MatchX[v] = u;
                return 1;
            }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ll w;
            cin >> w;
            Edge[i].pb(j), d[i][j] = w;
        }
    }

    l = 0, r = INF;
    while (l <= r){
        ll mid = (l + r) >> 1;
        memset(Used, 0);
        memset(MatchX, 0);
        ll res = 0;
        for (cur = n; cur >= 1; cur--)
            res += DFS(cur, mid);
        if (res < n) r = mid - 1;
            else l = mid + 1;
    //    cout << l << ' ' << r << '\n';
    }
    // int papa = 0;
    // for (cur = n; cur >= 1; cur--)
    //         papa += DFS(cur, r);
    // if (papa == n) {cout << r; return 0;} 
    cout << r;

    return 0;
}
