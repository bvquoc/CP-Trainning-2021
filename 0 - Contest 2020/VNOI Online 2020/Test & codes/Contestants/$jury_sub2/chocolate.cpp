#include <bits/stdc++.h>

using namespace std;
long long p[20];
bool mark[20];
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
    int n, m;
    cin >> n >> k >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
    }
    p[0] = 1;
    for (int i = 1; i <= n; ++i)
        p[i] = 1ll * p[i - 1] * i;
    if (k > p[n]) return !(cout << "poor professor");
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) if (!mark[j]) {
            if (p[n - i] < k)
                k -= p[n - i];
            else {
                mark[j] = 1;
                cout << j << ' ';
                break;
            }
        }
    } 
    
    return 0;
}
