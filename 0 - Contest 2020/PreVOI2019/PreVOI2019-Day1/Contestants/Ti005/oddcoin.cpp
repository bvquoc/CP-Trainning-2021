//Hi =)) I'm T.A
#include <bits/stdc++.h>
#define nmax 10000002
#define f first
#define s second
#define pb push_back
#define pa pair<int,int>
#define ll long long
#define ld long double
#define reset(a,x) memset(a,x,sizeof(a))
#define task "oddcoin"

using namespace std;
const int MOD=1e9+7;

int x,t,dd[nmax],q,cnt[nmax];
int a[]= {1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
ll sum(0);
map<int,int>m;

void sub1(int x, int t)
{
    sum=0;
    dd[0]=1;
    a[15]=x;
    for(int i=0; i<=15; i++)
        sum+=1ll*a[i];
    for(int i=0; i<=900000; i++)
        if(dd[i])
            for(int j=0; j<=15; j++)
            {
                int tg=i+a[j];
                dd[tg]=1;
                if(!cnt[tg])
                    cnt[tg]=cnt[i]+1;
                else
                    cnt[tg]=min(cnt[tg],cnt[i]+1);
            }
    cout<<cnt[t]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>q;
    for(int i=0; i<15; i++)
        m[a[i]]=1;
    while(q--)
    {
        reset(cnt,0);
        reset(dd,0);
        cin>>x>>t;
        m[x]=1;
        if(m[t])
        {
            cout<<1;
            continue;
        }
        m[x]=0;
        sub1(x,t);

    }
    return 0;
}
