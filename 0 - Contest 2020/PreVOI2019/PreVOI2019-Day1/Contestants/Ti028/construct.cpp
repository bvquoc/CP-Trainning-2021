#include<bits/stdc++.h>

#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define repn(i,a,b) for(ll i=a;i>=b;i--)
#define repv(i,v) for(__typeof(v.begin())i=v.begin();i!=v.end();i++)
#define ll int
#define db double
#define sqr(x) x*x
#define ft first
#define sc second
#define name "construct"

using namespace std;

typedef pair<ll,ll> ii;
const ll maxn=1e5+10;

ll a[maxn],d[maxn],l[maxn],r[maxn];
ll top,n,test,m,h[maxn],res;
priority_queue<ii,vector<ii>,greater<ii> >  se;

void sol(ll l1,ll r1)
{
    top=0;d[top]=l1-1;
    rep(i,l1,r1)
    {
        while(top>0&&h[d[top]]>=h[i]) top--;
        l[i]=d[top]+1;
        d[++top]=i;
    }
    top=0;d[top]=r1+1;
    repn(i,r1,l1)
    {
        while(top>0&&h[d[top]]>=h[i]) top--;
        r[i]=d[top]-1;
        d[++top]=i;
    }
    while(!se.empty()) se.pop();
    rep(i,l1,r1) se.push({h[i],i});
    while(se.top().ft==0) se.pop();
    if(se.empty()) return;
    ll x=se.top().sc;
    ll y=se.top().ft;
    res+=y;
    rep(i,l[x],r[x]) h[i]-=y;
    sol(l1,r1);
}

void tinh1()
{
    ll l1,r1;
    cin >> l1 >> r1;
    rep(i,l1,r1) h[i]=a[i];
    res=0;
    sol(l1,r1);
    cout<<res<<endl;
}

void tinh()
{
    cin >> n >> m;cout<<m<<endl;
    rep(i,1,n) cin >> a[i];
    while(m--)
    {
        ll l1,r1,x,k;
        cin >> x;
        if(x==1)
        {
            cin >> l1 >> r1 >> k;
            rep(i,l1,r1) a[i]+=k;
        } else tinh1();
    }
}

int main()
{
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> test;
    while(test--) tinh();
    return 0;
}
