// http://lqdoj.edu.vn/problem/ezgcd
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

using ii = pair <int, int>;
using ld = long double;

const int N = 300005, A = 3000006;
int n, k, a[N], cnt[A];

void update(int a) {
    int canA = sqrt(a);
    FOR(i,1,canA) {
        if (a%i == 0) {
            cnt[i]++;
            if (a/i != i) cnt[a/i]++;
        }
    }
}

signed main(void) {
    FastIO;
    Read(n); Read(k);
    FOR(i,1,n) {
        Read(a[i]);
        update(a[i]);
    }

    if (k == 0) {
        int gcd = a[1];
        FOR(i,1,n) gcd = __gcd(gcd,a[i]);
        cout << gcd;
        return 0;
    }

    FORD(i,*max_element(a+1,a+1+n),1) {
        if (cnt[i]>=n-k) {
            Write(i);
            break;
        }
    }
    return 0;
}