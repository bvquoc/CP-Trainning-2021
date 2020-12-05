#include <bits/stdc++.h>

#define N 100005

using namespace std;

int n;
int a[N];
int max_l[N], max_r[N], min_l[N], min_r[N];
long long ans = 0;

void solve(int l, int r) {
    if (l == r) {
        ans++;
        return;
    }  
    int mid = (l + r) >> 1;
    solve(l, mid);
    solve(mid + 1, r);

    max_l[mid] = min_l[mid] = a[mid];
    for (int i = mid - 1; i >= l; i--) {
        max_l[i] = max(max_l[i + 1], a[i]);
        min_l[i] = min(min_l[i + 1], a[i]);
    }
    max_r[mid + 1] = min_r[mid + 1] = a[mid + 1];
    for (int i = mid + 2; i <= r; i++) {
        max_r[i] = max(max_r[i - 1], a[i]);
        min_r[i] = min(min_r[i - 1], a[i]);
    }

    int cnt[2] = {0, 0};
    for (int i = mid, j1 = mid + 1, j2 = mid + 1; i >= l; i--) {
        while (j2 <= r && max_l[i] >= max_r[j2]) {
            cnt[min_r[j2] & 1]++;
            j2++;
        }
        while (j1 <= r && max_l[i] >= max_r[j1] && min_l[i] <= min_r[j1]) {
            cnt[min_r[j1] & 1]--;
            j1++;
        }
        ans += (((max_l[i] ^ min_l[i]) & 1) == 0) * (j1 - mid - 1);
        ans += cnt[max_l[i] & 1];
        // cout << "left:: " << l << " " << mid << " " << r << " " << i << " " << j1 << " " << j2 << " " << ((((max_l[i] ^ min_l[i]) & 1) == 0) * (j1 - mid)) << " " << cnt[max_l[i] & 1] << "\n";
    }

    cnt[0] = cnt[1] = 0;
    for (int i1 = mid, i2 = mid, j = mid + 1; j <= r; j++) {
        while (i2 >= l && max_l[i2] < max_r[j]) {
            cnt[min_l[i2] & 1]++;
            i2--;
        }
        while (i1 >= l && max_l[i1] < max_r[j] && min_l[i1] >= min_r[j]) {
            cnt[min_l[i1] & 1]--;
            i1--;
        }
        ans += (((max_r[j] ^ min_r[j]) & 1) == 0) * (mid - i1);
        ans += cnt[max_r[j] & 1];
        // cout << "right:: " << l << " " << mid << " " << r << " " << i2 << " " << i1 << " " << j << " " << ((((max_r[j] ^ min_r[j]) & 1) == 0) * (mid - i1 + 1)) << " " << cnt[max_r[j] & 1] << "\n";
    }
}

int main() {
    freopen("evensub.inp", "r", stdin);
    freopen("evensub.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    solve(1, n);
    cout << ans;
}