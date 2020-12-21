#include <bits/stdc++.h>
#define FILE "gift11"
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int N = 2009;
const ll M = 998244353;
int T,n,
    a[N],t[N];
pii calc(int x)
{
    int t=0,d=0,m=1;
    while(x) t+=m*(x%10),
             x/=10,
             m=-m,
             d++;
    if(d%2==0) t=-t;
    return {t,d};
}
void sub1()
{
    int p[11];
    for(int i=1;i<=n;i++) p[i]=i;
    int kq=0;
    do
    {
        //if(n <=5) {for(int i=1;i<=n;i++) cout<<a[i]<<' ';cout<<'\n';}
        int t=0,scs=0;
        for(int i=1;i<=n;i++)
        {
            pii tmp=calc(a[p[i]]);
            if(scs%2==0) t+=tmp.F;
            else t-=tmp.F;
            scs+=tmp.S;
        }
        if(t%11==0) kq++;
    } while (next_permutation(p+1,p+1+n));
    cout<<kq<<'\n';
}
void sub2()
{
    int s=0;
    for(int i=1;i<=n;i++)
        s+=t[i];
    if(s%11==0)
    {
        ll kq=1;
        for(int i=1;i<=n;i++)
            kq=(kq*i)%M;
        cout<<kq<<'\n';
    }
    else cout<<0<<'\n';
}
vector<vector<int> > f;
void sub3()
{
    int s=0;
    for(int i=1;i<=n;i++) 
        s+=t[i];
    s/=2;
    f.resize(n+3);
    f[0].resize(s+3);
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        f[i].resize(s+3);
        for(int j=1;j<=s;j++)  
        {
            if(j >= t[i]) f[i][j]=(f[i][j] + f[i-1][j-t[i]])%M;
            f[i][j]=(f[i][j] + f[i-1][j])%M;
        }
    }
    int kq=0;
    for(int i=1;i<=n;i++)
        kq=(kq+f[i][s])%M;
    cout<<kq;
}
int main()
{
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(n <= 9) {sub1();continue;}
        bool oks2=1,oks3=1;
        for(int i=1;i<=n;i++)
        {
            pii tmp=calc(a[i]);
            t[i]=tmp.F;
            if(tmp.S%2==0) oks3=0;
            else oks2=0;
        }
        if(oks2) {sub2();continue;}
        if(oks3) {sub3();continue;}
    }
}
