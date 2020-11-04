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

#define GetMask ((x >> i) & 1)
#define cntBit(n) __builtin_popcount(n)
#define cntBitll(n) __builtin_popcountll(n)

/// EDIT

const ll MAX = 100005;
const ll MOD = 1e9 + 7;
const ll BASE = 1000;
const ll DIGIT = 4;
const ll LIM = (1 << 24);
const ll INF = (1 << 30);
const ll LIMIT = 1e18;

/// ================================ - MAIN - ================================

ll k;
ll res;

ll Solve(ll a, ll b){
    if ((b + a) % 2 == 0)
        return (b + a) / 2;
            else return 0;
}
ll Find(ll N){
    ll X = 1e12;
    ll ans, tmp;
    ll n = N;
    N = abs(N);
    FOR(i, 1, sqrt(N)){
        if (N % i == 0){
            ll a = i;
            ll b = N / i;
            tmp = Solve(a, b);
//            cerr << tmp << '\n';
            if (tmp != 0 && tmp * tmp + n >= 0) X = min(X, abs(tmp));
            tmp = Solve(-a, n / (-a));
//            cerr << tmp << '\n';
            if (tmp != 0 && tmp * tmp + n >= 0) X = min(X, abs(tmp));
        }
    }
    X = min(X, tmp);
    if (X != 1e12)
        ans = X;
    else
        ans = -1;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    #ifndef ONLINE_JUDGE
//        freopen(TASK".INP","r",stdin);
//        freopen(TASK".OUT","w",stdout);
//    #endif
    cin >> k;
    if (k >= 0 && sqrt(k) * sqrt(k) == k){
        cout << sqrt(k);
        return 0;
    }
    res = Find(k);
    if (res == -1) cout << "none";
            else cout << res;
    return 0;
}
