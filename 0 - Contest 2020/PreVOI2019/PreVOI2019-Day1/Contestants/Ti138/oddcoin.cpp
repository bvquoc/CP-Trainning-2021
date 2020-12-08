#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m,i,j,k,res,s,t;
int a[200],b[200],c[200];
template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c))
    {
        x=x*10+c-48;
        c=getchar();
    }
}
void capnhat()
{
    int x=t;
    int ans=0;
    int i=s;
    while(x && i>0)
    {
        ans+=x/c[i];
        x-=c[i]*(x/c[i]);
        i--;
    }
    if(x==0)
    res=min(res,ans);
}
void Try(int i)
{

    for(int j=1;j>=0;j--)
    {
        if(j==1)
        {
            s++;
            c[s]=b[i];
        }
        if(i==n) capnhat();
        else Try(i+1);
        if(j==1) s--;
    }
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    a[1]=1;
    for(int i=2;i<=5;i++) a[i]=a[i-1]*10;
    a[6]=3;
    for(int i=7;i<=10;i++) a[i]=a[i-1]*10;
    a[11]=5;
    for(int i=12;i<=15;i++) a[i]=a[i-1]*10;
    n=15;
    int q;
    cin >> q;
    while(q--)
    {
        int x;
        for(int i=1;i<=n;i++) b[i]=a[i];
        cin >> x >> t;
        n++;
        b[n]=x;
        sort(b+1,b+n+1);
        res=t;
        s=0;
        Try(1);
        cout << res << '\n';
        n--;
    }
}
