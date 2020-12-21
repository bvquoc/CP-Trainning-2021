//Hoang Son WIBU lolicon codeforces rate 1439 khong cay
#include <bits/stdc++.h>
#define F first
#define S second
#define times double stime = clock();
#define gettime cerr << "\nTime executed: " << (clock() - stime) / CLOCKS_PER_SEC * 1000 << "ms.\n";
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const ll mod = 1000000007;
//-std=gnu++17 -Wall

struct BIT{
    int n;
    vector<int> bit;
    void setup(int _n){
        n = _n;
        bit = vector<int>(n + 1, 0);
    }
    void update(int i, int det){
        for(; i <= n; i+=i&-i){
            bit[i] += det;
        }
    }
    int query(int i){
        int res = 0;
        for(; i>=1; i-=i&-i){
            res += bit[i];
        }
        return res;
    }
};

//PERMEOW
int n;
int a[200005], b[200005];
BIT git;
int cntNsteps(){
    int ans = 0;
    git.setup(n);
    for(int i = n; i>=1; i--){
        ans = (ans + git.query(a[i]))%mod;
        git.update(a[i], 1);
    }
    return ans;
}
void sub3(){
    int res = 0;
    do {
        bool checkover = false;
        for(int i = 1; i<=n; i++){
            if(a[i] != b[i]){
                checkover = (a[i] > b[i]);
                break;
            }
        }
        if(checkover) break;
        int k = cntNsteps();
        res = (res + k)%mod;
    } while(next_permutation(a + 1, a + n + 1));
    cout << res;
}
ll powlf(ll ax, ll bx){
    ax %= mod;
    if(bx == 0) return 1;
    if(bx == 1) return ax;
    ll cx = powlf(ax, bx/2);
    cx = (cx * cx)%mod;
    if(bx%2) cx = (cx*ax)%mod;
    return cx;
}
ll fac[200005][2];
void process(){
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> a[i];
    bool oksub1 = true, oksub2 = true;
    for(int i = 1; i<=n; i++){
        cin >> b[i];
        if(b[i] != a[i]) oksub1 = false;
    }
    for(int i = 1; i<=n; i++){
        if(b[i] != a[n-i+1] || b[i] != n-i+1) oksub2 = false;
    }
    if(oksub1){
        cout << cntNsteps();
    } else if(oksub2){
        fac[0][0] = 1;
        for(int i = 1; i<=n; i++){
            fac[i][0] = (fac[i - 1][0]*i)%mod;
        }
        fac[n + 1][1] = 1;
        for(int i = n; i>=0; i--){
            fac[i][1] = (fac[i + 1][1] * i)%mod;
        }
        ll res = 0;
        for(int i = 1; i<=n; i++){
            res = (res + (1ll*(i-1)*i/2ll%mod) * fac[i-1][0]%mod * fac[i + 1][1] %mod)%mod;
        }
        cout << res;
    } else sub3();
}
int online = 1;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(online == 0){
        freopen("in.inp","r", stdin);
        freopen("out.out","w", stdout);
    } else if(online == 1){
        freopen("PERMEOW.inp","r", stdin);
        freopen("PERMEOW.out","w", stdout);
    }
    //times
    process();
    //gettime
    return 0;
}