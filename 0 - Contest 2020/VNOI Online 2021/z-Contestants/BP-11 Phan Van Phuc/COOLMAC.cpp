#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define se second

const ll INF=1e18;
const ll nmax=1e5+1;
const ll mod=1e9+7;

typedef pair<ll, ll> pa;
typedef vector<ll> ve;
typedef vector<ve> vve;
typedef vector<pa> vpa;

ifstream fi("COOLMAC.INP");
ofstream fo("COOLMAC.OUT");
ll n, m;
pa seg[nmax];
pa st[4*nmax];
ll f[nmax];
void build(ll pos, ll lo, ll hi)
{
    if(lo>hi)
        return;
    if(lo==hi)
    {
        st[pos]= {f[lo], f[lo]};
        return;
    }
    ll mid=(lo+hi)/2;
    build(pos*2, lo, mid);
    build(pos*2+1, mid+1, hi);
    st[pos].ff=max(st[pos*2].ff, st[pos*2+1].ff);
    st[pos].se=min(st[pos*2].se, st[pos*2+1].se);
}
pa query(ll pos, ll lo, ll hi, ll x, ll y)
{
    if(lo>y||hi<x)
        return {-INF, INF};
    if(lo>=x&&hi<=y)
        return st[pos];
    ll mid=(lo+hi)/2;
    pa res1=query(pos*2, lo, mid, x, y);
    pa res2=query(pos*2+1, mid+1, hi, x, y);
    return {max(res1.ff, res2.ff), min(res1.se, res2.se)};
}
int main()
{
    ios_base::sync_with_stdio(0), fi.tie(0), fo.tie(0);

    fi>>m;
    for(ll i=1; i<=m; ++i)
        fi>>seg[i].se>>seg[i].ff;
    sort(seg+1, seg+m+1);
    for(ll i=1; i<nmax; ++i)
    {
        ll x=lower_bound(seg+1, seg+m+1, make_pair(i, (ll)0))-seg;
        if(x>m||seg[x].se>i-1)
            f[i]=0;
        else
            f[i]=f[seg[x].se]+1;
    }
    build(1, 1, nmax-1);
    ll tem=INF;
    fi>>n;
    for(ll i=1; i<=n; ++i)
    {
        ll c;
        fi>>c;
        tem=min(tem, c);
    }
    ll g=INF;
    pa kq=query(1, 1, nmax-1, tem, nmax-1);
    if(kq.se>0)
        fo<<kq.ff;
    else
        fo<<-1;
}
