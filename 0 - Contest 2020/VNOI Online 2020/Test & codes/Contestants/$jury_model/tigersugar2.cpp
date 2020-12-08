#include <bits/stdc++.h>

using namespace std;

const int maxn = 200005;
int n;
long long k;
long long x[maxn], y[maxn];
int ord[maxn];
vector <long long> val[6];

int main(void) {
#if ONLINE_JUDGE || THEMIS
    freopen("tigersugar2.inp", "r", stdin);
    freopen("tigersugar2.out", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
        val[4].push_back(x[i]);
        val[5].push_back(y[i]);
    }
    if (n == 1) {
        cout << 0 << endl << x[1] << ' ' << y[1] << endl;
        return 0;
    }
    sort(val[4].begin(), val[4].end());
    sort(val[5].begin(), val[5].end());
    int tarx = val[4][n/2], tary = val[5][n/2];
    for (int i = 0; i < n / 2; ++i) {
        val[0].push_back(tarx - val[4][i]);
        val[2].push_back(tary - val[5][i]);
    }
    for (int i = n - 1; i > n - 1 - n / 2; --i) {
        val[1].push_back(val[4][i] - tarx);
        val[3].push_back(val[5][i] - tary);
    }
    for (int i = 0; i < 4; ++i) val[i].push_back(0);

    int id;
    for (id = 0; id < n / 2; ++id) {
        long long need = 0;
        for (int j = 0; j < 4; ++j) need += (val[j][id] - val[j][id+1]) * (id + 1);
        if (need > k) break;
        k -= need;
    }
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < id; ++i) val[j][i] = val[j][id];
    }
    if (id < n / 2) {
        for (int j = 0; j < 4; ++j) {
            long long gap = val[j][id] - val[j][id+1];
            if (gap * (id + 1) > k) {
                int phase = k / (id + 1);
                for (int i = 0; i <= id; ++i) val[j][i] -= phase;
                int odd = k % (id + 1);
                for (int i = id; i > id - odd; --i) --val[j][i];
                k = 0;
                break;
            }
            else {
                for (int i = 0; i <= id; ++i) val[j][i] = val[j][id+1];
                k -= gap * (id + 1);
            }
        }
    }

    val[4].clear();
    for (int i = 0; i <= (int)val[0].size() - 2; ++i) val[4].push_back(tarx - val[0][i]);
    if (n & 1) val[4].push_back(tarx);
    for (int i = (int)val[1].size() - 2; i >= 0; --i) val[4].push_back(tarx + val[1][i]);

    val[5].clear();
    for (int i = 0; i <= (int)val[2].size() - 2; ++i) val[5].push_back(tary - val[2][i]);
    if (n & 1) val[5].push_back(tary);
    for (int i = (int)val[3].size() - 2; i >= 0; --i) val[5].push_back(tary + val[3][i]);

    iota(ord, ord + n, 1);
    sort(ord, ord + n, [](int a, int b) { return x[a] < x[b]; });
    for (int i = 0; i < n; ++i) x[ord[i]] = val[4][i];

    iota(ord, ord + n, 1);
    sort(ord, ord + n, [](int a, int b) { return y[a] < y[b]; });
    for (int i = 0; i < n; ++i) y[ord[i]] = val[5][i];

    long long tot = 0;
    for (int i = 0; i < n; ++i)
        tot += (val[4][i] + val[5][i]) * (i - n + 1 + i);

    cout << tot << '\n';
    for (int i = 1; i <= n; ++i) cout << x[i] << ' ' << y[i] << '\n';
    return 0;
}
