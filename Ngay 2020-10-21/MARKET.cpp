#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

const string INP=".INP", OUT=".OUT";
const string FILENAME="MARKET";
const int N = 100005, INF = INT_MAX;

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


int n, m, x[N], c[N];
int G[N], f[N];

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    Read(n); Read(m);
    FOR(i,1,n) Read(x[i]);
    FOR(i,1,m) {
        Read(c[i]);
        G[i] = c[i];
    }
    FORD(i,m-1,1) G[i] = min(G[i], G[i+1]);
    f[0] = 0;
    sort(x+1, x+1+n);
    FOR(i,1,n) {
        f[i] = INF;
        FOR(j,0,i-1) f[i] = min(f[i], f[j]+G[x[i]-x[j+1]+1]);
    }
    Write(f[n]);
    return 0;
}