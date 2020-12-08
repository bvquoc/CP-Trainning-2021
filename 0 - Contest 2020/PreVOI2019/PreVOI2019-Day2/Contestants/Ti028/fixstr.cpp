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
#define name "fixstr"

using namespace std;

typedef pair<ll,ll> ii;
typedef pair<ll,ii> ii3;
const ll maxn=1e6+10;

ll n,it[maxn*4],mo[maxn*4];
ll vv[maxn],dong[maxn*4];
string s,S[maxn];
ii pos[maxn*4];

void built(ll l,ll r,ll vt)
{
    pos[vt].ft=l;
    pos[vt].sc=r;
    ll sum=0;
    mo[vt]=0;
    dong[vt]=0;
    rep(i,l,r)
    {
        if(s[i]=='(') sum++;
        if(s[i]==')') sum--;
        if(sum<0)
        {
            dong[vt]++;
            sum=0;
        }
    }
    mo[vt]=sum;
    it[vt]=dong[vt]+mo[vt];
    if(l==r)
    {
        vv[l]=vt;
        return;
    }
    ll mid=(l+r)/2;
    built(l,mid,vt*2);
    built(mid+1,r,vt*2+1);
}

ii3 get(ll l,ll r,ll vt,ll u,ll v)
{
    if(l>v || r<u) return {0,{0,0}};
    if(u<=l&&r<=v) return {it[vt],{mo[vt],dong[vt]}};
    ll mid=(l+r)/2;
    ii3 t1=get(l,mid,vt*2,u,v);
    ii3 t2=get(mid+1,r,vt*2+1,u,v);
    ll mn=min(t1.sc.ft,t2.sc.sc);
    ll res=t1.ft+t2.ft-mn*2;
    ll x=t1.sc.ft+t2.sc.ft-mn;
    ll y=t1.sc.sc+t2.sc.sc-mn;
    return {res,{x,y}};
}

void up(ll vt)
{
    ll l=pos[vt].ft;
    ll r=pos[vt].sc;
    ll sum=0;
    mo[vt]=0;
    dong[vt]=0;
    rep(i,l,r)
    {
        if(s[i]=='(') sum++;
        if(s[i]==')') sum--;
        if(sum<0)
        {
            dong[vt]++;
            sum=0;
        }
    }
    mo[vt]=sum;
    it[vt]=dong[vt]+mo[vt];
    if(vt>1) up(vt/2);
}

int main()
{
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s;
    s=" "+s;
    built(1,s.size()-1,1);
    cin >> n;
    rep(i,1,n)
    {
         ll x,y;
         char k;
        cin >> k;
        if(k=='C')
        {
            cin >> x;
            if(s[x]=='(') s[x]=')'; else if(s[x]==')') s[x]='(';
            up(vv[x]);
        } else if(k=='Q')
        {
            cin >> x >> y;
            cout<<get(1,s.size()-1,1,x,y).ft<<endl;;
        } else if(k=='U')
        {
            cin >> x;
            s=S[x-1];
            built(1,s.size()-1,1);
        }
        S[i]=s;
    }
    return 0;
}
