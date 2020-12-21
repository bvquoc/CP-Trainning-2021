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
int T,n,le,chan;
int x[10],a[2020];
bool used[10];
long long ans = 0, mod = 998244353;
void inp()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("GIFT11.inp","r",stdin);
    freopen("GIFT11.out","w",stdout);
    cin>>T;
}
void duyet(int i)
{
    if (i > n)
    {
        int du = 0, cnt = 0;
        fr(j,1,n)
        {
            int val = a[x[j]];
            while (val > 0)
            {
                cnt++;
                if (cnt % 2 == 0) du -= (val % 10);
                else du += (val % 10);
                val /= 10;
            }
        }
        du = abs(du);
        if (du % 11 == 0) ans++;
        return;
    }
    fr(j,1,n)
        if (!used[j])
        {
            used[j] = true;
            x[i] = j;
            duyet(i+1);
            used[j] = false;
        }
}
void solve1()
{
    ans = 0;
    duyet(1);
    cout<<ans<<"\n";
}
void solve2()
{
    ans = 1;
    int du = 0, cnt = 0;
    fr(i,1,n)
    {
        ans = (ans * i) % mod;
        int val = a[i];
        while (val > 0)
        {
            cnt++;
            if (cnt % 2 == 0) du -= (val % 10);
            else du += (val % 10);
            val /= 10;
        }
    }
    du = abs(du);
    if (du % 11 == 0) cout<<ans<<"\n";
    else cout<<"0\n";
}
void sub()
{
    fr(t,1,T)
    {
        chan = 0; le = 0;
        cin>>n;
        fr(i,1,n)
        {
            cin>>a[i];
            int val = a[i], cnt = 0;
            while (val > 0)
            {
                cnt++;
                val /= 10;
            }
            if (cnt % 2 == 0) chan++;
            else le++;
        }
        if (n <= 8) solve1();
        else
            if (chan == n) solve2();
    }
}
int main()
{
    inp();
    sub();
    return 0;
}
