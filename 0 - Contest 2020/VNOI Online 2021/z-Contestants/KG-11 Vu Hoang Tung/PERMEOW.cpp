#include <bits/stdc++.h>
#define int long long
#define Task "PERMEOW"
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READFILE freopen(Task".INP", "r", stdin)
#define WRITEFILE freopen(Task".OUT", "w", stdout)
#define pb push_back
#define mp make_pair
#define oo 1e18
#define ENDL '\n'
#define debug(x) cout << #x << " = " << x << ENDL
#define X first
#define Y second
#define ever (;true;)
#define all(x) x.begin(), x.end()

using namespace std;

typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < vvi > vvvi;
typedef pair < int, int > ii;
typedef vector < ii > vii;
typedef vector < vii > vvii;
typedef pair < int, ii > iii;
typedef vector < iii > viii;

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;


int n;
int P[N], F[N];
vi a(N);
vi b(N);
int ans = 0;
int used[N];
vi c(N);

void init(){
    FAST;
    READFILE;
    WRITEFILE;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    P[0] = 1;
    F[0] = 0;
    for (int i = 1; i <= n; ++i){
        P[i] = (P[i - 1] * i) % MOD;
        F[i] = ((2 * F[i - 1]) % MOD + (P[i - 1] * (i - 1))) % MOD;
    }
}

int Proc(int n, vi &a){
    vi g(N);
    for (int i = 1; i <= n; ++i){
        g[a[i]] = i;
    }
    vi vs(n + 10, 0);
    int cnt = 0;
    for (int i = 1; i <= n; ++i){
        if (vs[i] == 0){
            ++cnt;
            queue < int > q;
            vs[i] = 1;
            q.push(i);
            while (q.size()){
                int u = q.front();
                q.pop();
                int v = g[u];
                if (vs[v] == 1) continue;
                vs[v] = 1;
                q.push(v);
            }
        }
    }
    return (n - cnt) % MOD;
}

void backtrack(int i, bool ok1, bool ok2){
    int Min = a[i];
    int Max = b[i];
    if (ok1) Min = 1;
    if (ok2) Max = n;
    for (int k = Min; k <= Max; ++k){
        if (used[k]) continue;
        bool t1 = ok1;
        bool t2 = ok2;
        c[i] = k;
        if (k > a[i]) t1 = 1;
        if (k < b[i]) t2 = 1;
        used[k] = 1;
        if (i < n) backtrack(i + 1, t1, t2);
        else (ans += Proc(n, c)) %= MOD;
        used[k] = 0;
    }
}

signed main(){
    init();
    backtrack(1, 0, 0);
    cout << ans;
    return 0;
}

