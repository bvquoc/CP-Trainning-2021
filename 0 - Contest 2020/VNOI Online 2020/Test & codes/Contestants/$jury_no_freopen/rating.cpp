#include <bits/stdc++.h>

using namespace std;

const int maxn = 300005;
int n, q;
long long a[maxn], s1[maxn], s2[maxn];

long long cal(long long x, int l, int r) {
    if (l > r) return x;
    int til = upper_bound(s1 + l, s1 + r + 1, x + s1[l - 1]) - s1 - 1;
    x -= s1[til] - s1[l - 1];
    if (r % 2 == til % 2)
        x = s2[r] - s2[til] + x;
    else
        x = s2[r] + s2[til] - x;
    return x;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

#if ONLINE_JUDGE || THEMIS
#endif

    int nsubtask;
    cin >> nsubtask;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s1[i] = a[i] + s1[i - 1];
        s2[i] = a[i] - s2[i - 1];
    }
    while (q--) {
        int l, r;
        long long x;
        cin >> x >> l >> r;
        x = abs(x - a[l]);
        ++l;
        cout << cal(x, l, r) << '\n';
    }
    return 0;
}
