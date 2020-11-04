#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100005];
long long s[100005];

bool solve(int l) {
    for (int i = l; i <= n; i++) {
        if (s[i] - s[i - l] < m) return 0;
    }
    return 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    //cout << solve(2) << endl;
    int lower = 1, upper = n;
    while (lower < upper) {
        int mid = (lower + upper) / 2;
        if (solve(mid) == 0) {
            lower = mid + 1;
        }
        else upper = mid;
    }

    //if (!solve(lower)) lower--;
    cout << lower;

    return 0;
}