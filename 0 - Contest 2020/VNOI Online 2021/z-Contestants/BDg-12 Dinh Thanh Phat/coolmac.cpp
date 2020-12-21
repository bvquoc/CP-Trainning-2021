#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a),_b=(b);i<_b;++i)

using namespace std;
const int maxn = 1e5 + 5;
typedef pair<int,int> pir;
#define fi first
#define se second
pir a[maxn];
int n,m;
int b[maxn];
void enter()
{
    cin>>m;
    _for(i,1,m+1)
        cin>>a[i].fi>>a[i].se;
    cin>>n;
    _for(i,1,n+1)
        cin>>b[i];
}
int it[maxn*4];
const int oo = 1e9 + 7;
void update(int l,int r,int st,int q,int val)
{
    if (l==r) it[st] = min(it[st], val);
    else
    {
        int mid = (l+r)>>1;
        if (mid>=q) update(l, mid, st*2,q,val);
        else update(mid + 1, r, st*2+1, q, val);
        it[st] = min(it[st*2], it[st*2+1]);
    }
}

int _get(int l,int r,int u,int v,int st)
{
    if (u<=l && r<=v) return it[st];
    else if (l>v || r<u) return oo;
    else

    {
        int mid = (l+r)>>1;
        return min(_get(l, mid, u, v, st*2), _get(mid + 1, r, u,v , st*2+1));
    }
}

void init(int l,int r,int st)
{
    if (l==r) it[st] = oo;
    else

    {
        it[st] = oo;
        int mid = (l+r)>>1;
        init(l, mid, st*2);
        init(mid + 1, r, st*2+1);
    }
}

const int Las = 1e5;
int f[maxn];

void solve()
{
    init(1, Las, 1);
    sort(a+1,a+m+1);
    sort(b+1,b+n+1);
    _for(i,1,Las+1)
        f[i] = oo;
    for(int i = m; i>=1; --i)
    {
        if (a[i].se == Las)
        {
            f[a[i].fi]  = 1;
        }
        else f[a[i].fi] = min(_get(1, Las, a[i].fi, a[i].se, 1) + 1, f[a[i].fi]);
        update(1, Las, 1, a[i].fi, f[a[i].fi]);
    }
    int ans = oo;
    _for(i,1, b[1]+1)
        ans = min(ans, f[i]);
    if (ans == oo) cout<<"-1";
    else cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("coolmac.inp","r",stdin);
    freopen("coolmac.out","w",stdout);
    enter();
    solve();
    return 0;
}
