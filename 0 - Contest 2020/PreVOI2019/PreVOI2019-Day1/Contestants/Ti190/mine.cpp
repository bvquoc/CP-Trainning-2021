// KHAz
#include <bits/stdc++.h>
#define maxn 200005
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000003
#define Task "mine"
#define pii pair < int,int >
#define pil pair < int,pii >
using namespace std;
int n,m;
int a[2*maxn];
int get(int i, int j){return (i>>j)&1;}
void sub1()
{
    n*=2;
    bool ok;
    int kq=0;
    for(int x=1;x<(1<<n);x++)
    {
        if(__builtin_popcount(x)!=n/2) continue;
       // cout << x <<endl;
        int dem=0;
        int s[22],tp=0;
        ok=0;
        for(int i=n-1;i>=0;i--)
        {
            //int i1=i-1;
        //    if(x==44&&i==0) cout << get(x,i);
            if(get(x,i)) dem++ , s[++tp]=a[n-i];
            else
            {
                dem--;
                if(dem<0) {ok=1;break;}
                if(a[n-i]-s[tp]<=m) tp--;
                else {ok=1;break;}
            }
        }
        if(ok==0&&dem==0) kq++;
    }
  cout << kq;
}
void sub2()
{
    long long res=1;
    for(int i=1;i<n;i++)
    {
        res=(res*2)%MOD;
    }
    cout << res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
     cin>>n>>m;
     for(int i=1;i<=2*n;i++)
        cin>>a[i];
    if(n<=10) sub1();
    else sub2();
    return 0;
}
