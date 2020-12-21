#include<bits/stdc++.h>
#define MAX_N 100005
#define l first
#define r second
#define Task "COOLMAC"

using namespace std;

int n, m, L;
int T[MAX_N];
pair<int, int> A[MAX_N], vt[MAX_N];

bool cmp (pair<int, int> a, pair<int, int> b) {return a.r < b.r;}
bool cmp2 (pair<int, int> a, pair<int, int> b) {
    if (a.l == b.l)
        return a.r > b.r;
    return a.l < b.l;
}

bool check1(int x) {
    int cnt = 0;
    for (int i = 0; i < m; i++)
        if ((x >> i) & 1)
            vt[++cnt] = A[i + 1];

    sort(vt + 1, vt + cnt + 1, cmp);

    if (vt[cnt].r < 1e5 || vt[1].l > L)
        return 0;

    int Left = vt[cnt].l;
    for (int i = cnt; i >= 2; i--)
        if (vt[i].l > vt[i - 1].r)
            break;
        else
            Left = vt[i - 1].l;
    return Left <= L;
}

void sub1() {
    int ans = -1;
    for (int x = 0; x < (1 << m); x++)
        if (check1(x))
            if (ans == -1)
                ans = __builtin_popcount(x);
            else
                ans = min(ans, __builtin_popcount(x));
    cout << ans;
    exit(0);
}

int Bsearch(int x) {
    int l = 1, r = m, res = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if (A[mid].l <= x) {
            res = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return res;
}

void solve() {
    sort(A + 1, A + m + 1, cmp2);
    vector<pair<int, int>> ds;
    for (int i = 1; i <= m; i++) {
        if (ds.empty()) {
            ds.push_back(A[i]);
            continue;
        }
        if (ds.back().l <= A[i].l && A[i].r <= ds.back().r)
            continue;
        ds.push_back(A[i]);
    }
    int cnt = 0;
    for (auto x : ds)
        A[++cnt] = x;
    m = cnt;
    int ans = 0, prevpos = 0;
    for (int i = 1; i <= m; i++) {
        int pos = Bsearch(L);
        if (pos == -1 || pos == prevpos) {
            cout << -1;
            exit(0);
        }
        prevpos = pos;
        ans++;
        if (A[pos].r >= 1e5)
            break;
        L = A[pos].r;
    }
    cout << (!ans ? -1 : ans);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> A[i].l >> A[i].r;
    cin >> n;
    L = 1e5;
    for (int t, i = 1; i <= n; i++) {
        cin >> t;
        L = min(L, t);
    }
    if (n <= 10 && m <= 16)
        sub1();
    solve();
}
