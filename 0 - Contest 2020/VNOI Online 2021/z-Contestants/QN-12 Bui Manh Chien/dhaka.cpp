#include<bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define piii pair<ll,ii>
#define fi first
#define se second
#define add push_back
#define N 100010
using namespace std;
int n,m,k,l,s[N],a[N][10];
ll d[N],f[N][5],dp[N][50];
vector<ii>ed[N];
void dijksub2(int st)
{
    priority_queue<ii>qu;
    for(int i=1;i<=n;i++)
        d[i]=1e18;
    d[st]=0;
    qu.push({0,st});
    while(!qu.empty())
    {
        ii top=qu.top();
        qu.pop();
        int u=top.se;
        ll du=-top.fi;
        if(du!=d[u])continue;
        for(ii v:ed[u])
        {
            if(d[v.se]>d[u]+v.fi)
            {
                d[v.se]=d[u]+v.fi;
                qu.push({-d[v.se],v.se});
            }
        }
    }
}
void sub2()
{
    dijksub2(1);
    if(d[n]==1e18)
        cout<<"-1";
    else
        cout<<d[n];
}
void dijksub3(int st)
{
    priority_queue<piii>qu;
    for(int i=1;i<=n;i++)
    {
        f[i][0]=1e18;
        f[i][1]=1e18;
    }
    f[1][0]=0;
    f[1][1]=((s[1]==1)?0:1e18);
    if(f[1][1]==0)
        qu.push(piii(0,{st,1}));
    qu.push(piii(0,{st,0}));
    while(!qu.empty())
    {
        piii top=qu.top();
        qu.pop();
        int u=top.se.fi;
        int type=top.se.se;
        ll du=-top.fi;
        if(du!=f[u][type])continue;
        for(ii v:ed[u])
        {
            if(type==1)
            {
                if(f[v.se][type]>f[u][type]+v.fi)
                {
                    f[v.se][type]=f[u][type]+v.fi;
                    qu.push(piii(-f[v.se][type],{v.se,type}));
                }
            }
            else
            {
                if(s[v.se]==0)
                {
                    if(f[v.se][type]>f[u][type]+v.fi)
                    {
                        f[v.se][type]=f[u][type]+v.fi;
                        qu.push(piii(-f[v.se][type],{v.se,type}));
                    }
                }
                else
                {
                    if(f[v.se][1]>f[u][type]+v.fi)
                    {
                        f[v.se][1]=f[u][type]+v.fi;
                        qu.push(piii(-f[v.se][1],{v.se,1}));
                    }
                }
            }
        }
    }
}
void sub3()
{
    dijksub3(1);
    if(f[n][1]==1e18)
        cout<<"-1";
    else
        cout<<f[n][1];
}
void dijksub4(int st)
{
    priority_queue<piii>qu;
    for(int i=1;i<=n;i++)
        for(int j=0;j<(1<<k);j++)
            dp[i][j]=1e18;
    int type=0;
    for(int i=1;i<=s[st];i++)
        type+=(1<<(a[st][i]-1));
    dp[st][type]=0;
    qu.push(piii(0,{st,type}));
    while(!qu.empty())
    {
        piii top=qu.top();
        qu.pop();
        int u=top.se.fi;
        int type=top.se.se;
        ll du=-top.fi;
//        cout<<u<<" "<<type<<" "<<du<<endl;
        if(du!=dp[u][type])continue;
        for(ii v:ed[u])
        {
            int X=0;
            for(int i=1;i<=s[v.se];i++)
                X+=(1<<(a[v.se][i]-1));
            int neww=X|type;
            if(dp[v.se][neww]>dp[u][type]+v.fi)
            {
                dp[v.se][neww]=dp[u][type]+v.fi;
                qu.push(piii(-dp[v.se][neww],{v.se,neww}));
            }
        }
    }
}
void sub4()
{
    dijksub4(1);
    ll ans=1e18;
    for(int i=0;i<(1<<k);i++)
    {
        int cnt=0;
        for(int j=0;j<k;j++)
            if((i>>j)&1)
                cnt++;
        if(cnt>=l)
            ans=min(ans,dp[n][i]);
    }
    if(ans==1e18)
        cout<<"-1";
    else
        cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("dhaka.inp","r",stdin);
    freopen("dhaka.out","w",stdout);
    cin>>n>>m>>k>>l;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        for(int j=1;j<=s[i];j++)
            cin>>a[i][j];
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        ed[u].add({w,v});
        ed[v].add({w,u});
    }
    if(l==0)
        sub2();
    else
    {
        if(k==1)
            sub3();
        else
            sub4();
    }
}
