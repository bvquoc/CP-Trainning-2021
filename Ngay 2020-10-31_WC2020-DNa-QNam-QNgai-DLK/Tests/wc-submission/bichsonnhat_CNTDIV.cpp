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

const ll N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll BASE = 1000;
const ll DIGIT = 4;
const ll LIM = (1 << 24);
const ll INF = (1 << 30);
const ll LIMIT = 1e18;

/// ================================ - MAIN - ================================

int kt[N];
int n;
int d[N];
long long cnt[N],cnt1[N];
void Sieve(){
    kt[0] = kt[1]=1;
    for (int i = 2; i <= sqrt(N); i++)
        if (!kt[i])
            for (int j = 2; j * i <= N; j++)
                kt[i*j]=i;
    for (int i = 2; i <= N; i++)
        if (!kt[i]) kt[i]=i;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    #ifndef ONLINE_JUDGE
//        freopen(TASK".INP","r",stdin);
//        freopen(TASK".OUT","w",stdout);
//    #endif
    int TC;
    cin >> TC;
    Sieve();
//    cerr << kt[1];
    while (TC--)
    {
        long long kq=1,ans=1;
        int M=0;
        cin >> n;
//        vector <pii> S0, S1, S2;
        set <int > s;
        int m = n;
        while (m != 1){
         d[kt[m]]++;
         //M = max(M,kt[m]);
         s.insert(kt[m]);
         m /= kt[m];
        }
        m = n + 1;
        while (m != 1) {
            d[kt[m]]++;
//            M = max(M,kt[m]);
            s.insert(kt[m]);
            m /= kt[m];
        }
         m = n + 2;
           while (m!=1)
        {
         d[kt[m]]++;
//         M=max(M,kt[m]);
        s.insert(kt[m]);
         m/=kt[m];
        }
        for (auto x : s)
        {
            kq*=(d[x] + 1);
            ans*=(2*d[x]+1);
            d[x] = 0;
        }
        cout<<ans-kq-ans/2<<"\n";
    }
    return 0;
}
