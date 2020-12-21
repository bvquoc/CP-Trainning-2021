#include <bits/stdc++.h>
#define maxn 100005
#define MOD 1000000007
#define task "COOLMAC"
#define pii pair<int, int>
#define pb push_back
#define F first
#define S second

using namespace std;
typedef long long ll;
const ll MM = 1ll * MOD * MOD;
int n, m, T;
pii a[maxn];
void Input(){
    cin >> m;
    for (int i=1; i<=m; ++i) cin >> a[i].F >> a[i].S;
    T = int(1e5);
    cin >> n;
    for (int x, i=1; i<=n; ++i){
        cin >> x; T = min(T, x);
    }
}
int p[18][maxn], lim;
void Init(){
    lim = int(1e5);
    for (int i=0; i<=lim; ++i) p[0][i] = MOD;
    for (int i=1; i<=m; ++i)
        p[0][a[i].S] = min(p[0][a[i].S], a[i].F);
    for (int i=lim-1; i>=0; --i)
        p[0][i] = min(p[0][i], p[0][i+1]);
    for (int i=1; i<=17; ++i)
        for (int u=lim; u>=0; --u)
            p[i][u] = p[i-1][p[i-1][u]];

}
void Solve(){
    int ans = 0, run = lim;
    for (int i=17; i>=0; --i)
        if (p[i][run] > T){
            run = p[i][run];
            ans += (1 << i);
        }
    if (run > T) ans++;
    if (ans > (1 << 17)) cout << -1;
    else cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    Input();
    Init();
    Solve();
    return 0;
}
