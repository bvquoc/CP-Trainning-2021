#include <bits/stdc++.h>
#define Task "PERMEOW"

using namespace std;

const int maxn = 100005;

int n, a[maxn], b[maxn], pos[maxn], bonus[maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; ++ i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for(int i = 1; i <= n; ++ i) {
        cin >> b[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; ++ i) {
        for(int j = pos[i] - 1; j >= i; -- j) {
            swap(a[j], a[j + 1]);
            ++ans;
        }
        for(int j = 1; j <= n; ++ j) pos[a[j]] = j;
    }
    cout << ans;
}
