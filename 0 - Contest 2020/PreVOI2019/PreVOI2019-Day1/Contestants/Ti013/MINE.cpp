#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define pll pair<ll, ll>
#define ppii pair<pii, pii>
#define pli pair<ll, int>
using namespace std;
const int N=2e5+1;
const ll mod=1e6+3;
int n, a[2*N], m, it[2*N];
ll gt[2*N], rev[N+1], cat[N], dp[2*N];
ll Pow(ll x, int y)
{
    if(y==1) return x%mod;
    ll res=Pow(x, y/2);
    res=(res*res)%mod;
    if(y%2) res=(res*x)%mod;
    return res;
}
main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("MINE.inp", "r", stdin);
    freopen("MINE.out", "w", stdout);
    cin>>n>>m;
    for(int i=1; i<=2*n; i++) cin>>a[i];
    if(n<=2000){
        gt[0]=1;
        for(int i=1; i<=2*n; i++) gt[i]=(gt[i-1]*(ll)i)%mod;
        rev[0]=1;
        for(int i=1; i<=n+1; i++) rev[i]=Pow(gt[i], mod-2);
        cat[0]=1;
        for(int i=1; i<=n; i++) cat[i]=(((gt[2*i]*rev[i])%mod)*rev[i+1])%mod;
        int t=1;
        for(int i=1; i<=2*n; i++){
            t=max(t, i);
            while(t<=2*n&&a[t]-a[i]<=m) t++;
            it[i]=t-1; t--;
        }
        dp[2*n+1]=1;
        for(int i=2*n-1; i>=1; i-=2){
            if(it[i]==i) continue;
            t=it[i]; if((t-i)%2==0) t--;
            for(int j=t; j>i; j-=2){
                dp[i]=(dp[i]+dp[j+1]*cat[(j-i-1)/2]%mod)%mod;
            }
        }
        cout<<dp[1]<<'\n';
    }
}

