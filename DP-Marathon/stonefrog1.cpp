// http://lqdoj.edu.vn/problem/stonefrog1
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;

const int N = 100005;
int n, a[N], f[N];

signed main(void) {
    freopen("input.txt","r",stdin);
    FastIO;
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    f[1] = 0;
    f[2] = abs(a[1]-a[2]);
    FOR(i,3,n) {
        f[i] = f[i-1]+abs(a[i]-a[i-1]);
        f[i] = min(f[i], f[i-2]+abs(a[i]-a[i-2]));
    }
    cout << f[n];
    return 0;
}