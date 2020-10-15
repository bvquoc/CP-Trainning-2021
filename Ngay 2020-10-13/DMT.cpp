#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}
template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

template <typename T>
inline bool maximize(T &x, T y) {
    if (x < y) { x = y; return true; }
    return false;
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 1000006;
int n; ll LIM = -1;
pair <ll, ll> q[N];
vector <ll> a;
ll primeDiv[10000007];

void prepare(ll n) {
    for (ll i = 2; i * i <= n; ++i) {
        if (primeDiv[i] == 0) {
            for (ll j = i * i; j <= n; j += i) {
                if (primeDiv[j] == 0) {
                    primeDiv[j] = i;
                }
            }
        }
    }
    for (ll i = 2; i <= n; ++i) {
        if (primeDiv[i] == 0) {
            primeDiv[i] = i;
        }
    }
}

vector<pair<ll,int>> factorize(int n) {
    vector<pair <ll, int>> res;
    while (n != 1) {
        ll p = primeDiv[n];
        res.push_back({p,0});
        while (n % p == 0) {
            n /= p;
            res.back().second++;
        }
    }
    return res;
}

void getList(ll lim) {
    FOR(i,3,LIM) {
        vector <pair <ll,int>> res;
        res = factorize(i);
        bool have_3 = false;
        for (pair <ll,int> x: res) {
            if (x.first == 3LL) {
                have_3 = true;
                break;
            }
        }
        if (!have_3) continue;
        int cnt = 1;
        for (pair <ll,int> x: res) {
            if (cnt >= 9) break;
            cnt *= (x.second+1);
        }
        if (cnt == 9) a.push_back(i);
    }
}

int getAns(ll k) {
    int p = lower_bound(a.begin(), a.end(), k) - a.begin();
    if (p == a.size()) return p;
    if (a[p] == k) p++;
    return p;
}

signed main(void) {
    FastIO;
    freopen("DMT.INP","r",stdin);
    freopen("DMT.OUT","w",stdout);
    Read(n);
    FOR(i,1,n) {
        Read(q[i].first); Read(q[i].second);
        if (q[i].first > q[i].second) swap(q[i].first, q[i].second);
        maximize(LIM, q[i].second);
    }
    
    prepare(LIM);
    getList(LIM);
    FOR(i,1,n) {
        int ans = getAns(q[i].second) - getAns(q[i].first-1);
        Write(ans);
        putchar('\n');
    }
    return 0;
}