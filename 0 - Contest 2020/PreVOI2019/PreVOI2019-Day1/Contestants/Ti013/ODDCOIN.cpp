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
const int oo=2e9;
const int N=2e5+1;
int cnt[14]={2, 4, 1, 2, 4, 1, 2, 4, 1, 2, 4, 1, 2, 4}, a[15]={1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000}, query, dp[N], dp1[N];
vector<pii> q;
bool chk()
{
    for(int i=0; i<q.size(); i++){
        if(q[i].se>=5*10000000) return 1;
    }
    return 0;
}
main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("ODDCOIN.inp", "r", stdin);
    freopen("ODDCOIN.out", "w", stdout);
    int cur=0; dp[0]=0;
    for(int i=1; i<N; i++) dp[i]=oo;
    for(int i=0; i<14; i++){
        for(int j=0; j<=cur+cnt[i]*a[i]; j++) dp1[j]=oo;
        for(int j=0; j<=cur; j++){
            for(int k=1; k<=cnt[i]; k++){
                dp1[j+k*a[i]]=min(dp1[j+k*a[i]], dp[j]+k);
            }
        }
        cur+=cnt[i]*a[i];
        for(int j=0; j<=cur; j++) dp[j]=min(dp[j], dp1[j]);
    }
    cin>>query;
    q=vector<pii>(query);
    for(int i=0; i<q.size(); i++){
        cin>>q[i].fi>>q[i].se;
    }
    int rem, ans;
    if(chk())
    {
        for(int i=0; i<q.size(); i++){
            ans=oo;
            for(int j=0; j<=q[i].se/q[i].fi; j++){
                cur=j; rem=q[i].se-q[i].fi*j;
                cur+=rem/50000+dp[rem%50000];
                if(ans<cur) break; ans=cur;
            }
            cout<<ans<<'\n';
        }
    }
    else{
        for(int i=0; i<q.size(); i++){
            ans=oo;
            for(int j=0; j<=q[i].se/q[i].fi; j++){
                cur=j; rem=q[i].se-q[i].fi*j;
                cur+=rem/50000+dp[rem%50000];
                ans=min(ans, cur);
            }
            cout<<ans<<'\n';
        }
    }
}
