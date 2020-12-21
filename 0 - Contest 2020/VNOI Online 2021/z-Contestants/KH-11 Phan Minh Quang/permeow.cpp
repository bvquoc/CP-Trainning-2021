#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
#define mp(a, b) map<a, b>
#define setE(a, b) fill_n(a, sizeof(a)/sizeof(a[0]), b)
#define st(a) system((a).c_str());
using namespace std;
// cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "permeow";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll mxn = 2e5 + 7, MOD = 1e9 + 7, mn = 2007;
ll n, a[mxn], b[mxn], dp[mn] = {{0}}, gt[mn];

int main(){
    opt;
    file;
    cin >> n;
    lp(i, 1, n){
        cin >> a[i];
    }
    bool ok = 1;
    lp(i, 1, n) if(cin >> b[i], b[i] != a[i]) ok = 0;
    if(ok){
        ll cnt = 0;
        lp(i, 1, n){
            lp(j, i + 1, n){
                if(a[i] > a[j]) ++cnt;
            }
        }
        cout << cnt;
    }
    else{
        gt[0] = 1;
        lp(i, 1, n) gt[i] = (gt[i - 1] * i) % MOD;
        lpd(i, n - 1, 1){
            dp[i] = gt[i] * ((n - i) * (n - i + 1) / 2) + dp[i + 1];
        }
        cout << dp[1];
    }
}
