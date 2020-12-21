#include<bits/stdc++.h>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define pb push_back
#define f first
#define s second
#define nmax 100005
#define mod 998244353
using namespace std;
int n, t, c, l;
int a[nmax];
int check(int u)
{
    int tg = 0;
    while(u != 0)
    {
        if(tg%2 == 0)
            l = l + u%10;
        else
            c = c + u%10;
        u = u/10;
        tg++;
    }
    return tg;
}
void sub2()
{
    long long s = 1;
    if((l - c)%11 == 0)
    {
        For(i, 2, n)
            s = (s*i)%mod;
        cout<<s<<endl;
    }
    else
        cout<<0<<endl;
}
int build(int S, int k)
{
    if(S == 0)
    {
        S += k;
        return S;
    }
    int l = check(k);
    while(l--)
        S = S*10;
    S+=k;
    return S;
}
void solve()
{
    vector<int> d;
    long long s=0, kq = 0;
    For(i, 1, n)
        d.pb(i);
    For(i, 1, n)
        s = build(s, a[i]);
    if(s % 11 == 0)
        kq = (kq + 1)%mod;
    while(std::next_permutation(d.begin(), d.end()))
    {
        s = 0;
        For(i, 0, n - 1)
            s = build(s, a[d[i]]);
        if(s%11 == 0)
            kq = (kq + 1)%mod;

    }
    cout<<kq<<endl;
}
int main()
{
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    freopen("GIFT11.inp","r",stdin);
    freopen("GIFT11.out","w", stdout);
    cin >> t;
    while(t--)
    {
        l = 0, c = 0;
        int tg = 0;
        cin >> n;
        For(i, 1, n){
            cin >> a[i];
            if(check(a[i])%2 == 0)
                tg ++;
            }
        if(tg == n)
            sub2();
        else
            solve();
    }
}
