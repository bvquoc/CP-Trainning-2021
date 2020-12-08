#include<bits/stdc++.h>

#define file "oddcoin"
#define el cout<<"\n"
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define maxn 100005

using namespace std;
int test, x, t, f[maxn], g[maxn];
int c[20]={0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
void sub1()
{
    f1 (i, t) g[i]=1e9;
    c[16]=x;
    for (int i=1; i<=t; i++)
    f1 (j, 16) if (i>=c[j]) g[i]=min(g[i], g[i-c[j]]+1);
    cout << g[t]; el;
}
void sub2()
{
    int res=t/50000+f[t%50000];
    int ans = t/x; t%=x;
    ans += t/50000+f[t%50000];
    cout << min(ans, res); el;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    f1 (i, 50000) f[i]=1e9;
    f1 (i, 50000) f1 (j, 15)
    {
        if (i>=c[j])
            f[i]=min(f[i], f[i-c[j]]+1);
    }
    cin >> test;
    while (test--)
    {
        cin >> x >> t;
        if (x<=100000&&t<=100000)
        {
            sub1();
        }
        else sub2();
    }
    return 0;
}
