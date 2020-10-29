#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
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

#define MAX_Q 200005
int k, m, q_sz;
int a[MAX_Q], b[MAX_Q], c[MAX_Q];
string s;

int getIndex(int k) {
    FORD(i,q_sz,1) {
        if (k < c[i]) continue;
        if (k >= c[i] + (b[i] - a[i])) k -= b[i] - a[i];
        else k -= c[i] - a[i];
    }
    return k;
}

signed main(void) {
    freopen("FASTTYPE.INP","r",stdin);
    freopen("FASTTYPE.OUT","w",stdout);
    Read(k); Read(m);
    getline(cin,s);
    Read(q_sz);
    FOR(i,1,q_sz) Read(a[i]), Read(b[i]), Read(c[i]);

    FOR(i,0,k-1) putchar(s[getIndex(i)]);
    return 0;
}