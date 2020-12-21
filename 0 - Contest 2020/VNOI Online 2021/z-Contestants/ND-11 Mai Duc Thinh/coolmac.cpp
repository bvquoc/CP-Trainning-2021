#include<bits/stdc++.h>
#define fort(i,a,b) for(long i=a;i<=b;i++)
#define x first
#define y second
#define MP make_pair
#define forn(i,a,b) for(long i=a;i>=b;i--)
using namespace std;
const long N=1e5+5;
typedef pair<long,long> ii;
long n,t[N],cnt,rs;
ii a[N],st[N];
bool cmp(ii x,ii y)
{
    return x.x<y.x||(x.x==y.x&&x.y>y.y);
}
int main()
{
    freopen("coolmac.inp","r",stdin);
    freopen("coolmac.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    fort(i,1,n) cin>>a[i].x>>a[i].y;
    a[++n]=MP(1e5,1e5);
    sort(a+1,a+1+n,cmp);
    fort(i,1,n)
     if (st[cnt].y<a[i].y) st[++cnt]=a[i];
    cin>>n;
    fort(i,1,n) cin>>t[i];
    sort(t+1,t+1+n);
    forn(i,cnt,1)
     if (t[1]>=st[i].x&&st[i].y>=t[1])
     {
         rs=cnt-i+1;
         break;
     }
    fort(i,cnt-rs+1,cnt)
         {
             if (i>1&&st[i].x>st[i-1].y+1)
                {
                    cout<<"-1\n";
                    return 0;
                }
         }
    cout<<rs<<'\n';
}
