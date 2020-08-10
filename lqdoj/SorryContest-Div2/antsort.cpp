// http://lqdoj.edu.vn/problem/antsort
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
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

const int N = 300005;
int n, a[N], res = 2e9;

bool check(int t) {
    int cur_pos = a[1]-t;
	FOR(i,2,n) {
		if (a[i]<=cur_pos && (cur_pos+1-a[i])>t) return false;
		else if (a[i]<=cur_pos) cur_pos++;
		else cur_pos = max(cur_pos+1, a[i]-t);
	}
	return true;
}

signed main(void) {
    FastIO;
    Read(n);
    FOR(i,1,n) Read(a[i]);
    
    if (is_sorted(a+1,a+1+n,less_equal<int>())) {
        putchar('0');
        putchar('\n');
        FOR(i,1,n) {
            Write(a[i]);
            putchar(' ');
        }
        return 0;
    }

    int l = 0, r = 2e9;
    while (l<=r) {
        int mid = l+(r-l)/2;
        if (check(mid)) {
            r = mid-1;
            res = mid;
        } else l = mid+1;
    }

    Write(res); putchar('\n');
    int cur_pos = a[1] - res;
	Write(cur_pos); putchar(' ');
    FOR(i,2,n) {
		if (a[i]<=cur_pos) cur_pos++;
		else cur_pos = max(cur_pos+1, a[i]-res);
		Write(cur_pos); putchar(' ');
	}
    return 0;
}