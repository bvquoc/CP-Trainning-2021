#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define BIT(x,i) (1&((x)>>(i)))
using namespace std;
const int N = (int)1e5+1;
const int INF = (int)1e9;
int n , m;
struct clothes
{
    int L , R;
    bool operator < (const clothes &x) const
    {
        return R == x.R ? L < x.L : R < x.R;
    }
}f[N];
int minT = INF;
int it[N*4] , lazy[N*4];
void Init(int id , int l , int r)
{
    lazy[id] = INF;
    if(l == r)
    {
        it[id] = l <= minT ? 0 : INF;
        return;
    }
    int mid = (l+r)/2;
    Init(id*2 , l , mid);
    Init(id*2+1 , mid+1 , r);
    it[id] = min(it[id*2] , it[id*2+1]);
}
void down(int id)
{
    it[id*2] = min(it[id*2] , lazy[id]);
    it[id*2+1] = min(it[id*2+1] , lazy[id]);
    lazy[id*2] = min(lazy[id*2] , lazy[id]);
    lazy[id*2+1] = min(lazy[id*2+1] , lazy[id]);
    lazy[id] = INF;
}
void upd(int id , int l , int r , int u , int v , int value)
{
    if(l > v || r < u) return;
    if(u <= l && r <= v)
    {
        it[id] = min(it[id] , value);
        lazy[id] = min(lazy[id] , value);
        return;
    }
    down(id);
    int mid = (l+r)/2;
    upd(id*2 , l , mid , u , v , value);
    upd(id*2+1 , mid+1 , r , u , v , value);
    it[id] = min(it[id*2] , it[id*2+1]);
}
int get(int id , int l , int r , int u , int v)
{
    if(l > v || r < u) return INF;
    if(u <= l && r <= v) return it[id];
    down(id);
    int mid = (l+r)/2;
    return min(get(id*2 , l , mid , u , v) , get(id*2+1 , mid+1 , r , u , v));
}
void solve()
{
    cin >> m;
    for(int i=1 ; i<=m ; ++i) cin >> f[i].L >> f[i].R;
    cin >> n;
    for(int i=1 ; i<=n ; ++i)
    {
        int t;
        cin >> t;
        minT = min(minT , t);
    }
    int maxT = (int)1e5;
    if(minT == maxT)
    {
        for(int i=1 ; i<=m ; ++i)
        {
            if(f[i].R == maxT)
            {
                cout << 1;
                return;
            }
        }
        cout << -1;
        return;
    }
    Init(1 , 0 , maxT);
    sort(f+1 , f+m+1);
    for(int i=1 ; i<=m ; ++i)
    {
        int tmp = get(1 , 0 , maxT , f[i].L , f[i].R) + 1;
        upd(1 , 0 , maxT , f[i].L , f[i].R , tmp);
    }
    int ans = get(1 , 0 , maxT , maxT , maxT);
    if(ans == INF) cout << -1;
    else cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("COOLMAC.INP" , "r" , stdin);
    freopen("COOLMAC.OUT" , "w" , stdout);
    solve();
    return 0;
}
