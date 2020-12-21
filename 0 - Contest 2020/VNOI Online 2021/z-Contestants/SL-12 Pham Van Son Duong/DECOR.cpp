#include <bits/stdc++.h>
#define MAX_N 500005
#define Task "DECOR"

using namespace std;

int sum[MAX_N];
bool A[MAX_N];
int n, k, m;
vector<int> ds[MAX_N];

void sub1() {
    sum[0] = 0;
    int a, b;
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + A[i];
    int l = 1, res = 0;
    for (int i = 1; i <= n; i++) {
        while (sum[i] - sum[l - 1] < (i - l + 1))
            l++;
        if (res < i - l + 1) {
            res = i - l + 1;
            a = l, b = i;
        }
    }
    if (res < n - l + 1) {
        res = n - l + 1;
        a = l, b = n;
    }
    if (res)
        cout << a << ' ' << b;
    else
        cout << -1;
    exit(0);
}

void sub2() {
    sum[0] = 0;
    int a, b;
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + A[i];
    int l = 1, res = 0;
    for (int i = 1; i <= n; i++) {
        while (sum[i] - sum[l - 1] + k < (i - l + 1))
            l++;
        if (res < i - l + 1) {
            res = i - l + 1;
            a = l, b = i;
        }
    }
    if (res < n - l + 1) {
        res = n - l + 1;
        a = l, b = n;
    }
    if (res)
        cout << a << ' ' << b;
    else
        cout << -1;
    exit(0);
}

bool avail[MAX_N];
int L, R;

bool DFS(int u) {
    avail[u] = 0;
    if (A[u] && (L > u || R < u))
        return 1;
    for (int v : ds[u])
        if (avail[v])
            return DFS(v);
    return 0;
}

bool check(int l, int r) {
    int cnt = k;
    fill_n(avail + 1, n, 1);
    for (int i = l; i <= r; i++)
        if (!A[i]) {
            L = l, R = r;
            if (DFS(i))
                continue;
            if (cnt) {
                cnt--;
                continue;
            }
            return 0;
        }
    return 1;
}

void sub3() {
    int res = 0, a, b;
    for (int i = 1; i <= n; i++) {
        int l = i, r = n, j = i;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if (check(i, mid)) {
                j = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if (res < j - i + 1) {
            res = j - i + 1;
            a = i, b = j;
        }
    }
    if (res)
        cout << a << ' ' << b;
    else
        cout << -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> m >> k;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++)
        A[i] = (s[i - 1] == '1');
    for (int a, b, i = 1; i <= m; i++) {
        cin >> a >> b;
        ds[a].push_back(b);
        ds[b].push_back(a);
    }
    if (!m && !k)
        sub1();
    if (!m)
        sub2();
    if (n <= 2000)
        sub3();
}
