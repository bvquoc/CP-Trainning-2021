#include <iostream>
#include <algorithm>
#include <cstdio>
#define _for(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;
typedef long long ll;
const int maxn=100001;
const ll oo=10000000000000;

ll a[maxn];
int n,m;
ll h[maxn];
void update(int l,int r,ll val)
{
    for(int i=l;i<=r;++i)
    {
        h[i]+=val;
    }
}
ll compose(int l,int r,int L,int R,ll val)
{
    if (l>r) return 0;
    else if (l==r)
    {
        if (L<=l && l<=R) return (h[l] + val >=a[l]) ? ll(0) : (a[l] - h[l] - val) ;
        else return (val>=a[l]) ? ll(0) : (a[l] - val);
    }
    else
    {
        ll _min=oo;
        int pos=l;
        ll kq=0;
        for(int i=l;i<=r;++i)
            if (L<=i && i<=R)
                _min=min(_min,((h[i] + val >=a[i]) ? 0 : (a[i] - h[i] - val)));
            else
                _min=min(_min,((val>=a[i]) ? 0 : (a[i] - val)));
        for(int i=l;i<=r;++i)
        {
            if (L<=i && i<=R)
            {
                if (h[i] + val + _min>=a[i])
                {
                    kq+=compose(pos,i-1,L,R,val + _min);
                    pos=i+1;
                }
                else
                if (i==n)
                    kq+=compose(pos,i,L,R,val + _min);
            }
            else
            {

                if (val + _min>=a[i])
                {
                    kq+=compose(pos,i-1,L,R,val +_min);
                    pos=i+1;
                }
                else
                if (i==n) {
                        kq+=compose(pos,i,L,R,val + _min);
                }
            }

        }
        return kq+=_min;
    }
}
void query(int l,int r)
{
    ll kq=compose(1,n,l,r,0);
    cout<<kq<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    cin>>n>>m;
    _for(i,1,n+1) cin>>a[i];
    int tv,l,r,k;
    _for(i,0,m)
    {
        cin>>tv;
        if (tv==1)
        {
            cin>>l>>r>>k;
            update(l,r,k);
        }
        else
        {
            cin>>l>>r;
            query(l,r);
        }
    }
}
