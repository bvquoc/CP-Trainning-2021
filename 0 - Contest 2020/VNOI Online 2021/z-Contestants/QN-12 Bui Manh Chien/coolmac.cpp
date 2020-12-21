#include<bits/stdc++.h>
#define N 100010
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define add push_back
using namespace std;
int m,n,l[N],r[N],t[N],d[N],cnt,tg;
ii b[N];
bool ok;
int ans=1e9;
vector<int>discre;
void sub1()
{
    for(int i=0;i<(1<<m);i++)
    {
        for(int j=1;j<=discre.size();j++)
            d[j]=0;
        discre.clear();
        cnt=0;
        ok=true;
        tg=0;
        for(int j=0;j<m;j++)
            if((i>>j)&1)
            {
                tg++;
                b[tg].fi=l[j+1];
                b[tg].se=r[j+1];
                cnt++;
                discre.add(l[j+1]);
                discre.add(r[j+1]);
            }
        discre.add(-1);
        for(int j=1;j<=n;j++)
            discre.add(t[j]);
        discre.add(100000);
        sort(discre.begin(),discre.end());
        discre.erase(unique(discre.begin(),discre.end()),discre.end());
        for(int j=1;j<=tg;j++)
        {
            int vt1=lower_bound(discre.begin(),discre.end(),b[j].fi)-discre.begin();
            int vt2=lower_bound(discre.begin(),discre.end(),b[j].se)-discre.begin();
            for(int t=vt1;t<=vt2;t++)
                d[t]=1;
        }
        for(int j=1;j<=n;j++)
        {
            int vt1=lower_bound(discre.begin(),discre.end(),t[j])-discre.begin();
            int vt2=lower_bound(discre.begin(),discre.end(),100000)-discre.begin();
            for(int t=vt1;t<=vt2;t++)
                if(d[t]==0)
                    ok=false;
            if(!ok)
                break;
        }
        if(ok)
            ans=min(ans,cnt);
    }
    if(ans==1e9)
        cout<<"-1";
    else
        cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("coolmac.inp","r",stdin);
    freopen("coolmac.out","w",stdout);
    cin>>m;
    for(int i=1;i<=m;i++)
        cin>>l[i]>>r[i];
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>t[i];
    if(n<=10)
        sub1();
    else
        cout<<"-1";
}
