#include<bits/stdc++.h>
#define fort(i,a,b) for(LL i=a;i<=b;i++)
#define LL long long
using namespace std;
const LL M=998244353;
const LL N=2005;
LL n,test,p[15],a[N],v1[N],f[N][N][12],tx[N];
LL Count(LL x)
{
    LL rs=0;
    while (x!=0)
    {
        x/=10;
        rs++;
    }
    return rs;
}
void sub1()
{
    LL rs=0;
    fort(i,1,n) a[i]=i;
    do
    {
        LL tt=0;
        fort(i,1,n) tt=(tt*p[Count(v1[a[i]])]%11+v1[a[i]])%11;
        if (tt%11==0) rs++;
    }
    while (next_permutation(a+1,a+1+n));
    cout<<rs<<'\n';
}
LL tk()
{
    LL s0=0,s1=0;
    fort(i,1,n)
     if (Count(v1[i])%2==0) s0++;else s1++;
    if (s0==n) return 0;else
        if (s1==n) return 1;else return -1;
}
LL tinh(LL x)
{
    LL dem=0,rs=0;
    while (x!=0)
    {
        dem++;
        if (dem%2) rs+=x%10;else rs-=x%10;
        x/=10;
    }
    if (dem%2==0) return -rs;else return rs;
}
LL gt(LL x)
{
    LL rs=1;
    fort(i,1,x) rs=rs*i%M;
    return rs;
}
void sub2()
{
    LL tt=0;
    fort(i,1,n)
     tt=(tt+tinh(v1[i])+11)%11;
    if (tt==0) cout<<gt(n)<<'\n';else cout<<"0\n";
}
void sub3()
{
    fort(i,1,n)
     fort(j,0,n/2)
      fort(du,0,10) f[i][j][du]=0;
    fort(i,1,n) tx[i]=tinh(v1[i]);
    f[0][0][0]=1;
    fort(i,1,n)
     fort(j,0,n/2)
      fort(du,0,10)
       {
           f[i][j][(du+tx[i]+11)%11]=(f[i][j][(du+tx[i]+11)%11]+f[i-1][j][du])%M;
           if (j>0) f[i][j][(du-tx[i]+11)%11]=(f[i][j][(du-tx[i]+11)%11]+f[i-1][j-1][du])%M;
       }
    cout<<(f[n][n/2][0]*gt(n/2))%M*gt(n-n/2)%M<<'\n';
}
void sub4()
{

}
int main()
{
    freopen("gift11.inp","r",stdin);
    freopen("gift11.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    p[0]=1;
    fort(i,1,10) p[i]=10*p[i-1]%11;
    cin>>test;
    while (test--)
    {
        cin>>n;
        fort(i,1,n) cin>>v1[i];
        LL ok=tk();
        if (n<=8) sub1();else
            if (ok==0) sub2();else
                if (ok==1) sub3();else sub4();
    }
}
