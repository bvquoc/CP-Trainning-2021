#include<bits/stdc++.h>
using namespace std;
const long o=500005;
long n,m,k,on[o],dd[o],so[o],sd[o];
vector<long>ke[o];
void sub12()
{
    long j=1,sl=0,kq=0,l,r;
    for(long i=1;i<=n;i++)
    {
        sl+=(!on[i]);
        while(j<=i && sl>k)
        {
            sl-=(!on[j]);
            j++;
        }
        if(kq<i-j+1)
        {
            kq=i-j+1;
            l=j; r=i;
        }
    }
    if(kq==0)
    {
        cout<<-1; return;
    }
    cout<<l<<' '<<r;
    return;
}
void dfs(long x,long u)
{
    dd[u]=x; so[x]+=on[u];
    for(long i=0;i<ke[u].size();i++)
    {
        long v=ke[u][i];
        if(!dd[v])dfs(x,v);
    }
}
void sub3()
{
    for(long i=1;i<=n;i++)
        if(!dd[i])dfs(i,i);
    long kq=0,l,r;
    for(long i=1;i<=n;i++)
    {
        for(long j=1;j<=n;j++)
            sd[j]=0;
        long j=i+1,led=0;
        while(j>0)
        {
            j--;
            if(sd[dd[j]]<so[dd[j]])
            {
                sd[dd[j]]++;
                continue;
            }
            if(led<k)
            {
                led++;
                continue;
            }
            break;
        }
        j++;
        if(kq<i-j+1)
        {
            kq=i-j+1;
            l=j; r=i;
        }
    }
    if(kq==0)
    {
        cout<<-1; return;
    }
    cout<<l<<' '<<r;
    return;
}
void sub4()
{
    for(long i=1;i<=n;i++)
        if(!dd[i])dfs(i,i);
    long l=0,r=n;
    while(l<r)
    {
        long mid=(l+r+1)>>1;
        for(long i=1;i<=n;i++)
            sd[i]=0;
        long led=0;
        for(long i=1;i<=mid;i++)
        {
            sd[dd[i]]++;
            if(sd[dd[i]]>so[dd[i]])
                led++;
        }
        bool ok=(led<=k);
        for(long i=mid+1;i<=n;i++)
        {
            if(sd[dd[i-mid]]>so[dd[i-mid]])
                led--;
            sd[dd[i-mid]]--;
            sd[dd[i]]++;
            if(sd[dd[i]]>so[dd[i]])
                led++;
            if(led<=k)
            {
                ok=1; break;
            }
        }
        if(ok)l=mid;
        else r=mid-1;
    }
    if(l==0)
    {
        cout<<-1; return;
    }
    for(long i=1;i<=n;i++)
        sd[i]=0;
    long led=0;
    for(long i=1;i<=l;i++)
    {
        sd[dd[i]]++;
        if(sd[dd[i]]>so[dd[i]])
            led++;
    }
    if(led<=k)
    {
        cout<<1<<' '<<l;
        return;
    }
    for(long i=l+1;i<=n;i++)
    {
        if(sd[dd[i-l]]>so[dd[i-l]])
            led--;
        sd[dd[i-l]]--;
        sd[dd[i]]++;
        if(sd[dd[i]]>so[dd[i]])
            led++;
        if(led<=k)
        {
            cout<<i-l+1<<' '<<i;
            return;
        }
    }
}
int main()
{
    freopen("decor.inp","r",stdin);
    freopen("decor.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(long i=1;i<=n;i++)
    {
        char h; cin>>h;
        on[i]=(h=='1');
    }
    for(long i=1;i<=m;i++)
    {
        long a,b; cin>>a>>b;
        ke[a].push_back(b);
        ke[b].push_back(a);
    }
    if(m==0)sub12();
    else if(n<=2000)sub3();
    else sub4();
    return 0;
}
