#include<bits/stdc++.h>
#define N 100010
#define ll long long
using namespace std;
int T,n,a[N],x[N],ans,mod=998244353,gt[N],sum[N];
string s;
bool check[N];
void xuat()
{
    ll tong=0;
    int type=1;
    for(int i=1; i<=n; i++)
    {
        int tmp=a[x[i]];
        s="";
        while(tmp!=0)
        {
            s=s+char(tmp%10+'0');
            tmp/=10;
        }
        reverse(s.begin(),s.end());
        for(int j=0; j<s.size(); j++)
        {
            tong+=(s[j]-'0')*type;
            type*=-1;
        }
    }
    if(tong%11==0)
        ans=(ans+1)%mod;
}
void backtrack(int i)
{
    for(int j=1; j<=n; j++)
    {
        if(check[j]==false)
        {
            x[i]=j;
            check[j]=true;
            if(i==n)
                xuat();
            else
                backtrack(i+1);
            check[j]=false;
        }
    }
}
void pre()
{
    gt[0]=1;
    for(int i=1; i<=n; i++)
        gt[i]=(gt[i-1]*i)%mod;
}
void sub2()
{
    pre();
    int type=1,tong=0;
    for(int i=1; i<=n; i++)
    {
        int tmp=a[i];
        s="";
        while(tmp!=0)
        {
            s=s+char(tmp%10+'0');
            tmp/=10;
        }
        reverse(s.begin(),s.end());
        for(int j=0; j<s.size(); j++)
        {
            tong+=(s[j]-'0')*type;
            type*=-1;
        }
    }
    if(tong%11==0)
        cout<<gt[n]<<"\n";
    else
        cout<<"0\n";
}
int f[2010][15][1510];
void sub3()
{
    pre();
    for(int i=1; i<=n; i++)
    {
        int tmp=a[i],type=1;
        s="";
        while(tmp!=0)
        {
            s=s+char(tmp%10+'0');
            tmp/=10;
        }
        reverse(s.begin(),s.end());
        for(int j=0; j<s.size(); j++)
        {
            sum[i]+=(s[j]-'0')*type;
            type*=-1;
        }
    }
    f[0][0][0]=1;
    for(int i=0; i<n; i++)
    {
        for(int rem=0; rem<=10; rem++)
        {
            for(int t=0; t<=(n+1)/2; t++)
            {
                if(t<(n+1)/2)
                    f[i+1][(rem+sum[i+1]+11)%11][t+1]=(f[i+1][(rem+sum[i+1]+11)%11][t+1]+f[i][rem][t])%mod;
                f[i+1][(rem-sum[i+1]+11*11)%11][t]=(f[i+1][(rem-sum[i+1]+11*11)%11][t]+f[i][rem][t])%mod;
            }
        }
    }
    ans=((f[n][0][(ll)(n+1)/2]*gt[(ll)(n+1)/2])%mod*gt[(ll)n/2])%mod;
    cout<<ans<<"\n";
}
bool checki(int x)
{
    string s="";
    while(x>0)
    {
        s=s+(char)(x%10+'0');
        x/=10;
    }
    reverse(s.begin(),s.end());
    return (s.size()%2==0);
}
void sub1()
{
    ans=0;
    backtrack(1);
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("gift11.inp","r",stdin);
    freopen("gift11.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        bool checkchan=true;
        bool checkle=true;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            if(checki(a[i]))
                checkle=false;
            else
                checkchan=false;
        }
        if(checkle)
            sub3();
        else
        {
            if(checkchan)
                sub2();
            else
                sub1();
        }
    }
}
