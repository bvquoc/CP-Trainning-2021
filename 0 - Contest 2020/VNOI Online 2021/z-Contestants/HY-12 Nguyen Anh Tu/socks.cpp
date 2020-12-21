#include <bits/stdc++.h>
#define maxn 100005
#define maxc 1000000007
#define MOD 1000000007
#define task "socks"
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define ll long long
#define bit(p,x) ((x>>p) & 1)
using namespace std;

int n, q, b[maxn];

int main()
{
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> n >> q;
    int cnt = 0;
    for(int i = 1; i <= n; ++ i) {
        cin >> b[i];
        if(b[i] == 1) ++ cnt;
    }
    for(int i = 1; i < n; ++ i) {
        int u, v;
        cin >> u >> v;
//        a[u].pb(v);
//        a[v].pb(u);
    }
    cin >> q;
    while(q -- ){
        int x;
        cin >> x;
        b[x] ^= 1;
        if(b[x] == 1) ++ cnt;
        else -- cnt;
        if(cnt >= 2) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}
