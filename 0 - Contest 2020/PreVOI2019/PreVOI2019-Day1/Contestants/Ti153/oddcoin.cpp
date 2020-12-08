///HELLO EVERYONE! TODAY I FEEL SO GOOD :)
#include <bits/stdc++.h>
using namespace std;
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Task "oddcoin"
#define maxn 100005
#define MOD 1000000007
#define pii pair<int, int>
#define endl "\n"
int Q,x,t,n=16,res=MOD;
int f[18][maxn];
int b[20],st[20],c[20];
int a[100]={0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
void cal()
{
    int val=t,num=0,dem=0;
    for(int i=1; i<=n; ++i)
    {
        if(st[i])
          c[++dem]=b[i];
    }
    for(int i=dem; i>=1; --i)
    {
        int u=val/c[i];
        num+=u;
        val-=u*c[i];
    }
    if(val==0)
       res=min(res,num);
}
void dq(int i)
{
    if(i==n+1)
    {
        cal();
        return;
    }
    for(int j=0; j<=1; ++j)
    {
        st[i]=j;
        dq(i+1);
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> Q;
    while(Q--)
    {
        cin >> x >> t;
        if(x<= 1e5 && t <= 1e5)
        {
            a[n]=x;
            for(int j=1; j<=t; ++j) f[0][j]=MOD;
            for(int i=1; i<=n; ++i)
               for(int j=1; j<=t; ++j)
                  {
                      f[i][j]=MOD;
                      for(int k=0; k<=j/a[i]; ++k)
                  {
                     f[i][j]=min(f[i][j],f[i-1][j-(a[i]*k)]+k);
                  }
                  }
            cout<<f[n][t]<<endl;
        }
        else
        {
           a[n]=x;
           for(int i=1; i<=n; ++i) b[i]=a[i];
           sort(b+1,b+1+n);
           dq(1);
           cout<<res<<endl;
           res=MOD;
        }
    }
}
