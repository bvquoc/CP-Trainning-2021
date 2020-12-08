#include<bits/stdc++.h>

#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define repn(i,a,b) for(ll i=a;i>=b;i--)
#define repv(i,v) for(__typeof(v.begin())i=v.begin();i!=v.end();i++)
#define ll int
#define db double
#define sqr(x) x*x
#define pb push_back
#define ft first
#define sc second
#define name "paint"

using namespace std;

typedef pair<ll,ll> ii;
const ll maxn=1e6+10;

ll n,it[maxn*4],mx=0;
char pos[maxn];
vector<ll> ar[255];

void built(ll l,ll r,ll vt)
{
    if(l==r)
    {
        it[vt]=l;
        return;
    }
    ll mid=(l+r)/2;
    built(l,mid,vt*2);
    built(mid+1,r,vt*2+1);
    it[vt]=it[vt*2];
}

void up(ll l,ll r,ll vt,ll u,ll v)
{
    if(l>v || r<u) return;
    if(u<=l && r<=v)
    {
        it[vt]=u;
        return;
    }
    ll mid=(l+r)/2;
    up(l,mid,vt*2,u,v);
    up(mid+1,r,vt*2+1,u,v);
    if(pos[it[vt*2]]<=pos[it[vt*2+1]]) it[vt]=it[vt*2];
    else it[vt]=it[vt*2+1];
}

int main()
{
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    built(1,n,1);
    rep(i,1,n)
    {
        ll k;
        string x,y;
        cin >> k;
        if(k==2)
        {
            cin >> x >> y;
            repv(i,ar[int(x[0])]) ar[int(y[0])].pb(*i),pos[*i]=y[0],mx=max(mx,*i);
            ar[int(x[0])].clear();
        } else
        {
            cin >> x;
            ll u=it[1];
            ar[int(x[0])].pb(u);
            pos[u]=x[0];
            up(1,n,1,u,u);
        }
    }
    rep(i,1,mx) cout<<pos[i];
    return 0;
}
