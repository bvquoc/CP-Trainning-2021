#include<bits/stdc++.h>

using namespace std;

#define int long long

int n,m,sl[4005][2005],base=1e6+3,td[4005],f[4005],a[4005];

int SL(int i,int sum)
{
    if(sl[i][sum]!=-1) return sl[i][sum];
    else if(i==0)
    {
        if(sum==0) return 1;
        return 0;
    }
    else if(sum>i) return 0;
    else
    {
        int res=0;
        res=SL(i-1,sum+1);
        if(sum!=0)
        {
            res=res+SL(i-1,sum-1);
            if(res>=base) res-=base;
        }
        sl[i][sum]=res;
        return res;
    }
}

int F(int i)
{
    if(f[i]!=-1) return f[i];
    else if(i==2*n+1) return 1;
    else
    {
        int res=0;
        for(int id=i+1;id<=td[i];id+=2)
        {
            res=res+(F(id+1)*sl[id-i-1][0])%base;
            res=res%base;
        }
        f[i]=res;
        return res;
    }
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("Mine.inp","r",stdin);
    freopen("Mine.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=2*n;i++)
    {
        cin>>a[i];
    }
    memset(sl,-1,sizeof(sl));
    memset(f,-1,sizeof(f));
    SL(2*n,0);
    sl[0][0]=1;
    int id=0;
    a[2*n+1]=1e9;
    for(int i=1;i<=2*n;i++)
    {
        while(a[id]<=a[i]+m)
        {
            id++;
        }
        td[i]=id-1;
    }
    cout<<F(1);
}
