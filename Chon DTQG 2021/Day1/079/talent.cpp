#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pii;
const int maxN = 1e5+1;

int n, m;
pii a[maxN];
int sumW[maxN], sumWD[maxN];

int getSumW(int l, int r) {
    if (l > r) return 0;
    return sumW[r] - sumW[l-1];
}

int getSumWD(int l, int r) {
    if (l > r) return 0;
    return sumWD[r] - sumWD[l-1];
}

int binaryFind(int p) {
    int l = 1, r = n, mid, ans = 0;
    while (l <= r) {
        mid = (l + r)/2;
        if (a[mid].first <= p) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

int solve(int p) {
    int x = binaryFind(p);
    return p * getSumW(1, x) - getSumWD(1, x) - p * getSumW(x+1, n) + getSumWD(x+1, n);
}

int32_t main() {
    freopen("talent.inp", "r", stdin);
    freopen("talent.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first;
    for (int i = 1; i <= n; i++)
        cin >> a[i].second;

    sort(a+1, a+n+1);

    sumW[0] = sumWD[0] = 0;
    for (int i = 1; i <= n; i++) {
        sumW[i] = sumW[i-1] + a[i].second;
        sumWD[i] = sumWD[i-1] + a[i].first*a[i].second;
    }

    while (m--) {
        int p; cin >> p;
        cout << solve(p) << '\n';
    }

    return 0;
}
