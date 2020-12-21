#include <bits/stdc++.h>
#define fort(i,a,b) for(LL i=a;i<=b;i++)
#define forn(i,a,b) for(LL i=a;i>=b;i--)
#define x first
#define y second
#define MP make_pair
#define LL long long
using namespace std;
typedef pair<LL,LL> ii;
const LL M=1e9+7;
const LL N=2e5+5;
LL n,a[N],bit[N],b[N],gt[N];
ii f[N][2][2];
bool kt[N];
void upd(LL i,LL val)
{
    for(;i<=n;i+=i&-i) bit[i]+=val;
}
LL gts(LL i)
{
    LL rs=0;
    for(;i>=1;i-=i&-i) rs+=bit[i];
    return rs;
}
ii dq(LL x,bool ok1,bool ok2)
{
    if (x==n) return MP(0,1);
    if (f[x][ok1][ok2].x!=-1) return f[x][ok1][ok2];
    LL l,r;
    if (!ok1) l=a[x];else l=1;
    if (!ok2) r=b[x];else r=n;
    LL rs=0,rs2=0;
    fort(i,l,r)
     if (!kt[i])
     {
         LL tt=gts(i);
         kt[i]=1;
         upd(i,1);
         ii tts=dq(x+1,ok1|(i!=l),ok2|(i!=r));
         LL tinh=(tts.x+(i-tt-1)*tts.y%M)%M;
         rs=(rs+tinh)%M;
         rs2=(rs2+tts.y)%M;
         kt[i]=0;
         upd(i,-1);
     }
    return f[x][ok1][ok2]=MP(rs,rs2);
}
int main()
{
    freopen("permeow.inp","r",stdin);
    freopen("permeow.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    fort(i,1,n)
     fort(j,0,1)
      fort(z,0,1) f[i][j][z]=MP(-1,0);
    fort(i,1,n) cin>>a[i];
    fort(i,1,n) cin>>b[i];
    cout<<dq(1,0,0).x<<' ';
    return 0;
}
