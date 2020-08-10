// http://lqdoj.edu.vn/problem/cwdbot
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

int n, res = 0;

signed main(void) {
    FastIO;
    freopen("input.txt","r",stdin);
    cin >> n;
    int a = n/4, b = n/4;
    while (a*2+(b+1)*2<=n) b++;
    res = a*b;
    cout << res;
    return 0;
}