#include<bits/stdc++.h>
#define fr(i,x,y) for(int i=x;i<=y;i++)
#define ft(i,x,y) for(int i=x;i<y;i++)
#define frd(i,x,y) for(int i=y;i>=x;i--)
#define ii pair<long long,long long>
#define in freopen("oddcoin.inp","r",stdin)
#define out freopen("oddcoin.out","w",stdout)
#define fi first
#define se second
#define add push_back
#define ad push
#define ll long long
using namespace std;
long long ans,po,t,x,q;
ii a[101];
bool cmp(ii u,ii v)
{
    return u.se<v.se;
}
int main()
{
    in;
    out;
    cin>>q;
    a[1].fi=1;
    a[2].fi=3;
    a[3].fi=5;
    a[4].fi=10;
    a[5].fi=30;
    a[6].fi=50;
    a[7].fi=100;
    a[8].fi=300;
    a[9].fi=500;
    a[10].fi=1000;
    a[11].fi=3000;
    a[12].fi=5000;
    a[13].fi=10000;
    a[14].fi=30000;
    a[15].fi=50000;
    for(int i=1;i<=15;i++)
    {
        a[i].se=i;
    }
    a[17].fi=1e18;
    while(q--)
    {
        cin>>x>>t;
        a[16].fi=x;
        a[16].se=16;
        sort(a+1,a+16+1);
        ans=0;
        while(t!=0)
        {
            int l=1;
            int r=17;
            while(l<r)
            {
                int mid=(l+r)/2;
                if(a[mid].fi<t)l=mid+1;
                else
                    r=mid;
            }
            if(a[l].fi>t)
                l--;
            po=t/a[l].fi;
            ans+=po;
            t%=a[l].fi;
        }
        sort(a+1,a+16+1,cmp);
        cout<<ans<<endl;
    }
    return 0;
}
