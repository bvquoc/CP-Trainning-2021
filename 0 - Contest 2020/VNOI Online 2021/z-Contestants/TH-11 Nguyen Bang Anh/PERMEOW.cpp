#include <bits/stdc++.h>
using namespace std;
#define ii pair<long long,long long>
#define oo 1000000000000000000
#define MAXN 100001
#define all(x) x.begin(),x.end()
#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define PR(x,a,b) { cout<<#x<<' '; for(long long i=a;i<=b;i++) cout<<x[i]<<' '; cout<<'\n'; }
#define taskname "PERMEOW"
#define pb push_back
#define base 1000000007

int n, a[MAXN], b[MAXN];

void read()
{
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n) cin>>b[i];
}

bool sub1=true, sub2=true;

void init()
{
    FOR(i,1,n)
    {
        if(a[i]!=b[i]) sub1=false;
        if(a[i]!=i&&b[i]!=n-i+1) sub2=false;
    }
}

int kq=0;

int GiaiThua(int n)
{
    if(n==0) return 1;
    int res=1;
    for(int i=1;i<=n;i++)
        res=(res*i)%base;
    return res;
}

int ChinhHop(int n, int k)
{
    int res=1;
    for(int i=0;i<k;i++)
        res=(res*(n-i))%base;
    return res;
}

void solve()
{
    if(sub1)
    {
        int cnt=0;
        FOR(i,1,n)
        {
            cnt=0;
            FOR(j,1,i-1)
            {
                if(a[j]>a[i]) cnt++;
            }
            kq+=cnt;
            kq%=base;
        }
    }
    else if(sub2)
    {
        FOR(i,1,n)
        {
            int gt=n-2;
            FOR(j,1,n-i)
            {
                kq=(kq+((ChinhHop(n-i,j)*GiaiThua(gt)%base)*(j)%base))%base;
                gt--;
            }
        }
    }
}

void write()
{
    cout<<kq;
}

int main()
{
    freopen(taskname".INP","r",stdin);
    freopen(taskname".OUT","w",stdout);
    read();
    init();
    solve();
    write();
    return 0;
}
