#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fio(s) freopen(s".inp","r",stdin)
#define foo(s) freopen(s".out","w",stdout)
#define pb push_back
#define task "mine"
using namespace std;
typedef long long LL;
const LL N=201,OO=1e15,mod=1e9+3;
LL n,m,ans,a[N],s[N],cnt[N],used[N],x[N],xx[N],f[N][N][N],sum[N][N];
void ReadIO()
{
    scanf("%lld%lld",&n,&m);
    For(i,1,n*2)
        scanf("%lld",&a[i]),s[i]=s[i-1]+a[i];
}
void Trau(int ii)
{
    if(ii==n*2+1){
        For(i,1,n) cnt[i]=0;
        vector<int> v;
        int done=0;
        For(i,1,n*2){
            if(cnt[xx[i]]==0){
                    v.pb(xx[i]),++cnt[xx[i]];
            }
            else if(v.back()!=xx[i]) return;
            else v.pop_back(),++done;
        }
        ++ans;
        return;
    }
    For(j,1,n){
        bool ok=true;
        For(i,1,j-1)
            if(used[i]==0)
            {ok=false;break;}
        if(used[j]<2&&ok){
            if(used[j]==1) if(a[ii]-a[x[j]]>m) continue;
            used[j]++;
            if(used[j]==1) x[j]=ii;
            xx[ii]=j;
            Trau(ii+1);
            used[j]--;
        }
    }
}
LL cal(LL i,LL j,LL k)
{
    return f[i][j][k];
}
void Solve()
{
    if(n<=7) Trau(1),printf("%lld\n",ans);
    else
    {
        For(i,1,n*2-1)
            if(a[i+1]-a[i]<=m) f[i][i+1][1]=1,sum[i][i+1]=1;
            else f[i][i+1][1]=0,sum[i][i+1]=0;
        n*=2;
        for(int len=4;len<=n;len+=2)
        For(i,1,n-len+1){
            int j=i+len-1;
            if(a[j]-a[i]>m) f[i][j][1]=0;
            else
                f[i][j][1]=sum[i+1][j-1];
            sum[i][j]=f[i][j][1];
            For(k,2,len/2){
                for(int mid=i+1;mid<j;mid+=2)
                For(cnt,1,(k-1)/2+((k-1)%2>0))
                    f[i][j][k]=(f[i][j][k]+cal(i,mid,cnt)*cal(mid+1,j,k-cnt) ) % mod;
                sum[i][j]=(sum[i][j]+f[i][j][k]) % mod;
            }
        }
        ans=0;
        For(k,1,n/2) ans=(ans+f[1][n][k])% mod;
        printf("%lld",ans);
    }
}
int main()
{
    fio(task); foo(task);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ReadIO();
    Solve();
    return 0;
}
