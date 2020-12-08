#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Task "ODDCOIN"

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 5;

int f[maxn];
int a[20];
int n = 16;
int x, t;

void solve(void)
{
    memset(f, 0, sizeof f);
    a[n] = x;
    queue<int> Q;
    for (int i=1; i<=n; ++i){
        f[a[i]] = 1;
        Q.push(a[i]);
    }
    int res = 0;
    int mx = 1e9 + 5;
    while(t >= maxn){
        if (t < mx){
            mx = 0;
            for (int i=1; i<=n; ++i){
                if (a[i] <= t){
                    mx = max(mx, a[i]);
                }
            }
        }
        t -= mx;
        ++res;
    }
    while (Q.size()){
        int now = Q.front(); Q.pop();
        if (now >= maxn) continue;
        for (int i=1; i<=n; ++i){
            if (now + a[i] >= maxn) continue;
            if (f[now + a[i]] == 0){
                f[now + a[i]] = f[now] + 1;
                Q.push(now + a[i]);
            }
        }
    }
    cout << res + f[t] << '\n';
}

signed main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("A.INP", "r")){
        freopen("A.INP", "r", stdin);
        freopen("A.OUT", "w", stdout);
    }
    if (fopen(Task".inp", "r")){
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    a[1] = 1; a[2] = 3; a[3] = 5; a[4] = 10; a[5] = 30;
    a[6] = 50; a[7] = 100; a[8] = 300; a[9] = 500; a[10] = 1000;
    a[11] = 3000; a[12] = 5000; a[13] = 10000; a[14] = 30000; a[15] = 50000;
    int Q;
    cin >> Q;
    while (Q--){
        cin >> x >> t;
        solve();
    }
}
