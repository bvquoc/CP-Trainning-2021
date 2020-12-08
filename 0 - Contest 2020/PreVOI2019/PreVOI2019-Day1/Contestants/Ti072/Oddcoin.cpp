#include <bits/stdc++.h>

using namespace std;
const int MAXN=1e5+7;
long long d[18]= {0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
//                1 2 3  4 5   6   7  8  9    10   11   12    13   14     15
int dd[50005];
long long t;
long long ans=1e18;
long long sum=0;
int n=16,q;
int f[MAXN];
void sub1(int i,int x)
{
    if(i==n+1)
    {
        if(x==0)
            ans=min(ans,sum);
    }
    else
        for(int k=0; k*d[i]<=x; k++)
        {
            sum+=k;
            sub1(i+1,x-k*d[i]);
            sum-=k;
        }
}
set <long long> save;
void sub2()
{
    //save.insert(d[n]);
    //dd[d[n]]++;
    f[0]=0;
    for(int i=1; i<=t; i++)
    {
        f[i]=1e9;
        for(int j=1; j<=n; j++)
        {
            if(d[j]>i)
                continue ;
            for(int k=1; k*(d[j])<=i; k++)
            {
                f[i]=min(f[i],k+f[i-(k*d[j])]);
                //if(i==9400&&d[j]==4700)
                //cerr<<k<<" ";
            }
        }
    }
    cout<<f[t]<<'\n';
}
void sub3()
{
    save.insert(d[n]);
    if(d[n]<=50000)
        dd[d[n]]++;
    long long tmp=t;
    for(set <long long> :: reverse_iterator i=save.rbegin(); i!=save.rend(); i++)
    {
        long long val=*i;
        if(tmp%val==0)
            ans=min(ans,tmp/val);
        if(val>t)
            continue ;
        if(t==0)
            break ;
        sum+=t/val;
        t%=val;
    }
    cout<<min(ans,sum)<<'\n';
    if(d[n]<=50000)
    {
        dd[d[n]]--;
        if(dd[d[n]]==0)
            save.erase(d[n]);
    }
}
void Output()
{
    for(int i=1; i<n; i++)
    {
        save.insert(d[i]);
        dd[d[i]]++;
    }
    cin>>q;
    while(q--)
    {
        cin>>d[n]>>t;
        ans=1e18;
        sum=0;
        if(t<=20)
        {
            sub1(1,t);
            cout<<ans<<'\n';
        }
        else if(t<=10000)
            sub2();
        else
            sub3();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("Oddcoin.inp","r",stdin);
    freopen("Oddcoin.out","w",stdout);
    Output();
    return 0;
}
