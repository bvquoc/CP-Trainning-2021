#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
#define mod 1000000007
#define pii pair <int,int>
#define reset(x) memset(x, 0,sizeof(x))
#define PB push_back
#define mp make_pair
#define maxn 1000005

using namespace std;
int q,x,t,res,cnt[maxn];
int coin[20]= {1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    memset(cnt,32,sizeof(cnt));
    for(int i=0; i<15; i++)
    {
        for(int j=0; j<=(100000/coin[i]); j++)
            cnt[j*coin[i]]=min(cnt[j*coin[i]],j);
    }
    cin>>q;
    while(q--)
    {
        cin>>x>>t;
        for(int j=0; j<=(t/x); j++)
            cnt[j*x]=min(cnt[j*x],j);
        for(int i=1; i<=t; i++)
                for(int j=1; j<=i; j++)
                    cnt[i]=min(cnt[i],cnt[j]+cnt[i-j]);
        cout<<cnt[t]<<'\n';
    }
}
