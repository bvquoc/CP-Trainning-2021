#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
long T,n,a[2002],p[20],d,b[20],s,cnt,x,gt[2002];
const ll M=998244353;
ll dem(ll n)
{
    ll ans=0;
    while(n>0) ans++,n/=10;
    return ans;
}
void sub1()
{
    ll dem=0;
    for(int i=1;i<=n;i++) p[i]=i;
    do
    {   d=0;s=0;
        for(int i=1;i<=n;i++)
        {
            x=a[p[i]];cnt=0;
            while(x>0) b[++cnt]=x%10,x/=10;
            for(int j=cnt;j>=1;j--)
            {
                if(d==0) s=(s+b[j])%11;
                else s=(s-b[j]+11)%11;
                d=1-d;
            }
        }
        if(s%11==0) dem++;
    }while(next_permutation(p+1,p+n+1));
    cout<<dem<<'\n';
}
void sub2()
{
        d=0;s=0;
        for(int i=1;i<=n;i++)
        {
            x=a[i];cnt=0;
            while(x>0) b[++cnt]=x%10,x/=10;
            for(int j=cnt;j>=1;j--)
            {
                if(d==0) s=(s+b[j])%11;
                else s=(s-b[j]+11)%11;
                d=1-d;
            }
        }
        if(s%11==0) {cout<<gt[n]<<'\n';}
        else cout<<0<<'\n';
}
void sub3()
{

}
int main()
{
    freopen("gift11.inp","r",stdin);
    freopen("gift11.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    gt[0]=1;
    for(int i=1;i<=2000;i++) gt[i]=(i*gt[i-1])%M;
    while(T--)
    {
        cin>>n;
        bool kt1=1,kt2=1;
        for(int i=1;i<=n;i++)
             {cin>>a[i];
              if(dem(a[i])%2) kt1=0;
              else kt2=0;
             }
        if(kt1) {sub2();continue;}
        if(n<=10) {sub1();continue;}
        if(kt2) {sub3();continue;}
    }
}
