#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int n,m;
struct thing
{
    int l,r;
    bool operator < (thing const &T) const
    {
        return l < T.l;
    }
}a[100005];

int st[400050];
int lz[400050];
int mn,mx = 1e5+1;




void inp()
{
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].l >> a[i].r;
    }
    mn = 1e5;
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        mn = min(mn,x);
    }
    sort(a+1,a+m+1);
}


void build(int id,int l,int r)
{
    lz[id] = m+1;
    if (l == r)
    {
        if (r == mx)
        {
            lz[id] = m+1;
            st[id] = 0;
            return;
        }
        lz[id] = m+1;
        st[id] = m+1;
        return;
    }
    int mid = (l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = min(st[id*2],st[id*2+1]);
}


void down(int id)
{
    if (lz[id] == m+1) return;
    lz[id*2] = lz[id];
    lz[id*2+1] = lz[id];
    st[id*2] = lz[id];
    st[id*2+1] = lz[id];
    lz[id] = m+1;
}


int gett(int id,int l,int r,int u,int v)
{
    if (r < u || v < l) return m+1;
    if (u <= l && r <= v)
    {
        return st[id];
    }
    down(id);
    int mid = (l+r)>>1;
    return min(gett(id*2,l,mid,u,v),gett(id*2+1,mid+1,r,u,v));
}


void upd(int id,int l,int r,int u,int v,int val)
{
    if (r < u || v < l) return;
    if (u <= l && r <= v)
    {
        if (st[id] > val)
        {
            st[id] = val;
            lz[id] = val;
        }
        return;
    }
    down(id);
    int mid = (l+r)>>1;
    upd(id*2,l,mid,u,v,val);
    upd(id*2+1,mid+1,r,u,v,val);
    st[id] = min(st[id*2],st[id*2+1]);
}


void proc()
{
    build(1,0,mx);
    int l,r,val;
    for (int i = m; i > 0; i--)
    {
        l = a[i].l;
        r = a[i].r;
        val = gett(1,0,mx,l+1,r+1);
        upd(1,0,mx,l,r,val+1);
    }
    int ans = gett(1,0,mx,0,mn);
    if (ans > m) cout << -1;
    else cout << ans;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("coolmac.inp","r",stdin);
    freopen("coolmac.out","w",stdout);
    inp();
    proc();
    return 0;
}
