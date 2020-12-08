#include <bits/stdc++.h>

using namespace std;

const int maxn = 16;
const int MAXSTATE = 1 << maxn;

int n;
bool f[MAXSTATE];
int memo[MAXSTATE], cntDP;
int condition[maxn];
int pos[maxn], ans[maxn];

bool HasRes(int i, int mask) {
    if (i == n) return 1;
    if (memo[mask] == cntDP) return f[mask];
    memo[mask] = cntDP;
    
    f[mask] = 0;

    if (pos[i] != -1) {
        int nxt = pos[i];
        if ((condition[nxt] & mask) != condition[nxt]) return 0;
        return f[mask] = HasRes(i + 1, mask | (1 << pos[i]));
    }
    
    for (int nxt = 0; nxt < n; ++nxt) if (!(mask >> nxt & 1)) {
        //ans[nxt] = i
        if ((condition[nxt] & mask) != condition[nxt]) continue;
        if (ans[nxt] == -1 || ans[nxt] == i)
            f[mask] |= HasRes(i + 1, mask | (1 << nxt));
    }
    
    return f[mask];
}

int main() {
#if ONLINE_JUDGE || THEMIS
    freopen("chocolate.inp", "r", stdin);
    freopen("chocolate.out", "w", stdout);
#endif

#ifdef LDT
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long k;
    int m;
    cin >> n >> k >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        //a[u] < a[v]
        condition[v] |= (1 << u);
    }
    //todo : Read input
    memset(pos, 255, sizeof(pos));
    memset(ans, 255, sizeof(ans));
    for (int i = 0; i < n; ++i) {
        ans[i] = -1;
        for (int j = 0; j < n; ++j) if (pos[j] == -1) {
            pos[j] = i;
            ans[i] = j;
            ++cntDP;
            if (!HasRes(0, 0)) ans[i] = -1;
            else {
                ans[i] = j;
                break;
            }
            pos[j] = -1;
        }
        if (ans[i] == -1) return !(cout << "poor professor");
        pos[ans[i]] = i;
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] + 1 << ' ';
    return 0;
}
