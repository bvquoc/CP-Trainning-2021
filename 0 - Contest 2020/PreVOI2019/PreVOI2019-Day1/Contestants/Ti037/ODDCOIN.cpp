#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fio(s) freopen(s".inp","r",stdin)
#define foo(s) freopen(s".out","w",stdout)
#define pb push_back
#define task "oddcoin"
using namespace std;
typedef long long LL;
const LL N=100,OO=1e15;
LL n,test,T,X,dp[20][1000009],ans,Plus;
vector<LL> a;
void Reset()
{
    a.clear();a.pb(X);
    a.pb(-1); a.pb(1); a.pb(3); a.pb(5);
    LL cur1,cur2,cur3;
    cur1=1; cur2=3; cur3=5;
    For(i,1,4)
    {
        cur1*=10; cur2*=10; cur3*=10;
        a.pb(cur1); a.pb(cur2); a.pb(cur3);
    }
    sort(a.begin(),a.end()); n=a.size()-1;
}
void Solve()
{
    Plus=0;
    while(T>100000) T-=a.back(),++Plus;
    For(i,0,n)
        For(j,0,T) dp[i][j]=OO;
    For(i,0,n) dp[i][0]=0;

    For(i,1,n)
        For(j,1,T)
        {
            if(a[i]>j) dp[i][j]=dp[i-1][j];
            else{
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-a[i]]+1);
                dp[i][j]=min(dp[i][j],dp[i][j-a[i]]+1);
            }
        }
    ans=OO;
    For(i,1,n) ans=min(ans,dp[i][T]+Plus);
    printf("%lld\n",ans);
}
int main()
{
    fio(task); foo(task);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld%lld",&X,&T);
        Reset();
        Solve();
    }
    return 0;
}
