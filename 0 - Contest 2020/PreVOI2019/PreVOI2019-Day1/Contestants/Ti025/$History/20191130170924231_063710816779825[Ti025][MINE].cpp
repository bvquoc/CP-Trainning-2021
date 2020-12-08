#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define ROF(i,a,b) for(int i = a; i >= b; --i)
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
#define maxN 500005
#define Bit(i,j) ((j>>i)&1)
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,N,m;
const ll mod = 1000003;
ll f[5005][5005];
int a[maxN],id[maxN],cntL,cntR;
bool check() {
    int cur = 0;
    stack<int> stk;
    FOR(i,1,N) {
        if(id[i]) {
            stk.push(i);
        }
        else {
            if(stk.empty()) return false;
            int u = stk.top();
            stk.pop();
            if(abs(a[i] - a[u]) > m) return false;
        }
    }
    return true;
}
void trau() {
    N = 2*n;
    ll ans = 0 ;
    FOR(mask,1,(1<<N) - 1) {
        cntL = 0 ;
        cntR = 0 ;
        FOR(i,0,N - 1) {
            int bt = Bit(i,mask);
          //  cout<<bt;
            if(bt == 1) {
                id[i+1] = 1;
                ++cntL;
            }
            else {
                id[i+1] = 0;
                ++cntR;
            }
        }
       // cout<<"endl" <<endl;
        if(cntR != cntL) continue;
        if(check()) {
//            cout<<"OKOK " <<endl;
//            FOR(i,0,N-1)
//                cout<<Bit(i,mask);
//            cout<<endl;
            ans = (ans + 1)%mod;
        }
    }
    cout<<"ans " <<ans<<'\n';
}
void ac() {
    ll ans = 0;
    N = 2*n;
    f[1][1] = 1;
    FOR(i,2,N) {
        FOR(j,0,i) {
            if(j > 0) f[i][j] = (f[i][j] + f[i-1][j-1])%mod;
            if(j + 1 <= i - 1) f[i][j] = (f[i][j] + f[i-1][j+1])%mod;
            //cout<< "F " <<i<<' '<<j<<' '<<f[i][j]<<endl;
        }
    }
    cout<<f[N][0]%mod ;
}
int main () {
    fast_read
    freopen("MINE.inp","r",stdin);
    freopen("MINE.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,2*n) {
        cin>>a[i];
    }
    //trau();
    ac();
}
