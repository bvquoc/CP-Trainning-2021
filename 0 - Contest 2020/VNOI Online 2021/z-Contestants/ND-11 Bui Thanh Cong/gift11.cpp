#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=998244353;
const long o=2005;
ll n,sc,sl,a[o],ev[o],od[o],b[o],f[o][o][11];
void sub1()
{
    for(long i=1;i<=n;i++)
        b[i]=i;
    long kq=0;
    do{
        long sd=0;
        for(long i=1;i<=n;i++)
        {
            long phu=a[b[i]];
            while(phu>0)
            {
                sd=(sd*10+phu%10)%11;
                phu/=10;
            }
        }
        if(sd==0)kq++;
    }
    while(next_permutation(b+1,b+1+n));
    cout<<kq<<'\n';
}
void sub2()
{
    long tong=0;
    for(long i=1;i<=sc;i++)
        tong+=ev[i];
    if(tong%11!=0)
    {
        cout<<-1<<'\n';
        return;
    }
    ll kq=1;
    for(long i=1;i<=n;i++)
        kq=kq*i%M;
    cout<<kq<<'\n';
}
ll dq(long x,long le,long du)
{
    if(x>n)return (le==0 && du==0);
    if(f[x][le][du]!=-1)return f[x][le][du];
    ll da=0;
    if(le>0)da=(da+dq(x+1,le-1,(du+od[x]+11000)%11)*le)%M;
    long chan=n/2-(x-1-(n-n/2-le));
    if(chan>0)da=(da+dq(x+1,le,(du-od[x]+11000)%11)*chan)%M;
    return f[x][le][du]=da;
}
void sub3()
{
    for(long i=0;i<=n;i++)
    for(long j=0;j<=n;j++)
    for(long k=0;k<11;k++)
        f[i][j][k]=-1;
    cout<<dq(1,n-n/2,0)<<'\n';
}
int main()
{
    freopen("gift11.inp","r",stdin);
    freopen("gift11.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long test; cin>>test;
    while(test--)
    {
        cin>>n;
        sc=0; sl=0;
        for(long i=1;i<=n;i++)
        {
            cin>>a[i];
            long phu=a[i],scs=0,tong=0;
            while(phu>0)
            {
                if(scs%2==0)tong+=phu%10;
                else tong-=phu%10;
                scs++; phu/=10;
            }
            if(scs%2==0)ev[++sc]=-tong;
            else od[++sl]=tong;
        }
        if(n<=8)sub1();
        else if(sl==0)sub2();
        else if(sc==0)sub3();
    }
    return 0;
}
