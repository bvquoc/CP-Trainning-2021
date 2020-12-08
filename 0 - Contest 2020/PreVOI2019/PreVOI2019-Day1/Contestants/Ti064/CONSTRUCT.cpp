#include <bits/stdc++.h>
using namespace std;
#define el '\n'

typedef unsigned long long ull;

typedef long long ll;

template<typename so>

void read(so &x)
{
    x = 0;
    ll dem = 0;char c;
    for (c = getchar();'0'>c||c>'9';c=getchar())
    {
        dem++;if(dem==100) return;
    }
    for (;'0'<=c&&c<='9';c=getchar())
    {
        x = (x<<3) + (x<<1) + c - '0';
    }
}

const ll MaxN = 1e6+1;

const ll mod = 1e9+7;

template<typename so> void get_min(so &a,so b)
{
    if (a>b) a = b;
}

ll h[MaxN];

ll a[MaxN];

ll n,m;

set<ll> s;

vector<ll> gg;

vector<ll> xoa;

void giai(ll l,ll r)
{
    s.clear();gg.clear();
    for(ll i=l;i<=r;i++)
    {
        s.insert(i);
        gg.push_back(a[i]);
    }
    sort(gg.begin(),gg.end());
    vector<ll>::iterator it = unique(gg.begin(),gg.end());
    gg.resize(distance(gg.begin(),it));
    ll dem = 0;
    ll id = 0;
    ll last = 0;
    ll vtl = -1;
    ll ff = 0;
    while(!s.empty())
    {
        ll val = gg[id],cao = 0;
        for(set<ll>::iterator it=s.begin();it!=s.end();it++)
        {
            ll vt = *it;
            if (a[vt]==val)
            {
                xoa.push_back(vt);
            }
            if (a[vt]>=val)
            {
                if (vtl!=vt-1)
                {
                    cao++;
                }
                vtl = vt;
            }
        }
        dem+= cao*(val-last);
        last = val;
        for (ll i=0;i<xoa.size();i++)
        {
            s.erase(xoa[i]);
        }
        xoa.clear();
        id++;
    }
    cout<<dem<<el;
}

void input()
{
    cin>>n>>m;
    for (ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    while(m--)
    {
        ll type,l,r,k;cin>>type>>l>>r;
        if (type==1)
        {
            cin>>k;
            for (ll i=l;i<=r;i++)
            {
                a[i]+=k;
            }
        }
        else
        {
            giai(l,r);
        }
    }
}

//name CONSTRUCT

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CONSTRUCT.inp","r",stdin);
    freopen("CONSTRUCT.out","w",stdout);
    ll test = 1;
    cin>>test;
    while(test--)
    input();
}
