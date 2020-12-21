#include <bits/stdc++.h>
#define fr(i,x,y) for(int i=x;i<=y;i++)
#define frd(i,x,y) for(int i=x;i>=y;i--)
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second
#define maxn 300100
#define Bit(x,i) ((x>>i)&1)
#define Turnoff(t,k) (t^(1<<(k)))
using namespace std;
int m,n;
int ans = 1e9;
pii a[maxn],p[maxn];
void inp()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("COOLMAC.inp","r",stdin);
    freopen("COOLMAC.out","w",stdout);
    cin>>m;
    fr(i,1,m) cin>>a[i].fi>>a[i].se;
    cin>>n;
    fr(i,1,n) cin>>p[i].fi, p[i].se = 100000;
    sort(a+1,a+1+m);
    sort(p+1,p+1+n);
}
void sub1()
{
    fr(x,1,(1<<m)-1)
    {
        int cnt = 0;
        bool ok = true;
        fr(i,1,m) if (Bit(x,i-1) == 1) cnt++;
        fr(i,1,n)
        {
            int R = p[i].fi, dem = 0;
            fr(j,1,m)
                if (Bit(x,j-1) == 1)
                {
                    if (a[j].fi > R) continue;
                    R = max(R,a[j].se); dem += (a[j].se >= p[i].fi);
                }
            if (R < p[i].se || dem == 0) { ok = false; break; }
        }
        if (ok) ans = min(ans,cnt);
    }
    if (ans == 1e9) cout<<"-1";
    else cout<<ans;
}
void sub2()
{
    int i = 1, R = p[1].fi;
    bool check = false;
    ans = 0;
    while (i <= m)
    {
        int maxR = -1;
        while (i <= m && a[i].fi <= R) check = true, maxR = max(maxR,a[i].se), i++;
        if (maxR == -1) break;
        R = maxR; ans++;
        if (R >= 100000) break;
    }
    if (R < 100000 || !check) cout<<"-1";
    else cout<<ans;
}
int main()
{
    inp();
    if (n <= 10 && m <= 16) sub1();
    else sub2();
    return 0;
}
