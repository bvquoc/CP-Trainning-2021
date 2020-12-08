#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define ROF(i,a,b) for(int i = a; i >= b; --i)
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
#define maxN 100005
#define Bit(i,j) ((j>>i)&1)
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int dx[20] = {0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000,1000000};
int mod[20];
int f[50000005];
int dp[50000005];
void trau(int x,int t) {
    int n = 4;
    int res = 1e9;
    int aa , bb ,cc ,dd ,ee ;
    FOR(a,0,20)
        FOR(b,0,7)
            FOR(c,0,4)
                FOR(d,0,2)
                    FOR(e,0,20){
                    int sl = a + b + c + d + e ;
                    int sum = dx[1]*a + dx[2]*b +dx[3]*c + dx[4]*d +e*x;
                    if(sum == t){
                       // cout<<"SL1 " <<a<<" SL3 " <<b<<" SL5 " <<c<<" SL10 " <<d<<" SLE "<<e<<' '<<sl<<' '<<sum<<endl;
                        if(res < sl ) continue;
                        res = sl ;
                        aa = a;
                        bb = b;
                        cc = c;
                        dd = d;
                        ee = e;
                    }
            }
//    cout<<aa<<' '<<bb<<' '<<cc<<' '<<dd<<' '<< ee<< " RES " <<res<<'\n';
    cout<<res<<'\n';
}
void AC(ll x,ll t) {

    FOR(i,1,16) mod[i] = dx[i];
    mod[16] = x;
    sort(mod + 1,mod + 1 + 16);
    int pos = 16;
    ll res = 0;
   // FOR(i,1,16) cout<<"mod " <<i<<' '<<mod[i]<<endl;
    while(pos > 1 && t < mod[pos]) {
        pos--;
    }
    ll cur = t;
    //cout<<"pos " <<pos<<' '<<mod[pos]<<endl;
    while(pos >= 1 && cur > 0) {
       // cout<<" cur " <<cur<<endl;
        ll val = cur/mod[pos];
       // cout<<pos<<' '<<"pos"<<' '<<mod[pos]<< " VAL " <<val<<endl;
        res += val;
        cur = cur%mod[pos];
        pos --;
    }
    cout<<"RESSSSSSS " << res<<'\n';
}
void solve(int x,int t) {
    FOR(i,1,16) mod[i] = dx[i];
    mod[16] = x;
    sort(mod + 1,mod + 1 + 16);
    f[0] = 0;
    FOR(cur,1,t) {
        f[cur] = 2e9;
        FOR(k,1,16){
            if(cur - mod[k] < 0 ) break;
            if( f[cur] > f[cur - mod[k]] + 1) f[cur] = f[cur - mod[k]] + 1;
           // if(cur == t) cout<<" cur " <<cur<<' '<<f[cur]<<endl;
        }
    }
    cout<<f[t]<<'\n';
}
int DP(int cur) {
    if(cur <= 1) return cur;
    if(dp[cur] != 1e18) return dp[cur];
    //cout<<"DP " <<cur<<endl;
    FOR(k,1,16) {
        if(cur - mod[k] < 0) break;
        int val = DP(cur - mod[k]) +1 ;
        if(dp[cur] > val)
            dp[cur] = val;
    }
    return dp[cur];
}
void ac(int x,int t) {
    FOR(i,1,16) mod[i] = dx[i];
    mod[16] = x;
    sort(mod + 1,mod + 1 + 16);
    FOR(i,1,t) dp[i] = 1e18;
    dp[1] = 1;
    dp[0] = 0;
    int res = DP(t);
    cout<<res<<'\n';
}
int main () {
    fast_read
    freopen("ODDCOIN.inp","r",stdin);
    freopen("ODDCOIN.out","w",stdout);
    int Q;
    cin>>Q;
    FOR(q,1,Q) {
        int x,t;
        cin>>x>>t;
        if(t == 0) {
            cout<<"0\n";
            continue;
        }
//        if(x <= 20 && t <= 20 )
       // trau((int) x,(int) t);
       // AC(x,t);
        if(x <= 100000 && t <= 100000 ) solve((int) x,(int) t) ;
        else
            ac(x,t);
    }
}
/*
4
4700 53
4700 9400
4700 9401
4700 30000
*/
