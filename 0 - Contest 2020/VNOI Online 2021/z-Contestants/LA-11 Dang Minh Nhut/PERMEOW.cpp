#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 2e5+5;
int a[N], b[N];

void Input() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
}

void Solve() {
    int ans = 0;
    for(int i = n; i >= 1; --i) {
        for(int j = 1; j < i; ++j) {
            if (a[j] > a[j+1]) ans++, swap(a[j], a[j+1]);
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("PERMEOW.inp", "r", stdin);
    freopen("PERMEOW.out", "w", stdout);
    Input(); Solve();
    return 0;
}
