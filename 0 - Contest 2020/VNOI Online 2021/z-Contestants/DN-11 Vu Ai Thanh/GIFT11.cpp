// i'm wutan
#include <bits/stdc++.h>
#define io_faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define EL cout<<'\n'
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
#define sz(a) int(a.size())
#define FU(x,a,b) for(int x=int(a);x<=int(b);x++)
#define FD(x,a,b) for(int x=int(a);x>=int(b);x--)
#define PROB "GIFT11"

using namespace std;
typedef long long ll;
typedef double db;

void file(){
    freopen(PROB".inp","r",stdin);
    freopen(PROB".out","w",stdout);
}

const int N = 2000;
const ll mod = 998244353;
int n; string a[N + 1];
bool in[10]{0};
int dp[1002][11][11];
int f[1002][11][11];

void readinp(){
    cin >> n;
    FU(i, 1, n) cin >> a[i];
}

bool sub1(){
    return (n <= 9);
}

bool sub2(){
    FU(i, 1, n) if (sz(a[i]) % 2 == 1) return false;
    return true;
}

bool sub3(){
    FU(i, 1, n) if (sz(a[i]) % 2 == 0) return false;
    return true;
}

int sc, sl, si, res;
void bt(int i){
    FU(j, 1, n) if (!in[j]){
        in[j] = true;
        int p1 = 0, p2 = 0;
        FU(k, 1, sz(a[j])){
            if ((si + k) % 2 == 0)
                p1+= int(a[j][k-1] - '0');
            else p2+= int(a[j][k-1] - '0');
        }
        sc+= p1; sl+= p2;
        si+= sz(a[j]);
        if (i == n){
            if ((sc - sl) % 11 == 0)
                res++;
        }
        else bt(i + 1);
        in[j] = false;
        sc-= p1, sl-= p2;
        si-= sz(a[j]);
    }
}

int add(int a, int b){
    return (a + b) % mod;
}

int mul (int a, int b){
    return (ll(a) * ll(b)) % mod;
}

int gt(int k){
    int res = 1;
    FU(i, 1, k) res = mul(res, i);
    return res;
}

void solve(){

    if (sub1()){
        sc = sl = si = res = 0;
        bt(1); cout << res; EL;
    }
    else if (sub2()){
        sc = sl = 0;
        FU(i, 1, n){
            FU(k, 1, sz(a[i])){
                if (k % 2 == 0) sc+= int(a[i][k-1] - '0');
                else sl+= int(a[i][k-1] - '0');
            }
        }
        int res = 0;
        if ((sc - sl) % 11 == 0) {
            res = gt(n);
        }
        cout << res; EL;
    }
    else if (sub3()){
        FU(j, 0, (n + 1) / 2)
        FU(c, 0, 10)
        FU(l, 0, 10)
            dp[j][c][l] = f[j][c][l] = 0;

        dp[0][0][0] = 1;
        FU(i, 0, n - 1){
            FU(j, 0, (n + 1) / 2)
            FU(c, 0, 10)
            FU(l, 0, 10){
                if (dp[j][c][l] == 0) continue;
                int p = (i + 1);
                int sumc = 0, suml = 0;
                FU(k, 0, sz(a[i+1]) - 1){
                    if ((k + 1) % 2 == 0)
                        sumc+= int(a[i+1][k] - '0');
                    else
                        suml+= int(a[i+1][k] - '0');
                }

                int t = dp[j][c][l];
                f[j][(c + sumc) % 11][(l + suml) % 11]+=t;
                f[j][(c + sumc) % 11][(l + suml) % 11]%= mod;
                f[j+1][(c + suml) % 11][(l + sumc) % 11]+= t;
                f[j+1][(c + suml) % 11][(l + sumc) % 11]%= mod;
            }

            FU(j, 0, (n + 1) / 2)
            FU(d, 0, 10)
            FU(c, 0, 10)
                dp[j][d][c] = f[j][d][c];
        }
        int ans = 0;
        FU(i, 0, 10) if (dp[(n + 1)/2][i][i]){
            ans = add(ans, dp[(n+1)/2][i][i]);
        }
        int t1 = (n + 1) / 2;
        int t2 = n - t1;
        cout << mul(ans, mul(gt(t1), gt(t2))); EL;
    }
    else cout << 0,EL;
}

int main(){
    io_faster
    file();
    int t = 1;
    cin >> t;
    while (t--){
        readinp();
        solve();
    }
}


