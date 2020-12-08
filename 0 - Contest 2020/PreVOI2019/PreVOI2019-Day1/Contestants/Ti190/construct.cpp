// KHAz
#include <bits/stdc++.h>
#define maxn 1005
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007
#define Task "construct"
#define pii pair < int,int >
#define pil pair < int,pii >
using namespace std;
int t,n,m , a[maxn], b[maxn] ,dd[maxn];
priority_queue< pii , vector<pii> ,greater<pii> > q;
void lam()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=m;i++)
    {
        int ty , u ,v;
        cin>>ty>>u>>v;
        if(ty==1)
        {
            int w;cin>>w;
            for(int j=u;j<=v;j++) a[j]+=w;
        }
        else
        {
            for(int j=u;j<=v;j++)
            {
                q.push({a[j],j});
                b[j]=0;
                dd[j]=0;
            }
            int res=0;
            while(q.size())
            {
                pii k=q.top();q.pop();
                if(dd[k.S]) continue;
                int l , r;
                for(int j=k.S;j>=u;j--)
                {
                    if(dd[j]) break;
                    l=j;
                }
                for(int j=k.S;j<=v;j++)
                {
                    if(dd[j]) break;
                    r=j;
                }
                res+=a[k.S] -b[k.S];
                for(int j=l;j<=r;j++)
                { b[j]=k.F;
                  if(b[j]==a[j]) dd[j]=1;
                }
            }
            cout << res << '\n';
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin>>t;
    while(t--)
    {
        lam();
    }
    return 0;
}
