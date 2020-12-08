#include <bits/stdc++.h>
#define fo(i, a, b) for(int i=a;i<=b;i++)
#define rep(i, a, b) for(int i=a;i>=b;i--)
#define Reset(c) memset(c,0,sizeof(c))
#define ll long long
#define ii pair<int, int>
#define ft first
#define sc second
#define vi vector<int>
#define pb push_back
#define maxn 1000001
#define inf 100000001
#define name "oddcoin"
#define INPUT  freopen(name".inp","r",stdin)
#define OUTPUT freopen(name".out","w",stdout)
#define el '\n'
//-------------------------------------------------------------------------------
using namespace std;

int kq, f[maxn];
ll x, t;
ll a[17];
void findf(int t)
{
    fo(i, 1, t)
    {
        f[i]=inf;
        fo(j, 1, 16)
        if(i>=a[j]) f[i]=min(f[i], f[i-a[j]]+1);
    }
    kq=f[t];
}
int cal(ll t)
{
    if(t<=1000000) {
        findf(t); return f[t];
    }
    findf(1000000);
    int res=inf;
    fo(i, 2, sqrt(t))
    if(!(t%i) && t/i<=1000000)
        res=min(res,f[t/i]*i);
    fo(i, 2, sqrt(t))
        if((t-1)%i==0 && (t-1)/i<=1000000) res=min(res, f[t/i]*i+1);
    return res;
}
//-------------------------------------------------------------------------------
int main()
{
    INPUT; OUTPUT;
    int q; cin >> q;
    a[1]=1; a[2]=3; a[3]=5;
    for(int i=4; i<=15; i++) a[i]=a[i-3]*10;
    while(q--){
        cin >> a[16] >> t;
        kq=cal(t);
        cerr << kq << el;
    }
}
