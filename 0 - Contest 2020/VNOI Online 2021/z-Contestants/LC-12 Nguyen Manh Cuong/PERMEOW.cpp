#include <bits/stdc++.h>
#define Killian "PERMEOW"
#define endl "\n"
#define pii pair <int,int>
#define long long long
#define bit(mask,u) (((mask)>>(u))&1)
#define bitcount(mask) __builtin_popcount((mask))
using namespace std;
mt19937_64 random_num(chrono::high_resolution_clock::now().time_since_epoch().count());
const long MOD=1000000007;
const int base=26;
const int arsz=100005;

int n;
int A[200005],B[200005];
int bit[200005];
long gt[200005],f[200005];

int get (int pos)
{
    int k=0;
    for (; pos; pos-=(pos&-pos))
        k+=bit[pos];
    return k;
}
void update (int pos)
{
    for (; pos<=200000; pos+=(pos&-pos))
        bit[pos]++;
}
long calc (int *a)
{
    for (int i=0;i<=n;i++)
        bit[i]=0;
    long ans=0;
    long prvsum=1;
    for(int i=n; i>=1; i--)
    {
        int m=n-i+1;
        int t=get(a[i]);
        ans=(ans+prvsum*t%MOD)%MOD;
        ans=(ans+f[m-1]*t%MOD)%MOD;
        ans=(ans+(1LL*t*(t-1)/2%MOD*gt[m-1])%MOD)%MOD;
        prvsum=(prvsum+gt[m-1]*t%MOD)%MOD;
        update(a[i]);
    }
    return ans;
}
long inverson_cnt (int *a)
{
    for (int i=0;i<=n;i++)
        bit[i]=0;
    long ans=0;
    for (int i=1; i<=n; i++)
    {
        update(a[i]);
        int t=get(a[i]);
        ans+=1LL*(i-t);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Killian".inp","r",stdin);
    freopen(Killian".out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>A[i];
    for (int i=1; i<=n; i++)
        cin>>B[i];
    gt[0]=1;
    for (int i=1; i<=n; i++)
        gt[i]=gt[i-1]*i%MOD;
    for (int i=1;i<=n;i++)
        f[i]=(1LL*i*(i-1)/2%MOD)*(gt[i]*500000004%MOD)%MOD;
    cout<<(calc(B)-calc(A)+inverson_cnt(A)+MOD*MOD)%MOD;
}
