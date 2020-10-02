#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
using namespace std;

using ii = pair <int,int>;
using ll = long long;
using ld = long double;

const int N = 100005;
int n, K, a[N];
int psum[N];

signed main() {
    FastIO;
    freopen("TEAM.INP","r",stdin);
    freopen("TEAM.OUT","w",stdout);
    cin >> n >> K;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
    }
    K %= psum[n];
    for (int i=1; i<=n; i++) {
        if (K<a[i]) break;
        K -= a[i];
    }
    cout << K;
    return 0;
}
